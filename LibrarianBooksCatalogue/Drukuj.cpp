#include "stdafx.h"
#include "Drukuj.h"

Drukuj::Drukuj(QWidget *parent, Qt::WFlags flags)
	: QDialog(parent, flags)
{
	ui.setupUi(this);

}

Drukuj::~Drukuj()
{


}
void Drukuj::BTN_PRINT_CLICKED()
{



}

void Drukuj::BTN_CANCEL_CLICKED()
{
	this->close();
}