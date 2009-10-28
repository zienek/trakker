/********************************************************************************
** Form generated from reading ui file 'centralwidget.ui'
**
** Created: Tue Oct 27 14:47:48 2009
**      by: Qt User Interface Compiler version 4.5.2
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef CENTRALWIDGET_H
#define CENTRALWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QGraphicsView>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QRadioButton>
#include <QtGui/QSlider>
#include <QtGui/QSpacerItem>
#include <QtGui/QTabWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_centralWidget
{
public:
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QLabel *Signal1;
    QGraphicsView *graphicsView_1;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_2;
    QGraphicsView *graphicsView_2;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_3;
    QGraphicsView *graphicsView_3;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_4;
    QGraphicsView *graphicsView_4;
    QVBoxLayout *verticalLayout_2;
    QSlider *verticalSlider;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *verticalSpacer_6;
    QSpacerItem *verticalSpacer_4;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *verticalSpacer_5;
    QSpacerItem *verticalSpacer;
    QTabWidget *tabWidget;
    QWidget *Input;
    QComboBox *comboBox_2;
    QLabel *label_6;
    QRadioButton *radioButton_1;
    QRadioButton *radioButton_2;
    QLabel *label_7;
    QWidget *Windowing;
    QLabel *label;
    QComboBox *comboBox;
    QGraphicsView *graphicsViewWindow;
    QLabel *label_5;
    QGraphicsView *graphicsView_5;
    QGraphicsView *graphicsView_6;
    QGraphicsView *graphicsView_7;
    QGraphicsView *graphicsView_8;
    QWidget *Correlation;
    QComboBox *comboBox_3;
    QGraphicsView *graphicsView_9;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout_3;

    void setupUi(QWidget *centralWidget)
    {
        if (centralWidget->objectName().isEmpty())
            centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        centralWidget->resize(1123, 728);
        horizontalLayout_2 = new QHBoxLayout(centralWidget);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        Signal1 = new QLabel(centralWidget);
        Signal1->setObjectName(QString::fromUtf8("Signal1"));

        horizontalLayout_3->addWidget(Signal1);


        verticalLayout->addLayout(horizontalLayout_3);

        graphicsView_1 = new QGraphicsView(centralWidget);
        graphicsView_1->setObjectName(QString::fromUtf8("graphicsView_1"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(graphicsView_1->sizePolicy().hasHeightForWidth());
        graphicsView_1->setSizePolicy(sizePolicy);
        graphicsView_1->setMinimumSize(QSize(512, 128));
        graphicsView_1->setMaximumSize(QSize(512, 128));

        verticalLayout->addWidget(graphicsView_1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_4->addWidget(label_2);


        verticalLayout->addLayout(horizontalLayout_4);

        graphicsView_2 = new QGraphicsView(centralWidget);
        graphicsView_2->setObjectName(QString::fromUtf8("graphicsView_2"));
        sizePolicy.setHeightForWidth(graphicsView_2->sizePolicy().hasHeightForWidth());
        graphicsView_2->setSizePolicy(sizePolicy);
        graphicsView_2->setMinimumSize(QSize(512, 128));
        graphicsView_2->setMaximumSize(QSize(512, 128));

        verticalLayout->addWidget(graphicsView_2);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_5->addWidget(label_3);


        verticalLayout->addLayout(horizontalLayout_5);

        graphicsView_3 = new QGraphicsView(centralWidget);
        graphicsView_3->setObjectName(QString::fromUtf8("graphicsView_3"));
        sizePolicy.setHeightForWidth(graphicsView_3->sizePolicy().hasHeightForWidth());
        graphicsView_3->setSizePolicy(sizePolicy);
        graphicsView_3->setMinimumSize(QSize(512, 128));
        graphicsView_3->setMaximumSize(QSize(512, 128));

        verticalLayout->addWidget(graphicsView_3);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_6->addWidget(label_4);


        verticalLayout->addLayout(horizontalLayout_6);

        graphicsView_4 = new QGraphicsView(centralWidget);
        graphicsView_4->setObjectName(QString::fromUtf8("graphicsView_4"));
        sizePolicy.setHeightForWidth(graphicsView_4->sizePolicy().hasHeightForWidth());
        graphicsView_4->setSizePolicy(sizePolicy);
        graphicsView_4->setMinimumSize(QSize(512, 128));
        graphicsView_4->setMaximumSize(QSize(512, 128));

        verticalLayout->addWidget(graphicsView_4);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalSlider = new QSlider(centralWidget);
        verticalSlider->setObjectName(QString::fromUtf8("verticalSlider"));
        verticalSlider->setOrientation(Qt::Vertical);

        verticalLayout_2->addWidget(verticalSlider);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_3);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_6);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_4);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_5);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);


        horizontalLayout->addLayout(verticalLayout_2);

        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setMinimumSize(QSize(560, 0));
        Input = new QWidget();
        Input->setObjectName(QString::fromUtf8("Input"));
        comboBox_2 = new QComboBox(Input);
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));
        comboBox_2->setGeometry(QRect(160, 130, 121, 30));
        label_6 = new QLabel(Input);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(20, 140, 121, 20));
        radioButton_1 = new QRadioButton(Input);
        radioButton_1->setObjectName(QString::fromUtf8("radioButton_1"));
        radioButton_1->setEnabled(true);
        radioButton_1->setGeometry(QRect(20, 30, 271, 23));
        radioButton_1->setChecked(true);
        radioButton_1->setAutoExclusive(true);
        radioButton_2 = new QRadioButton(Input);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));
        radioButton_2->setGeometry(QRect(20, 60, 271, 23));
        radioButton_2->setAutoExclusive(true);
        label_7 = new QLabel(Input);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(20, 180, 251, 71));
        tabWidget->addTab(Input, QString());
        Windowing = new QWidget();
        Windowing->setObjectName(QString::fromUtf8("Windowing"));
        label = new QLabel(Windowing);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(60, 70, 111, 16));
        comboBox = new QComboBox(Windowing);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(20, 110, 201, 25));
        comboBox->setMaxVisibleItems(10);
        graphicsViewWindow = new QGraphicsView(Windowing);
        graphicsViewWindow->setObjectName(QString::fromUtf8("graphicsViewWindow"));
        graphicsViewWindow->setGeometry(QRect(260, 70, 150, 128));
        sizePolicy.setHeightForWidth(graphicsViewWindow->sizePolicy().hasHeightForWidth());
        graphicsViewWindow->setSizePolicy(sizePolicy);
        graphicsViewWindow->setMinimumSize(QSize(150, 128));
        graphicsViewWindow->setMaximumSize(QSize(150, 128));
        label_5 = new QLabel(Windowing);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(160, 260, 201, 18));
        graphicsView_5 = new QGraphicsView(Windowing);
        graphicsView_5->setObjectName(QString::fromUtf8("graphicsView_5"));
        graphicsView_5->setGeometry(QRect(10, 290, 260, 128));
        graphicsView_5->setMinimumSize(QSize(260, 128));
        graphicsView_5->setMaximumSize(QSize(260, 128));
        graphicsView_6 = new QGraphicsView(Windowing);
        graphicsView_6->setObjectName(QString::fromUtf8("graphicsView_6"));
        graphicsView_6->setGeometry(QRect(280, 290, 260, 128));
        graphicsView_6->setMinimumSize(QSize(260, 128));
        graphicsView_6->setMaximumSize(QSize(260, 128));
        graphicsView_7 = new QGraphicsView(Windowing);
        graphicsView_7->setObjectName(QString::fromUtf8("graphicsView_7"));
        graphicsView_7->setGeometry(QRect(10, 440, 260, 128));
        graphicsView_7->setMinimumSize(QSize(260, 128));
        graphicsView_7->setMaximumSize(QSize(260, 128));
        graphicsView_8 = new QGraphicsView(Windowing);
        graphicsView_8->setObjectName(QString::fromUtf8("graphicsView_8"));
        graphicsView_8->setGeometry(QRect(280, 440, 260, 128));
        graphicsView_8->setMinimumSize(QSize(260, 128));
        graphicsView_8->setMaximumSize(QSize(260, 128));
        tabWidget->addTab(Windowing, QString());
        Correlation = new QWidget();
        Correlation->setObjectName(QString::fromUtf8("Correlation"));
        comboBox_3 = new QComboBox(Correlation);
        comboBox_3->setObjectName(QString::fromUtf8("comboBox_3"));
        comboBox_3->setGeometry(QRect(80, 70, 400, 30));
        comboBox_3->setMinimumSize(QSize(400, 0));
        comboBox_3->setMaximumSize(QSize(400, 16777215));
        graphicsView_9 = new QGraphicsView(Correlation);
        graphicsView_9->setObjectName(QString::fromUtf8("graphicsView_9"));
        graphicsView_9->setGeometry(QRect(20, 160, 512, 300));
        graphicsView_9->setMinimumSize(QSize(512, 300));
        graphicsView_9->setMaximumSize(QSize(512, 300));
        tabWidget->addTab(Correlation, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        tabWidget->addTab(tab_2, QString());

        horizontalLayout->addWidget(tabWidget);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));

        horizontalLayout->addLayout(verticalLayout_3);


        horizontalLayout_2->addLayout(horizontalLayout);


        retranslateUi(centralWidget);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(centralWidget);
    } // setupUi

    void retranslateUi(QWidget *centralWidget)
    {
        centralWidget->setWindowTitle(QApplication::translate("centralWidget", "Form", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        Signal1->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        Signal1->setText(QApplication::translate("centralWidget", "Signal 1", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("centralWidget", "Signal 2", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("centralWidget", "Signal 3", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("centralWidget", "Signal 4", 0, QApplication::UnicodeUTF8));
        comboBox_2->clear();
        comboBox_2->insertItems(0, QStringList()
         << QApplication::translate("centralWidget", "48 ksps", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("centralWidget", "24 ksps", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("centralWidget", "12 ksps", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("centralWidget", "6 ksps", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("centralWidget", "3 ksps", 0, QApplication::UnicodeUTF8)
        );
        label_6->setText(QApplication::translate("centralWidget", "Sampling rate", 0, QApplication::UnicodeUTF8));
        radioButton_1->setText(QApplication::translate("centralWidget", "Single event processing", 0, QApplication::UnicodeUTF8));
        radioButton_2->setText(QApplication::translate("centralWidget", "Continuous signal processing", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("centralWidget", "TODO: Save triggered signals\n"
" and load saved signals", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(Input), QApplication::translate("centralWidget", "Input", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        Windowing->setToolTip(QApplication::translate("centralWidget", "Windowing", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        label->setText(QApplication::translate("centralWidget", "Window type", 0, QApplication::UnicodeUTF8));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("centralWidget", "Rectangular", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("centralWidget", "Triangular", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("centralWidget", "Blackman", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("centralWidget", "Hamming", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("centralWidget", "Gauss", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("centralWidget", "Nuttall", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("centralWidget", "Blackman-Harris", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("centralWidget", "Blackman-Nuttall", 0, QApplication::UnicodeUTF8)
        );
        label_5->setText(QApplication::translate("centralWidget", "Signals after windowing", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(Windowing), QApplication::translate("centralWidget", "Windowing", 0, QApplication::UnicodeUTF8));
        comboBox_3->clear();
        comboBox_3->insertItems(0, QStringList()
         << QApplication::translate("centralWidget", "GCC General Cross Corelation (unfiltered)", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("centralWidget", "ML Maximum Likelihood", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("centralWidget", "PHAT weighting function", 0, QApplication::UnicodeUTF8)
        );
        tabWidget->setTabText(tabWidget->indexOf(Correlation), QApplication::translate("centralWidget", "Correlation", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("centralWidget", "TDOA", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(centralWidget);
    } // retranslateUi

};

namespace Ui {
    class centralWidget: public Ui_centralWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // CENTRALWIDGET_H
