#include "stdafx.h"
#include "robotcontrol.h"
#include <iostream>


RobotControl::RobotControl(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	n = 1;
	mFlipVert = false;
	mFlipHoriz = false;
	vidstarted = false;


	connect(ui.pushButton, SIGNAL(released()), this, SLOT(SetClient()));
	connect(ui.pushButton_2, SIGNAL(released()), this, SLOT(StartListening()));
	connect(ui.pushButton_3, SIGNAL(released()), this, SLOT(StopListening()));
	
	if(n == 0)m_Cap.open(0);

	if (m_Cap.isOpened() && n == 0)
	{
		ui.mBox->append("Videocapturing started");
	}
	
	mFlipHoriz = true;
	mFlipVert = true;
	startTimer(25);
}

RobotControl::~RobotControl()
{

}


void RobotControl::StartListening()
{
	isRecording = true;
}
void RobotControl::StopListening()
{
	isRecording = false;
	ui.openCVviewer->ClearView();
}

//Clientin eli ohjattavan koneen ip
void RobotControl::SetClient()
{
	QString client_ip = ui.lineEdit->text();
	std::string tempip = client_ip.toStdString();
	
	Client_address = (char*)tempip.c_str();

	ui.mBox->append("Client address is: " + QString(Client_address));
}

void RobotControl::on_actionStart_triggered()
{
	if (!m_Cap.isOpened())
	if (!m_Cap.open(0))
		return;

	
}

//Kuvan n‰ytt‰miseen vaadittu metodi, ajetaan omassa s‰ikeess‰
void RobotControl::FVideoCap()
{
	if (n > 0 && !vidstarted)
	{
		m_Client = new UDPClient(port);
		buff = (char*)malloc(UDPMAX);

		ui.mBox->append("Listening to port: " + QString::number(port));
		vidstarted = true;
	}

	if (vidstarted)
	{
		cv::Mat image;
		//Clientin tekemiset
		if (n > 0)
		{
			int result = m_Client->receiveData(buff, UDPMAX);		
			if (result < 0)
			{
				ui.mBox->append("Error with receiving data");
			}
			ui.label->setText("Frame Size: " + QString::number(result));
			videoBuffer.resize(result);
			memcpy((char*)(&videoBuffer[0]), buff, result);

			image = cv::imdecode(cv::Mat(videoBuffer), CV_LOAD_IMAGE_COLOR);
		}

		else
		{
			m_Cap >> image;
		}
		

		//K‰‰nnet‰‰n kuvaa tarpeen mukaan
		if (mFlipVert && mFlipHoriz)
			cv::flip(image, image, -1);
		else if (mFlipVert)
			cv::flip(image, image, 0);
		else if (mFlipHoriz)
		cv::flip(image, image, 1);

		
	

		// N‰ytet‰‰n kuva
		ui.openCVviewer->showImage(image);
	}
}

void RobotControl::timerEvent(QTimerEvent *event)
{
	//Jos halutaan n‰ytt‰‰ kuvaa niin laitetaan se omaan s‰ikeeseens‰
	if (isRecording)
	{
		m_VidThread = std::thread(&RobotControl::FVideoCap, this);
		m_VidThread.join();
	}
	
}


void RobotControl::on_actionVertical_Flip_triggered(bool checked)
{
	mFlipVert = checked;
}

void RobotControl::on_action_Horizontal_Mirror_triggered(bool checked)
{
	mFlipHoriz = checked;
}