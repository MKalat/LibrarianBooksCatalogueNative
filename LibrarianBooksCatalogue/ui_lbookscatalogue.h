/********************************************************************************
** Form generated from reading UI file 'lbookscatalogueHp1124.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef LBOOKSCATALOGUEHP1124_H
#define LBOOKSCATALOGUEHP1124_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QTabWidget>
#include <QtGui/QTableWidget>
#include <QtGui/QTextEdit>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LibrarianBooksCatalogue
{
public:
    QAction *actionWyszukaj;
    QAction *actionUstawienia;
    QAction *actionKoniec;
    QAction *actionO_programie;
    QAction *actionPomoc;
    QWidget *centralwidget;
    QLabel *label;
    QLineEdit *lineEdit_Tytul;
    QLabel *label_2;
    QLineEdit *lineEdit_TytulOryg;
    QLabel *label_3;
    QLineEdit *lineEdit_Gatunek;
    QLabel *label_8;
    QLineEdit *lineEdit_Count;
    QLabel *label_10;
    QLineEdit *lineEdit_DatePub;
    QLabel *label_20;
    QLineEdit *lineEdit_Publisher;
    QLabel *label_21;
    QLineEdit *lineEdit_PubLang;
    QTabWidget *tabWidget;
    QWidget *TAB_OPIS;
    QTextEdit *textEdit_Opis;
    QLabel *label_6;
    QTableWidget *tableWidget_Autorzy;
    QLabel *label_7;
    QPushButton *pushButton_AUT_USUN;
    QPushButton *pushButton_AUT_NOWY;
    QLabel *label_9;
    QTableWidget *tableWidget_Wydania;
    QPushButton *pushButton_WYD_NOWY;
    QPushButton *pushButton_WYD_USUN;
    QPushButton *pushButton;
    QPushButton *pushButton_PUB_SAVE;
    QWidget *TAB_INFO;
    QGroupBox *groupBox;
    QLabel *label_11;
    QLineEdit *lineEdit_WL_Imienazw;
    QLabel *label_12;
    QLineEdit *lineEdit_WL_Adres;
    QGroupBox *groupBox_2;
    QLabel *label_14;
    QLineEdit *lineEdit_MZ_Nazwa;
    QLabel *label_15;
    QLineEdit *lineEdit__MZ_Adres;
    QLabel *label_16;
    QLineEdit *lineEdit_MZ_WWW;
    QGroupBox *groupBox_3;
    QLabel *label_22;
    QLabel *label_25;
    QLabel *label_26;
    QLabel *label_27;
    QLineEdit *lineEdit_INFO_PageCount;
    QLineEdit *lineEdit_INFO_Format;
    QLineEdit *lineEdit_INFO_Oprawa;
    QLineEdit *lineEdit_INFO_Cena;
    QWidget *TAB_BIBLIO;
    QLabel *label_29;
    QTableWidget *tableWidget_BIBLIO_WypoIN;
    QPushButton *pushButton_BIBLIO_Nowy;
    QPushButton *pushButton_BIBLIO_USUN;
    QPushButton *pushButton_B_SAVE;
    QLabel *label_4;
    QLineEdit *lineEdit__RecNo;
    QLabel *label_5;
    QLineEdit *lineEdit_RecCount;
    QPushButton *pushButton_FIRST;
    QPushButton *pushButton_PREV;
    QPushButton *pushButton_NEXT;
    QPushButton *pushButton_LAST;
    QPushButton *pushButton_NEW;
    QPushButton *pushButton_SAVE;
    QPushButton *pushButton_DEL;
    QMenuBar *menubar;
    QMenu *menuPlik;
    QMenu *menuPomoc;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *LibrarianBooksCatalogue)
    {
        if (LibrarianBooksCatalogue->objectName().isEmpty())
            LibrarianBooksCatalogue->setObjectName(QString::fromUtf8("LibrarianBooksCatalogue"));
        LibrarianBooksCatalogue->resize(768, 766);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(LibrarianBooksCatalogue->sizePolicy().hasHeightForWidth());
        LibrarianBooksCatalogue->setSizePolicy(sizePolicy);
        LibrarianBooksCatalogue->setMaximumSize(QSize(768, 766));
        LibrarianBooksCatalogue->setContextMenuPolicy(Qt::DefaultContextMenu);
        LibrarianBooksCatalogue->setAnimated(false);
        actionWyszukaj = new QAction(LibrarianBooksCatalogue);
        actionWyszukaj->setObjectName(QString::fromUtf8("actionWyszukaj"));
        actionUstawienia = new QAction(LibrarianBooksCatalogue);
        actionUstawienia->setObjectName(QString::fromUtf8("actionUstawienia"));
        actionKoniec = new QAction(LibrarianBooksCatalogue);
        actionKoniec->setObjectName(QString::fromUtf8("actionKoniec"));
        actionO_programie = new QAction(LibrarianBooksCatalogue);
        actionO_programie->setObjectName(QString::fromUtf8("actionO_programie"));
        actionPomoc = new QAction(LibrarianBooksCatalogue);
        actionPomoc->setObjectName(QString::fromUtf8("actionPomoc"));
        centralwidget = new QWidget(LibrarianBooksCatalogue);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(6, 6, 46, 13));
        lineEdit_Tytul = new QLineEdit(centralwidget);
        lineEdit_Tytul->setObjectName(QString::fromUtf8("lineEdit_Tytul"));
        lineEdit_Tytul->setGeometry(QRect(90, 6, 307, 16));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(6, 24, 85, 16));
        lineEdit_TytulOryg = new QLineEdit(centralwidget);
        lineEdit_TytulOryg->setObjectName(QString::fromUtf8("lineEdit_TytulOryg"));
        lineEdit_TytulOryg->setGeometry(QRect(90, 24, 307, 16));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(6, 42, 46, 13));
        lineEdit_Gatunek = new QLineEdit(centralwidget);
        lineEdit_Gatunek->setObjectName(QString::fromUtf8("lineEdit_Gatunek"));
        lineEdit_Gatunek->setGeometry(QRect(90, 42, 259, 16));
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(6, 60, 46, 13));
        lineEdit_Count = new QLineEdit(centralwidget);
        lineEdit_Count->setObjectName(QString::fromUtf8("lineEdit_Count"));
        lineEdit_Count->setGeometry(QRect(90, 60, 79, 16));
        label_10 = new QLabel(centralwidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(450, 6, 73, 16));
        lineEdit_DatePub = new QLineEdit(centralwidget);
        lineEdit_DatePub->setObjectName(QString::fromUtf8("lineEdit_DatePub"));
        lineEdit_DatePub->setGeometry(QRect(522, 6, 79, 16));
        label_20 = new QLabel(centralwidget);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setGeometry(QRect(450, 24, 73, 16));
        lineEdit_Publisher = new QLineEdit(centralwidget);
        lineEdit_Publisher->setObjectName(QString::fromUtf8("lineEdit_Publisher"));
        lineEdit_Publisher->setGeometry(QRect(522, 24, 211, 16));
        label_21 = new QLabel(centralwidget);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setGeometry(QRect(450, 42, 79, 16));
        lineEdit_PubLang = new QLineEdit(centralwidget);
        lineEdit_PubLang->setObjectName(QString::fromUtf8("lineEdit_PubLang"));
        lineEdit_PubLang->setGeometry(QRect(522, 42, 211, 16));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(6, 84, 751, 577));
        tabWidget->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        TAB_OPIS = new QWidget();
        TAB_OPIS->setObjectName(QString::fromUtf8("TAB_OPIS"));
        textEdit_Opis = new QTextEdit(TAB_OPIS);
        textEdit_Opis->setObjectName(QString::fromUtf8("textEdit_Opis"));
        textEdit_Opis->setGeometry(QRect(7, 24, 733, 115));
        textEdit_Opis->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        textEdit_Opis->setUndoRedoEnabled(false);
        textEdit_Opis->setAcceptRichText(false);
        label_6 = new QLabel(TAB_OPIS);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(6, 6, 49, 16));
        tableWidget_Autorzy = new QTableWidget(TAB_OPIS);
        if (tableWidget_Autorzy->columnCount() < 6)
            tableWidget_Autorzy->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget_Autorzy->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget_Autorzy->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget_Autorzy->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget_Autorzy->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget_Autorzy->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget_Autorzy->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        tableWidget_Autorzy->setObjectName(QString::fromUtf8("tableWidget_Autorzy"));
        tableWidget_Autorzy->setGeometry(QRect(6, 156, 733, 151));
        tableWidget_Autorzy->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableWidget_Autorzy->setCornerButtonEnabled(true);
        tableWidget_Autorzy->horizontalHeader()->setDefaultSectionSize(100);
        label_7 = new QLabel(TAB_OPIS);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(6, 144, 46, 13));
        pushButton_AUT_USUN = new QPushButton(TAB_OPIS);
        pushButton_AUT_USUN->setObjectName(QString::fromUtf8("pushButton_AUT_USUN"));
        pushButton_AUT_USUN->setGeometry(QRect(666, 306, 75, 23));
        pushButton_AUT_NOWY = new QPushButton(TAB_OPIS);
        pushButton_AUT_NOWY->setObjectName(QString::fromUtf8("pushButton_AUT_NOWY"));
        pushButton_AUT_NOWY->setGeometry(QRect(8, 308, 75, 23));
        label_9 = new QLabel(TAB_OPIS);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(6, 330, 46, 13));
        tableWidget_Wydania = new QTableWidget(TAB_OPIS);
        if (tableWidget_Wydania->columnCount() < 7)
            tableWidget_Wydania->setColumnCount(7);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget_Wydania->setHorizontalHeaderItem(0, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget_Wydania->setHorizontalHeaderItem(1, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget_Wydania->setHorizontalHeaderItem(2, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget_Wydania->setHorizontalHeaderItem(3, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidget_Wydania->setHorizontalHeaderItem(4, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableWidget_Wydania->setHorizontalHeaderItem(5, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tableWidget_Wydania->setHorizontalHeaderItem(6, __qtablewidgetitem12);
        tableWidget_Wydania->setObjectName(QString::fromUtf8("tableWidget_Wydania"));
        tableWidget_Wydania->setGeometry(QRect(6, 342, 733, 169));
        tableWidget_Wydania->setMinimumSize(QSize(733, 0));
        tableWidget_Wydania->setProperty("showDropIndicator", QVariant(false));
        tableWidget_Wydania->setDragDropOverwriteMode(true);
        tableWidget_Wydania->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableWidget_Wydania->horizontalHeader()->setDefaultSectionSize(100);
        pushButton_WYD_NOWY = new QPushButton(TAB_OPIS);
        pushButton_WYD_NOWY->setObjectName(QString::fromUtf8("pushButton_WYD_NOWY"));
        pushButton_WYD_NOWY->setGeometry(QRect(8, 512, 75, 23));
        pushButton_WYD_USUN = new QPushButton(TAB_OPIS);
        pushButton_WYD_USUN->setObjectName(QString::fromUtf8("pushButton_WYD_USUN"));
        pushButton_WYD_USUN->setGeometry(QRect(666, 510, 75, 23));
        pushButton = new QPushButton(TAB_OPIS);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(84, 308, 75, 23));
        pushButton_PUB_SAVE = new QPushButton(TAB_OPIS);
        pushButton_PUB_SAVE->setObjectName(QString::fromUtf8("pushButton_PUB_SAVE"));
        pushButton_PUB_SAVE->setGeometry(QRect(84, 512, 75, 23));
        tabWidget->addTab(TAB_OPIS, QString());
        TAB_INFO = new QWidget();
        TAB_INFO->setObjectName(QString::fromUtf8("TAB_INFO"));
        groupBox = new QGroupBox(TAB_INFO);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(6, 6, 733, 67));
        label_11 = new QLabel(groupBox);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(12, 18, 91, 16));
        lineEdit_WL_Imienazw = new QLineEdit(groupBox);
        lineEdit_WL_Imienazw->setObjectName(QString::fromUtf8("lineEdit_WL_Imienazw"));
        lineEdit_WL_Imienazw->setGeometry(QRect(102, 18, 253, 16));
        label_12 = new QLabel(groupBox);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(360, 18, 46, 13));
        lineEdit_WL_Adres = new QLineEdit(groupBox);
        lineEdit_WL_Adres->setObjectName(QString::fromUtf8("lineEdit_WL_Adres"));
        lineEdit_WL_Adres->setGeometry(QRect(396, 18, 319, 16));
        groupBox_2 = new QGroupBox(TAB_INFO);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(6, 84, 379, 79));
        label_14 = new QLabel(groupBox_2);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(12, 18, 46, 13));
        lineEdit_MZ_Nazwa = new QLineEdit(groupBox_2);
        lineEdit_MZ_Nazwa->setObjectName(QString::fromUtf8("lineEdit_MZ_Nazwa"));
        lineEdit_MZ_Nazwa->setGeometry(QRect(60, 18, 307, 16));
        label_15 = new QLabel(groupBox_2);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(12, 36, 37, 16));
        lineEdit__MZ_Adres = new QLineEdit(groupBox_2);
        lineEdit__MZ_Adres->setObjectName(QString::fromUtf8("lineEdit__MZ_Adres"));
        lineEdit__MZ_Adres->setGeometry(QRect(60, 36, 307, 16));
        label_16 = new QLabel(groupBox_2);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(12, 54, 46, 13));
        lineEdit_MZ_WWW = new QLineEdit(groupBox_2);
        lineEdit_MZ_WWW->setObjectName(QString::fromUtf8("lineEdit_MZ_WWW"));
        lineEdit_MZ_WWW->setGeometry(QRect(60, 54, 307, 16));
        groupBox_3 = new QGroupBox(TAB_INFO);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(396, 84, 343, 97));
        label_22 = new QLabel(groupBox_3);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setGeometry(QRect(12, 72, 46, 16));
        label_25 = new QLabel(groupBox_3);
        label_25->setObjectName(QString::fromUtf8("label_25"));
        label_25->setGeometry(QRect(12, 18, 61, 16));
        label_26 = new QLabel(groupBox_3);
        label_26->setObjectName(QString::fromUtf8("label_26"));
        label_26->setGeometry(QRect(12, 36, 46, 13));
        label_27 = new QLabel(groupBox_3);
        label_27->setObjectName(QString::fromUtf8("label_27"));
        label_27->setGeometry(QRect(12, 54, 46, 13));
        lineEdit_INFO_PageCount = new QLineEdit(groupBox_3);
        lineEdit_INFO_PageCount->setObjectName(QString::fromUtf8("lineEdit_INFO_PageCount"));
        lineEdit_INFO_PageCount->setGeometry(QRect(114, 18, 55, 16));
        lineEdit_INFO_Format = new QLineEdit(groupBox_3);
        lineEdit_INFO_Format->setObjectName(QString::fromUtf8("lineEdit_INFO_Format"));
        lineEdit_INFO_Format->setGeometry(QRect(114, 36, 55, 16));
        lineEdit_INFO_Oprawa = new QLineEdit(groupBox_3);
        lineEdit_INFO_Oprawa->setObjectName(QString::fromUtf8("lineEdit_INFO_Oprawa"));
        lineEdit_INFO_Oprawa->setGeometry(QRect(114, 54, 113, 16));
        lineEdit_INFO_Cena = new QLineEdit(groupBox_3);
        lineEdit_INFO_Cena->setObjectName(QString::fromUtf8("lineEdit_INFO_Cena"));
        lineEdit_INFO_Cena->setGeometry(QRect(114, 72, 55, 16));
        tabWidget->addTab(TAB_INFO, QString());
        TAB_BIBLIO = new QWidget();
        TAB_BIBLIO->setObjectName(QString::fromUtf8("TAB_BIBLIO"));
        label_29 = new QLabel(TAB_BIBLIO);
        label_29->setObjectName(QString::fromUtf8("label_29"));
        label_29->setGeometry(QRect(6, 6, 79, 16));
        tableWidget_BIBLIO_WypoIN = new QTableWidget(TAB_BIBLIO);
        if (tableWidget_BIBLIO_WypoIN->columnCount() < 7)
            tableWidget_BIBLIO_WypoIN->setColumnCount(7);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tableWidget_BIBLIO_WypoIN->setHorizontalHeaderItem(0, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        tableWidget_BIBLIO_WypoIN->setHorizontalHeaderItem(1, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        tableWidget_BIBLIO_WypoIN->setHorizontalHeaderItem(2, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        tableWidget_BIBLIO_WypoIN->setHorizontalHeaderItem(3, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        tableWidget_BIBLIO_WypoIN->setHorizontalHeaderItem(4, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        tableWidget_BIBLIO_WypoIN->setHorizontalHeaderItem(5, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        tableWidget_BIBLIO_WypoIN->setHorizontalHeaderItem(6, __qtablewidgetitem19);
        tableWidget_BIBLIO_WypoIN->setObjectName(QString::fromUtf8("tableWidget_BIBLIO_WypoIN"));
        tableWidget_BIBLIO_WypoIN->setGeometry(QRect(6, 24, 733, 487));
        sizePolicy.setHeightForWidth(tableWidget_BIBLIO_WypoIN->sizePolicy().hasHeightForWidth());
        tableWidget_BIBLIO_WypoIN->setSizePolicy(sizePolicy);
        tableWidget_BIBLIO_WypoIN->setEditTriggers(QAbstractItemView::DoubleClicked|QAbstractItemView::EditKeyPressed);
        tableWidget_BIBLIO_WypoIN->setProperty("showDropIndicator", QVariant(false));
        tableWidget_BIBLIO_WypoIN->setDragDropOverwriteMode(false);
        tableWidget_BIBLIO_WypoIN->setAlternatingRowColors(true);
        tableWidget_BIBLIO_WypoIN->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableWidget_BIBLIO_WypoIN->horizontalHeader()->setDefaultSectionSize(150);
        pushButton_BIBLIO_Nowy = new QPushButton(TAB_BIBLIO);
        pushButton_BIBLIO_Nowy->setObjectName(QString::fromUtf8("pushButton_BIBLIO_Nowy"));
        pushButton_BIBLIO_Nowy->setGeometry(QRect(8, 512, 75, 23));
        pushButton_BIBLIO_USUN = new QPushButton(TAB_BIBLIO);
        pushButton_BIBLIO_USUN->setObjectName(QString::fromUtf8("pushButton_BIBLIO_USUN"));
        pushButton_BIBLIO_USUN->setGeometry(QRect(666, 510, 75, 23));
        pushButton_B_SAVE = new QPushButton(TAB_BIBLIO);
        pushButton_B_SAVE->setObjectName(QString::fromUtf8("pushButton_B_SAVE"));
        pushButton_B_SAVE->setGeometry(QRect(84, 512, 75, 23));
        tabWidget->addTab(TAB_BIBLIO, QString());
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(12, 666, 43, 16));
        lineEdit__RecNo = new QLineEdit(centralwidget);
        lineEdit__RecNo->setObjectName(QString::fromUtf8("lineEdit__RecNo"));
        lineEdit__RecNo->setGeometry(QRect(48, 666, 31, 16));
        sizePolicy.setHeightForWidth(lineEdit__RecNo->sizePolicy().hasHeightForWidth());
        lineEdit__RecNo->setSizePolicy(sizePolicy);
        lineEdit__RecNo->setContextMenuPolicy(Qt::NoContextMenu);
        lineEdit__RecNo->setAcceptDrops(false);
        lineEdit__RecNo->setReadOnly(true);
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(84, 666, 16, 16));
        lineEdit_RecCount = new QLineEdit(centralwidget);
        lineEdit_RecCount->setObjectName(QString::fromUtf8("lineEdit_RecCount"));
        lineEdit_RecCount->setGeometry(QRect(102, 666, 31, 16));
        sizePolicy.setHeightForWidth(lineEdit_RecCount->sizePolicy().hasHeightForWidth());
        lineEdit_RecCount->setSizePolicy(sizePolicy);
        lineEdit_RecCount->setAcceptDrops(false);
        lineEdit_RecCount->setReadOnly(true);
        pushButton_FIRST = new QPushButton(centralwidget);
        pushButton_FIRST->setObjectName(QString::fromUtf8("pushButton_FIRST"));
        pushButton_FIRST->setGeometry(QRect(6, 684, 55, 31));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        pushButton_FIRST->setFont(font);
        pushButton_FIRST->setAutoDefault(false);
        pushButton_FIRST->setDefault(false);
        pushButton_FIRST->setFlat(false);
        pushButton_PREV = new QPushButton(centralwidget);
        pushButton_PREV->setObjectName(QString::fromUtf8("pushButton_PREV"));
        pushButton_PREV->setGeometry(QRect(66, 684, 43, 31));
        pushButton_PREV->setFont(font);
        pushButton_NEXT = new QPushButton(centralwidget);
        pushButton_NEXT->setObjectName(QString::fromUtf8("pushButton_NEXT"));
        pushButton_NEXT->setGeometry(QRect(114, 684, 43, 31));
        pushButton_NEXT->setFont(font);
        pushButton_LAST = new QPushButton(centralwidget);
        pushButton_LAST->setObjectName(QString::fromUtf8("pushButton_LAST"));
        pushButton_LAST->setGeometry(QRect(162, 684, 55, 31));
        pushButton_LAST->setFont(font);
        pushButton_NEW = new QPushButton(centralwidget);
        pushButton_NEW->setObjectName(QString::fromUtf8("pushButton_NEW"));
        pushButton_NEW->setGeometry(QRect(246, 684, 75, 31));
        pushButton_NEW->setFont(font);
        pushButton_SAVE = new QPushButton(centralwidget);
        pushButton_SAVE->setObjectName(QString::fromUtf8("pushButton_SAVE"));
        pushButton_SAVE->setGeometry(QRect(330, 684, 75, 31));
        pushButton_SAVE->setFont(font);
        pushButton_DEL = new QPushButton(centralwidget);
        pushButton_DEL->setObjectName(QString::fromUtf8("pushButton_DEL"));
        pushButton_DEL->setGeometry(QRect(432, 684, 79, 31));
        pushButton_DEL->setFont(font);
        pushButton_DEL->setStyleSheet(QString::fromUtf8(""));
        LibrarianBooksCatalogue->setCentralWidget(centralwidget);
        menubar = new QMenuBar(LibrarianBooksCatalogue);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 768, 21));
        menuPlik = new QMenu(menubar);
        menuPlik->setObjectName(QString::fromUtf8("menuPlik"));
        menuPomoc = new QMenu(menubar);
        menuPomoc->setObjectName(QString::fromUtf8("menuPomoc"));
        LibrarianBooksCatalogue->setMenuBar(menubar);
        statusbar = new QStatusBar(LibrarianBooksCatalogue);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        statusbar->setEnabled(true);
        statusbar->setSizeGripEnabled(false);
        LibrarianBooksCatalogue->setStatusBar(statusbar);

        menubar->addAction(menuPlik->menuAction());
        menubar->addAction(menuPomoc->menuAction());
        menuPlik->addAction(actionWyszukaj);
        menuPlik->addAction(actionUstawienia);
        menuPlik->addAction(actionKoniec);
        menuPomoc->addAction(actionO_programie);
        menuPomoc->addAction(actionPomoc);

        retranslateUi(LibrarianBooksCatalogue);
        QObject::connect(pushButton_FIRST, SIGNAL(clicked()), LibrarianBooksCatalogue, SLOT(BTN_FIRST_CLICKED()));
        QObject::connect(pushButton_PREV, SIGNAL(clicked()), LibrarianBooksCatalogue, SLOT(BTN_PREV_CLICKED()));
        QObject::connect(pushButton_NEXT, SIGNAL(clicked()), LibrarianBooksCatalogue, SLOT(BTN_NEXT_CLICKED()));
        QObject::connect(pushButton_LAST, SIGNAL(clicked()), LibrarianBooksCatalogue, SLOT(BTN_LAST_CLICKED()));
        QObject::connect(pushButton_NEW, SIGNAL(clicked()), LibrarianBooksCatalogue, SLOT(BTN_NEW_CLICKED()));
        QObject::connect(pushButton_SAVE, SIGNAL(clicked()), LibrarianBooksCatalogue, SLOT(BTN_SAVE_CLICKED()));
        QObject::connect(pushButton_DEL, SIGNAL(clicked()), LibrarianBooksCatalogue, SLOT(BTN_DEL_CLICKED()));
        QObject::connect(pushButton_AUT_NOWY, SIGNAL(clicked()), LibrarianBooksCatalogue, SLOT(BTN_A_NEW_CLICKED()));
        QObject::connect(pushButton_AUT_USUN, SIGNAL(clicked()), LibrarianBooksCatalogue, SLOT(BTN_A_DEL_CLICKED()));
        QObject::connect(pushButton_WYD_NOWY, SIGNAL(clicked()), LibrarianBooksCatalogue, SLOT(BTN_W_NEW_CLICKED()));
        QObject::connect(pushButton_WYD_USUN, SIGNAL(clicked()), LibrarianBooksCatalogue, SLOT(BTN_W_DEL_CLICKED()));
        QObject::connect(pushButton_BIBLIO_Nowy, SIGNAL(clicked()), LibrarianBooksCatalogue, SLOT(BTN_B_NEW_CLICKED()));
        QObject::connect(pushButton_BIBLIO_USUN, SIGNAL(clicked()), LibrarianBooksCatalogue, SLOT(BTN_B_DEL_CLICKED()));
        QObject::connect(pushButton, SIGNAL(clicked()), LibrarianBooksCatalogue, SLOT(BTN_A_SAVE_CLICKED()));
        QObject::connect(pushButton_PUB_SAVE, SIGNAL(clicked()), LibrarianBooksCatalogue, SLOT(BTN_W_SAVE_CLICKED()));
        QObject::connect(pushButton_B_SAVE, SIGNAL(clicked()), LibrarianBooksCatalogue, SLOT(BTN_B_SAVE_CLICKED()));
        QObject::connect(actionKoniec, SIGNAL(triggered()), LibrarianBooksCatalogue, SLOT(ActionKoniec()));
        QObject::connect(actionWyszukaj, SIGNAL(triggered()), LibrarianBooksCatalogue, SLOT(ActionSearch()));
        QObject::connect(actionO_programie, SIGNAL(triggered()), LibrarianBooksCatalogue, SLOT(ActionAbout()));
        QObject::connect(actionUstawienia, SIGNAL(triggered()), LibrarianBooksCatalogue, SLOT(ActionSettings()));
        QObject::connect(actionPomoc, SIGNAL(triggered()), LibrarianBooksCatalogue, SLOT(ActionHelp()));
        QObject::connect(LibrarianBooksCatalogue, SIGNAL(ustaw_rec(QString)), LibrarianBooksCatalogue, SLOT(SetRecAkt(QString)));

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(LibrarianBooksCatalogue);
    } // setupUi

    void retranslateUi(QMainWindow *LibrarianBooksCatalogue)
    {
        LibrarianBooksCatalogue->setWindowTitle(QApplication::translate("LibrarianBooksCatalogue", "Librarian Books Catalogue", 0, QApplication::UnicodeUTF8));
        actionWyszukaj->setText(QApplication::translate("LibrarianBooksCatalogue", "Search", 0, QApplication::UnicodeUTF8));
        actionUstawienia->setText(QApplication::translate("LibrarianBooksCatalogue", "Settings", 0, QApplication::UnicodeUTF8));
        actionKoniec->setText(QApplication::translate("LibrarianBooksCatalogue", "Exit", 0, QApplication::UnicodeUTF8));
        actionO_programie->setText(QApplication::translate("LibrarianBooksCatalogue", "About", 0, QApplication::UnicodeUTF8));
        actionPomoc->setText(QApplication::translate("LibrarianBooksCatalogue", "Help", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("LibrarianBooksCatalogue", "Title", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("LibrarianBooksCatalogue", "Orig. title", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("LibrarianBooksCatalogue", "Genre", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("LibrarianBooksCatalogue", "Amount", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("LibrarianBooksCatalogue", "Date Pub.", 0, QApplication::UnicodeUTF8));
        label_20->setText(QApplication::translate("LibrarianBooksCatalogue", "Publisher", 0, QApplication::UnicodeUTF8));
        label_21->setText(QApplication::translate("LibrarianBooksCatalogue", "Pub. Lang.", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("LibrarianBooksCatalogue", "Decription", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = tableWidget_Autorzy->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("LibrarianBooksCatalogue", "ID", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget_Autorzy->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("LibrarianBooksCatalogue", "IDM", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget_Autorzy->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("LibrarianBooksCatalogue", "Name & Lastname", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget_Autorzy->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("LibrarianBooksCatalogue", "Nationality", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget_Autorzy->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("LibrarianBooksCatalogue", "Interests", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget_Autorzy->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("LibrarianBooksCatalogue", "Chapters", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("LibrarianBooksCatalogue", "Authors", 0, QApplication::UnicodeUTF8));
        pushButton_AUT_USUN->setText(QApplication::translate("LibrarianBooksCatalogue", "Delete", 0, QApplication::UnicodeUTF8));
        pushButton_AUT_NOWY->setText(QApplication::translate("LibrarianBooksCatalogue", "New", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("LibrarianBooksCatalogue", "Editions", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget_Wydania->horizontalHeaderItem(0);
        ___qtablewidgetitem6->setText(QApplication::translate("LibrarianBooksCatalogue", "ID", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget_Wydania->horizontalHeaderItem(1);
        ___qtablewidgetitem7->setText(QApplication::translate("LibrarianBooksCatalogue", "IDM", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget_Wydania->horizontalHeaderItem(2);
        ___qtablewidgetitem8->setText(QApplication::translate("LibrarianBooksCatalogue", "Date Pub.", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget_Wydania->horizontalHeaderItem(3);
        ___qtablewidgetitem9->setText(QApplication::translate("LibrarianBooksCatalogue", "Publisher", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget_Wydania->horizontalHeaderItem(4);
        ___qtablewidgetitem10->setText(QApplication::translate("LibrarianBooksCatalogue", "Pub. Lang.", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidget_Wydania->horizontalHeaderItem(5);
        ___qtablewidgetitem11->setText(QApplication::translate("LibrarianBooksCatalogue", "Edition No.", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem12 = tableWidget_Wydania->horizontalHeaderItem(6);
        ___qtablewidgetitem12->setText(QApplication::translate("LibrarianBooksCatalogue", "Edition Country", 0, QApplication::UnicodeUTF8));
        pushButton_WYD_NOWY->setText(QApplication::translate("LibrarianBooksCatalogue", "New", 0, QApplication::UnicodeUTF8));
        pushButton_WYD_USUN->setText(QApplication::translate("LibrarianBooksCatalogue", "Delete", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("LibrarianBooksCatalogue", "Save", 0, QApplication::UnicodeUTF8));
        pushButton_PUB_SAVE->setText(QApplication::translate("LibrarianBooksCatalogue", "Save", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(TAB_OPIS), QApplication::translate("LibrarianBooksCatalogue", "Description", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("LibrarianBooksCatalogue", "Owner Data", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("LibrarianBooksCatalogue", "Name & Lastname", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("LibrarianBooksCatalogue", "Adress", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("LibrarianBooksCatalogue", "Shop Data", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("LibrarianBooksCatalogue", "Name", 0, QApplication::UnicodeUTF8));
        label_15->setText(QApplication::translate("LibrarianBooksCatalogue", "Adress", 0, QApplication::UnicodeUTF8));
        label_16->setText(QApplication::translate("LibrarianBooksCatalogue", "WWW", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("LibrarianBooksCatalogue", "Additional Info", 0, QApplication::UnicodeUTF8));
        label_22->setText(QApplication::translate("LibrarianBooksCatalogue", "Price", 0, QApplication::UnicodeUTF8));
        label_25->setText(QApplication::translate("LibrarianBooksCatalogue", "Pages count", 0, QApplication::UnicodeUTF8));
        label_26->setText(QApplication::translate("LibrarianBooksCatalogue", "Format", 0, QApplication::UnicodeUTF8));
        label_27->setText(QApplication::translate("LibrarianBooksCatalogue", "Binding", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(TAB_INFO), QApplication::translate("LibrarianBooksCatalogue", "Info", 0, QApplication::UnicodeUTF8));
        label_29->setText(QApplication::translate("LibrarianBooksCatalogue", "Borrows", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem13 = tableWidget_BIBLIO_WypoIN->horizontalHeaderItem(0);
        ___qtablewidgetitem13->setText(QApplication::translate("LibrarianBooksCatalogue", "ID", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem14 = tableWidget_BIBLIO_WypoIN->horizontalHeaderItem(1);
        ___qtablewidgetitem14->setText(QApplication::translate("LibrarianBooksCatalogue", "IDM", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem15 = tableWidget_BIBLIO_WypoIN->horizontalHeaderItem(2);
        ___qtablewidgetitem15->setText(QApplication::translate("LibrarianBooksCatalogue", "Person", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem16 = tableWidget_BIBLIO_WypoIN->horizontalHeaderItem(3);
        ___qtablewidgetitem16->setText(QApplication::translate("LibrarianBooksCatalogue", "Date borrowed", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem17 = tableWidget_BIBLIO_WypoIN->horizontalHeaderItem(4);
        ___qtablewidgetitem17->setText(QApplication::translate("LibrarianBooksCatalogue", "Date of return", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem18 = tableWidget_BIBLIO_WypoIN->horizontalHeaderItem(5);
        ___qtablewidgetitem18->setText(QApplication::translate("LibrarianBooksCatalogue", "Condition before borrowing", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem19 = tableWidget_BIBLIO_WypoIN->horizontalHeaderItem(6);
        ___qtablewidgetitem19->setText(QApplication::translate("LibrarianBooksCatalogue", "Condition after return", 0, QApplication::UnicodeUTF8));
        pushButton_BIBLIO_Nowy->setText(QApplication::translate("LibrarianBooksCatalogue", "New", 0, QApplication::UnicodeUTF8));
        pushButton_BIBLIO_USUN->setText(QApplication::translate("LibrarianBooksCatalogue", "Delete", 0, QApplication::UnicodeUTF8));
        pushButton_B_SAVE->setText(QApplication::translate("LibrarianBooksCatalogue", "Save", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(TAB_BIBLIO), QApplication::translate("LibrarianBooksCatalogue", "Librarian", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("LibrarianBooksCatalogue", "Record", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("LibrarianBooksCatalogue", "of", 0, QApplication::UnicodeUTF8));
        pushButton_FIRST->setText(QApplication::translate("LibrarianBooksCatalogue", "|<", "|<", QApplication::UnicodeUTF8));
        pushButton_PREV->setText(QApplication::translate("LibrarianBooksCatalogue", "<", 0, QApplication::UnicodeUTF8));
        pushButton_NEXT->setText(QApplication::translate("LibrarianBooksCatalogue", ">", 0, QApplication::UnicodeUTF8));
        pushButton_LAST->setText(QApplication::translate("LibrarianBooksCatalogue", ">|", 0, QApplication::UnicodeUTF8));
        pushButton_NEW->setText(QApplication::translate("LibrarianBooksCatalogue", "New", 0, QApplication::UnicodeUTF8));
        pushButton_SAVE->setText(QApplication::translate("LibrarianBooksCatalogue", "Save", 0, QApplication::UnicodeUTF8));
        pushButton_DEL->setText(QApplication::translate("LibrarianBooksCatalogue", "Delete", 0, QApplication::UnicodeUTF8));
        menuPlik->setTitle(QApplication::translate("LibrarianBooksCatalogue", "File", 0, QApplication::UnicodeUTF8));
        menuPomoc->setTitle(QApplication::translate("LibrarianBooksCatalogue", "Help", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class LibrarianBooksCatalogue: public Ui_LibrarianBooksCatalogue {};
} // namespace Ui

QT_END_NAMESPACE

#endif // LBOOKSCATALOGUEHP1124_H
