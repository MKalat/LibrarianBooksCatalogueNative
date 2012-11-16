#ifndef ADDPUB_H
#define ADDPUB_H

#include <QtGui/QDialog>
#include "ui_AddPub.h"

class AddPub : public QDialog
{
	Q_OBJECT

public:
	AddPub(QWidget *parent = 0, Qt::WFlags flags = 0);
	~AddPub();

public slots:
	void BTN_OK_CLICKED();
	void BTN_CANCEL_CLICKED();


private:
	Ui::AddPub ui;



};
#endif // ADDPUB_H