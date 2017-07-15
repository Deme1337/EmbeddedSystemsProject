/********************************************************************************
** Form generated from reading UI file 'robotcontrol.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ROBOTCONTROL_H
#define UI_ROBOTCONTROL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include "cqtopencvviewergl.h"

QT_BEGIN_NAMESPACE

class Ui_RobotControlClass
{
public:
    QWidget *centralWidget;
    CQtOpenCVViewerGl *openCVviewer;
    QPushButton *pushButton;
    QLineEdit *lineEdit;
    QTextEdit *mBox;
    QLabel *label;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *RobotControlClass)
    {
        if (RobotControlClass->objectName().isEmpty())
            RobotControlClass->setObjectName(QStringLiteral("RobotControlClass"));
        RobotControlClass->resize(1335, 800);
        centralWidget = new QWidget(RobotControlClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        openCVviewer = new CQtOpenCVViewerGl(centralWidget);
        openCVviewer->setObjectName(QStringLiteral("openCVviewer"));
        openCVviewer->setGeometry(QRect(0, -1, 1200, 600));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(10, 690, 93, 28));
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(10, 720, 181, 22));
        mBox = new QTextEdit(centralWidget);
        mBox->setObjectName(QStringLiteral("mBox"));
        mBox->setGeometry(QRect(600, 630, 601, 141));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 610, 181, 31));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(1240, 10, 93, 28));
        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(1240, 40, 93, 28));
        RobotControlClass->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(RobotControlClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        RobotControlClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(RobotControlClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        RobotControlClass->setStatusBar(statusBar);

        retranslateUi(RobotControlClass);

        QMetaObject::connectSlotsByName(RobotControlClass);
    } // setupUi

    void retranslateUi(QMainWindow *RobotControlClass)
    {
        RobotControlClass->setWindowTitle(QApplication::translate("RobotControlClass", "RobotControl", 0));
        pushButton->setText(QApplication::translate("RobotControlClass", "Client IP", 0));
        label->setText(QString());
        pushButton_2->setText(QApplication::translate("RobotControlClass", "Start", 0));
        pushButton_3->setText(QApplication::translate("RobotControlClass", "Stop", 0));
    } // retranslateUi

};

namespace Ui {
    class RobotControlClass: public Ui_RobotControlClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ROBOTCONTROL_H
