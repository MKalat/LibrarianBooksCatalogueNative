#ifndef ABOUT_H
#define ABOUT_H

#include <QtWidgets/QDialog>
#include "ui_About.h"

class About : public QDialog
{
	Q_OBJECT

public:
	About(QWidget *parent = 0, Qt::WindowFlags flags = 0);
	~About();
	

public slots:
	void BTN_OK_CLICKED();
	
	


private:
	Ui::About ui;



};

#endif // ABOUT_H