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
	}

}
void LBooksCatalogue::BTN_NEXT_CLICKED()
{
	if (GetLastId(0) != 0)
	{
		SaveRec(0);
		cur_id = FindNextId();
		ReadRec(0,0);
	}
	

}
void LBooksCatalogue::BTN_PREV_CLICKED()
{
	if (GetLastId(0) != 0)
	{
		SaveRec(0);
		cur_id = FindPrevId();
		ReadRec(0,0);
	}
}

void LBooksCatalogue::BTN_LAST_CLICKED()
{
	if (GetLastId(0) != 0)
	{
		SaveRec(0);
		cur_id = GetLastId(0);
		ReadRec(0,0);
	}

}

void LBooksCatalogue::BTN_NEW_CLICKED()
{

	new_rec_adding = true;
	ClearCtrls();

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

}

void LBooksCatalogue::BTN_DEL_CLICKED()
{
	if (GetLastId(0) != 0)
	{
		SaveRec(0);
		DelRec(0);
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
				query.exec("CREATE TABLE lbcmain (id int primary key asc autoincrement, tytul TEXT, tytul_oryg TEXT, "
			"gatunek TEXT, ilosc TEXT, rok_wyd TEXT, wydawnictwo TEXT, jezyk_wydania TEXT, opis TEXT, WL_ImieNazw TEXT, "
			"WL_Adres TEXT, MZ_Nazwa TEXT, MZ_Adres TEXT, MZ_WWW TEXT, INFO_IloscStr TEXT, INFO_Format TEXT,  "
			"INFO_Oprawa TEXT, INFO_Ocena TEXT");
		QSqlQuery query2(db);
				query2.exec("CREATE TABLE lbca (id int primaty key asc autoincrement, id_m int, "
			"imie_nazw TEXT, narod TEXT, spec TEXT, rozdz TEXT");
		QSqlQuery query3(db);
				query3.exec(db,"CREATE TABLE lbcp (id int primary key asc autoincrement, id_m int, "
			"data_wyd TEXT, wyd TEXT, jezyk TEXT, numer_wyd TEXT, kraj_wyd TEXT");
		QSqlQuery query4(db);
				query4.exec(db,"CREATE TABLE lbcb (id int primary key asc autoincrement, id_m int, "
			"osoba TEXT, data_wyp TEXT, data_odd TEXT, stan_wyp TEXT, stan_odd TEXT");
		

	}
}

void LBooksCatalogue::ReadRec(int id, int dir)
{
	
	QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
	db.setDatabaseName("lbcmain.db");

if(db.open())
{
		QSqlQuery query(db);
				query.exec("SELECT id, tytul, tytul_oryg, "
			"gatunek, ilosc, rok_wyd, wydawnictwo, jezyk_wydania, opis, WL_ImieNazw, "
			"WL_Adres, MZ_Nazwa, MZ_Adres, MZ_WWW, INFO_IloscStr, INFO_Format,  "
			"INFO_Oprawa, INFO_Ocena FROM lbcmain WHERE id=" + QString(cur_id).toAscii());
		QSqlRecord qrec = query.record();
		int titleCol = rec.indexOf("tytul");
		int title_origCol = rec.indexOf("tytul_oryg");
		int genreCol = rec.indexOf("gatunek");
		int countCol = rec.indexOf("ilosc");
		int year_pub = rec.indexOf("rok_wyd");
		int pubCol = rec.indexOf("wydawnictwo");
		int lang_pubCol = rec.indexOf("jezyk_wydania");
		int descCol = rec.indexOf("opis");
		int WL_Im_Nazw_Col = rec.indexOf("WL_ImieNazw");
		int WL_Adres_Col = rec.indexOf("WL_Adres");
		int MZ_Nazwa_Col = rec.indexOf("MZ_Nazwa");
		int MZ_Adres_Col = rec.indexOf("MZ_Adres");
		int MZ_WWW_Col = rec.indexOf("MZ_WWW");
		int INFO_IloscStr_Col = rec.indexOf("INFO_IloscStr");
		int INFO_Format_Col = rec.indexOf("INFO_Format");
		int INFO_Oprawa_Col = rec.indexOf("INFO_Oprawa");
		int INFO_Ocena_Col = rec.indexOf("INFO_Ocena");

		query.next();

			this->ui.lineEdit_Tytul->setText(QString(query.value(titleCol).toString());
			this->ui.lineEdit_TytulOryg->setText(QString(query.value(title_origCol).toString());
			this->ui.lineEdit_Gatunek->setText(QString(query.value(genreCol).toString());
			this->ui.lineEdit_Count->setText(QString(query.value(countCol).toString());
			this->ui.lineEdit_DatePub->setText(QString(query.value(year_pub).toString());
			this->ui.lineEdit_Publisher->setText(QString(query.value(pubCol).toString());
			this->ui.lineEdit_PubLang->setText(QString(query.value(lang_pubCol).toString());
			this->ui.textEdit_Opis->setText(QString(query.value(descCol).toString());
			this->ui.lineEdit_WL_Imienazw->setText(QString(query.value(WL_Im_Nazw_Col).toString());
			this->ui.lineEdit_WL_Adres->setText(QString(query.value(WL_Adres_Col).toString());
			this->ui.lineEdit_MZ_Nazwa->setText(QString(query.value(MZ_Nazwa_Col).toString());
			this->ui.lineEdit__MZ_Adres->setText(QString(query.value(MZ_Adres_Col).toString());
			this->ui.lineEdit_MZ_WWW->setText(QString(query.value(MZ_WWW_Col).toString());
			this->ui.lineEdit_INFO_PageCount->setText(QString(query.value(INFO_IloscStr_Col).toString());
			this->ui.lineEdit_INFO_Format->setText(QString(query.value(INFO_Format_Col).toString());
			this->ui.lineEdit_INFO_Oprawa->setText(QString(query.value(INFO_Oprawa_Col).toString();
			this->ui.lineEdit_INFO_Cena->setText(QString(query.value(INFO_Ocena_Col).toString());
			
		
			//Authors
			QSqlQuery query(db);
				query.exec("select id, id_m, imie_nazw, narod, spec, rozdz from lbca where id_m=" + QString(cur_id).toAscii());
			
				this->ui.tableWidget_Autorzy->setRowCount(rows);
				for (int x = 0; x < rows; x++)
				{
					for (int y = 0; y < cols; y++) //columns
					{
						QTableWidgetItem *item = this->ui.tableWidget_Autorzy->item(x,y);
						item->setText(QString(table[((x + 1) * cols) + y]));
					}
					

				}
			}
			table = 0;
			errmsg = 0;

			//Wydania
			result = sqlite3_get_table(db,"select id, id_m, data_wyd, wydawnictwo, jezyk, numer_wyd, kraj_wyd from lbcp where id_m=" + QString(cur_id).toAscii(),
				&table,&rows,&cols,&errmsg);
			if (result == SQLITE_OK)
			{
				this->ui.tableWidget_Wydania->setRowCount(rows);
				for (int x = 0; x < rows; x++)
				{
					for (int y = 0; y < cols; y++) //columns
					{
						QTableWidgetItem *item = this->ui.tableWidget_Wydania->item(x,y);
						item->setText(QString(table[((x + 1) * cols) + y]));
						
					}


				}
			}
			table = 0;
			errmsg = 0;

			// BIBLIO
			result = sqlite3_get_table(db,"select id, id_m, osoba, data_wyp, data_odd, "
				"stan_wyp, stan_odd from lbcb where id_m=" + QString(cur_id).toAscii(),
				&table,&rows,&cols,&errmsg);
			if (result == SQLITE_OK)
			{
				this->ui.tableWidget_BIBLIO_WypoIN->setRowCount(rows);
				for (int x = 0; x < rows; x++)
				{				
					for (int y = 0; y < cols; y++) //columns
					{
						QTableWidgetItem *item = this->ui.tableWidget_BIBLIO_WypoIN->item(x,y);
						item->setText(QString(table[((x + 1) * cols) + y]));
					}
				
				}
			}
			CalcRecInfo();
		}
		sqlite3_free_table(table);
		sqlite3_free(errmsg);
		sqlite3_close(db);
	}
	

}

void LBooksCatalogue::ReadSettings()
{
	//TODO: Napisaæ odczytwyanie ustawieñ aplikacji

}

void LBooksCatalogue::SaveRec(int id)
{
	sqlite3 *db;
	int result;
	char *errmsg = 0;
	if (sqlite3_open("lbcmain.db",&db) == SQLITE_OK)
	{
			QString qstrqry("update lbcmain set tytul=" + this->ui.lineEdit_Tytul->text() + ", tytul_oryg=" +
				this->ui.lineEdit_TytulOryg->text() + ", gatunek=" + this->ui.lineEdit_Gatunek->text() + 
				", ilosc=" + this->ui.lineEdit_Count->text() + ", rok_wyd=" + this->ui.lineEdit_DatePub->text() + 
				", wydawnictwo=" + this->ui.lineEdit_Publisher->text() + ", jezyk_wydania=" + this->ui.lineEdit_PubLang->text() +
				", opis=" + this->ui.textEdit_Opis->toPlainText() + ", WL_ImieNazw=" + this->ui.lineEdit_WL_Imienazw->text() +
				", WL_Adres=" + this->ui.lineEdit_WL_Adres->text() + 
				", MZ_Nazwa=" + this->ui.lineEdit_MZ_Nazwa->text()+ ", MZ_Adres=" + this->ui.lineEdit__MZ_Adres->text() + 
				", MZ_WWW=" + this->ui.lineEdit_MZ_WWW->text() +  
				", INFO_IloscStr=" + this->ui.lineEdit_INFO_PageCount->text() + ", INFO_Format=" +
				this->ui.lineEdit_INFO_Format->text() + ", INFO_Oprawa=" + this->ui.lineEdit_INFO_Oprawa->text() + 
				", INFO_Cena=" + this->ui.lineEdit_INFO_Cena->text() + " where id=" + QString(cur_id));
				QByteArray qry(qstrqry.toAscii());
			result = sqlite3_exec(db,qry.data(),NULL,NULL,&errmsg);

			if (result == SQLITE_OK)
			{
				
				UpdateDB(cur_id); // update-uj tabele podrzêdne
				
			}
			else
			{	
				QByteArray errormesg(errmsg);
				QString qstrerrmesg(errormesg);
				QMessageBox qmsg(QMessageBox::Critical,QString("Error"),qstrerrmesg,QMessageBox::Ok);
				qmsg.exec();

			}
	}
	sqlite3_free(errmsg);
	sqlite3_close(db);

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
					", spec=" + qsl[4] + ", rozdz=" + qsl[5] + "where id=" + qsl[0]);
				
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
					", jezyk=" + qsl[4] + ", numer_wyd=" + qsl[5] + ", kraj_wyd=" + qsl[6] + " where id=" + qsl[0]);
				
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
					", data_odd=" + qsl[4] + ", stan_wyp=" + qsl[5] + ", stan_odd=" + qsl[6] + " where id=" + qsl[0]);
				
			}
		}
	}
	sqlite3_free(errmsg);
	sqlite3_close(db);

}

void LBooksCatalogue::ReadStartRec()
{
	sqlite3 *db;
	int result;
	char *errmsg = 0;
	char *table = 0;
	int rows;
	int cols;
	if (sqlite3_open("lbcmain.db",&db) == SQLITE_OK)
	{
		result = sqlite3_get_table(db,"select id from mkbcmain",&&table,&rows,&cols,&errmsg);
		if (result == 0)
		{
			cur_id = QString(table[cols]).toInt(0);
			ReadRec(0,0);
		}
	}
	sqlite3_free_table(&table);
	sqlite3_free(errmsg);
	sqlite3_close(db);
}



void LBooksCatalogue::AddNewRec(int id)
{
	sqlite3 *db;
	char *errmsg = 0;
	if (sqlite3_open("lbcmain.db",&db) == 0)
	{
		QString qstrquery("INSERT INTO main.lbcmain "
			" VALUES (" + this->ui.lineEdit_Tytul->text() + " , " + this->ui.lineEdit_TytulOryg->text() + " , " +
			this->ui.lineEdit_Gatunek->text() + " , " + this->ui.lineEdit_Count->text() + " , " + 
			this->ui.lineEdit_DatePub->text() + " , " + this->ui.lineEdit_Publisher->text() + " , " +
			this->ui.lineEdit_PubLang->text() + " , " + this->ui.textEdit_Opis->toPlainText() + " , " +
			this->ui.lineEdit_WL_Imienazw->text() + " , " + this->ui.lineEdit_WL_Adres->text() + " , " +
			this->ui.lineEdit_MZ_Nazwa->text() + " , " +
			this->ui.lineEdit__MZ_Adres->text() + " , " + this->ui.lineEdit_MZ_WWW->text() + " , " +
			this->ui.lineEdit_INFO_PageCount->text() + " , " + this->ui.lineEdit_INFO_Format->text() + " , " +
			this->ui.lineEdit_INFO_Oprawa->text() + " , " + this->ui.lineEdit_INFO_Cena->text() + " )");
		QByteArray query(qstrquery.toAscii());

		if (sqlite3_exec(db,query.data(),NULL,NULL,&errmsg) != 0)
			
		{
			QByteArray errormesg(errmsg);
			QString qstrerrmesg(errormesg);
			QMessageBox qmsg(QMessageBox::Critical,QString("Error"),qstrerrmesg,QMessageBox::Ok);
			qmsg.exec();
			return;
		}
			
		
			InsertDB(GetLastId(0),db);
		
		sqlite3_free(errmsg);
		sqlite3_close(db);
	}
}

int LBooksCatalogue::GetLastId(int db)
{
	sqlite3 *db;
	char *errmsg = 0;
	int rows;
	int cols;
	int ret = 0;
	char *table = 0;
	if (sqlite3_open("lbcmain.db",&db) == 0)
	{
		switch (db)
		{
		case 0: // MAIN
			
			if (sqlite3_get_table(db,"select id from lbcmain",&&table,&rows,&cols,&errmsg) == 0)
			{
				ret = QString(table[rows + cols]).toInt(0);
			}
			break;
		case 1: 
			// Authors
			if (sqlite3_get_table(db,"select id from lbca",&&table,&rows,&cols,&errmsg) == 0)
			{
				ret = QString(table[rows + cols]).toInt(0);
			}
			break;
			

		case 2: // Wydania
			if (sqlite3_get_table(db,"select id from lbcp",&&table,&rows,&cols,&errmsg) == 0)
			{
				ret = QString(table[rows + cols]).toInt(0);
			}
			break;

		case 3:  // BIBLIO
			if (sqlite3_get_table(db,"select id from lbcb",&&table,&rows,&cols,&errmsg) == 0)
			{
				ret = QString(table[rows + cols]).toInt(0);
			}
			break;

		default:
				return 0;
			break;

		}
		
	}
	sqlite3_free(errmsg);
	sqlite3_free_table(&table);
	sqlite3_close(db);
	return ret;

}

void LBooksCatalogue::InsertDB(int id)
{
	
	if (db.isValid())
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

				QSqlQuery query("insert into lbca(id_m, imie_nazw, narod, spec, rozdz)"
					"VALUES(" + QString(id) + ", " + qsl[0] + ", " + qsl[1] + ", " + qsl[2] + ", " + qsl[3] + ")",db);
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
				QSqlQuery query("insert into lbcp(id_m int, data_wyd, wydawnictwo, jezyk, numer_wyd, kraj_wyd)"
					"VALUES(" + QString(id) + ", " + qsl[0] + ", " + qsl[1] + ", " + qsl[2] + ", " + qsl[3] + ", " + qsl[4] + ")",db);
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
				QSqlQuery query("insert into lbcb(id_m, osoba, data_wyp, data_odd, stan_wyp, stan_odd"
					"VALUES(" + QString(id) + ", " + qsl[0] + ", " + qsl[1] + ", " + qsl[2] + ", " + qsl[3] + ", " + qsl[4] + ")",db);
			}

		}
	}

}

void LBooksCatalogue::InsertRecDB(int id, int table)
{
	QSqlDatabase db = OpenDB();
	QStringList qsl(params_db);
	if (db.isValid())
	{
		if (table == 0) // Authors
		{	
			if (qsl.count() == 4)
			{
				QSqlQuery query1("insert into lbca(id_m, imie_nazw, narod, spec, rozdz)"
					"VALUES(" + QString(id) + ", " + qsl[0] + ", " + qsl[1] + ", " + qsl[2] + ", " + qsl[3] + ")",db);
			}

		}
		else if (table == 1) // PUB
		{
			if (qsl.count() == 5)
			{
				QSqlQuery query2("insert into lbcp(id_m int, data_wyd, wydawnictwo, jezyk, numer_wyd, kraj_wyd)"
					"VALUES(" + QString(id) + ", " + qsl[0] + ", " + qsl[1] + ", " + qsl[2] + ", " + qsl[3] + 
					", " + qsl[4] + ")",db);
			}
		}
		else if (table == 2) // BIBLIO
		{
			if (qsl.count() == 5)
			{
				QSqlQuery query3("insert into lbcb(id_m, osoba, data_wyp, data_odd, stan_wyp, stan_odd"
					"VALUES(" + QString(id) + ", " + qsl[0] + ", " + qsl[1] + ", " + qsl[2] + ", " + qsl[3] + 
					", " + qsl[4] + ")",db);
			}
		}


		CloseDB(db);
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
	QSqlDatabase db = OpenDB();
	if (db.isValid())
	{
		QSqlQuery query(db);
		query.exec("delete from lbcmain where id=" + QString(cur_id));
		CloseDB(db);
	}
	ReadStartRec();
}

void LBooksCatalogue::DelRecDB(int id, int table)
{
	
	QSqlDatabase db = OpenDB();
	if (db.isValid())
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
		CloseDB(db);
	}
}

void LBooksCatalogue::CalcRecInfo()
{
	if (db.isValid())
	{
		if (query.isActive())
		{
			this->ui.lineEdit__RecNo->setText(QString(query.at()));
			this->ui.lineEdit_RecCount->setText(QString(query.size()));

		}
		else
		{
			this->ui.lineEdit__RecNo->setText("0");
			this->ui.lineEdit_RecCount->setText("0");

		}
	}
}

int LBooksCatalogue::FindNextId()
{
	//TODO: napisac znajdowanie id nastêpnego rekordu

}

int LBooksCatalogue::FindPrevId()
{
	//TODO: napisac znajdowanie id poprzedniego rekordu

}