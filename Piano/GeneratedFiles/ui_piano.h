/********************************************************************************
** Form generated from reading UI file 'piano.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PIANO_H
#define UI_PIANO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PianoClass
{
public:
    QWidget *centralWidget;
    QPushButton *NoteC;
    QPushButton *NoteD;
    QPushButton *NoteE;
    QPushButton *NoteF;
    QPushButton *NoteG;
    QPushButton *NoteA;
    QPushButton *NoteB;
    QPushButton *NoteCb;
    QPushButton *NoteDb;
    QPushButton *NoteFb;
    QPushButton *NoteGb;
    QPushButton *NoteAb;
    QLabel *label;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *PianoClass)
    {
        if (PianoClass->objectName().isEmpty())
            PianoClass->setObjectName(QStringLiteral("PianoClass"));
        PianoClass->resize(600, 400);
        centralWidget = new QWidget(PianoClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        NoteC = new QPushButton(centralWidget);
        NoteC->setObjectName(QStringLiteral("NoteC"));
        NoteC->setGeometry(QRect(70, 90, 61, 241));
        NoteD = new QPushButton(centralWidget);
        NoteD->setObjectName(QStringLiteral("NoteD"));
        NoteD->setGeometry(QRect(130, 90, 61, 241));
        NoteE = new QPushButton(centralWidget);
        NoteE->setObjectName(QStringLiteral("NoteE"));
        NoteE->setGeometry(QRect(190, 90, 61, 241));
        NoteF = new QPushButton(centralWidget);
        NoteF->setObjectName(QStringLiteral("NoteF"));
        NoteF->setGeometry(QRect(250, 90, 61, 241));
        NoteG = new QPushButton(centralWidget);
        NoteG->setObjectName(QStringLiteral("NoteG"));
        NoteG->setGeometry(QRect(310, 90, 61, 241));
        NoteA = new QPushButton(centralWidget);
        NoteA->setObjectName(QStringLiteral("NoteA"));
        NoteA->setGeometry(QRect(370, 90, 61, 241));
        NoteB = new QPushButton(centralWidget);
        NoteB->setObjectName(QStringLiteral("NoteB"));
        NoteB->setGeometry(QRect(430, 90, 61, 241));
        NoteCb = new QPushButton(centralWidget);
        NoteCb->setObjectName(QStringLiteral("NoteCb"));
        NoteCb->setGeometry(QRect(110, 90, 41, 161));
        NoteDb = new QPushButton(centralWidget);
        NoteDb->setObjectName(QStringLiteral("NoteDb"));
        NoteDb->setGeometry(QRect(170, 90, 41, 161));
        NoteFb = new QPushButton(centralWidget);
        NoteFb->setObjectName(QStringLiteral("NoteFb"));
        NoteFb->setGeometry(QRect(290, 90, 41, 161));
        NoteGb = new QPushButton(centralWidget);
        NoteGb->setObjectName(QStringLiteral("NoteGb"));
        NoteGb->setGeometry(QRect(350, 90, 41, 161));
        NoteAb = new QPushButton(centralWidget);
        NoteAb->setObjectName(QStringLiteral("NoteAb"));
        NoteAb->setGeometry(QRect(410, 90, 41, 161));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(190, 30, 221, 41));
        PianoClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(PianoClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 26));
        PianoClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(PianoClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        PianoClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(PianoClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        PianoClass->setStatusBar(statusBar);

        retranslateUi(PianoClass);

        NoteCb->setDefault(false);
        NoteDb->setDefault(false);
        NoteFb->setDefault(false);
        NoteGb->setDefault(false);
        NoteAb->setDefault(false);


        QMetaObject::connectSlotsByName(PianoClass);
    } // setupUi

    void retranslateUi(QMainWindow *PianoClass)
    {
        PianoClass->setWindowTitle(QApplication::translate("PianoClass", "Piano", 0));
        NoteC->setText(QApplication::translate("PianoClass", "C", 0));
        NoteD->setText(QApplication::translate("PianoClass", "D", 0));
        NoteE->setText(QApplication::translate("PianoClass", "E", 0));
        NoteF->setText(QApplication::translate("PianoClass", "F", 0));
        NoteG->setText(QApplication::translate("PianoClass", "G", 0));
        NoteA->setText(QApplication::translate("PianoClass", "A", 0));
        NoteB->setText(QApplication::translate("PianoClass", "B", 0));
        NoteCb->setText(QApplication::translate("PianoClass", "C#", 0));
        NoteDb->setText(QApplication::translate("PianoClass", "D#", 0));
        NoteFb->setText(QApplication::translate("PianoClass", "F#", 0));
        NoteGb->setText(QApplication::translate("PianoClass", "G#", 0));
        NoteAb->setText(QApplication::translate("PianoClass", "A#", 0));
        label->setText(QApplication::translate("PianoClass", "TextLabel", 0));
    } // retranslateUi

};

namespace Ui {
    class PianoClass: public Ui_PianoClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PIANO_H
