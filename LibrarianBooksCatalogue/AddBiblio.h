#ifndef ADDBIBLIO_H
#define ADDBIBLIO_H

#include <QtGui/QDialog>
#include "ui_AddBIBLIO.h"

class AddBiblio: public QDialog
{
	Q_OBJECT

public:
	AddBiblio(QWidget *parent = 0, Qt::WFlags flags = 0);
	~AddBiblio();

public slots:
	void BTN_OK_CLICKED();
	void BTN_CANCEL_CLICKED();


private:
	Ui::AddBIBLIO ui;



};
#endif // ADDBIBLIO_H