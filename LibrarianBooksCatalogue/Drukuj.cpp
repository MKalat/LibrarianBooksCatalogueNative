#include "stdafx.h"
#include "Drukuj.h"

Drukuj::Drukuj(QWidget *parent, Qt::WindowFlags flags, int id_act)
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
                QString cur_id_str;
                cur_id_str.setNum(id);
				bool ok = query.exec("SELECT id, tytul, tytul_oryg, "
                "gatunek, ilosc, rok_wyd, wydawnictwo, jezyk_wydania, opis, WL_ImieNazw, "
                "WL_Adres, MZ_Nazwa, MZ_Adres, MZ_WWW, INFO_IloscStr, INFO_Format,  "
                "INFO_Oprawa, INFO_Ocena, ISBN FROM lbcmain WHERE id = '" + cur_id_str + "'");

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
                    fnout << tr("Oryginalny tytu³") << QString::fromWCharArray(L"</p></td><td>");
                    fnout << QString(query.value(title_origCol).toString());
                    fnout << QString::fromWCharArray(L"</td></tr><tr><td><p>");
                    fnout << tr("Gatunek") << QString::fromWCharArray(L"</p></td><td>");
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
                    fnout << tr("W³aœciciel - Adres") << QString::fromWCharArray(L"</p></td><td>");
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
                    fnout << tr("Oprawa") << QString::fromWCharArray(L"</p></td><td>");
                    fnout << QString(query.value(INFO_Oprawa_Col).toString());
                    fnout << QString::fromWCharArray(L"</td></tr><tr><td><p>");
                    fnout << tr("Ocena ksi¹¿ki") << QString::fromWCharArray(L"</p></td><td>");
                    fnout << QString(query.value(INFO_Ocena_Col).toString());
                    fnout << QString::fromWCharArray(L"</td></tr><tr><td><p>");
                    fnout << tr("ISBN") << QString::fromWCharArray(L"</p></td><td>");
                    fnout << QString(query.value(ISBN_Col).toString());
                    fnout << QString::fromWCharArray(L"</td></tr>");
                    fnout << QString::fromWCharArray(L"</table >");

					if (ui.checkBox_AUTHORS->isChecked())
					{

						QSqlQuery query2(db);
						ok = query2.exec("select id, id_m, imie_nazw, narod, spec, rozdz from lbca where id_m = '" + cur_id_str + "'");
						if (ok) 
						{
							QSqlRecord qrec2 = query2.record();
							int idCol = qrec2.indexOf("id");
							int idmCol = qrec2.indexOf("id_m");
							int imienazwCol = qrec2.indexOf("imie_nazw");
							int narodCol = qrec2.indexOf("narod");
							int specCol = qrec2.indexOf("spec");
							int rozdzCol = qrec2.indexOf("rozdz");

							fnout << QString::fromWCharArray(L"<h1>Autorzy");
							while (query2.next())
							{
								
								fnout << QString::fromWCharArray(L"</h1><table ><tr><td><p>");
								fnout << tr("Imie i Nazwisko") << QString::fromWCharArray(L"</p></td><td>");
								fnout << QString(query2.value(imienazwCol).toString());
								fnout << QString::fromWCharArray(L"</td></tr><tr><td><p>");
								fnout << tr("Narodowoœæ") << QString::fromWCharArray(L"</p></td><td>");
								fnout << QString(query2.value(narodCol).toString());
								fnout << QString::fromWCharArray(L"</td></tr><tr><td><p>");
								fnout << tr("Specjalnoœæ") << QString::fromWCharArray(L"</p></td><td>");
								fnout << QString(query2.value(specCol).toString());
								fnout << QString::fromWCharArray(L"</td></tr><tr><td><p>");
								fnout << tr("Napisane rozdzia³y") << QString::fromWCharArray(L"</p></td><td>");
								fnout << QString(query2.value(rozdzCol).toString());
								fnout << QString::fromWCharArray(L"</td></tr>");
								
							}
							fnout << QString::fromWCharArray(L"</table>");

						}
					}

					if (ui.checkBox_PUBS->isChecked())
					{
						QSqlQuery query3(db);
						ok = query3.exec("select id, id_m, data_wyd, wyd, jezyk, numer_wyd, kraj_wyd from lbcp where id_m = '" + cur_id_str + "'");
						if (ok)
						{
							QSqlRecord qrec3 = query3.record();
							int idwCol = qrec3.indexOf("id");
							int idwmCol = qrec3.indexOf("id_m");
							int datawydCol = qrec3.indexOf("data_wyd");
							int wydCol = qrec3.indexOf("wyd");
							int langCol = qrec3.indexOf("jezyk");
							int pubnoCol = qrec3.indexOf("numer_wyd");
							int krajwydCol = qrec3.indexOf("kraj_wyd");
													
							fnout << QString::fromWCharArray(L"<h1>Wydawcy");
							while (query3.next())
							{
								
								fnout << QString::fromWCharArray(L"</h1><table ><tr><td><p>");
								fnout << tr("Data Wydania") << QString::fromWCharArray(L"</p></td><td>");
								fnout << QString(query3.value(datawydCol).toString());
								fnout << QString::fromWCharArray(L"</td></tr><tr><td><p>");
								fnout << tr("Wydawca") << QString::fromWCharArray(L"</p></td><td>");
								fnout << QString(query3.value(wydCol).toString());
								fnout << QString::fromWCharArray(L"</td></tr><tr><td><p>");
								fnout << tr("Jêzyk wydania") << QString::fromWCharArray(L"</p></td><td>");
								fnout << QString(query3.value(langCol).toString());
								fnout << QString::fromWCharArray(L"</td></tr><tr><td><p>");
								fnout << tr("Numer Wydania") << QString::fromWCharArray(L"</p></td><td>");
								fnout << QString(query3.value(pubnoCol).toString());
								fnout << QString::fromWCharArray(L"</td></tr><tr><td><p>");
								fnout << tr("Kraj Wydania") << QString::fromWCharArray(L"</p></td><td>");
								fnout << QString(query3.value(krajwydCol).toString());
								fnout << QString::fromWCharArray(L"</td></tr>");
								
							}
							fnout << QString::fromWCharArray(L"</table>");
						}
					}

					if (ui.checkBox_BORROWS->isChecked())
					{
						QSqlQuery query4(db);
						ok = query4.exec("select id, id_m, osoba, data_wyp, data_odd, "
							"stan_wyp, stan_odd from lbcb where id_m = '" + cur_id_str + "'");
						if (ok)
						{
							QSqlRecord qrec4 = query4.record();
							int idbCol = qrec4.indexOf("id");
							int idbmCol = qrec4.indexOf("id_m");
							int osobaCol = qrec4.indexOf("osoba");
							int dwypCol = qrec4.indexOf("data_wyp");
							int doddCol = qrec4.indexOf("data_odd");
							int swypCol = qrec4.indexOf("stan_wyp");
							int soddCol = qrec4.indexOf("stan_odd");
							fnout << QString::fromWCharArray(L"<h1>Bibliotekarz");
							
							while (query4.next())
							{		
								
								fnout << QString::fromWCharArray(L"</h1><table ><tr><td><p>");
								fnout << tr("Osoba wypo¿yczaj¹ca") << QString::fromWCharArray(L"</p></td><td>");
								fnout << QString(query4.value(osobaCol).toString());
								fnout << QString::fromWCharArray(L"</td></tr><tr><td><p>");
								fnout << tr("Data wypo¿yczenia") << QString::fromWCharArray(L"</p></td><td>");
								fnout << QString(query4.value(dwypCol).toString());
								fnout << QString::fromWCharArray(L"</td></tr><tr><td><p>");
								fnout << tr("Data oddania") << QString::fromWCharArray(L"</p></td><td>");
								fnout << QString(query4.value(doddCol).toString());
								fnout << QString::fromWCharArray(L"</td></tr><tr><td><p>");
								fnout << tr("Stan przed wypo¿yczeniem") << QString::fromWCharArray(L"</p></td><td>");
								fnout << QString(query4.value(swypCol).toString());
								fnout << QString::fromWCharArray(L"</td></tr><tr><td><p>");
								fnout << tr("Stan po oddaniu") << QString::fromWCharArray(L"</p></td><td>");
								fnout << QString(query4.value(soddCol).toString());
								fnout << QString::fromWCharArray(L"</td></tr>");
								
							}
							fnout << QString::fromWCharArray(L"</table>");
						}
					}

                }
				

            }
            else
            {


            }
			fnout << QString::fromWCharArray(L"</body></html>");
			fn_exp.close();
            print_doc();
        }



    }
    else if (ui.radioButton_ALL)
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
                QString cur_id_str;
                bool ok = query.exec("SELECT id, tytul, tytul_oryg, "
                "gatunek, ilosc, rok_wyd, wydawnictwo, jezyk_wydania, opis, WL_ImieNazw, "
                "WL_Adres, MZ_Nazwa, MZ_Adres, MZ_WWW, INFO_IloscStr, INFO_Format,  "
                "INFO_Oprawa, INFO_Ocena, ISBN FROM lbcmain");

                QSqlRecord qrec = query.record();
				int m_rec_id = qrec.indexOf("id");
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
                    while(query.next())
					{

						cur_id_str.setNum(m_rec_id);
						fnout << QString::fromWCharArray(L"<h1>");
						fnout << QString(query.value(titleCol).toString());
						fnout << QString::fromWCharArray(L"</h1><table ><tr><td><p>");
						fnout << tr("Oryginalny tytu³") << QString::fromWCharArray(L"</p></td><td>");
						fnout << QString(query.value(title_origCol).toString());
						fnout << QString::fromWCharArray(L"</td></tr><tr><td><p>");
						fnout << tr("Gatunek") << QString::fromWCharArray(L"</p></td><td>");
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
						fnout << tr("W³aœciciel - Adres") << QString::fromWCharArray(L"</p></td><td>");
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
						fnout << tr("Oprawa") << QString::fromWCharArray(L"</p></td><td>");
						fnout << QString(query.value(INFO_Oprawa_Col).toString());
						fnout << QString::fromWCharArray(L"</td></tr><tr><td><p>");
						fnout << tr("Ocena ksi¹¿ki") << QString::fromWCharArray(L"</p></td><td>");
						fnout << QString(query.value(INFO_Ocena_Col).toString());
						fnout << QString::fromWCharArray(L"</td></tr><tr><td><p>");
						fnout << tr("ISBN") << QString::fromWCharArray(L"</p></td><td>");
						fnout << QString(query.value(ISBN_Col).toString());
						fnout << QString::fromWCharArray(L"</td></tr>");
						fnout << QString::fromWCharArray(L"</table >");

						if (ui.checkBox_AUTHORS->isChecked())
						{
							QSqlQuery query2(db);
							ok = query2.exec("select id, id_m, imie_nazw, narod, spec, rozdz from lbca where id_m = '" + cur_id_str + "'");
							if (ok) 
							{
								QSqlRecord qrec2 = query2.record();
								int idCol = qrec2.indexOf("id");
								int idmCol = qrec2.indexOf("id_m");
								int imienazwCol = qrec2.indexOf("imie_nazw");
								int narodCol = qrec2.indexOf("narod");
								int specCol = qrec2.indexOf("spec");
								int rozdzCol = qrec2.indexOf("rozdz");
								fnout << QString::fromWCharArray(L"<h1>Autorzy");
								while (query2.next())
								{
									
									fnout << QString::fromWCharArray(L"</h1><table ><tr><td><p>");
									fnout << tr("Imie i Nazwisko") << QString::fromWCharArray(L"</p></td><td>");
									fnout << QString(query2.value(imienazwCol).toString());
									fnout << QString::fromWCharArray(L"</td></tr><tr><td><p>");
									fnout << tr("Narodowoœæ") << QString::fromWCharArray(L"</p></td><td>");
									fnout << QString(query2.value(narodCol).toString());
									fnout << QString::fromWCharArray(L"</td></tr><tr><td><p>");
									fnout << tr("Specjalnoœæ") << QString::fromWCharArray(L"</p></td><td>");
									fnout << QString(query2.value(specCol).toString());
									fnout << QString::fromWCharArray(L"</td></tr><tr><td><p>");
									fnout << tr("Napisane rozdzia³y") << QString::fromWCharArray(L"</p></td><td>");
									fnout << QString(query2.value(rozdzCol).toString());
									fnout << QString::fromWCharArray(L"</td></tr>");
									
								}
								fnout << QString::fromWCharArray(L"</table>");

							}
						}

						if (ui.checkBox_PUBS->isChecked())
						{	
							QSqlQuery query3(db);
							ok = query3.exec("select id, id_m, data_wyd, wyd, jezyk, numer_wyd, kraj_wyd from lbcp where id_m = '" + cur_id_str + "'");
							if (ok)
							{
								QSqlRecord qrec3 = query3.record();
								int idwCol = qrec3.indexOf("id");
								int idwmCol = qrec3.indexOf("id_m");
								int datawydCol = qrec3.indexOf("data_wyd");
								int wydCol = qrec3.indexOf("wyd");
								int langCol = qrec3.indexOf("jezyk");
								int pubnoCol = qrec3.indexOf("numer_wyd");
								int krajwydCol = qrec3.indexOf("kraj_wyd");
								fnout << QString::fromWCharArray(L"<h1>Wydawcy");
														
								while (query3.next())
								{
									
									fnout << QString::fromWCharArray(L"</h1><table ><tr><td><p>");
									fnout << tr("Data Wydania") << QString::fromWCharArray(L"</p></td><td>");
									fnout << QString(query3.value(datawydCol).toString());
									fnout << QString::fromWCharArray(L"</td></tr><tr><td><p>");
									fnout << tr("Wydawca") << QString::fromWCharArray(L"</p></td><td>");
									fnout << QString(query3.value(wydCol).toString());
									fnout << QString::fromWCharArray(L"</td></tr><tr><td><p>");
									fnout << tr("Jêzyk wydania") << QString::fromWCharArray(L"</p></td><td>");
									fnout << QString(query3.value(langCol).toString());
									fnout << QString::fromWCharArray(L"</td></tr><tr><td><p>");
									fnout << tr("Numer Wydania") << QString::fromWCharArray(L"</p></td><td>");
									fnout << QString(query3.value(pubnoCol).toString());
									fnout << QString::fromWCharArray(L"</td></tr><tr><td><p>");
									fnout << tr("Kraj Wydania") << QString::fromWCharArray(L"</p></td><td>");
									fnout << QString(query3.value(krajwydCol).toString());
									fnout << QString::fromWCharArray(L"</td></tr>");
									
								}
								fnout << QString::fromWCharArray(L"</table>");
							}
						}

						if (ui.checkBox_BORROWS->isChecked())
						{
							QSqlQuery query4(db);
							ok = query4.exec("select id, id_m, osoba, data_wyp, data_odd, "
								"stan_wyp, stan_odd from lbcb where id_m = '" + cur_id_str + "'");
							if (ok)
							{
								QSqlRecord qrec4 = query4.record();
								int idbCol = qrec4.indexOf("id");
								int idbmCol = qrec4.indexOf("id_m");
								int osobaCol = qrec4.indexOf("osoba");
								int dwypCol = qrec4.indexOf("data_wyp");
								int doddCol = qrec4.indexOf("data_odd");
								int swypCol = qrec4.indexOf("stan_wyp");
								int soddCol = qrec4.indexOf("stan_odd");
								fnout << QString::fromWCharArray(L"<h1>Bibliotekarz");
								
								while (query4.next())
								{		
									
									fnout << QString::fromWCharArray(L"</h1><table ><tr><td><p>");
									fnout << tr("Osoba wypo¿yczaj¹ca") << QString::fromWCharArray(L"</p></td><td>");
									fnout << QString(query4.value(osobaCol).toString());
									fnout << QString::fromWCharArray(L"</td></tr><tr><td><p>");
									fnout << tr("Data wypo¿yczenia") << QString::fromWCharArray(L"</p></td><td>");
									fnout << QString(query4.value(dwypCol).toString());
									fnout << QString::fromWCharArray(L"</td></tr><tr><td><p>");
									fnout << tr("Data oddania") << QString::fromWCharArray(L"</p></td><td>");
									fnout << QString(query4.value(doddCol).toString());
									fnout << QString::fromWCharArray(L"</td></tr><tr><td><p>");
									fnout << tr("Stan przed wypo¿yczeniem") << QString::fromWCharArray(L"</p></td><td>");
									fnout << QString(query4.value(swypCol).toString());
									fnout << QString::fromWCharArray(L"</td></tr><tr><td><p>");
									fnout << tr("Stan po oddaniu") << QString::fromWCharArray(L"</p></td><td>");
									fnout << QString(query4.value(soddCol).toString());
									fnout << QString::fromWCharArray(L"</td></tr>");
									
								}
								fnout << QString::fromWCharArray(L"</table>");
							}
						}
						
					}
				}

                }
				

            }
            else
            {


            }
			fnout << QString::fromWCharArray(L"</body></html>");
			fn_exp.close();
            print_doc();


    }
	
	


}

void Drukuj::BTN_CANCEL_CLICKED()
{
	this->close();
}
void Drukuj::print_doc()
{
    QFile file("wydruk.html");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    QString htmlContent;
    QTextStream in(&file);
    htmlContent = in.readAll();

    QTextDocument *document = new QTextDocument();
    document->setHtml(htmlContent);

    QPrinter printer;

    QPrintDialog *dialog = new QPrintDialog(&printer, this);
    if (dialog->exec() != QDialog::Accepted)
    return;

    document->print(&printer);

    delete document;
}
