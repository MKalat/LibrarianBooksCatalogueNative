/********************************************************************************
** Form generated from reading UI file 'WyszukajHp2568.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef WYSZUKAJHP2568_H
#define WYSZUKAJHP2568_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_Wyszukaj
{
public:
    QLabel *label;
    QLineEdit *lineEdit_SzFraza;
    QComboBox *comboBox_SzPole;
    QLabel *label_2;
    QTableWidget *tableWidget_Wyniki;
    QPushButton *pushButton_Search;
    QLabel *label_3;

    void setupUi(QDialog *Wyszukaj)
    {
        if (Wyszukaj->objectName().isEmpty())
            Wyszukaj->setObjectName(QString::fromUtf8("Wyszukaj"));
        Wyszukaj->resize(487, 382);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Wyszukaj->sizePolicy().hasHeightForWidth());
        Wyszukaj->setSizePolicy(sizePolicy);
        Wyszukaj->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        Wyszukaj->setModal(true);
        label = new QLabel(Wyszukaj);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(18, 18, 46, 13));
        lineEdit_SzFraza = new QLineEdit(Wyszukaj);
        lineEdit_SzFraza->setObjectName(QString::fromUtf8("lineEdit_SzFraza"));
        lineEdit_SzFraza->setGeometry(QRect(90, 18, 355, 16));
        comboBox_SzPole = new QComboBox(Wyszukaj);
        comboBox_SzPole->setObjectName(QString::fromUtf8("comboBox_SzPole"));
        comboBox_SzPole->setGeometry(QRect(90, 54, 217, 19));
        label_2 = new QLabel(Wyszukaj);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(18, 54, 73, 16));
        tableWidget_Wyniki = new QTableWidget(Wyszukaj);
        if (tableWidget_Wyniki->columnCount() < 4)
            tableWidget_Wyniki->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget_Wyniki->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget_Wyniki->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget_Wyniki->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget_Wyniki->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        tableWidget_Wyniki->setObjectName(QString::fromUtf8("tableWidget_Wyniki"));
        tableWidget_Wyniki->setGeometry(QRect(6, 108, 475, 265));
        sizePolicy.setHeightForWidth(tableWidget_Wyniki->sizePolicy().hasHeightForWidth());
        tableWidget_Wyniki->setSizePolicy(sizePolicy);
        pushButton_Search = new QPushButton(Wyszukaj);
        pushButton_Search->setObjectName(QString::fromUtf8("pushButton_Search"));
        pushButton_Search->setGeometry(QRect(348, 58, 97, 25));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        pushButton_Search->setFont(font);
        label_3 = new QLabel(Wyszukaj);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(6, 90, 46, 13));

        retranslateUi(Wyszukaj);
        QObject::connect(tableWidget_Wyniki, SIGNAL(cellClicked(int,int)), Wyszukaj, SLOT(ITEM_CLICKED(int,int)));
        QObject::connect(pushButton_Search, SIGNAL(clicked()), Wyszukaj, SLOT(BTN_SEARCH_CLICKED()));

        QMetaObject::connectSlotsByName(Wyszukaj);
    } // setupUi

    void retranslateUi(QDialog *Wyszukaj)
    {
        Wyszukaj->setWindowTitle(QApplication::translate("Wyszukaj", "LBC - Search", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Wyszukaj", "Search", 0, QApplication::UnicodeUTF8));
        comboBox_SzPole->clear();
        comboBox_SzPole->insertItems(0, QStringList()
         << QApplication::translate("Wyszukaj", "Title", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Wyszukaj", "Original Title", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Wyszukaj", "Genre", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Wyszukaj", "Count", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Wyszukaj", "Date Published", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Wyszukaj", "Publisher", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Wyszukaj", "Published in Language", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Wyszukaj", "Description", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Wyszukaj", "Owner - Name & Lastname", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Wyszukaj", "Owner - Adress", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Wyszukaj", "Shop - Name", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Wyszukaj", "Shop - Adress", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Wyszukaj", "Shop - WWW", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Wyszukaj", "Pages Count", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Wyszukaj", "Format", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Wyszukaj", "Binding", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Wyszukaj", "Price", 0, QApplication::UnicodeUTF8)
        );
        label_2->setText(QApplication::translate("Wyszukaj", "Search in field", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = tableWidget_Wyniki->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("Wyszukaj", "Title", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget_Wyniki->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("Wyszukaj", "Orig. Title", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget_Wyniki->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("Wyszukaj", "Genre", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget_Wyniki->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("Wyszukaj", "Date Pub.", 0, QApplication::UnicodeUTF8));
        pushButton_Search->setText(QApplication::translate("Wyszukaj", "S E A R C H", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Wyszukaj", "Results", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Wyszukaj: public Ui_Wyszukaj {};
} // namespace Ui

QT_END_NAMESPACE

#endif // WYSZUKAJHP2568_H
