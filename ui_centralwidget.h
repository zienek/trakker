/********************************************************************************
** Form generated from reading ui file 'centralwidget.ui'
**
** Created: Wed Nov 4 02:55:03 2009
**      by: Qt User Interface Compiler version 4.5.2
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_CENTRALWIDGET_H
#define UI_CENTRALWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_trakkercontroller
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *trakkercontroller)
    {
        if (trakkercontroller->objectName().isEmpty())
            trakkercontroller->setObjectName(QString::fromUtf8("trakkercontroller"));
        trakkercontroller->resize(600, 400);
        menuBar = new QMenuBar(trakkercontroller);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        trakkercontroller->setMenuBar(menuBar);
        mainToolBar = new QToolBar(trakkercontroller);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        trakkercontroller->addToolBar(mainToolBar);
        centralWidget = new QWidget(trakkercontroller);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        trakkercontroller->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(trakkercontroller);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        trakkercontroller->setStatusBar(statusBar);

        retranslateUi(trakkercontroller);

        QMetaObject::connectSlotsByName(trakkercontroller);
    } // setupUi

    void retranslateUi(QMainWindow *trakkercontroller)
    {
        trakkercontroller->setWindowTitle(QApplication::translate("trakkercontroller", "trakkercontroller", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(trakkercontroller);
    } // retranslateUi

};

namespace Ui {
    class trakkercontroller: public Ui_trakkercontroller {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CENTRALWIDGET_H
