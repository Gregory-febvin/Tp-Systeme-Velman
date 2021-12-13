#include <QtCore/QCoreApplication>
#include "K8055Adapter.h"
#include "BDD.h"
#include "Timer.h"
#include <QTimer>
#include <Qdebug>

//*********************************************************************************************
//* Programme : main.cpp date : 07/12/2021
//*---------------------------------------------------------------------------------------------------------
//* dernière mise a jour : 07/12/2021
//*
//*Programmeurs : Febvin Grégory classe : BTSSN2
//* Lea Bernard
//*--------------------------------------------------------------------------------------------------------
//* BUT : Lancer les différentes fonction
//*Programmes associés : AUCUN
//*********************************************************************************************
//--------------------------------------------------------------------------------------------- 


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

	BDD db = new BDD;
	db.connectToDB();

	TimerChrono * timer = new TimerChrono(&db, &a);

    return a.exec();
}
