#ifndef WYSZUKAJ_H
#define WYSZUKAJ_H

#include <QtWidgets>
#include <QtWidgets/QDialog>
#include "ui_Wyszukaj.h"
#include <QtWidgets/QMessageBox>
#include <QStringList>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlError>

class Wyszukaj : public QDialog
{
	Q_OBJECT

public:
	Wyszukaj(QWidget *parent = 0, Qt::WindowFlags flags = 0);
	~Wyszukaj();
	QStringList lista_id;
signals :
    void ustaw_rec(QString);

public slots:
	void BTN_SEARCH_CLICKED();
	void ITEM_CLICKED(int row, int column);
	


private:
	Ui::Wyszukaj ui;



};
#endif // WYSZUKAJ_H