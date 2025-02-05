/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDial>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionSave;
    QAction *actionOpen;
    QAction *actionColorLivingCells;
    QAction *actionColor_of_dead_cells;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QFrame *line_2;
    QHBoxLayout *horizontalLayout_13;
    QVBoxLayout *verticalLayout_10;
    QHBoxLayout *horizontalLayout_16;
    QHBoxLayout *horizontalLayout_12;
    QHBoxLayout *horizontalLayout_11;
    QLabel *columnsLabel;
    QSpacerItem *horizontalSpacer_5;
    QSpinBox *rowBox;
    QSpacerItem *horizontalSpacer_3;
    QFrame *line;
    QHBoxLayout *horizontalLayout_10;
    QSpacerItem *horizontalSpacer_2;
    QLabel *rowsLabel;
    QSpacerItem *horizontalSpacer_6;
    QSpinBox *columnBox;
    QSpacerItem *horizontalSpacer;
    QFrame *line_9;
    QTableWidget *gameTable;
    QFrame *line_8;
    QVBoxLayout *verticalLayout_9;
    QVBoxLayout *verticalLayout_8;
    QHBoxLayout *horizontalLayout_8;
    QLabel *stepsLabel;
    QLCDNumber *stepsLCD;
    QHBoxLayout *horizontalLayout_9;
    QLabel *lifeLabel;
    QLCDNumber *LifeCells;
    QSpacerItem *verticalSpacer_3;
    QFrame *line_7;
    QSpacerItem *verticalSpacer_4;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_7;
    QVBoxLayout *verticalLayout_3;
    QPushButton *startButton;
    QPushButton *stopButton;
    QSpacerItem *horizontalSpacer_8;
    QSpacerItem *verticalSpacer_5;
    QFrame *line_3;
    QSpacerItem *verticalSpacer_6;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_9;
    QVBoxLayout *verticalLayout_4;
    QPushButton *pauseButton;
    QPushButton *resumeButton;
    QSpacerItem *horizontalSpacer_10;
    QSpacerItem *verticalSpacer_7;
    QFrame *line_4;
    QSpacerItem *verticalSpacer_8;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_12;
    QVBoxLayout *verticalLayout_5;
    QPushButton *stepButton;
    QPushButton *clearButton;
    QSpacerItem *horizontalSpacer_11;
    QSpacerItem *verticalSpacer_9;
    QFrame *line_6;
    QSpacerItem *verticalSpacer_10;
    QVBoxLayout *verticalLayout_12;
    QHBoxLayout *horizontalLayout_15;
    QSpacerItem *horizontalSpacer_13;
    QPushButton *randomButton;
    QSpacerItem *horizontalSpacer_14;
    QHBoxLayout *horizontalLayout_14;
    QLabel *seedLabel;
    QSpinBox *setSeedBox;
    QVBoxLayout *verticalLayout_6;
    QSpacerItem *verticalSpacer_11;
    QFrame *line_5;
    QSpacerItem *verticalSpacer_12;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout_7;
    QLabel *speedLabel;
    QLCDNumber *speedLCD;
    QSpacerItem *verticalSpacer_2;
    QDial *speedDial;
    QSpacerItem *verticalSpacer;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1056, 936);
        MainWindow->setAutoFillBackground(false);
        MainWindow->setAnimated(true);
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName("actionSave");
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName("actionOpen");
        actionColorLivingCells = new QAction(MainWindow);
        actionColorLivingCells->setObjectName("actionColorLivingCells");
        actionColor_of_dead_cells = new QAction(MainWindow);
        actionColor_of_dead_cells->setObjectName("actionColor_of_dead_cells");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        line_2 = new QFrame(centralwidget);
        line_2->setObjectName("line_2");
        line_2->setFrameShape(QFrame::Shape::HLine);
        line_2->setFrameShadow(QFrame::Shadow::Sunken);

        gridLayout->addWidget(line_2, 0, 0, 1, 1);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName("horizontalLayout_13");
        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setObjectName("verticalLayout_10");
        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setObjectName("horizontalLayout_16");
        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName("horizontalLayout_12");
        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName("horizontalLayout_11");
        columnsLabel = new QLabel(centralwidget);
        columnsLabel->setObjectName("columnsLabel");
        columnsLabel->setMinimumSize(QSize(0, 27));
        columnsLabel->setMaximumSize(QSize(16777215, 27));
        QFont font;
        font.setPointSize(10);
        columnsLabel->setFont(font);

        horizontalLayout_11->addWidget(columnsLabel);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_5);

        rowBox = new QSpinBox(centralwidget);
        rowBox->setObjectName("rowBox");
        rowBox->setMinimumSize(QSize(100, 27));
        rowBox->setMaximumSize(QSize(100, 27));
        rowBox->setMaximum(300);
        rowBox->setValue(10);

        horizontalLayout_11->addWidget(rowBox);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_3);


        horizontalLayout_12->addLayout(horizontalLayout_11);

        line = new QFrame(centralwidget);
        line->setObjectName("line");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(line->sizePolicy().hasHeightForWidth());
        line->setSizePolicy(sizePolicy);
        line->setMinimumSize(QSize(0, 30));
        line->setFrameShape(QFrame::Shape::VLine);
        line->setFrameShadow(QFrame::Shadow::Sunken);

        horizontalLayout_12->addWidget(line);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName("horizontalLayout_10");
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_2);

        rowsLabel = new QLabel(centralwidget);
        rowsLabel->setObjectName("rowsLabel");
        rowsLabel->setMinimumSize(QSize(0, 27));
        rowsLabel->setMaximumSize(QSize(16777215, 27));
        rowsLabel->setFont(font);

        horizontalLayout_10->addWidget(rowsLabel);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_6);

        columnBox = new QSpinBox(centralwidget);
        columnBox->setObjectName("columnBox");
        columnBox->setMinimumSize(QSize(100, 27));
        columnBox->setMaximumSize(QSize(100, 27));
        columnBox->setMaximum(300);
        columnBox->setValue(10);

        horizontalLayout_10->addWidget(columnBox);


        horizontalLayout_12->addLayout(horizontalLayout_10);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_12->addItem(horizontalSpacer);


        horizontalLayout_16->addLayout(horizontalLayout_12);


        verticalLayout_10->addLayout(horizontalLayout_16);

        line_9 = new QFrame(centralwidget);
        line_9->setObjectName("line_9");
        line_9->setFrameShape(QFrame::Shape::HLine);
        line_9->setFrameShadow(QFrame::Shadow::Sunken);

        verticalLayout_10->addWidget(line_9);

        gameTable = new QTableWidget(centralwidget);
        gameTable->setObjectName("gameTable");

        verticalLayout_10->addWidget(gameTable);


        horizontalLayout_13->addLayout(verticalLayout_10);

        line_8 = new QFrame(centralwidget);
        line_8->setObjectName("line_8");
        line_8->setFrameShape(QFrame::Shape::VLine);
        line_8->setFrameShadow(QFrame::Shadow::Sunken);

        horizontalLayout_13->addWidget(line_8);

        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setObjectName("verticalLayout_9");
        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName("verticalLayout_8");
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        stepsLabel = new QLabel(centralwidget);
        stepsLabel->setObjectName("stepsLabel");
        stepsLabel->setMinimumSize(QSize(0, 27));
        stepsLabel->setFont(font);

        horizontalLayout_8->addWidget(stepsLabel);

        stepsLCD = new QLCDNumber(centralwidget);
        stepsLCD->setObjectName("stepsLCD");
        sizePolicy.setHeightForWidth(stepsLCD->sizePolicy().hasHeightForWidth());
        stepsLCD->setSizePolicy(sizePolicy);
        stepsLCD->setMinimumSize(QSize(135, 27));
        stepsLCD->setMaximumSize(QSize(135, 27));
        QFont font1;
        font1.setBold(false);
        stepsLCD->setFont(font1);
        stepsLCD->setAutoFillBackground(false);
        stepsLCD->setStyleSheet(QString::fromUtf8("QLCDNumber { \n"
"	color: black; \n"
"	background-color: lightGray; \n"
"}"));
        stepsLCD->setSmallDecimalPoint(false);
        stepsLCD->setDigitCount(7);

        horizontalLayout_8->addWidget(stepsLCD);


        verticalLayout_8->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName("horizontalLayout_9");
        lifeLabel = new QLabel(centralwidget);
        lifeLabel->setObjectName("lifeLabel");
        lifeLabel->setMinimumSize(QSize(0, 27));
        lifeLabel->setFont(font);

        horizontalLayout_9->addWidget(lifeLabel);

        LifeCells = new QLCDNumber(centralwidget);
        LifeCells->setObjectName("LifeCells");
        sizePolicy.setHeightForWidth(LifeCells->sizePolicy().hasHeightForWidth());
        LifeCells->setSizePolicy(sizePolicy);
        LifeCells->setMinimumSize(QSize(135, 27));
        LifeCells->setMaximumSize(QSize(135, 27));
        LifeCells->setFont(font1);
        LifeCells->setAutoFillBackground(false);
        LifeCells->setStyleSheet(QString::fromUtf8("QLCDNumber { \n"
"	color: black; \n"
"	background-color: lightGray; \n"
"}"));
        LifeCells->setSmallDecimalPoint(false);
        LifeCells->setDigitCount(7);

        horizontalLayout_9->addWidget(LifeCells);


        verticalLayout_8->addLayout(horizontalLayout_9);

        verticalSpacer_3 = new QSpacerItem(20, 13, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);

        verticalLayout_8->addItem(verticalSpacer_3);

        line_7 = new QFrame(centralwidget);
        line_7->setObjectName("line_7");
        line_7->setFrameShape(QFrame::Shape::HLine);
        line_7->setFrameShadow(QFrame::Shadow::Sunken);

        verticalLayout_8->addWidget(line_7);

        verticalSpacer_4 = new QSpacerItem(20, 13, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);

        verticalLayout_8->addItem(verticalSpacer_4);


        verticalLayout_9->addLayout(verticalLayout_8);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_7);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        startButton = new QPushButton(centralwidget);
        startButton->setObjectName("startButton");

        verticalLayout_3->addWidget(startButton);

        stopButton = new QPushButton(centralwidget);
        stopButton->setObjectName("stopButton");

        verticalLayout_3->addWidget(stopButton);


        horizontalLayout_2->addLayout(verticalLayout_3);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_8);


        verticalLayout_9->addLayout(horizontalLayout_2);

        verticalSpacer_5 = new QSpacerItem(20, 13, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);

        verticalLayout_9->addItem(verticalSpacer_5);

        line_3 = new QFrame(centralwidget);
        line_3->setObjectName("line_3");
        line_3->setFrameShape(QFrame::Shape::HLine);
        line_3->setFrameShadow(QFrame::Shadow::Sunken);

        verticalLayout_9->addWidget(line_3);

        verticalSpacer_6 = new QSpacerItem(20, 13, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);

        verticalLayout_9->addItem(verticalSpacer_6);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_9);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName("verticalLayout_4");
        pauseButton = new QPushButton(centralwidget);
        pauseButton->setObjectName("pauseButton");

        verticalLayout_4->addWidget(pauseButton);

        resumeButton = new QPushButton(centralwidget);
        resumeButton->setObjectName("resumeButton");

        verticalLayout_4->addWidget(resumeButton);


        horizontalLayout_3->addLayout(verticalLayout_4);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_10);


        verticalLayout_9->addLayout(horizontalLayout_3);

        verticalSpacer_7 = new QSpacerItem(20, 13, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);

        verticalLayout_9->addItem(verticalSpacer_7);

        line_4 = new QFrame(centralwidget);
        line_4->setObjectName("line_4");
        line_4->setFrameShape(QFrame::Shape::HLine);
        line_4->setFrameShadow(QFrame::Shadow::Sunken);

        verticalLayout_9->addWidget(line_4);

        verticalSpacer_8 = new QSpacerItem(20, 13, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);

        verticalLayout_9->addItem(verticalSpacer_8);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_12);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName("verticalLayout_5");
        stepButton = new QPushButton(centralwidget);
        stepButton->setObjectName("stepButton");

        verticalLayout_5->addWidget(stepButton);

        clearButton = new QPushButton(centralwidget);
        clearButton->setObjectName("clearButton");

        verticalLayout_5->addWidget(clearButton);


        horizontalLayout_4->addLayout(verticalLayout_5);

        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_11);


        verticalLayout_9->addLayout(horizontalLayout_4);

        verticalSpacer_9 = new QSpacerItem(20, 13, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);

        verticalLayout_9->addItem(verticalSpacer_9);

        line_6 = new QFrame(centralwidget);
        line_6->setObjectName("line_6");
        line_6->setFrameShape(QFrame::Shape::HLine);
        line_6->setFrameShadow(QFrame::Shadow::Sunken);

        verticalLayout_9->addWidget(line_6);

        verticalSpacer_10 = new QSpacerItem(20, 13, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);

        verticalLayout_9->addItem(verticalSpacer_10);

        verticalLayout_12 = new QVBoxLayout();
        verticalLayout_12->setObjectName("verticalLayout_12");
        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setObjectName("horizontalLayout_15");
        horizontalSpacer_13 = new QSpacerItem(45, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        horizontalLayout_15->addItem(horizontalSpacer_13);

        randomButton = new QPushButton(centralwidget);
        randomButton->setObjectName("randomButton");

        horizontalLayout_15->addWidget(randomButton);

        horizontalSpacer_14 = new QSpacerItem(40, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);

        horizontalLayout_15->addItem(horizontalSpacer_14);


        verticalLayout_12->addLayout(horizontalLayout_15);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setObjectName("horizontalLayout_14");
        seedLabel = new QLabel(centralwidget);
        seedLabel->setObjectName("seedLabel");
        sizePolicy.setHeightForWidth(seedLabel->sizePolicy().hasHeightForWidth());
        seedLabel->setSizePolicy(sizePolicy);
        seedLabel->setMinimumSize(QSize(40, 27));
        seedLabel->setMaximumSize(QSize(40, 16777215));
        seedLabel->setFont(font);

        horizontalLayout_14->addWidget(seedLabel);

        setSeedBox = new QSpinBox(centralwidget);
        setSeedBox->setObjectName("setSeedBox");
        sizePolicy.setHeightForWidth(setSeedBox->sizePolicy().hasHeightForWidth());
        setSeedBox->setSizePolicy(sizePolicy);
        setSeedBox->setMinimumSize(QSize(135, 27));
        setSeedBox->setMaximumSize(QSize(60, 27));

        horizontalLayout_14->addWidget(setSeedBox);


        verticalLayout_12->addLayout(horizontalLayout_14);


        verticalLayout_9->addLayout(verticalLayout_12);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName("verticalLayout_6");

        verticalLayout_9->addLayout(verticalLayout_6);

        verticalSpacer_11 = new QSpacerItem(20, 13, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);

        verticalLayout_9->addItem(verticalSpacer_11);

        line_5 = new QFrame(centralwidget);
        line_5->setObjectName("line_5");
        line_5->setFrameShape(QFrame::Shape::HLine);
        line_5->setFrameShadow(QFrame::Shadow::Sunken);

        verticalLayout_9->addWidget(line_5);

        verticalSpacer_12 = new QSpacerItem(20, 13, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);

        verticalLayout_9->addItem(verticalSpacer_12);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName("verticalLayout_7");
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        speedLabel = new QLabel(centralwidget);
        speedLabel->setObjectName("speedLabel");
        speedLabel->setFont(font);

        horizontalLayout_7->addWidget(speedLabel);

        speedLCD = new QLCDNumber(centralwidget);
        speedLCD->setObjectName("speedLCD");
        sizePolicy.setHeightForWidth(speedLCD->sizePolicy().hasHeightForWidth());
        speedLCD->setSizePolicy(sizePolicy);
        speedLCD->setMinimumSize(QSize(100, 27));
        speedLCD->setMaximumSize(QSize(100, 27));
        speedLCD->setFont(font1);
        speedLCD->setAutoFillBackground(false);
        speedLCD->setStyleSheet(QString::fromUtf8("QLCDNumber::Flat {\n"
"    color: black; \n"
"    background-color: lightGray;\n"
"    border: 2px solid darkGray; \n"
"}\n"
"\n"
"QLCDNumber:flat {\n"
"    border: none;\n"
"}"));
        speedLCD->setSmallDecimalPoint(false);
        speedLCD->setDigitCount(7);
        speedLCD->setProperty("intValue", QVariant(50));

        horizontalLayout_7->addWidget(speedLCD);


        verticalLayout_7->addLayout(horizontalLayout_7);

        verticalSpacer_2 = new QSpacerItem(20, 13, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);

        verticalLayout_7->addItem(verticalSpacer_2);

        speedDial = new QDial(centralwidget);
        speedDial->setObjectName("speedDial");
        speedDial->setMinimumSize(QSize(150, 150));
        speedDial->setMinimum(1);
        speedDial->setMaximum(500);
        speedDial->setValue(50);
        speedDial->setTracking(true);
        speedDial->setWrapping(false);
        speedDial->setNotchesVisible(true);

        verticalLayout_7->addWidget(speedDial);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::MinimumExpanding);

        verticalLayout_7->addItem(verticalSpacer);


        verticalLayout_9->addLayout(verticalLayout_7);


        horizontalLayout_13->addLayout(verticalLayout_9);


        gridLayout->addLayout(horizontalLayout_13, 1, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1056, 21));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName("menuFile");
        menuEdit = new QMenu(menubar);
        menuEdit->setObjectName("menuEdit");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuEdit->menuAction());
        menuFile->addAction(actionSave);
        menuFile->addAction(actionOpen);
        menuEdit->addAction(actionColorLivingCells);
        menuEdit->addAction(actionColor_of_dead_cells);

        retranslateUi(MainWindow);

        startButton->setDefault(false);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Game Of Life", nullptr));
        actionSave->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
#if QT_CONFIG(shortcut)
        actionSave->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+S", nullptr));
#endif // QT_CONFIG(shortcut)
        actionOpen->setText(QCoreApplication::translate("MainWindow", "Open", nullptr));
#if QT_CONFIG(shortcut)
        actionOpen->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+O", nullptr));
#endif // QT_CONFIG(shortcut)
        actionColorLivingCells->setText(QCoreApplication::translate("MainWindow", "Color of living cells", nullptr));
#if QT_CONFIG(tooltip)
        actionColorLivingCells->setToolTip(QCoreApplication::translate("MainWindow", "Color of living cells", nullptr));
#endif // QT_CONFIG(tooltip)
        actionColor_of_dead_cells->setText(QCoreApplication::translate("MainWindow", "Color of dead cells", nullptr));
        columnsLabel->setText(QCoreApplication::translate("MainWindow", "Columns: [1 - 300]", nullptr));
        rowsLabel->setText(QCoreApplication::translate("MainWindow", "Rows: [1 - 300]", nullptr));
        stepsLabel->setText(QCoreApplication::translate("MainWindow", "Steps:", nullptr));
        lifeLabel->setText(QCoreApplication::translate("MainWindow", "Life:", nullptr));
        startButton->setText(QCoreApplication::translate("MainWindow", "Start", nullptr));
        stopButton->setText(QCoreApplication::translate("MainWindow", "Stop", nullptr));
        pauseButton->setText(QCoreApplication::translate("MainWindow", "Pause", nullptr));
        resumeButton->setText(QCoreApplication::translate("MainWindow", "Resume", nullptr));
        stepButton->setText(QCoreApplication::translate("MainWindow", "Step", nullptr));
        clearButton->setText(QCoreApplication::translate("MainWindow", "Clear", nullptr));
        randomButton->setText(QCoreApplication::translate("MainWindow", "Random Seed", nullptr));
        seedLabel->setText(QCoreApplication::translate("MainWindow", "Seed:  ", nullptr));
        speedLabel->setText(QCoreApplication::translate("MainWindow", "Speed (ms): ", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
        menuEdit->setTitle(QCoreApplication::translate("MainWindow", "Edit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
