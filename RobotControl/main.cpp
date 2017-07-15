#include "stdafx.h"
#include "robotcontrol.h"

#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	RobotControl w;
	w.show();
	return a.exec();
}
