/********************************************************************************
** Form generated from reading UI file 'circuito.ui'
**
** Created by: Qt User Interface Compiler version 5.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CIRCUITO_H
#define UI_CIRCUITO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_circuito
{
public:
    QAction *actionNovo;
    QAction *actionLer;
    QAction *actionSalvar;
    QAction *actionSair;
    QAction *actionGerar_Tabela;
    QWidget *centralWidget;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QTableWidget *tableWidget;
    QTableWidget *tableWidget_2;
    QTableWidget *tableWidget_3;
    QMenuBar *menuBar;
    QMenu *menuCircuito;
    QMenu *menuSimular;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *circuito)
    {
        if (circuito->objectName().isEmpty())
            circuito->setObjectName(QStringLiteral("circuito"));
        circuito->resize(598, 488);
        actionNovo = new QAction(circuito);
        actionNovo->setObjectName(QStringLiteral("actionNovo"));
        actionLer = new QAction(circuito);
        actionLer->setObjectName(QStringLiteral("actionLer"));
        actionSalvar = new QAction(circuito);
        actionSalvar->setObjectName(QStringLiteral("actionSalvar"));
        actionSair = new QAction(circuito);
        actionSair->setObjectName(QStringLiteral("actionSair"));
        actionGerar_Tabela = new QAction(circuito);
        actionGerar_Tabela->setObjectName(QStringLiteral("actionGerar_Tabela"));
        centralWidget = new QWidget(circuito);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 0, 321, 21));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label->setFocusPolicy(Qt::NoFocus);
        label->setLayoutDirection(Qt::LeftToRight);
        label->setAutoFillBackground(true);
        label->setFrameShape(QFrame::Box);
        label->setFrameShadow(QFrame::Plain);
        label->setTextFormat(Qt::PlainText);
        label->setScaledContents(false);
        label->setAlignment(Qt::AlignCenter);
        label->setWordWrap(false);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(0, 20, 231, 20));
        label_2->setFont(font);
        label_2->setFocusPolicy(Qt::NoFocus);
        label_2->setLayoutDirection(Qt::LeftToRight);
        label_2->setAutoFillBackground(true);
        label_2->setFrameShape(QFrame::Box);
        label_2->setFrameShadow(QFrame::Plain);
        label_2->setTextFormat(Qt::PlainText);
        label_2->setScaledContents(false);
        label_2->setAlignment(Qt::AlignCenter);
        label_2->setWordWrap(false);
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(230, 20, 91, 20));
        label_3->setFont(font);
        label_3->setFocusPolicy(Qt::NoFocus);
        label_3->setLayoutDirection(Qt::LeftToRight);
        label_3->setAutoFillBackground(true);
        label_3->setFrameShape(QFrame::Box);
        label_3->setFrameShadow(QFrame::Plain);
        label_3->setTextFormat(Qt::PlainText);
        label_3->setScaledContents(false);
        label_3->setAlignment(Qt::AlignCenter);
        label_3->setWordWrap(false);
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(330, 0, 261, 20));
        label_4->setFont(font);
        label_4->setFocusPolicy(Qt::NoFocus);
        label_4->setLayoutDirection(Qt::LeftToRight);
        label_4->setAutoFillBackground(true);
        label_4->setFrameShape(QFrame::Box);
        label_4->setFrameShadow(QFrame::Plain);
        label_4->setTextFormat(Qt::PlainText);
        label_4->setScaledContents(false);
        label_4->setAlignment(Qt::AlignCenter);
        label_4->setWordWrap(false);
        tableWidget = new QTableWidget(centralWidget);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(0, 39, 231, 381));
        tableWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        tableWidget->setAutoScroll(true);
        tableWidget_2 = new QTableWidget(centralWidget);
        if (tableWidget_2->columnCount() < 1)
            tableWidget_2->setColumnCount(1);
        if (tableWidget_2->rowCount() < 2)
            tableWidget_2->setRowCount(2);
        tableWidget_2->setObjectName(QStringLiteral("tableWidget_2"));
        tableWidget_2->setGeometry(QRect(230, 39, 91, 381));
        tableWidget_2->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        tableWidget_2->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);
        tableWidget_2->setAutoScroll(true);
        tableWidget_2->setRowCount(2);
        tableWidget_2->setColumnCount(1);
        tableWidget_2->horizontalHeader()->setVisible(false);
        tableWidget_2->horizontalHeader()->setDefaultSectionSize(75);
        tableWidget_2->horizontalHeader()->setHighlightSections(false);
        tableWidget_2->verticalHeader()->setVisible(false);
        tableWidget_3 = new QTableWidget(centralWidget);
        tableWidget_3->setObjectName(QStringLiteral("tableWidget_3"));
        tableWidget_3->setGeometry(QRect(330, 20, 261, 401));
        tableWidget_3->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        circuito->setCentralWidget(centralWidget);
        label->raise();
        tableWidget->raise();
        tableWidget_2->raise();
        tableWidget_3->raise();
        label_4->raise();
        label_3->raise();
        label_2->raise();
        menuBar = new QMenuBar(circuito);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 598, 22));
        menuCircuito = new QMenu(menuBar);
        menuCircuito->setObjectName(QStringLiteral("menuCircuito"));
        menuSimular = new QMenu(menuBar);
        menuSimular->setObjectName(QStringLiteral("menuSimular"));
        circuito->setMenuBar(menuBar);
        mainToolBar = new QToolBar(circuito);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        mainToolBar->setEnabled(true);
        circuito->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(circuito);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        circuito->setStatusBar(statusBar);

        menuBar->addAction(menuCircuito->menuAction());
        menuBar->addAction(menuSimular->menuAction());
        menuCircuito->addAction(actionNovo);
        menuCircuito->addAction(actionLer);
        menuCircuito->addAction(actionSalvar);
        menuCircuito->addSeparator();
        menuCircuito->addAction(actionSair);
        menuSimular->addAction(actionGerar_Tabela);

        retranslateUi(circuito);

        QMetaObject::connectSlotsByName(circuito);
    } // setupUi

    void retranslateUi(QMainWindow *circuito)
    {
        circuito->setWindowTitle(QApplication::translate("circuito", "Simulador de Circuitos Digitais", nullptr));
        actionNovo->setText(QApplication::translate("circuito", "Novo...", nullptr));
        actionLer->setText(QApplication::translate("circuito", "Ler...", nullptr));
        actionSalvar->setText(QApplication::translate("circuito", "Salvar...", nullptr));
        actionSair->setText(QApplication::translate("circuito", "Sair", nullptr));
        actionGerar_Tabela->setText(QApplication::translate("circuito", "Gerar Tabela", nullptr));
#ifndef QT_NO_TOOLTIP
        label->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        label->setText(QApplication::translate("circuito", "CIRCUITO", nullptr));
#ifndef QT_NO_TOOLTIP
        label_2->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        label_2->setText(QApplication::translate("circuito", "PORTAS E CONEX\303\225ES", nullptr));
#ifndef QT_NO_TOOLTIP
        label_3->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        label_3->setText(QApplication::translate("circuito", "SA\303\215DAS", nullptr));
#ifndef QT_NO_TOOLTIP
        label_4->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        label_4->setText(QApplication::translate("circuito", "TABELA VERDADE", nullptr));
        menuCircuito->setTitle(QApplication::translate("circuito", "Circuito", nullptr));
        menuSimular->setTitle(QApplication::translate("circuito", "Simular", nullptr));
    } // retranslateUi

};

namespace Ui {
    class circuito: public Ui_circuito {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CIRCUITO_H
