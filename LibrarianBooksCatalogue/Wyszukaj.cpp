#include "stdafx.h"
#include "Wyszukaj.h"

Wyszukaj::Wyszukaj(QWidget *parent, Qt::WindowFlags flags)
	: QDialog(parent, flags)
{
	ui.setupUi(this);

}

Wyszukaj::~Wyszukaj()
{


}
void Wyszukaj::BTN_SEARCH_CLICKED()
{
	if (this->ui.lineEdit_SzFraza->text().length() > 0)
	{
		QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
		db.setDatabaseName("lbcmain.db");

		if(db.open())
		{
			QSqlQuery query(db);
			bool ok = false;
			switch (this->ui.comboBox_SzPole->currentIndex())
			{
				case 0: 
					ok = query.exec("SELECT id, tytul, tytul_oryg, gatunek, rok_wyd FROM lbcmain WHERE tytul LIKE '%" + this->ui.lineEdit_SzFraza->text() + "%'");
					if (!ok)
					QMessageBox::information(this, "Fail Search index 0", query.lastError().text());
					break;
				case 1:
					ok = query.exec("SELECT id,tytul, tytul_oryg, gatunek, rok_wyd FROM lbcmain WHERE tytul_oryg LIKE '%" + this->ui.lineEdit_SzFraza->text() + "%'");
					if (!ok)
					QMessageBox::information(this, "Fail Search index 1", query.lastError().text());
					break;
				case 2: 
					ok = query.exec("SELECT id,tytul, tytul_oryg, gatunek, rok_wyd FROM lbcmain WHERE gatunek LIKE '%" + this->ui.lineEdit_SzFraza->text() + "%'");
					if (!ok)
					QMessageBox::information(this, "Fail Search index 2", query.lastError().text());
					break;
				case 3: 
					ok = query.exec("SELECT id,tytul, tytul_oryg, gatunek, rok_wyd FROM lbcmain WHERE ilosc LIKE '%" + this->ui.lineEdit_SzFraza->text() + "%'");
					if (!ok)
					QMessageBox::information(this, "Fail Search index 3", query.lastError().text());
					break;
				case 4: 
					ok = query.exec("SELECT id,tytul, tytul_oryg, gatunek, rok_wyd FROM lbcmain WHERE rok_wyd LIKE '%" + this->ui.lineEdit_SzFraza->text() + "%'");
					if (!ok)
					QMessageBox::information(this, "Fail Search index 4", query.lastError().text());
					break;
				case 5: 
					ok = query.exec("SELECT id,tytul, tytul_oryg, gatunek, rok_wyd FROM lbcmain WHERE wydawnictwo LIKE '%" + this->ui.lineEdit_SzFraza->text() + "%'");
					if (!ok)
					QMessageBox::information(this, "Fail Search index 5", query.lastError().text());
					break;
				case 6: 
					ok = query.exec("SELECT id,tytul, tytul_oryg, gatunek, rok_wyd FROM lbcmain WHERE jezyk_wydania LIKE '%" + this->ui.lineEdit_SzFraza->text() + "%'");
					if (!ok)
					QMessageBox::information(this, "Fail Search index 6", query.lastError().text());
					break;
				case 7: 
					ok = query.exec("SELECT id,tytul, tytul_oryg, gatunek, rok_wyd FROM lbcmain WHERE opis LIKE '%" + this->ui.lineEdit_SzFraza->text() + "%'");
					if (!ok)
					QMessageBox::information(this, "Fail Search index 7", query.lastError().text());
					break;
				case 8: 
					ok = query.exec("SELECT id,tytul, tytul_oryg, gatunek, rok_wyd FROM lbcmain WHERE WL_ImieNazw LIKE '%" + this->ui.lineEdit_SzFraza->text() + "%'");
					if (!ok)
					QMessageBox::information(this, "Fail Search index 8", query.lastError().text());
					break;
				case 9: 
					ok = query.exec("SELECT id,tytul, tytul_oryg, gatunek, rok_wyd FROM lbcmain WHERE WL_Adres LIKE '%" + this->ui.lineEdit_SzFraza->text() + "%'");
					if (!ok)
					QMessageBox::information(this, "Fail Search index 9", query.lastError().text());
					break;
				case 10: 
					ok = query.exec("SELECT id,tytul, tytul_oryg, gatunek, rok_wyd FROM lbcmain WHERE MZ_Nazwa LIKE '%" + this->ui.lineEdit_SzFraza->text() + "%'");
					if (!ok)
					QMessageBox::information(this, "Fail Search index 10", query.lastError().text());
					break;
				case 11: 
					ok = query.exec("SELECT id,tytul, tytul_oryg, gatunek, rok_wyd FROM lbcmain WHERE MZ_Adres LIKE '%" + this->ui.lineEdit_SzFraza->text() + "%'");
					if (!ok)
					QMessageBox::information(this, "Fail Search index 11", query.lastError().text());
					break;
				case 12: 
					ok = query.exec("SELECT id,tytul, tytul_oryg, gatunek, rok_wyd FROM lbcmain WHERE MZ_WWW LIKE '%" + this->ui.lineEdit_SzFraza->text() + "%'");
					if (!ok)
					QMessageBox::information(this, "Fail Search index 12", query.lastError().text());
					break;
				case 13: 
					ok = query.exec("SELECT id,tytul, tytul_oryg, gatunek, rok_wyd FROM lbcmain WHERE INFO_IloscStr LIKE '%" + this->ui.lineEdit_SzFraza->text() + "%'");
					if (!ok)
					QMessageBox::information(this, "Fail Search index 13", query.lastError().text());
					break;
				case 14: 
					ok = query.exec("SELECT id,tytul, tytul_oryg, gatunek, rok_wyd FROM lbcmain WHERE INFO_Format LIKE '%" + this->ui.lineEdit_SzFraza->text() + "%'");
					if (!ok)
					QMessageBox::information(this, "Fail Search index 14", query.lastError().text());
					break;
				case 15: 
					ok = query.exec("SELECT id,tytul, tytul_oryg, gatunek, rok_wyd FROM lbcmain WHERE INFO_Oprawa LIKE '%" + this->ui.lineEdit_SzFraza->text() + "%'");
					if (!ok)
					QMessageBox::information(this, "Fail Search index 15", query.lastError().text());
					break;
				case 16: 
					ok = query.exec("SELECT id,tytul, tytul_oryg, gatunek, rok_wyd FROM lbcmain WHERE INFO_Ocena LIKE '%" + this->ui.lineEdit_SzFraza->text() + "%'");
					if (!ok)
					QMessageBox::information(this, "Fail Search index 16", query.lastError().text());
					break;

			}
			int x = 0;
			this->ui.tableWidget_Wyniki->setRowCount(0);
			lista_id.clear();
			while (query.next())
			{
				this->ui.tableWidget_Wyniki->insertRow(x);
				QTableWidgetItem *item = new QTableWidgetItem(query.value(1).toString());
				this->ui.tableWidget_Wyniki->setItem(x,0,item);
				QTableWidgetItem *item2 = new QTableWidgetItem(query.value(2).toString());
				this->ui.tableWidget_Wyniki->setItem(x,1,item2);
				QTableWidgetItem *item3 = new QTableWidgetItem(query.value(3).toString());
				this->ui.tableWidget_Wyniki->setItem(x,2,item3);
				QTableWidgetItem *item4 = new QTableWidgetItem(query.value(4).toString());
				this->ui.tableWidget_Wyniki->setItem(x,3,item4);
				lista_id << query.value(0).toString();
				x++;
			}
		}

	}

}

void Wyszukaj::ITEM_CLICKED(int row, int column)
{
	emit ustaw_rec(lista_id[row]);
}

