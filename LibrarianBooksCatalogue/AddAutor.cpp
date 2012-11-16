#include "stdafx.h"
#include "AddAutor.h"
#include "lbookscatalogue.h"

QStringList LBooksCatalogue::params_db;

AddAutor::AddAutor(QWidget *parent, Qt::WFlags flags)
	: QDialog(parent, flags)
{
	ui.setupUi(this);

}

AddAutor::~AddAutor()
{


}
void AddAutor::BTN_OK_CLICKED()
{


}

void AddAutor::BTN_CANCEL_CLICKED()
{


}

void AddAutor::closeEvent(QCloseEvent *event)
{
	LBooksCatalogue::params_db << this->ui.lineEdit_ImieNazw->text() << this->ui.lineEdit_Narod->text();
	LBooksCatalogue::params_db << this->ui.lineEdit_Spec->text() << this->ui.lineEdit_Rozdz->text();
	event->accept();


}