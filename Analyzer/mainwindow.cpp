#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ctrlthread.h"
#include "plotdialog.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
	this->setWindowFlags(Qt::FramelessWindowHint);
	_UInit();

	CtrlThread *mThread = new CtrlThread();
	connect(mThread, SIGNAL(nxtPage()), this, SLOT(ChangePage()));

	mThread->setUp();
	mThread->start();


}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::_UInit()
{
	PlotDialog *plotdlg = new PlotDialog();
//	ui->tabWidget->addTab(plotdlg, "Plot");
	connect(this->ui->dial, SIGNAL(valueChanged(int)), &plotdlg->mWave,SLOT(GenSinWave(int)));

	ui->tabWidget->insertTab(0, plotdlg, "Plot");
	ui->tabWidget->setCurrentIndex(0);
}

void MainWindow::ChangePage()
{
	if(ui->tabWidget->currentIndex() == ui->tabWidget->count() - 1)
	{
		ui->tabWidget->setCurrentIndex(0);
	}else {

		ui->tabWidget->setCurrentIndex(ui->tabWidget->currentIndex() + 1);
	}
}
