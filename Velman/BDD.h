#pragma once

#include <QObject>
#include <QtSql/QtSql>
#include <qsqldatabase.h>

class BDD : public QObject
{
	Q_OBJECT

private:
	QSqlDatabase * db;
public:
	BDD(QObject *parent = Q_NULLPTR);
	~BDD();

	void connectToDB();
	void InsertBdd(double Température, double Volt);
};
