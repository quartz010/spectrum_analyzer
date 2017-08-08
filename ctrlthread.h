#ifndef CTRLTHREAD_H
#define CTRLTHREAD_H

#include <QThread>


class CtrlThread : public QThread
{
    Q_OBJECT

public:
	explicit CtrlThread(QObject *parent = 0);
	void setUp();




	static CtrlThread* mCtrl;
private:

	void _SendSignal();

protected:
	void run();

	static void _BottonPressed();

signals:
	void prePage();
	void nxtPage();

public slots:
};


#endif // CTRLTHREAD_H
