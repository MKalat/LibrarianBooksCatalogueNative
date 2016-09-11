#ifndef DRUKUJ_H
#define DRUKUJ_H

#include <QtWidgets/QDialog>
#include "ui_Drukuj.h"
#include <QtWidgets/QMessageBox>
#include <QStringList>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlError>
#include <QtPrintSupport/QPrinter>
#include <QtPrintSupport/QPrintDialog>

class Drukuj : public QDialog
{
	Q_OBJECT

public:
	Drukuj(QWidget *parent = 0, Qt::WindowFlags flags = 0, int id_act = 0);
	~Drukuj();
	int id;
    void print_doc();

	

public slots:
	void BTN_PRINT_CLICKED();
	void BTN_CANCEL_CLICKED();
	
	


private:
	Ui::Drukuj ui;



};

#endif // DRUKUJ_H
