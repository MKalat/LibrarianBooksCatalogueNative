/********************************************************************************
** Form generated from reading UI file 'AboutHp3152.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef ABOUTHP3152_H
#define ABOUTHP3152_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_About
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QPushButton *pushButton_OK;

    void setupUi(QDialog *About)
    {
        if (About->objectName().isEmpty())
            About->setObjectName(QString::fromUtf8("About"));
        About->resize(488, 277);
        label = new QLabel(About);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(160, 12, 225, 33));
        label->setStyleSheet(QString::fromUtf8("color: rgb(255, 170, 0);\n"
"font: 14pt \"MS Shell Dlg 2\";"));
        label_2 = new QLabel(About);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(160, 52, 217, 16));
        label_3 = new QLabel(About);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(160, 88, 285, 45));
        label_3->setWordWrap(true);
        label_4 = new QLabel(About);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(160, 72, 89, 16));
        pushButton_OK = new QPushButton(About);
        pushButton_OK->setObjectName(QString::fromUtf8("pushButton_OK"));
        pushButton_OK->setGeometry(QRect(236, 224, 75, 23));

        retranslateUi(About);
        QObject::connect(pushButton_OK, SIGNAL(clicked()), About, SLOT(BTN_OK_CLICKED()));

        QMetaObject::connectSlotsByName(About);
    } // setupUi

    void retranslateUi(QDialog *About)
    {
        About->setWindowTitle(QApplication::translate("About", "LBC - About", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("About", "Librarian Books Catalogue", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("About", "(C) Copyright by Marcin Ka\305\202at 2012 - 2014", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("About", "This program uses Qt 4.8.6 Library licensed under terms of GNU LGPL 2.1 License", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("About", "http://mkalat.pl", 0, QApplication::UnicodeUTF8));
        pushButton_OK->setText(QApplication::translate("About", "OK", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class About: public Ui_About {};
} // namespace Ui

QT_END_NAMESPACE

#endif // ABOUTHP3152_H