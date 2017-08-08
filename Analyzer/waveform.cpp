#include "waveform.h"

WaveForm::WaveForm(QObject *parent) : QObject(parent)
{

}

void WaveForm::GenSinWave(int Freq = 1)
{
	xVector.clear();
	yVector.clear();
	m_WaveVector.clear();
	qDebug() << xVector << yVector << "clear";
	for (int var = 0; var < 100; ++var) {
		QPointF point;
		point.setX(var);
		double y = 20*sin(Freq/100.00*var*M_PI/10);
		point.setY(y);

		m_WaveVector.append(point);
//		qDebug() << m_WaveVector.at(var).x();
//		qDebug() << m_WaveVector.at(var).y();
	}


	foreach (QPointF point, m_WaveVector) {
		xVector.append(point.x());
		yVector.append(point.y());
	}
	qDebug() << xVector << yVector;

	emit GenFinish();
	qDebug() << "emitted!";
}

void WaveForm::GenTriangleWave(int Freq = 1)
{
	xVector.clear();
	yVector.clear();
	m_WaveVector.clear();
	qDebug() << xVector << yVector << "clear";

	int a = 1;
	for (int var = 0; var < 100; ++var) {
		QPointF point;
		point.setX(var);
		double y;
//	double y = 20 * a * (var % 10) * Freq/100.00;
		if(var % 10 == 0)
		{
			a = -a;
		}
		if (a > 0) {
			 y = 20 * (var % 10) * Freq / 100.00;
		} else {
			 y = 20 * (10 - var % 10) * Freq / 100.00;
		}
		point.setY(y);
		m_WaveVector.append(point);
	}

	foreach (QPointF point, m_WaveVector) {
		xVector.append(point.x());
		yVector.append(point.y());
	}
	qDebug() << xVector << yVector;

	emit GenFinish();
	qDebug() << "emitted!";
}

void WaveForm::GenSquareWave(int Freq)
{
	xVector.clear();
	yVector.clear();
	m_WaveVector.clear();
	qDebug() << xVector << yVector << "clear";
	int a = 1;
	for (int var = 0; var < 100; ++var) {
		QPointF point;
		point.setX(var);

		if(var % (10 * Freq/10) == 0)
		{
			a = -a;
		}
		double y = 20 * a;
		point.setY(y);

		m_WaveVector.append(point);
	}


	foreach (QPointF point, m_WaveVector) {
		xVector.append(point.x());
		yVector.append(point.y());
	}
	qDebug() << xVector << yVector;

	emit GenFinish();
	qDebug() << "emitted!";
}
