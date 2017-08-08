#ifndef PLOTDIALOG_H
#define PLOTDIALOG_H

#include <QDialog>
#include "qwt_plot_curve.h"

#include <QVector>
#include <QTimer>
#include <QEvent>

#include "waveform.h"
namespace Ui {
class PlotDialog;
}

class PlotDialog : public QDialog
{
	Q_OBJECT

public:
	explicit PlotDialog(QWidget *parent = 0);
	~PlotDialog();

	WaveForm mWave;
	void timerEvent(QTimerEvent *);
private:
	Ui::PlotDialog *ui;
	void _PlotInit();

	QwtPlotCurve  m_CurveWave;
	QVector<double> m_Amplitude_Y;
	QVector<double> m_Time_X;


	void _RefrashCurve();

public slots:
	void DrawCurve();
};

#endif // PLOTDIALOG_H
