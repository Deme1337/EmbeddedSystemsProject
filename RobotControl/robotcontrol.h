#ifndef ROBOTCONTROL_H
#define ROBOTCONTROL_H

#include <QtWidgets/QMainWindow>
#include "ui_robotcontrol.h"
#include <thread>
#include <opencv2\highgui\highgui.hpp>
#include "UDPClient.h"




class RobotControl : public QMainWindow
{
	Q_OBJECT

public:
	RobotControl(QWidget *parent = 0);
	~RobotControl();
	
private slots:

	void on_actionStart_triggered();
	void on_actionVertical_Flip_triggered(bool triggered);
	void on_action_Horizontal_Mirror_triggered(bool checked);
	void SetClient();
	void StartListening();
	void StopListening();
	

private:
	Ui::RobotControlClass ui;
	cv::VideoCapture m_Cap;

protected:
	void timerEvent(QTimerEvent *event);

private:
	void FVideoCap();
	std::thread m_VidThread;
	bool mFlipVert;
	bool mFlipHoriz;

	char *Client_address;
	char *Client_port;


	bool isRecording = false;

	bool vidstarted;
	int n;
	std::vector<uchar> videoBuffer;
	char *buff;
	UDPClient *m_Client;
	int UDPMAX = 65507;
	int port = 9999;
};

#endif // ROBOTCONTROL_H
