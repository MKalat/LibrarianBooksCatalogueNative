#ifndef ADDAUTOR_H
#define ADDAUTOR_H

#include <QtGui/QDialog>
#include "ui_AddAutor.h"


class AddAutor : public QDialog
{
	Q_OBJECT

public:
	AddAutor(QWidget *parent = 0, Qt::WFlags flags = 0);
	~AddAutor();

	

public slots:
	void BTN_OK_CLICKED();
	void BTN_CANCEL_CLICKED();


private:
	Ui::AddAutor ui;
protected:
	virtual void closeEvent(QCloseEvent *event);

};
#endif // ADDAUTOR_H