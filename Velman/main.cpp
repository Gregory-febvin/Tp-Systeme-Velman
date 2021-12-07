#include <QtCore/QCoreApplication>
#include "K8055Adapter.h"
#include "BDD.h"
#include "Timer.h"
#include <QTimer>
#include <Qdebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

	BDD db = new BDD;
	db.connectToDB();

	TimerChrono * timer = new TimerChrono(&db, &a);

    return a.exec();
}