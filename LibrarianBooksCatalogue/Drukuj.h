#ifndef DRUKUJ_H
#define DRUKUJ_H

#include <QtGui/QDialog>
#include "ui_Drukuj.h"
#include <QMessageBox>
#include <QStringList>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlError>

class Drukuj : public QDialog
{
	Q_OBJECT

public:
    Drukuj(QWidget *parent = 0, Qt::WFlags flags = 0, int id_act = 0);
	~Drukuj();
	int id;

	

public slots:
	void BTN_PRINT_CLICKED();
	void BTN_CANCEL_CLICKED();
	
	


private:
	Ui::Drukuj ui;



};

#endif // DRUKUJ_H
