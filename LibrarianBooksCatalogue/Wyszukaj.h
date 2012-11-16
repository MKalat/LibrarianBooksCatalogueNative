#ifndef WYSZUKAJ_H
#define WYSZUKAJ_H

#include <QtGui/QDialog>
#include "ui_Wyszukaj.h"

class Wyszukaj : public QDialog
{
	Q_OBJECT

public:
	Wyszukaj(QWidget *parent = 0, Qt::WFlags flags = 0);
	~Wyszukaj();

public slots:
	void BTN_SEARCH_CLICKED();
	


private:
	Ui::Wyszukaj ui;



};
#endif // WYSZUKAJ_H