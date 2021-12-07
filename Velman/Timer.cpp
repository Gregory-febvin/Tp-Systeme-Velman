#include "Timer.h"
#include "BDD.h"

TimerChrono::TimerChrono(BDD * db, QObject *parent) : QObject(parent)
{
	carteES = K8055Adapter::getInstance();
	carteES->OpenDevice(0);

	TensionFiveSecond = new QTimer(this);
	QObject::connect(TensionFiveSecond, SIGNAL(timeout()), this, SLOT(takeTemp()));
	TensionFiveSecond->start(5000);

	TensionFiveMinutes = new QTimer(this);
	QObject::connect(TensionFiveMinutes, SIGNAL(timeout()), this, SLOT(StopTimer()));
	TensionFiveMinutes->start(305000);

}
void TimerChrono::takeTemp() {

	this->Value = carteES->ReadAnalogChannel( 1 );
	double Volt = Value / 255.0 * 5.0;
	double Température = (Volt * 90.0 / 5.0) - 30.0;
	qDebug() << Volt;
	qDebug() << Température;
	db->InsertBdd(Volt, Température);
}

TimerChrono::~TimerChrono()
{

}

void TimerChrono::StopTimer()
{
	TensionFiveMinutes->stop();
	TensionFiveSecond->stop();


	carteES->CloseDevice();
	K8055Adapter::freeInstance();
}
