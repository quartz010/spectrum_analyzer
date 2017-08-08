#include "plotdialog.h"
#include "ui_plotdialog.h"

#include "qwt_plot.h"
#include "qwt_plot_grid.h"

#include "waveform.h"

PlotDialog::PlotDialog(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::PlotDialog)
{
	connect(&mWave, SIGNAL(GenFinish()), this, SLOT(DrawCurve()));

	ui->setupUi(this);
	_PlotInit();

	mWave.GenSinWave(1);
//	startTimer(500);
}

PlotDialog::~PlotDialog()
{
	delete ui;
}

void PlotDialog::_PlotInit()
{
	QwtPlotGrid *grid = new QwtPlotGrid;

	grid->enableX(true);//设置网格线
	grid->enableY(true);
	grid->setMajorPen(Qt::black, 0, Qt::DotLine);
	grid->attach(ui->qwtPlot);
	m_CurveWave.attach(ui->qwtPlot);

//	for (int x = 0; x < 64; x++)
//	{
//		m_Time_X.;
//		m_Time_X.append((double)x);
//		m_Amplitude_Y.append(qSin(x));
//		//用于对齐数据
//	}


//	ui->qwtPlot->setAxisScale(QwtPlot::yLeft, -1, 1);
//	ui->qwtPlot->setAxisScale(QwtPlot::xBottom, 0, 32);


}

void PlotDialog::timerEvent(QTimerEvent *)
{
	m_Time_X.append(m_Time_X.last() + 1);
	_RefrashCurve();

}

void PlotDialog::_RefrashCurve()
{

	ui->qwtPlot->setAxisScale(QwtPlot::xBottom, m_Time_X.last() - 300, m_Time_X.last());

	//最后一位为新数据（这里为随机数模拟）
	m_Amplitude_Y.append(m_Amplitude_Y.last());
//	m_Amplitude_Y.append(rand()%10);

	//重新加载数据
	m_CurveWave.setSamples(m_Time_X, m_Amplitude_Y);
	//qDebug() << yPower.last() << xTime.last();

	//QwtPlot重绘，重要，没有这句不起作用
	ui->qwtPlot->replot();

	//清零向量
	if (m_Time_X.count() > 600)
		m_Time_X.remove(200);

	if (m_Amplitude_Y.count() > 600)
		m_Amplitude_Y.remove(200);
}

void PlotDialog::DrawCurve()
{
	//here is strange


	QwtPointSeriesData *WaveData = new QwtPointSeriesData(mWave.m_WaveVector);
	m_CurveWave.setData(WaveData);

	ui->qwtPlot->replot();
	qDebug() << "reploted";
}
