#include "main.h"
#include <vector>
#include "opencv2/highgui/highgui.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include<stdio.h>
#include<winsock2.h>

#pragma comment(lib,"ws2_32.lib") //Winsock Library

#define SERVER "192.168.0.101"  //ip address of udp server
#define BUFLEN 1024  //Max length of buffer
#define PORT 9999   //The port on which to listen for incoming data


using namespace std;
using namespace cv;



int main(int argc, const char** argv)
{
	struct sockaddr_in si_other;
	int s, slen = sizeof(si_other);
	char buf[BUFLEN];
	
	WSADATA wsa;

	//std::string videopath = "c:\\temp\\cosmose1.mkv";

	VideoCapture cap(0);
	
	//jossei toimi
	if (!cap.isOpened())
	{
		cout << "Cannot open the video file" << endl;
	}


	//Initialise winsock
	printf("\nInitialising Winsock...");
	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
	{
		printf("Failed. Error Code : %d", WSAGetLastError());
		
	}
	printf("Initialised.\n");

	//create socket
	if ((s = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) == SOCKET_ERROR)
	{
		printf("socket() failed with error code : %d", WSAGetLastError());
		exit(EXIT_FAILURE);
	}

	//setup address structure
	memset((char *)&si_other, 0, sizeof(si_other));
	si_other.sin_family = AF_INET;
	si_other.sin_port = htons(PORT);
	si_other.sin_addr.S_un.S_addr = inet_addr(SERVER);
	vector<int> compression_params = vector<int>(2);
	compression_params.push_back(CV_IMWRITE_JPEG_QUALITY);
	compression_params.push_back(95);

	//start communication
	while (1)
	{

		vector<uchar> message;

		Mat frame;
		
		bool bSuccess = cap.read(frame); // read a new frame from video
		
		if (!bSuccess)
		{
			cout << "Cannot read the frame from video file" << endl;
			break;
		}
	
		
		imencode(".jpeg", frame, message, compression_params);
		
		//send the message
		
		if (sendto(s, (char*)(&message[0]),message.size(), 0, (struct sockaddr *)&si_other, slen) == SOCKET_ERROR)
		{
			printf("sendto() failed with error code : %d size: %d\n", WSAGetLastError(), message.size());	

			continue;
		}
		
		//receive a reply and print it
		//clear the buffer by filling null, it might have previously received data
		//memset(buf, '\0', BUFLEN);
		////try to receive some data, this is a blocking call
		//if (recvfrom(s, buf, BUFLEN, 0, (struct sockaddr *) &si_other, &slen) == SOCKET_ERROR)
		//{
		//	printf("recvfrom() failed with error code : %d", WSAGetLastError());
		//	exit(EXIT_FAILURE);
		//}
		//
		//puts(buf);
		message.clear();
	}

	closesocket(s);
	WSACleanup();

	return 0;
}