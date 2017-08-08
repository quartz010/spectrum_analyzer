#ifndef WAVEFORM_H
#define WAVEFORM_H

#include <QtMath>
#include <QPointF>
#include "qwt_series_data.h"
#include "qwt_plot_curve.h"


class WaveForm : public QObject
{
	Q_OBJECT
public:
	explicit WaveForm(QObject *parent = 0);

	QVector<QPointF> m_WaveVector;




signals:
	void GenFinish();

private:

	QVector<double> xVector;
	QVector<double> yVector;

public slots:
	void GenSinWave(int);
	void GenTriangleWave(int);
	void GenSquareWave(int);
};

#endif // WAVEFORM_H
