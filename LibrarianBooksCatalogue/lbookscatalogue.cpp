#include "stdafx.h"
#include "lbookscatalogue.h"



LBooksCatalogue::LBooksCatalogue(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags)
{
	ui.setupUi(this);
	new_rec_adding = false;
	ReadSettings();
	if (!CheckDBExists())
	{
		CreateDB();
	}
	ReadStartRec();
}

LBooksCatalogue::~LBooksCatalogue()
{

}
void LBooksCatalogue::BTN_FIRST_CLICKED()
{
	if (GetLastId(0) != 0)
	{
		SaveRec(0);
		ReadStartRec();
		CalcRecInfo();
	}

}
void LBooksCatalogue::BTN_NEXT_CLICKED()
{
	if (GetLastId(0) != 0)
	{
		SaveRec(0);
		cur_id = FindNextId();
		ReadRec(0,0);
		CalcRecInfo();
	}
	

}
void LBooksCatalogue::BTN_PREV_CLICKED()
{
	if (GetLastId(0) != 0)
	{
		SaveRec(0);
		cur_id = FindPrevId();
		ReadRec(0,0);
		CalcRecInfo();
	}
}

void LBooksCatalogue::BTN_LAST_CLICKED()
{
	if (GetLastId(0) != 0)
	{
		SaveRec(0);
		cur_id = GetLastId(0);
		ReadRec(0,0);
		CalcRecInfo();
	}

}

void LBooksCatalogue::BTN_NEW_CLICKED()
{

	new_rec_adding = true;
	ClearCtrls();
	this->ui.pushButton_NEW->setEnabled(false);

}

void LBooksCatalogue::BTN_SAVE_CLICKED()
{
	if (new_rec_adding) // program wtrybie dodawania nowego rekordu
	{
		AddNewRec(0);
		new_rec_adding = false; // po zakoñczonych dodaniach wyczyœæ status dodawania nowego rekordu
		this->ui.pushButton_NEW->setEnabled(true);
	}
	else // program w trybie update
	{
		SaveRec(cur_id);
	}
	ReadRec(0,0);
	CalcRecInfo();

}

void LBooksCatalogue::BTN_DEL_CLICKED()
{
	if (GetLastId(0) != 0)
	{
		SaveRec(0);
		DelRec(0);
		CalcRecInfo();
	}

}

bool LBooksCatalogue::CheckDBExists()
{
	struct _stat buf;
	if (_wstat(L"lbcmain.db",&buf) == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void LBooksCatalogue::CreateDB()
{
	QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
	db.setDatabaseName("lbcmain.db");

if(db.open())
{
		QSqlQuery query(db);
			bool ok = query.exec("CREATE TABLE lbcmain (id integer primary key autoincrement, tytul varchar (1024), tytul_oryg varchar (1024), "
			"gatunek varchar (1024), ilosc varchar (1024), rok_wyd varchar (1024), wydawnictwo varchar (1024), jezyk_wydania varchar (1024), opis varchar (1024), WL_ImieNazw varchar (1024), "
			"WL_Adres varchar (1024), MZ_Nazwa varchar (1024), MZ_Adres varchar (1024), MZ_WWW varchar (1024), INFO_IloscStr varchar (1024), INFO_Format varchar (1024),  "
			"INFO_Oprawa varchar (1024), INFO_Ocena varchar (1024))");
		if( !ok )
		QMessageBox::information(this, "Fail", query.lastError().text());

		QSqlQuery query2(db);
		ok = query2.exec("CREATE TABLE lbca (id integer primary key autoincrement, id_m integer, "
			"imie_nazw varchar (1024), narod varchar (1024), spec varchar (1024), rozdz varchar (1024))");
		if( !ok )
		QMessageBox::information(this, "Fail", query2.lastError().text());
		
		QSqlQuery query3(db);
				ok = query3.exec("CREATE TABLE lbcp (id integer primary key autoincrement, id_m integer, "
			"data_wyd varchar (1024), wyd varchar (1024), jezyk varchar (1024), numer_wyd varchar (1024), kraj_wyd varchar (1024))");
		if( !ok )
		QMessageBox::information(this, "Fail", query3.lastError().text());
		
		QSqlQuery query4(db);
				ok = query4.exec("CREATE TABLE lbcb (id integer primary key autoincrement, id_m integer, "
			"osoba varchar (1024), data_wyp varchar (1024), data_odd varchar (1024), stan_wyp varchar (1024), stan_odd varchar (1024))");
		if( !ok )
		QMessageBox::information(this, "Fail", query4.lastError().text());
		db.close();

	}
else
{
	QMessageBox::information(this,"FAIL", "Fail conn not established");
}
}

void LBooksCatalogue::ReadRec(int id, int dir)
{
	
	QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
	db.setDatabaseName("lbcmain.db");

if(db.open())
{
		QString cur_id_str;
		cur_id_str.setNum(cur_id);
		QSqlQuery query(db);
				bool ok = query.exec("SELECT id, tytul, tytul_oryg, "
			"gatunek, ilosc, rok_wyd, wydawnictwo, jezyk_wydania, opis, WL_ImieNazw, "
			"WL_Adres, MZ_Nazwa, MZ_Adres, MZ_WWW, INFO_IloscStr, INFO_Format,  "
			"INFO_Oprawa, INFO_Ocena FROM lbcmain WHERE id = '" + cur_id_str + "'");
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
		
		if (ok)
		{
		query.next();
			QMessageBox::information(this,"cur_id VALUE ",cur_id_str);
			QMessageBox::information(this,"TITLE VALUE ", query.value(titleCol).toString());
			this->ui.lineEdit_Tytul->setText(QString(query.value(titleCol).toString()));
			this->ui.lineEdit_TytulOryg->setText(QString(query.value(title_origCol).toString()));
			this->ui.lineEdit_Gatunek->setText(QString(query.value(genreCol).toString()));
			this->ui.lineEdit_Count->setText(QString(query.value(countCol).toString()));
			this->ui.lineEdit_DatePub->setText(QString(query.value(year_pub).toString()));
			this->ui.lineEdit_Publisher->setText(QString(query.value(pubCol).toString()));
			this->ui.lineEdit_PubLang->setText(QString(query.value(lang_pubCol).toString()));
			this->ui.textEdit_Opis->setText(QString(query.value(descCol).toString()));
			this->ui.lineEdit_WL_Imienazw->setText(QString(query.value(WL_Im_Nazw_Col).toString()));
			this->ui.lineEdit_WL_Adres->setText(QString(query.value(WL_Adres_Col).toString()));
			this->ui.lineEdit_MZ_Nazwa->setText(QString(query.value(MZ_Nazwa_Col).toString()));
			this->ui.lineEdit__MZ_Adres->setText(QString(query.value(MZ_Adres_Col).toString()));
			this->ui.lineEdit_MZ_WWW->setText(QString(query.value(MZ_WWW_Col).toString()));
			this->ui.lineEdit_INFO_PageCount->setText(QString(query.value(INFO_IloscStr_Col).toString()));
			this->ui.lineEdit_INFO_Format->setText(QString(query.value(INFO_Format_Col).toString()));
			this->ui.lineEdit_INFO_Oprawa->setText(QString(query.value(INFO_Oprawa_Col).toString()));
			this->ui.lineEdit_INFO_Cena->setText(QString(query.value(INFO_Ocena_Col).toString()));
			
		
			//Authors
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
				int x = 0;
				this->ui.tableWidget_Autorzy->setRowCount(query2.size());
				while (query2.next())
				{
						QTableWidgetItem *item = this->ui.tableWidget_Autorzy->item(x,0);
						item->setText(query2.value(idCol).toString());
						QTableWidgetItem *item2 = this->ui.tableWidget_Autorzy->item(x,1);
						item2->setText(query2.value(idmCol).toString());
						QTableWidgetItem *item3 = this->ui.tableWidget_Autorzy->item(x,2);
						item3->setText(query2.value(imienazwCol).toString());
						QTableWidgetItem *item4 = this->ui.tableWidget_Autorzy->item(x,3);
						item4->setText(query2.value(narodCol).toString());
						QTableWidgetItem *item5 = this->ui.tableWidget_Autorzy->item(x,4);
						item5->setText(query2.value(specCol).toString());
						QTableWidgetItem *item6 = this->ui.tableWidget_Autorzy->item(x,5);
						item6->setText(query2.value(rozdzCol).toString());
						x++;

				}
			}
			else
			{
				QMessageBox::information(this,"FAIL read rec lbca qry ", "query to lbca failed");
			}
			

			//Wydania
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
				int x = 0;
				this->ui.tableWidget_Wydania->setRowCount(query3.size());
				while (query3.next())
				{
						
						QTableWidgetItem *item = this->ui.tableWidget_Wydania->item(x,0);
						item->setText(query3.value(idwCol).toString());
						QTableWidgetItem *item2 = this->ui.tableWidget_Wydania->item(x,1);
						item2->setText(query3.value(idwmCol).toString());
						QTableWidgetItem *item3 = this->ui.tableWidget_Wydania->item(x,2);
						item3->setText(query3.value(datawydCol).toString());
						QTableWidgetItem *item4 = this->ui.tableWidget_Wydania->item(x,3);
						item4->setText(query3.value(wydCol).toString());
						QTableWidgetItem *item5 = this->ui.tableWidget_Wydania->item(x,4);
						item5->setText(query3.value(langCol).toString());
						QTableWidgetItem *item6 = this->ui.tableWidget_Wydania->item(x,5);
						item6->setText(query3.value(pubnoCol).toString());
						QTableWidgetItem *item7 = this->ui.tableWidget_Wydania->item(x,6);
						item7->setText(query3.value(krajwydCol).toString());
						x++;
					


				}
			}
			else
			{
				QMessageBox::information(this,"FAIL read rec lbcp qry ", "query to lbcp failed");
			}
			
			// BIBLIO
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
				int x = 0;
				this->ui.tableWidget_BIBLIO_WypoIN->setRowCount(query4.size());
				while (query4.next())
				{				
					
						
						QTableWidgetItem *item = this->ui.tableWidget_BIBLIO_WypoIN->item(x,0);
						item->setText(query4.value(idbCol).toString());
						QTableWidgetItem *item2 = this->ui.tableWidget_BIBLIO_WypoIN->item(x,1);
						item2->setText(query4.value(idbmCol).toString());
						QTableWidgetItem *item3 = this->ui.tableWidget_BIBLIO_WypoIN->item(x,2);
						item3->setText(query4.value(osobaCol).toString());
						QTableWidgetItem *item4 = this->ui.tableWidget_BIBLIO_WypoIN->item(x,3);
						item4->setText(query4.value(dwypCol).toString());
						QTableWidgetItem *item5 = this->ui.tableWidget_BIBLIO_WypoIN->item(x,4);
						item5->setText(query4.value(doddCol).toString());
						QTableWidgetItem *item6 = this->ui.tableWidget_BIBLIO_WypoIN->item(x,5);
						item6->setText(query4.value(swypCol).toString());
						QTableWidgetItem *item7 = this->ui.tableWidget_BIBLIO_WypoIN->item(x,6);
						item7->setText(query4.value(soddCol).toString());
						x++;
				
				}
			}
			else
			{
				QMessageBox::information(this,"FAIL read rec lbcb qry ", "query to lbcb failed");
			}
				db.close();
				CalcRecInfo();
		}
		else
		{
			QMessageBox::information(this,"FAIL read rec lbcmain qry ", "query to lbcmain failed");
		}
		
	}
	else
	{
		QMessageBox::information(this,"FAIL read rec", "DB OPEN FAILED");
	}

}

void LBooksCatalogue::ReadSettings()
{
	//TODO: Napisaæ odczytwyanie ustawieñ aplikacji

}

void LBooksCatalogue::SaveRec(int id)
{
	QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
	db.setDatabaseName("lbcmain.db");

if(db.open())
{
			
			QString cur_id_str;
			cur_id_str.setNum(cur_id);
			QSqlQuery query(db);
				query.exec("update lbcmain set tytul=" + this->ui.lineEdit_Tytul->text() + ", tytul_oryg=" +
				this->ui.lineEdit_TytulOryg->text() + ", gatunek=" + this->ui.lineEdit_Gatunek->text() + 
				", ilosc=" + this->ui.lineEdit_Count->text() + ", rok_wyd=" + this->ui.lineEdit_DatePub->text() + 
				", wydawnictwo=" + this->ui.lineEdit_Publisher->text() + ", jezyk_wydania=" + this->ui.lineEdit_PubLang->text() +
				", opis=" + this->ui.textEdit_Opis->toPlainText() + ", WL_ImieNazw=" + this->ui.lineEdit_WL_Imienazw->text() +
				", WL_Adres=" + this->ui.lineEdit_WL_Adres->text() + 
				", MZ_Nazwa=" + this->ui.lineEdit_MZ_Nazwa->text()+ ", MZ_Adres=" + this->ui.lineEdit__MZ_Adres->text() + 
				", MZ_WWW=" + this->ui.lineEdit_MZ_WWW->text() +  
				", INFO_IloscStr=" + this->ui.lineEdit_INFO_PageCount->text() + ", INFO_Format=" +
				this->ui.lineEdit_INFO_Format->text() + ", INFO_Oprawa=" + this->ui.lineEdit_INFO_Oprawa->text() + 
				", INFO_Cena=" + this->ui.lineEdit_INFO_Cena->text() + " where id = '" + cur_id_str + "'");
			
			db.close();
			
				
				UpdateDB(cur_id); // update-uj tabele podrzêdne
				
			}
			else
			{	
				

			}
	
	

}

void LBooksCatalogue::SaveSettings()
{
	//TODO: napisac zapisywanie ustawieñ aplikacji


}

void LBooksCatalogue::UpdateDB(int id)
{
	QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
	db.setDatabaseName("lbcmain.db");

if(db.open())
{
	if (this->ui.tableWidget_Autorzy->rowCount() > 0) //Authors
		{
			for (int x = 0; x < this->ui.tableWidget_Autorzy->rowCount(); x++)
			{
				QStringList qsl;
				for (int y = 0; y < 6; y++) //columns
				{
					QTableWidgetItem *item = this->ui.tableWidget_Autorzy->item(x,y);
					qsl << item->text();
				}
				QSqlQuery query(db);
				query.exec("update lbca set imie_nazw=" + qsl[2] + ", narod=" + qsl[3] + 
					", spec=" + qsl[4] + ", rozdz=" + qsl[5] + "where id = '" + qsl[0] + "'");
				
			}


		}

		if (this->ui.tableWidget_Wydania->rowCount() > 0) //Wydania
		{
			for (int x = 0; x < this->ui.tableWidget_Wydania->rowCount(); x++)
			{
				QStringList qsl;
				for (int y = 0; y < 7; y++) //columns
				{
					QTableWidgetItem *item = this->ui.tableWidget_Wydania->item(x,y);
					qsl << item->text();
				}
				QSqlQuery query(db);
				query.exec("update lbcp set data_wyd=" + qsl[2] + ", wydawnictwo=" + qsl[3] +
					", jezyk=" + qsl[4] + ", numer_wyd=" + qsl[5] + ", kraj_wyd=" + qsl[6] + " where id = '" + qsl[0] + "'");
				
			}
		}

		if (this->ui.tableWidget_BIBLIO_WypoIN->rowCount() > 0) // BIBLIO
		{
			for (int x = 0; x < this->ui.tableWidget_BIBLIO_WypoIN->rowCount(); x++)
			{
				QStringList qsl;
				for (int y = 0; y < 7; y++) //columns
				{
					QTableWidgetItem *item = this->ui.tableWidget_BIBLIO_WypoIN->item(x,y);
					qsl << item->text();
				}
				QSqlQuery query(db);
				query.exec("update lbcb set osoba=" + qsl[2] + ", data_wyp=" + qsl[3] + 
					", data_odd=" + qsl[4] + ", stan_wyp=" + qsl[5] + ", stan_odd=" + qsl[6] + " where id = '" + qsl[0] + "'");
				
			}
		}
		db.close();
	}
	

}

void LBooksCatalogue::ReadStartRec()
{
	QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
	db.setDatabaseName("lbcmain.db");

if(db.open())
{
		QSqlQuery query(db);
			bool ok = query.exec("SELECT * FROM lbcmain");
			if (ok)
			{
				query.next();
				QSqlRecord qrec = query.record();
				int idCol = qrec.indexOf("id");
				bool seek_ok = query.seek(0);
				if (seek_ok)
				{
					cur_id = query.value(idCol).toInt();
					ReadRec(0,0);
				}
				else
				{
					QMessageBox::information(this,"FAIL read start rec", "SEEK FAILED");
				}
			}
			else
			{
				QMessageBox::information(this,"FAIL read start rec", query.lastError().text());
			}
			db.close();
	
}
else
{
	QMessageBox::information(this,"FAIL read start rec", "Fail cant open db");
}
}


void LBooksCatalogue::AddNewRec(int id)
{
	QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
	db.setDatabaseName("lbcmain.db");

if(db.open())
{
		QSqlQuery query(db);
		bool ok = query.exec("INSERT INTO lbcmain (tytul , tytul_oryg , gatunek , ilosc , rok_wyd , wydawnictwo , jezyk_wydania , opis , WL_ImieNazw , WL_Adres , MZ_Nazwa , MZ_Adres , MZ_WWW , INFO_IloscStr , INFO_Format , INFO_Oprawa , INFO_Ocena )  VALUES (\"" + this->ui.lineEdit_Tytul->text() + " \" , \" " + this->ui.lineEdit_TytulOryg->text() + " \" , \" " +
			this->ui.lineEdit_Gatunek->text() + " \" , \" " + this->ui.lineEdit_Count->text() + " \" , \" " + 
			this->ui.lineEdit_DatePub->text() + " \" , \" " + this->ui.lineEdit_Publisher->text() + " \" , \" " +
			this->ui.lineEdit_PubLang->text() + " \" , \" " + this->ui.textEdit_Opis->toPlainText() + " \" , \" " +
			this->ui.lineEdit_WL_Imienazw->text() + " \" , \" " + this->ui.lineEdit_WL_Adres->text() + " \" ,\" " +
			this->ui.lineEdit_MZ_Nazwa->text() + " \" , \" " +
			this->ui.lineEdit__MZ_Adres->text() + " \" , \" " + this->ui.lineEdit_MZ_WWW->text() + " \" , \" " +
			this->ui.lineEdit_INFO_PageCount->text() + " \" , \" " + this->ui.lineEdit_INFO_Format->text() + " \" , \" " +
			this->ui.lineEdit_INFO_Oprawa->text() + " \" , \" " + this->ui.lineEdit_INFO_Cena->text() + " \" )");

		if( !ok )
		QMessageBox::information(this, "Fail Add new rec", query.lastError().text());
		db.close();
		InsertDB(GetLastId(0));

		
		
}
else
{
	QMessageBox::information(this, "Fail Add new rec","Cant open db" );
}
}

int LBooksCatalogue::GetLastId(int table)
{
	QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
	db.setDatabaseName("lbcmain.db");
	int ret = 0;
	bool ok = false;

if(db.open())
{
		QSqlQuery query(db);
		switch (table)
		{
		case 0: // MAIN
			
				
				ok = query.exec("select id from lbcmain");
				if (ok)
				{
					query.next();
					QSqlRecord qrec = query.record();
					query.last();
					int idCol = qrec.indexOf("id");
			
					ret = query.value(idCol).toInt();
				}
			break;
		case 1: 
			// Authors
				
				ok = query.exec("select id from lbca");
				if (ok)
				{
					query.next();
					QSqlRecord qrec2 = query.record();
					query.last();
					int idCol = qrec2.indexOf("id");
				
					ret = query.value(idCol).toInt();
				}
			break;
			

		case 2: // Wydania
				
				ok = query.exec("select id from lbcp");
				if (ok)
				{
					query.next();
					QSqlRecord qrec3 = query.record();
					query.last();
					int idCol = qrec3.indexOf("id");
					ret = query.value(idCol).toInt();
				}
			break;

		case 3:  // BIBLIO
				
				ok = query.exec("select id from lbcb");
				if (ok)
				{
					query.next();
					QSqlRecord qrec4 = query.record();
					query.last();
					int idCol = qrec4.indexOf("id");
					ret = query.value(idCol).toInt();
				}
			break;

		default:
				return 0;
			break;

		}
		db.close();
	}
	return ret;

}

void LBooksCatalogue::InsertDB(int id)
{
	
	QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
	db.setDatabaseName("lbcmain.db");

if(db.open())
{
		if (this->ui.tableWidget_Autorzy->rowCount() > 0) //Authors
		{
			for (int x = 0; x < this->ui.tableWidget_Autorzy->rowCount(); x++)
			{
				QStringList qsl;
				for (int y = 2; y < 6; y++) //columns
				{
					QTableWidgetItem *item = this->ui.tableWidget_Autorzy->item(x,y);
					qsl << item->text();
				}
				QString id_m_str;
				id_m_str.setNum(id);
				QSqlQuery query(db);
				bool ok = query.exec("insert into lbca(id_m, imie_nazw, narod, spec, rozdz)"
					"VALUES(" + id_m_str + ", " + qsl[0] + ", " + qsl[1] + ", " + qsl[2] + ", " + qsl[3] + ")");
				if( !ok )
				QMessageBox::information(this, "Fail lbca", query.lastError().text());
			}

		}

		if (this->ui.tableWidget_Wydania->rowCount() > 0) //Wydania
		{
			for (int x = 0; x < this->ui.tableWidget_Wydania->rowCount(); x++)
			{
				QStringList qsl;
				for (int y = 2; y < 7; y++) //columns
				{
					QTableWidgetItem *item = this->ui.tableWidget_Wydania->item(x,y);
					qsl << item->text();
				}
				QString id_m_str;
				id_m_str.setNum(id);
				QSqlQuery query(db);
				bool ok = query.exec("insert into lbcp(id_m int, data_wyd, wydawnictwo, jezyk, numer_wyd, kraj_wyd)"
					"VALUES(" + id_m_str + ", " + qsl[0] + ", " + qsl[1] + ", " + qsl[2] + ", " + qsl[3] + ", " + qsl[4] + ")");
				if( !ok )
				QMessageBox::information(this, "Fail lbcp", query.lastError().text());
			}
		}

		if (this->ui.tableWidget_BIBLIO_WypoIN->rowCount() > 0) // BIBLIO
		{	
			for (int x = 0; x < this->ui.tableWidget_Wydania->rowCount(); x++)
			{
				QStringList qsl;
				for (int y = 2; y < 7; y++) //columns
				{
					QTableWidgetItem *item = this->ui.tableWidget_BIBLIO_WypoIN->item(x,y);
					qsl << item->text();
				}
				QString id_m_str;
				id_m_str.setNum(id);
				QSqlQuery query(db);
				bool ok = query.exec("insert into lbcb(id_m, osoba, data_wyp, data_odd, stan_wyp, stan_odd"
					"VALUES(" + id_m_str + ", " + qsl[0] + ", " + qsl[1] + ", " + qsl[2] + ", " + qsl[3] + ", " + qsl[4] + ")");
				if( !ok )
				QMessageBox::information(this, "Fail lbcb", query.lastError().text());
			}

		}
		db.close();
	}

}

void LBooksCatalogue::InsertRecDB(int id, int table)
{
	QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
	db.setDatabaseName("lbcmain.db");

if(db.open())
{
		if (table == 0) // Authors
		{	
			
				QSqlQuery query(db);
				query.exec("insert into lbca(id_m, imie_nazw, narod, spec, rozdz)"
					"VALUES(" + QString(id) + ", " ", " ", " ", " ")");
			

		}
		else if (table == 1) // PUB
		{
			
				QSqlQuery query(db);
				query.exec("insert into lbcp(id_m int, data_wyd, wydawnictwo, jezyk, numer_wyd, kraj_wyd)"
					"VALUES(" + QString(id) + ", " ", " ", " ", " ", " ")");
			
		}
		else if (table == 2) // BIBLIO
		{
			
				QSqlQuery query(db);
				query.exec("insert into lbcb(id_m, osoba, data_wyp, data_odd, stan_wyp, stan_odd"
					"VALUES(" + QString(id) + ", " ", " ", " ", " ", " ")");
			
		}

	db.close();
		
	}

}

void LBooksCatalogue::ClearCtrls()
{
	this->ui.lineEdit__MZ_Adres->clear();
	
	this->ui.lineEdit_Count->clear();
	this->ui.lineEdit_DatePub->clear();
	this->ui.lineEdit_Gatunek->clear();
	this->ui.lineEdit_INFO_Cena->clear();
	
	
	this->ui.lineEdit_INFO_Format->clear();
	this->ui.lineEdit_INFO_Oprawa->clear();
	this->ui.lineEdit_INFO_PageCount->clear();


	this->ui.lineEdit_MZ_Nazwa->clear();
	this->ui.lineEdit_MZ_WWW->clear();
	this->ui.lineEdit_PubLang->clear();
	this->ui.lineEdit_Publisher->clear();
	this->ui.lineEdit_Tytul->clear();
	this->ui.lineEdit_TytulOryg->clear();
	this->ui.lineEdit_WL_Adres->clear();
	this->ui.lineEdit_WL_Imienazw->clear();
	
	this->ui.textEdit_Opis->clear();


	this->ui.tableWidget_Autorzy->clearContents();
	this->ui.tableWidget_BIBLIO_WypoIN->clearContents();
	this->ui.tableWidget_Wydania->clearContents();


}

void LBooksCatalogue::BTN_A_NEW_CLICKED()
{
	AddAutor a_form(this);
	if (a_form.exec() == QDialog::Accepted)
	{
		// data entered - prepere for copy string list with params
		InsertRecDB(cur_id,0);
	}
	else
	{
		// discard changes  do nothing
	}

}

void LBooksCatalogue::BTN_A_DEL_CLICKED()
{
	DelRecDB(0,0);

}

void LBooksCatalogue::BTN_B_NEW_CLICKED()
{
	AddBiblio b_form(this);
	if (b_form.exec() == QDialog::Accepted)
	{
		// data entered - prepere for copy string list with params
	InsertRecDB(cur_id,2);
	}
	else
	{
		// discard changes  do nothing
	}
}

void LBooksCatalogue::BTN_B_DEL_CLICKED()
{
	DelRecDB(0,2);

}

void LBooksCatalogue::BTN_W_NEW_CLICKED()
{
	AddPub p_form(this);
	if (p_form.exec() == QDialog::Accepted)
	{
		// data entered - prepere for copy string list with params
		InsertRecDB(cur_id,1);
	}
	else
	{
		// discard changes  do nothing
	}

}

void LBooksCatalogue::BTN_W_DEL_CLICKED()
{
	DelRecDB(0,1);
}



void LBooksCatalogue::CreateDefConf()
{
	//TODO: Napisaæ tworzenie domyœlnej konfiguracji i zapsiawanie jej na dysk

}

void LBooksCatalogue::DelRec(int id)
{
	QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
	db.setDatabaseName("lbcmain.db");

if(db.open())
{
		QSqlQuery query(db);
		query.exec("delete from lbcmain where id=" + QString(cur_id));
		db.close();
}
	
	ReadStartRec();
}

void LBooksCatalogue::DelRecDB(int id, int table)
{
	
	QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
	db.setDatabaseName("lbcmain.db");

if(db.open())
{
		if (table == 0) // Authors
		{
			QList<QTableWidgetItem*> item = this->ui.tableWidget_Autorzy->selectedItems();
			QSqlQuery query(db);
			query.exec("delete from lbca where id=" + item[0]->text());
			
		}
		else if (table == 1) // Pub
		{
			QList<QTableWidgetItem*> item = this->ui.tableWidget_Wydania->selectedItems();
			QSqlQuery query(db);
			query.exec("delete from lbcp where id=" + item[0]->text());
		}
		else if (table == 2) // Biblio
		{
			QList<QTableWidgetItem*> item = this->ui.tableWidget_BIBLIO_WypoIN->selectedItems();
			QSqlQuery query(db);
			query.exec("delete from lbcb where id=" + item[0]->text());

		}
		db.close();
}
}

void LBooksCatalogue::CalcRecInfo()
{
	QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
	db.setDatabaseName("lbcmain.db");

if(db.open())
{
		QSqlQuery query(db);
		bool ok = query.exec("SELECT id from lbcmain");
		if (ok)
		{
			QSqlRecord qrec = query.record();
			int idCol = qrec.indexOf("id");
			int x = 0;
			while (query.next())
			{
				x++;
				if (cur_id == query.value(idCol).toInt())
				{
					QString rec_no_str;
					rec_no_str.setNum(x);
					this->ui.lineEdit__RecNo->setText(rec_no_str);
				}
				

			}
			QString rec_count_str;
			rec_count_str.setNum(x);
			this->ui.lineEdit_RecCount->setText(rec_count_str);

		}
		else
		{
			this->ui.lineEdit__RecNo->setText("0");
			this->ui.lineEdit_RecCount->setText("0");

		}
		db.close();
	}
}

int LBooksCatalogue::FindNextId()
{
	QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
	db.setDatabaseName("lbcmain.db");

if(db.open())
{
		QSqlQuery query(db);
		bool ok = query.exec("SELECT id from lbcmain");
		if (ok)
		{
			QSqlRecord qrec = query.record();
			int idCol = qrec.indexOf("id");
			while (query.next())
			{
				if (cur_id == query.value(idCol).toInt())
				{
					query.next();
					int ret = query.value(idCol).toInt();
					if (ret != 0)
					{
						return ret;
					}
					else
					{
						query.first();
						return query.value(idCol).toInt();
					}
				}
				
			}
			db.close();
		}
}

}

int LBooksCatalogue::FindPrevId()
{
	QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
	db.setDatabaseName("lbcmain.db");

if(db.open())
{
		QSqlQuery query(db);
		bool ok = query.exec("SELECT id from lbcmain");
		if (ok)
		{
			QSqlRecord qrec = query.record();
			int idCol = qrec.indexOf("id");
			//query.last();
			while (query.next())
			{
				if (cur_id == query.value(idCol).toInt())
				{
					query.previous();
					int ret = query.value(idCol).toInt();
					if (ret != 0)
					{
						return ret;
					}
					else
					{
						query.first();
						return query.value(idCol).toInt();
					}
				}
				

			}
			db.close();
		}


}

}