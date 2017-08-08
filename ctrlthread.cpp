#include "ctrlthread.h"
#include <QDebug>
#include "wiringPi.h"


#define CTRL 29
#define LED 28

CtrlThread *CtrlThread::mCtrl = NULL;


CtrlThread::CtrlThread(QObject *parent)
{
	mCtrl = this;
}

void CtrlThread::setUp()
{
	if(-1 == wiringPiSetup())
	{
		return;
	}
	pinMode(CTRL, INPUT);
	pullUpDnControl(CTRL, PUD_UP);

	wiringPiISR(CTRL, INT_EDGE_RISING, _BottonPressed);
}

void CtrlThread::_BottonPressed()
{
	qDebug() << "PRESSED!";
	mCtrl->_SendSignal();

	//sleep(1);
	return;
}

void CtrlThread::run()
{
	if(-1 == wiringPiSetup())
	{
		return;
	}
	pinMode(LED, OUTPUT);

	while (true) {
		digitalWrite(LED, HIGH);
		delay(500);
		digitalWrite(LED, LOW);
		delay(500);
	}
}

void CtrlThread::_SendSignal()
{
	static bool flag = true;
	if(flag == true)
	{
		qDebug() << "call successed";
		emit nxtPage();
	}
	flag = !flag;

}
