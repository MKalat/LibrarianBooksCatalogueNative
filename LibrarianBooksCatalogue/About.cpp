#include "stdafx.h"
#include "About.h"

About::About(QWidget *parent, Qt::WindowFlags flags)
	: QDialog(parent, flags)
{
	ui.setupUi(this);

}

About::~About()
{


}

void About::BTN_OK_CLICKED()
{
	this->close();
}