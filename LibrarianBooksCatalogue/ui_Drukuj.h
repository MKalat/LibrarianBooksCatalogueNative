/********************************************************************************
** Form generated from reading UI file 'DrukujGg3268.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef DRUKUJGG3268_H
#define DRUKUJGG3268_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDialog>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>

QT_BEGIN_NAMESPACE

class Ui_Drukuj
{
public:
    QGroupBox *groupBox;
    QRadioButton *radioButton_ALL;
    QRadioButton *radioButton_CUR;
    QGroupBox *groupBox_2;
    QCheckBox *checkBox_BASIC;
    QCheckBox *checkBox_BORROWS;
    QCheckBox *checkBox_AUTHORS;
    QCheckBox *checkBox_PUBS;
    QPushButton *pushButton_CANCEL;
    QPushButton *pushButton_PRINT;

    void setupUi(QDialog *Drukuj)
    {
        if (Drukuj->objectName().isEmpty())
            Drukuj->setObjectName(QString::fromUtf8("Drukuj"));
        Drukuj->resize(410, 258);
        groupBox = new QGroupBox(Drukuj);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(12, 12, 389, 80));
        radioButton_ALL = new QRadioButton(groupBox);
        radioButton_ALL->setObjectName(QString::fromUtf8("radioButton_ALL"));
        radioButton_ALL->setGeometry(QRect(24, 28, 82, 17));
        radioButton_CUR = new QRadioButton(groupBox);
        radioButton_CUR->setObjectName(QString::fromUtf8("radioButton_CUR"));
        radioButton_CUR->setGeometry(QRect(260, 28, 101, 17));
        groupBox_2 = new QGroupBox(Drukuj);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(12, 100, 389, 113));
        checkBox_BASIC = new QCheckBox(groupBox_2);
        checkBox_BASIC->setObjectName(QString::fromUtf8("checkBox_BASIC"));
        checkBox_BASIC->setGeometry(QRect(12, 28, 121, 17));
        checkBox_BORROWS = new QCheckBox(groupBox_2);
        checkBox_BORROWS->setObjectName(QString::fromUtf8("checkBox_BORROWS"));
        checkBox_BORROWS->setGeometry(QRect(12, 48, 109, 17));
        checkBox_AUTHORS = new QCheckBox(groupBox_2);
        checkBox_AUTHORS->setObjectName(QString::fromUtf8("checkBox_AUTHORS"));
        checkBox_AUTHORS->setGeometry(QRect(12, 68, 70, 17));
        checkBox_PUBS = new QCheckBox(groupBox_2);
        checkBox_PUBS->setObjectName(QString::fromUtf8("checkBox_PUBS"));
        checkBox_PUBS->setGeometry(QRect(12, 88, 77, 17));
        pushButton_CANCEL = new QPushButton(Drukuj);
        pushButton_CANCEL->setObjectName(QString::fromUtf8("pushButton_CANCEL"));
        pushButton_CANCEL->setGeometry(QRect(324, 220, 75, 23));
        pushButton_PRINT = new QPushButton(Drukuj);
        pushButton_PRINT->setObjectName(QString::fromUtf8("pushButton_PRINT"));
        pushButton_PRINT->setGeometry(QRect(244, 220, 75, 23));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        pushButton_PRINT->setFont(font);

        retranslateUi(Drukuj);

        QMetaObject::connectSlotsByName(Drukuj);
    } // setupUi

    void retranslateUi(QDialog *Drukuj)
    {
        Drukuj->setWindowTitle(QApplication::translate("Drukuj", "LBC - Drukuj", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("Drukuj", "Select how many book records to print", 0, QApplication::UnicodeUTF8));
        radioButton_ALL->setText(QApplication::translate("Drukuj", "All", 0, QApplication::UnicodeUTF8));
        radioButton_CUR->setText(QApplication::translate("Drukuj", "Current record", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("Drukuj", "Select what data to print", 0, QApplication::UnicodeUTF8));
        checkBox_BASIC->setText(QApplication::translate("Drukuj", "Basic information", 0, QApplication::UnicodeUTF8));
        checkBox_BORROWS->setText(QApplication::translate("Drukuj", "Borrows register", 0, QApplication::UnicodeUTF8));
        checkBox_AUTHORS->setText(QApplication::translate("Drukuj", "Authors", 0, QApplication::UnicodeUTF8));
        checkBox_PUBS->setText(QApplication::translate("Drukuj", "Publishings", 0, QApplication::UnicodeUTF8));
        pushButton_CANCEL->setText(QApplication::translate("Drukuj", "Cancel", 0, QApplication::UnicodeUTF8));
        pushButton_PRINT->setText(QApplication::translate("Drukuj", "Print", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Drukuj: public Ui_Drukuj {};
} // namespace Ui

QT_END_NAMESPACE

#endif // DRUKUJGG3268_H
