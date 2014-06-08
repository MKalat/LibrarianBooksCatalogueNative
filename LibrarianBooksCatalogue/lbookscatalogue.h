#ifndef LBOOKSCATALOGUE_H
#define LBOOKSCATALOGUE_H

#include <QtGui/QDialog>

#include <QTableWidgetItem>
#include <QMessageBox>
#include <QFile>
#include "ui_lbookscatalogue.h"
#include "Wyszukaj.h"
#include <stdio.h>
#include <iostream>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlError>
//#include "sqlite3.h"
//#include "data_struts.h"

class LBooksCatalogue : public QMainWindow
{
	Q_OBJECT

public:
	LBooksCatalogue(QWidget *parent = 0, Qt::WFlags flags = 0);
	~LBooksCatalogue();
	void ReadSettings();
	bool CheckDBExists();
	void CreateDB();
	void ReadStartRec();
	void ReadRec(int id, int dir);
	void UpdateDB(int id);
	void SaveRec(int id);
	void SaveSettings();
	void AddNewRec(int id);
	int GetLastId(int db);
	int last_id;
	int cur_id;
	bool new_rec_adding;
	void InsertDB(int id);
	void ClearCtrls();
	void InsertRecDB(int id, int table);
	static QStringList params_db;
	void CreateDefConf();
	void DelRec(int id);
	void DelRecDB(int id, int table);
	void CalcRecInfo();
	int FindNextId();
	int FindPrevId();
	static struct MAIN_REC main_rec;
	static struct REC_AUTH auth_rec;
	static struct REC_PUB pub_rec;
	static struct REC_BIBLIO biblio_rec;
public slots :;
	void BTN_FIRST_CLICKED();
	void BTN_PREV_CLICKED();
	void BTN_NEXT_CLICKED();
	void BTN_LAST_CLICKED();
	void BTN_NEW_CLICKED();
	void BTN_SAVE_CLICKED();
	void BTN_DEL_CLICKED();

	void BTN_A_NEW_CLICKED();
	void BTN_A_DEL_CLICKED();
	void BTN_A_SAVE_CLICKED();
	void BTN_W_NEW_CLICKED();
	void BTN_W_DEL_CLICKED();
	void BTN_W_SAVE_CLICKED();
	void BTN_B_NEW_CLICKED();
	void BTN_B_DEL_CLICKED();
	void BTN_B_SAVE_CLICKED();

	void ActionKoniec();
	void ActionSettings();
	void ActionExport();
	void ActionSearch();
	void ActionPrint();
	void ActionHelp();
	void ActionAbout();

    void SetRecAkt(QString id);
private:
	Ui::LibrarianBooksCatalogue ui;
	

};

#endif // LBOOKSCATALOGUE_H
