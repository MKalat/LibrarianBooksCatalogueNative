#include "stdafx.h"
#include "Drukuj.h"

Drukuj::Drukuj(QWidget *parent, Qt::WFlags flags, int id_act)
	: QDialog(parent, flags)
{
	ui.setupUi(this);
	id = id_act;

}

Drukuj::~Drukuj()
{


}
void Drukuj::BTN_PRINT_CLICKED()
{
	if (QFile::exists(QString::fromWCharArray(L"wydruk.html")))
	{
		QFile::remove(QString::fromWCharArray(L"wydruk.html"));
	}
	
    if (ui.radioButton_CUR)
    {
		bool head_wrttn = false;
		bool close_html = true;
		QFile fn_exp(QString::fromWCharArray(L"wydruk.html"));
		fn_exp.open(QFile::WriteOnly | QFile::Append | QFile::Text);
		QTextStream fnout(&fn_exp);
	
		fnout << QString::fromWCharArray(L"<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.01 Transitional//EN\" \"http://www.w3.org/TR/html4/loose.dtd\"><html><head><title>") << tr("Librarian Books Catalogue Printing from database - http://mkalat.pl") << QString::fromWCharArray(L"</title><meta http-equiv=\"Content-Type\" content=\"text/html; charset=cp-1250\"><style type=\"text/css\">p {font-family: Verdana, Arial, Helvetica, sans-serif;font-size: 12px;}</style></head><body>") << "\n";
			
		
		QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
		db.setDatabaseName("lbcmain.db");

		if(db.open())
		{
			QSqlQuery query(db);
			if (id !=0)
			{
				bool ok = query.exec("SELECT id, tytul, tytul_oryg, "
			"gatunek, ilosc, rok_wyd, wydawnictwo, jezyk_wydania, opis, WL_ImieNazw, "
			"WL_Adres, MZ_Nazwa, MZ_Adres, MZ_WWW, INFO_IloscStr, INFO_Format,  "
			"INFO_Oprawa, INFO_Ocena, ISBN FROM lbcmain WHERE id = '" + id + "'");

			QSqlRecord qrec = query.record();
			int titleCol = qrec.indexOf("tytul");
			int title_origCol = qrec.indexOf("tytul_oryg");
			int genreCol = qrec.indexOf("gatunek");
			int countCol = qrec.indexOf("ilosc");
			int year_pub = qrec.indexOf("rok_wyd");
			int pubCol = qrec.indexOf("wydawnictwo");
			int lang_pubCol = qrec.indexOf("jezyk_wydania");
			int descCol = qrec.indexOf("opis");
			int WL_Im_Nazw_Col = qrec.indexOf("WL_ImieNazw");
			int WL_Adres_Col = qrec.indexOf("WL_Adres");
			int MZ_Nazwa_Col = qrec.indexOf("MZ_Nazwa");
			int MZ_Adres_Col = qrec.indexOf("MZ_Adres");
			int MZ_WWW_Col = qrec.indexOf("MZ_WWW");
			int INFO_IloscStr_Col = qrec.indexOf("INFO_IloscStr");
			int INFO_Format_Col = qrec.indexOf("INFO_Format");
			int INFO_Oprawa_Col = qrec.indexOf("INFO_Oprawa");
			int INFO_Ocena_Col = qrec.indexOf("INFO_Ocena");
			int ISBN_Col = qrec.indexOf("ISBN");
			
			if (ok)
			{
				query.next();


				fnout << QString::fromWCharArray(L"<h1>");
				fnout << QString(query.value(titleCol).toString());
				fnout << QString::fromWCharArray(L"</h1><table ><tr><td><p>");
				fnout << tr("Oryginalny tytu³") << QString::fromWCharArray("</p></td><td>");
				fnout << QString(query.value(title_origCol).toString());
				fnout << QString::fromWCharArray(L"</td></tr><tr><td><p>");
				fnout << tr("Gatunek") << QString::fromWCharArray("</p></td><td>");
				fnout << QString(query.value(genreCol).toString());
				fnout << QString::fromWCharArray(L"</td></tr><tr><td><p>");
				fnout << tr("Iloœæ") << QString::fromWCharArray(L"</p></td><td>");
				fnout << QString(query.value(countCol).toString());
				fnout << QString::fromWCharArray(L"</td></tr><tr><td><p>");
				fnout << tr("Rok wydania") << QString::fromWCharArray(L"</p></td><td>");
				fnout << QString(query.value(year_pub).toString());
				fnout << QString::fromWCharArray(L"</td></tr><tr><td><p>");
				fnout << tr("Wydawnictwo") << QString::fromWCharArray(L"</p></td><td>");
				fnout << QString(query.value(pubCol).toString());
				fnout << QString::fromWCharArray(L"</td></tr><tr><td><p>");
				fnout << tr("Jêzyk wydania") << QString::fromWCharArray(L"</p></td><td>");
				fnout << QString(query.value(lang_pubCol).toString());
				fnout << QString::fromWCharArray(L"</td></tr><tr><td><p>");
				fnout << tr("Opis") << QString::fromWCharArray(L"</p></td><td>");
				fnout << QString(query.value(descCol).toString());
				fnout << QString::fromWCharArray(L"</td></tr><tr><td><p>");
				fnout << tr("W³aœciciel - Imiê i nazwisko") << QString::fromWCharArray(L"</p></td><td>");
				fnout << QString(query.value(WL_Im_Nazw_Col).toString());
				fnout << QString::fromWCharArray(L"</td></tr><tr><td><p>");
				fnout << tr("W³aœciciel - Adres") << QString::fromWCharArray("</p></td><td>");
				fnout << QString(query.value(WL_Adres_Col).toString());
				fnout << QString::fromWCharArray(L"</td></tr><tr><td><p>");
				fnout << tr("Miejsce zakupu - Nazwa") << QString::fromWCharArray(L"</p></td><td>");
				fnout << QString(query.value(MZ_Nazwa_Col).toString());
				fnout << QString::fromWCharArray(L"</td></tr><tr><td><p>");
				fnout << tr("Miejsce zakupu - Adres") << QString::fromWCharArray(L"</p></td><td>");
				fnout << QString(query.value(MZ_Adres_Col).toString());
				fnout << QString::fromWCharArray(L"</td></tr><tr><td><p>");
				fnout << tr("Miejsce zakupu - WWW") << QString::fromWCharArray(L"</p></td><td>");
				fnout << QString(query.value(MZ_WWW_Col).toString());
				fnout << QString::fromWCharArray(L"</td></tr><tr><td><p>");
				fnout << tr("Iloœæ stron") << QString::fromWCharArray(L"</p></td><td>");
				fnout << QString(query.value(INFO_IloscStr_Col).toString());
				fnout << QString::fromWCharArray(L"</td></tr><tr><td><p>");
				fnout << tr("Format") << QString::fromWCharArray(L"</p></td><td>");
				fnout << QString(query.value(INFO_Format_Col).toString());
				fnout << QString::fromWCharArray(L"</td></tr><tr><td><p>");
				fnout << tr("Oprawa") << QString::fromWCharArray("</p></td><td>");
				fnout << QString(query.value(INFO_Oprawa_Col).toString());
				fnout << QString::fromWCharArray(L"</td></tr><tr><td><p>");
				fnout << tr("Ocena ksi¹¿ki") << QString::fromWCharArray("</p></td><td>");
				fnout << QString(query.value(INFO_Ocena_Col).toString());
				fnout << QString::fromWCharArray(L"</td></tr><tr><td><p>");
				fnout << tr("ISBN") << QString::fromWCharArray(L"</p></td><td>");
				fnout << QString(query.value(ISBN_Col).toString());
				fnout << QString::fromWCharArray(L"</td></tr><tr><td><p>");
				fnout << QString::fromWCharArray(L"</table >");

			}
			

		}
		else
		{


		}
		
		print_doc();



    }
    else if (ui.radioButton_ALL)
    {



    }
	
	


}

void Drukuj::BTN_CANCEL_CLICKED()
{
	this->close();
}
