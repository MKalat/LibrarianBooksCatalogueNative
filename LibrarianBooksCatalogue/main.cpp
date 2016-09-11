#include "stdafx.h"
#include "lbookscatalogue.h"
#include <QtWidgets/QApplication>
#include <QTranslator>

int main(int argc, char *argv[])
{
	

	QApplication a(argc, argv);
	QTranslator qtTranslator;
    qtTranslator.load("qt_" + QLocale::system().name(),
    QLibraryInfo::location(QLibraryInfo::TranslationsPath));
    a.installTranslator(&qtTranslator);

    QTranslator myappTranslator;
    myappTranslator.load("librarianbookscatalogue_" + QLocale::system().name());
    a.installTranslator(&myappTranslator);
	LBooksCatalogue w;
	w.show();
	return a.exec();
}
