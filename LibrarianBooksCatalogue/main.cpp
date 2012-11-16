#include "stdafx.h"
#include "lbookscatalogue.h"
#include <QtGui/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	LBooksCatalogue w;
	w.show();
	return a.exec();
}
