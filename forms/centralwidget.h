/********************************************************************************
** Form generated from reading ui file 'centralwidget.ui'
**
** Created: Sat Nov 7 14:33:29 2009
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
#include <QtGui/QPushButton>
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
    QSpacerItem *verticalSpacer_4;
    QSlider *verticalSlider;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *verticalLayout_3;
    QTabWidget *tabWidget;
    QWidget *Input;
    QComboBox *comboBox_2;
    QLabel *label_6;
    QRadioButton *radioButton_1;
    QRadioButton *radioButton_2;
    QLabel *label_7;
    QPushButton *pushButton_12;
    QPushButton *pushButton_13;
    QPushButton *pushButton_14;
    QPushButton *pushButton_15;
    QWidget *Windowing;
    QLabel *label;
    QComboBox *comboBox;
    QGraphicsView *graphicsViewWindow;
    QLabel *label_5;
    QGraphicsView *graphicsView_5;
    QGraphicsView *graphicsView_6;
    QGraphicsView *graphicsView_7;
    QGraphicsView *graphicsView_8;
    QPushButton *pushButton;
    QWidget *Correlation;
    QComboBox *comboBox_3;
    QGraphicsView *graphicsView_9;
    QPushButton *pushButton_2;
    QTabWidget *tabWidget_2;
    QWidget *tab;
    QComboBox *comboBox_4;
    QPushButton *pushButton_11;
    QWidget *tab_3;
    QComboBox *comboBox_5;
    QPushButton *pushButton_10;
    QWidget *tab_4;
    QComboBox *comboBox_6;
    QPushButton *pushButton_9;
    QWidget *tab_5;
    QComboBox *comboBox_7;
    QPushButton *pushButton_8;
    QWidget *tab_6;
    QComboBox *comboBox_8;
    QPushButton *pushButton_7;
    QWidget *tab_7;
    QComboBox *comboBox_9;
    QPushButton *pushButton_6;
    QLabel *label_8;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QLabel *label_9;
    QWidget *tab_2;

    void setupUi(QWidget *centralWidget)
    {
        if (centralWidget->objectName().isEmpty())
            centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        centralWidget->resize(1131, 728);
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
        graphicsView_1->setMinimumSize(QSize(519, 134));
        graphicsView_1->setMaximumSize(QSize(520, 134));
        graphicsView_1->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        graphicsView_1->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

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
        graphicsView_2->setMinimumSize(QSize(520, 134));
        graphicsView_2->setMaximumSize(QSize(520, 134));
        graphicsView_2->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        graphicsView_2->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

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
        graphicsView_3->setMinimumSize(QSize(520, 134));
        graphicsView_3->setMaximumSize(QSize(520, 134));
        graphicsView_3->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        graphicsView_3->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

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
        graphicsView_4->setMinimumSize(QSize(520, 134));
        graphicsView_4->setMaximumSize(QSize(520, 134));
        graphicsView_4->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        graphicsView_4->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        verticalLayout->addWidget(graphicsView_4);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalSpacer_4 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_2->addItem(verticalSpacer_4);

        verticalSlider = new QSlider(centralWidget);
        verticalSlider->setObjectName(QString::fromUtf8("verticalSlider"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(80);
        sizePolicy1.setHeightForWidth(verticalSlider->sizePolicy().hasHeightForWidth());
        verticalSlider->setSizePolicy(sizePolicy1);
        verticalSlider->setMinimumSize(QSize(0, 80));
        verticalSlider->setMaximumSize(QSize(16777215, 64));
        verticalSlider->setMaximum(512);
        verticalSlider->setSingleStep(8);
        verticalSlider->setPageStep(32);
        verticalSlider->setOrientation(Qt::Vertical);
        verticalSlider->setInvertedAppearance(true);

        verticalLayout_2->addWidget(verticalSlider);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_3);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setMinimumSize(QSize(560, 0));
        Input = new QWidget();
        Input->setObjectName(QString::fromUtf8("Input"));
        comboBox_2 = new QComboBox(Input);
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));
        comboBox_2->setGeometry(QRect(150, 140, 121, 30));
        label_6 = new QLabel(Input);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(20, 150, 121, 20));
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
        label_7->setGeometry(QRect(30, 280, 221, 41));
        pushButton_12 = new QPushButton(Input);
        pushButton_12->setObjectName(QString::fromUtf8("pushButton_12"));
        pushButton_12->setGeometry(QRect(40, 240, 181, 27));
        pushButton_13 = new QPushButton(Input);
        pushButton_13->setObjectName(QString::fromUtf8("pushButton_13"));
        pushButton_13->setGeometry(QRect(270, 240, 201, 27));
        pushButton_14 = new QPushButton(Input);
        pushButton_14->setObjectName(QString::fromUtf8("pushButton_14"));
        pushButton_14->setGeometry(QRect(270, 280, 201, 27));
        pushButton_15 = new QPushButton(Input);
        pushButton_15->setObjectName(QString::fromUtf8("pushButton_15"));
        pushButton_15->setGeometry(QRect(300, 140, 112, 27));
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
        label_5->setGeometry(QRect(200, 260, 171, 18));
        graphicsView_5 = new QGraphicsView(Windowing);
        graphicsView_5->setObjectName(QString::fromUtf8("graphicsView_5"));
        graphicsView_5->setGeometry(QRect(10, 290, 260, 132));
        graphicsView_5->setMinimumSize(QSize(260, 132));
        graphicsView_5->setMaximumSize(QSize(260, 132));
        graphicsView_6 = new QGraphicsView(Windowing);
        graphicsView_6->setObjectName(QString::fromUtf8("graphicsView_6"));
        graphicsView_6->setGeometry(QRect(280, 290, 260, 132));
        graphicsView_6->setMinimumSize(QSize(260, 132));
        graphicsView_6->setMaximumSize(QSize(260, 132));
        graphicsView_7 = new QGraphicsView(Windowing);
        graphicsView_7->setObjectName(QString::fromUtf8("graphicsView_7"));
        graphicsView_7->setGeometry(QRect(10, 440, 260, 132));
        graphicsView_7->setMinimumSize(QSize(260, 132));
        graphicsView_7->setMaximumSize(QSize(260, 132));
        graphicsView_8 = new QGraphicsView(Windowing);
        graphicsView_8->setObjectName(QString::fromUtf8("graphicsView_8"));
        graphicsView_8->setGeometry(QRect(280, 440, 260, 132));
        graphicsView_8->setMinimumSize(QSize(260, 132));
        graphicsView_8->setMaximumSize(QSize(260, 132));
        pushButton = new QPushButton(Windowing);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(50, 160, 123, 29));
        tabWidget->addTab(Windowing, QString());
        Correlation = new QWidget();
        Correlation->setObjectName(QString::fromUtf8("Correlation"));
        comboBox_3 = new QComboBox(Correlation);
        comboBox_3->setObjectName(QString::fromUtf8("comboBox_3"));
        comboBox_3->setGeometry(QRect(80, 30, 400, 30));
        comboBox_3->setMinimumSize(QSize(400, 0));
        comboBox_3->setMaximumSize(QSize(400, 16777215));
        graphicsView_9 = new QGraphicsView(Correlation);
        graphicsView_9->setObjectName(QString::fromUtf8("graphicsView_9"));
        graphicsView_9->setGeometry(QRect(20, 230, 512, 300));
        graphicsView_9->setMinimumSize(QSize(512, 300));
        graphicsView_9->setMaximumSize(QSize(512, 300));
        pushButton_2 = new QPushButton(Correlation);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(80, 80, 181, 27));
        tabWidget_2 = new QTabWidget(Correlation);
        tabWidget_2->setObjectName(QString::fromUtf8("tabWidget_2"));
        tabWidget_2->setGeometry(QRect(30, 120, 321, 81));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        comboBox_4 = new QComboBox(tab);
        comboBox_4->setObjectName(QString::fromUtf8("comboBox_4"));
        comboBox_4->setGeometry(QRect(10, 10, 101, 27));
        pushButton_11 = new QPushButton(tab);
        pushButton_11->setObjectName(QString::fromUtf8("pushButton_11"));
        pushButton_11->setGeometry(QRect(190, 10, 112, 27));
        tabWidget_2->addTab(tab, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        comboBox_5 = new QComboBox(tab_3);
        comboBox_5->setObjectName(QString::fromUtf8("comboBox_5"));
        comboBox_5->setGeometry(QRect(10, 10, 101, 27));
        pushButton_10 = new QPushButton(tab_3);
        pushButton_10->setObjectName(QString::fromUtf8("pushButton_10"));
        pushButton_10->setGeometry(QRect(190, 10, 112, 27));
        tabWidget_2->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        comboBox_6 = new QComboBox(tab_4);
        comboBox_6->setObjectName(QString::fromUtf8("comboBox_6"));
        comboBox_6->setGeometry(QRect(10, 10, 101, 27));
        pushButton_9 = new QPushButton(tab_4);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));
        pushButton_9->setGeometry(QRect(190, 10, 112, 27));
        tabWidget_2->addTab(tab_4, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QString::fromUtf8("tab_5"));
        comboBox_7 = new QComboBox(tab_5);
        comboBox_7->setObjectName(QString::fromUtf8("comboBox_7"));
        comboBox_7->setGeometry(QRect(10, 10, 101, 27));
        pushButton_8 = new QPushButton(tab_5);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));
        pushButton_8->setGeometry(QRect(190, 10, 112, 27));
        tabWidget_2->addTab(tab_5, QString());
        tab_6 = new QWidget();
        tab_6->setObjectName(QString::fromUtf8("tab_6"));
        comboBox_8 = new QComboBox(tab_6);
        comboBox_8->setObjectName(QString::fromUtf8("comboBox_8"));
        comboBox_8->setGeometry(QRect(10, 10, 101, 27));
        pushButton_7 = new QPushButton(tab_6);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        pushButton_7->setGeometry(QRect(190, 10, 112, 27));
        tabWidget_2->addTab(tab_6, QString());
        tab_7 = new QWidget();
        tab_7->setObjectName(QString::fromUtf8("tab_7"));
        comboBox_9 = new QComboBox(tab_7);
        comboBox_9->setObjectName(QString::fromUtf8("comboBox_9"));
        comboBox_9->setGeometry(QRect(10, 10, 101, 27));
        pushButton_6 = new QPushButton(tab_7);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setGeometry(QRect(190, 10, 112, 27));
        tabWidget_2->addTab(tab_7, QString());
        label_8 = new QLabel(Correlation);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(180, 210, 171, 18));
        pushButton_3 = new QPushButton(Correlation);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(390, 150, 112, 27));
        pushButton_4 = new QPushButton(Correlation);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(40, 550, 191, 27));
        pushButton_5 = new QPushButton(Correlation);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(310, 550, 191, 27));
        label_9 = new QLabel(Correlation);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(200, 530, 151, 18));
        label_9->setFrameShape(QFrame::NoFrame);
        tabWidget->addTab(Correlation, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        tabWidget->addTab(tab_2, QString());

        verticalLayout_3->addWidget(tabWidget);


        horizontalLayout->addLayout(verticalLayout_3);


        horizontalLayout_2->addLayout(horizontalLayout);


        retranslateUi(centralWidget);

        tabWidget->setCurrentIndex(0);
        tabWidget_2->setCurrentIndex(0);


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
         << QApplication::translate("centralWidget", "44.1 ksps ", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("centralWidget", "24 ksps", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("centralWidget", "22.05 ksps", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("centralWidget", "12 ksps", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("centralWidget", "10 ksps", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("centralWidget", "8 ksps", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("centralWidget", "6 ksps", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("centralWidget", "4 ksps", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("centralWidget", "3 ksps", 0, QApplication::UnicodeUTF8)
        );
        label_6->setText(QApplication::translate("centralWidget", "Sampling rate", 0, QApplication::UnicodeUTF8));
        radioButton_1->setText(QApplication::translate("centralWidget", "Single event processing", 0, QApplication::UnicodeUTF8));
        radioButton_2->setText(QApplication::translate("centralWidget", "Continuous signal processing", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("centralWidget", "TODO: Save triggered signals\n"
" and load saved signals", 0, QApplication::UnicodeUTF8));
        pushButton_12->setText(QApplication::translate("centralWidget", "Save views as graphic", 0, QApplication::UnicodeUTF8));
        pushButton_13->setText(QApplication::translate("centralWidget", "Save as text coefficient", 0, QApplication::UnicodeUTF8));
        pushButton_14->setText(QApplication::translate("centralWidget", "Load coefficient from file", 0, QApplication::UnicodeUTF8));
        pushButton_15->setText(QApplication::translate("centralWidget", "Submit", 0, QApplication::UnicodeUTF8));
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
        pushButton->setText(QApplication::translate("centralWidget", "&Windowing", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(Windowing), QApplication::translate("centralWidget", "Windowing", 0, QApplication::UnicodeUTF8));
        comboBox_3->clear();
        comboBox_3->insertItems(0, QStringList()
         << QApplication::translate("centralWidget", "GCC General Cross Corelation (unfiltered)", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("centralWidget", "ML Maximum Likelihood", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("centralWidget", "PHAT weighting function", 0, QApplication::UnicodeUTF8)
        );
        pushButton_2->setText(QApplication::translate("centralWidget", "Run &Cross-Correlation", 0, QApplication::UnicodeUTF8));
        comboBox_4->clear();
        comboBox_4->insertItems(0, QStringList()
         << QApplication::translate("centralWidget", "Blue", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("centralWidget", "Red", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("centralWidget", "Green", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("centralWidget", "Black", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("centralWidget", "Cyan", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("centralWidget", "Magenta", 0, QApplication::UnicodeUTF8)
        );
        pushButton_11->setText(QApplication::translate("centralWidget", "Add", 0, QApplication::UnicodeUTF8));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab), QApplication::translate("centralWidget", "1 - 2", 0, QApplication::UnicodeUTF8));
        comboBox_5->clear();
        comboBox_5->insertItems(0, QStringList()
         << QApplication::translate("centralWidget", "Blue", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("centralWidget", "Red", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("centralWidget", "Green", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("centralWidget", "Black", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("centralWidget", "Cyan", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("centralWidget", "Magenta", 0, QApplication::UnicodeUTF8)
        );
        pushButton_10->setText(QApplication::translate("centralWidget", "Add", 0, QApplication::UnicodeUTF8));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_3), QApplication::translate("centralWidget", "1 - 3", 0, QApplication::UnicodeUTF8));
        comboBox_6->clear();
        comboBox_6->insertItems(0, QStringList()
         << QApplication::translate("centralWidget", "Blue", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("centralWidget", "Red", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("centralWidget", "Green", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("centralWidget", "Black", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("centralWidget", "Cyan", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("centralWidget", "Magenta", 0, QApplication::UnicodeUTF8)
        );
        pushButton_9->setText(QApplication::translate("centralWidget", "Add", 0, QApplication::UnicodeUTF8));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_4), QApplication::translate("centralWidget", "1 - 4", 0, QApplication::UnicodeUTF8));
        comboBox_7->clear();
        comboBox_7->insertItems(0, QStringList()
         << QApplication::translate("centralWidget", "Blue", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("centralWidget", "Red", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("centralWidget", "Green", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("centralWidget", "Black", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("centralWidget", "Cyan", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("centralWidget", "Magenta", 0, QApplication::UnicodeUTF8)
        );
        pushButton_8->setText(QApplication::translate("centralWidget", "Add", 0, QApplication::UnicodeUTF8));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_5), QApplication::translate("centralWidget", "2 - 3", 0, QApplication::UnicodeUTF8));
        comboBox_8->clear();
        comboBox_8->insertItems(0, QStringList()
         << QApplication::translate("centralWidget", "Blue", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("centralWidget", "Red", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("centralWidget", "Green", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("centralWidget", "Black", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("centralWidget", "Cyan", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("centralWidget", "Magenta", 0, QApplication::UnicodeUTF8)
        );
        pushButton_7->setText(QApplication::translate("centralWidget", "Add", 0, QApplication::UnicodeUTF8));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_6), QApplication::translate("centralWidget", "2 - 4", 0, QApplication::UnicodeUTF8));
        comboBox_9->clear();
        comboBox_9->insertItems(0, QStringList()
         << QApplication::translate("centralWidget", "Blue", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("centralWidget", "Red", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("centralWidget", "Green", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("centralWidget", "Black", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("centralWidget", "Cyan", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("centralWidget", "Magenta", 0, QApplication::UnicodeUTF8)
        );
        pushButton_6->setText(QApplication::translate("centralWidget", "Add", 0, QApplication::UnicodeUTF8));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_7), QApplication::translate("centralWidget", "3 - 4", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("centralWidget", "Cross-Correlation view", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("centralWidget", "Clear all", 0, QApplication::UnicodeUTF8));
        pushButton_4->setText(QApplication::translate("centralWidget", "Save view as graphic", 0, QApplication::UnicodeUTF8));
        pushButton_5->setText(QApplication::translate("centralWidget", "Save as text coefficient", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("centralWidget", "TODO: save results", 0, QApplication::UnicodeUTF8));
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
