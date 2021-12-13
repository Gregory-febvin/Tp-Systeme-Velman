#include "BDD.h"
//*********************************************************************************************
//* Programme : BDD.cpp date : 07/12/2021
//*---------------------------------------------------------------------------------------------------------
//* dernière mise a jour : 07/12/2021
//*
//*Programmeurs : Febvin Grégory classe : BTSSN2
//* Lea Bernard
//*--------------------------------------------------------------------------------------------------------
//* BUT : Démarer une connection avec la BDD et envoyer les informations a l'intérieur
//*Programmes associés : AUCUN
//*********************************************************************************************
//--------------------------------------------------------------------------------------------- 


BDD::BDD(QObject *parent)
	: QObject(parent)
{

}

BDD::~BDD()
{

}

void BDD::connectToDB()
{
	QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
	db.setHostName("192.168.64.113");
	db.setDatabaseName("micro-station");
	db.setUserName("bts");
	db.setPassword("root");

	if (db.open()) {
		qDebug() << "Connexion BDD OK";
	}
	else {
		qDebug() << "Erreur Connection";
		exit(1);
	}
}

void BDD::InsertBdd(double Température, double Volt)
{
	QSqlQuery request;
	request.prepare("INSERT INTO `meteo`(`Temperature`, `Tension`) VALUES(?, ?)");
	request.addBindValue(Température);
	request.addBindValue(Volt);

	request.exec();
}
