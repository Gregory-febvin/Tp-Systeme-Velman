#pragma once

#include <QObject>
#include <QTimer>
#include "BDD.h"
#include <qsqldatabase.h>
#include "K8055Adapter.h"

class TimerChrono : public QObject
{
	Q_OBJECT


private:
	double Value;

public:
	TimerChrono(BDD * db, QObject *parent= Q_NULLPTR );

	virtual ~TimerChrono();
	QTimer * TensionFiveSecond;
	QTimer * TensionFiveMinutes;
	K8055Adapter * carteES;
	BDD * db;

public slots:
	void takeTemp();
	void StopTimer();
};