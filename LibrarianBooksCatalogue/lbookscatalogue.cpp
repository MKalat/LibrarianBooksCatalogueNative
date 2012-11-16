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
	sqlite3 *db;
	char *errmsg = 0;
	int result;
	if (sqlite3_open("lbcmain.db",&db) != 0)
	{
		result = sqlite3_exec(db,"CREATE TABLE lbcmain (id int primary key asc autoincrement, tytul TEXT, tytul_oryg TEXT, "
			"gatunek TEXT, ilosc TEXT, rok_wyd TEXT, wydawnictwo TEXT, jezyk_wydania TEXT, opis TEXT, WL_ImieNazw TEXT, "
			"WL_Adres TEXT, MZ_Nazwa TEXT, MZ_Adres TEXT, MZ_WWW TEXT, INFO_IloscStr TEXT, INFO_Format TEXT,  "
			"INFO_Oprawa TEXT, INFO_Ocena TEXT",NULL,NULL,&errmsg);
		if (result != SQLITE_OK)
		{
			QMessageBox qmsg(QString(errmsg));
			qmsg.exec();
		}
		result = sqlite3_exec(db,"CREATE TABLE lbca (id int primaty key asc autoincrement, id_m int, "
			"imie_nazw TEXT, narod TEXT, spec TEXT, rozdz TEXT",NULL,NULL,&errmsg);
		if (result != SQLITE_OK)
		{
			QMessageBox qmsg(QString(errmsg));
			qmsg.exec();
		}
		result = sqlite3_exec(db,"CREATE TABLE lbcp (id int primary key asc autoincrement, id_m int, "
			"data_wyd TEXT, wyd TEXT, jezyk TEXT, numer_wyd TEXT, kraj_wyd TEXT", NULL, NULL, &errmsg);
		if (result != SQLITE_OK)
		{
			QMessageBox qmsg(QString(errmsg));
			qmsg.exec();
		}
		result = sqlite3_exec(db,"CREATE TABLE lbcb (id int primary key asc autoincrement, id_m int, "
			"osoba TEXT, data_wyp TEXT, data_odd TEXT, stan_wyp TEXT, stan_odd TEXT", NULL, NULL, &errmsg);
		if (result != SQLITE_OK)
		{
			QMessageBox qmsg(QString(errmsg));
			qmsg.exec();
		}
		sqlite3_free(errmsg);
		sqlite3_close(db);

	}
}

void LBooksCatalogue::ReadRec(int id, int dir)
{
	
	sqlite3 *db;
	char *errmsg = 0;
	int result;
	char *table = 0;
	int rows;
	int cols;
	if (sqlite3_open("lbcmain.db",&db))
	{
		if (sqlite3_get_table(db,"SELECT id, tytul, tytul_oryg, "
			"gatunek, ilosc, rok_wyd, wydawnictwo, jezyk_wydania, opis, WL_ImieNazw, "
			"WL_Adres, MZ_Nazwa, MZ_Adres, MZ_WWW, INFO_IloscStr, INFO_Format,  "
			"INFO_Oprawa, INFO_Ocena FROM lbcmain WHERE id=" + QString(cur_id).toAscii(),&table,&rows,&cols,&errmsg) == SQLITE_OK)
		{

			this->ui.lineEdit_Tytul->setText(QString(table[1+cols]));
			this->ui.lineEdit_TytulOryg->setText(QString(table[2+cols]));
			this->ui.lineEdit_Gatunek->setText(QString(table[3+cols]));
			this->ui.lineEdit_Count->setText(QString(table[4+cols]));
			this->ui.lineEdit_DatePub->setText(QString(table[5+cols]));
			this->ui.lineEdit_Publisher->setText(QString(table[6+cols]));
			this->ui.lineEdit_PubLang->setText(QString(table[7+cols]));
			this->ui.textEdit_Opis->setText(QString(table[8+cols]));
			this->ui.lineEdit_WL_Imienazw->setText(QString(table[9+cols]));
			this->ui.lineEdit_WL_Adres->setText(QString(table[10+cols]));
			this->ui.lineEdit_MZ_Nazwa->setText(QString(table[11+cols]));
			this->ui.lineEdit__MZ_Adres->setText(QString(table[12+cols]));
			this->ui.lineEdit_MZ_WWW->setText(QString(table[13+cols]));
			this->ui.lineEdit_INFO_PageCount->setText(QString(table[14+cols]));
			this->ui.lineEdit_INFO_Format->setText(QString(table[15+cols]));
			this->ui.lineEdit_INFO_Oprawa->setText(QString(table[16+cols]));
			this->ui.lineEdit_INFO_Cena->setText(QString(table[17+cols]));
		
			//Authors
			table = 0;
			errmsg = 0;
			
			result = sqlite3_get_table(db,"select id, id_m, imie_nazw, narod, spec, rozdz from lbca where id_m=" + QString(cur_id).toAscii(),
				&table,&rows,&cols,&errmsg);
			if (result == SQLITE_OK)
			{
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
		sqlite3_free_table(&table);
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
			result = sqlite3_exec(db,QString("update lbcmain set tytul=" + this->ui.lineEdit_Tytul->text() + ", tytul_oryg=" +
				this->ui.lineEdit_TytulOryg->text() + ", gatunek=" + this->ui.lineEdit_Gatunek->text() + 
				", ilosc=" + this->ui.lineEdit_Count->text() + ", rok_wyd=" + this->ui.lineEdit_DatePub->text() + 
				", wydawnictwo=" + this->ui.lineEdit_Publisher->text() + ", jezyk_wydania=" + this->ui.lineEdit_PubLang->text() +
				", opis=" + this->ui.textEdit_Opis->toPlainText() + ", WL_ImieNazw=" + this->ui.lineEdit_WL_Imienazw->text() +
				", WL_Adres=" + this->ui.lineEdit_WL_Adres->text() + 
				", MZ_Nazwa=" + this->ui.lineEdit_MZ_Nazwa->text()+ ", MZ_Adres=" + this->ui.lineEdit__MZ_Adres->text() + 
				", MZ_WWW=" + this->ui.lineEdit_MZ_WWW->text() +  
				", INFO_IloscStr=" + this->ui.lineEdit_INFO_PageCount->text() + ", INFO_Format=" +
				this->ui.lineEdit_INFO_Format->text() + ", INFO_Oprawa=" + this->ui.lineEdit_INFO_Oprawa->text() + 
				", INFO_Cena=" + this->ui.lineEdit_INFO_Cena->text().toAscii() + " where id=" + QString(cur_id).toAscii(),NULL,NULL,&errmsg);

			if (result == SQLITE_OK)
			{
				
				UpdateDB(cur_id); // update-uj tabele podrzêdne
				
			}
			else
			{
				QMessageBox qmsg(errmsg);
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
	sqlite3 *db;
	int result;
	char *errmsg = 0;
	if (sqlite3_open("lbcmain.db",db) == SQLITE_OK)
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

				sqlite3_exec(db,"update lbca set imie_nazw=" + qsl[2] + ", narod=" + qsl[3] + 
					", spec=" + qsl[4] + ", rozdz=" + qsl[5] + "where id=" + qsl[0],NULL,NULL,&errmsg);
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

				sqlite3_exec(db,"update lbcp set data_wyd=" + qsl[2] + ", wydawnictwo=" + qsl[3] +
					", jezyk=" + qsl[4] + ", numer_wyd=" + qsl[5] + ", kraj_wyd=" + qsl[6] + " where id=" + qsl[0],NULL,NULL,&errmsg);
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

				sqlite3_exec(db,"update lbcb set osoba=" + qsl[2] + ", data_wyp=" + qsl[3] + 
					", data_odd=" + qsl[4] + ", stan_wyp=" + qsl[5] + ", stan_odd=" + qsl[6] + " where id=" + qsl[0],NULL,NULL,&errmsg);
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
	if (sqlite3_open("lbcmain.db",db) == SQLITE_OK)
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
	if (sqlite3_open("lbcmain.db",db) == 0)
	{
		if (sqlite3_exec(db,"INSERT INTO main.lbcmain "
			" VALUES (" + this->ui.lineEdit_Tytul->text() + " , " + this->ui.lineEdit_TytulOryg->text() + " , " +
			this->ui.lineEdit_Gatunek->text() + " , " + this->ui.lineEdit_Count->text() + " , " + 
			this->ui.lineEdit_DatePub->text() + " , " + this->ui.lineEdit_Publisher->text() + " , " +
			this->ui.lineEdit_PubLang->text() + " , " + this->ui.textEdit_Opis->toPlainText() + " , " +
			this->ui.lineEdit_WL_Imienazw->text() + " , " + this->ui.lineEdit_WL_Adres->text() + " , " +
			this->ui.lineEdit_MZ_Nazwa->text() + " , " +
			this->ui.lineEdit__MZ_Adres->text() + " , " + this->ui.lineEdit_MZ_WWW->text() + " , " +
			this->ui.lineEdit_INFO_PageCount->text() + " , " + this->ui.lineEdit_INFO_Format->text() + " , " +
			this->ui.lineEdit_INFO_Oprawa->text() + " , " + this->ui.lineEdit_INFO_Cena->text() + " )",NULL,NULL,&errmsg) != 0)
			
		{
			QMessageBox msg(errmsg);

			msg.exec();
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
	if (sqlite3_open("lbcmain.db",db) == 0)
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