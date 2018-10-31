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
    QWidget *JanelaPrincipal;
    QLabel *text_circuito;
    QLabel *text_portas;
    QLabel *text_saidas;
    QLabel *text_tabelaverdade;
    QTableWidget *table_portas;
    QTableWidget *table_saidas;
    QTableWidget *tabelaVerdade;
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
        JanelaPrincipal = new QWidget(circuito);
        JanelaPrincipal->setObjectName(QStringLiteral("JanelaPrincipal"));
        text_circuito = new QLabel(JanelaPrincipal);
        text_circuito->setObjectName(QStringLiteral("text_circuito"));
        text_circuito->setGeometry(QRect(0, 0, 321, 21));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        text_circuito->setFont(font);
        text_circuito->setFocusPolicy(Qt::NoFocus);
        text_circuito->setLayoutDirection(Qt::LeftToRight);
        text_circuito->setAutoFillBackground(true);
        text_circuito->setFrameShape(QFrame::Box);
        text_circuito->setFrameShadow(QFrame::Plain);
        text_circuito->setTextFormat(Qt::PlainText);
        text_circuito->setScaledContents(false);
        text_circuito->setAlignment(Qt::AlignCenter);
        text_circuito->setWordWrap(false);
        text_portas = new QLabel(JanelaPrincipal);
        text_portas->setObjectName(QStringLiteral("text_portas"));
        text_portas->setGeometry(QRect(0, 20, 231, 20));
        text_portas->setFont(font);
        text_portas->setFocusPolicy(Qt::NoFocus);
        text_portas->setLayoutDirection(Qt::LeftToRight);
        text_portas->setAutoFillBackground(true);
        text_portas->setFrameShape(QFrame::Box);
        text_portas->setFrameShadow(QFrame::Plain);
        text_portas->setTextFormat(Qt::PlainText);
        text_portas->setScaledContents(false);
        text_portas->setAlignment(Qt::AlignCenter);
        text_portas->setWordWrap(false);
        text_saidas = new QLabel(JanelaPrincipal);
        text_saidas->setObjectName(QStringLiteral("text_saidas"));
        text_saidas->setGeometry(QRect(230, 20, 91, 20));
        text_saidas->setFont(font);
        text_saidas->setFocusPolicy(Qt::NoFocus);
        text_saidas->setLayoutDirection(Qt::LeftToRight);
        text_saidas->setAutoFillBackground(true);
        text_saidas->setFrameShape(QFrame::Box);
        text_saidas->setFrameShadow(QFrame::Plain);
        text_saidas->setTextFormat(Qt::PlainText);
        text_saidas->setScaledContents(false);
        text_saidas->setAlignment(Qt::AlignCenter);
        text_saidas->setWordWrap(false);
        text_tabelaverdade = new QLabel(JanelaPrincipal);
        text_tabelaverdade->setObjectName(QStringLiteral("text_tabelaverdade"));
        text_tabelaverdade->setGeometry(QRect(330, 0, 261, 20));
        text_tabelaverdade->setFont(font);
        text_tabelaverdade->setFocusPolicy(Qt::NoFocus);
        text_tabelaverdade->setLayoutDirection(Qt::LeftToRight);
        text_tabelaverdade->setAutoFillBackground(true);
        text_tabelaverdade->setFrameShape(QFrame::Box);
        text_tabelaverdade->setFrameShadow(QFrame::Plain);
        text_tabelaverdade->setTextFormat(Qt::PlainText);
        text_tabelaverdade->setScaledContents(false);
        text_tabelaverdade->setAlignment(Qt::AlignCenter);
        text_tabelaverdade->setWordWrap(false);
        table_portas = new QTableWidget(JanelaPrincipal);
        table_portas->setObjectName(QStringLiteral("table_portas"));
        table_portas->setGeometry(QRect(0, 39, 231, 381));
        table_portas->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        table_portas->setAutoScroll(true);
        table_saidas = new QTableWidget(JanelaPrincipal);
        if (table_saidas->columnCount() < 1)
            table_saidas->setColumnCount(1);
        table_saidas->setObjectName(QStringLiteral("table_saidas"));
        table_saidas->setGeometry(QRect(230, 39, 91, 381));
        table_saidas->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        table_saidas->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);
        table_saidas->setAutoScroll(true);
        table_saidas->setRowCount(0);
        table_saidas->setColumnCount(1);
        table_saidas->horizontalHeader()->setVisible(false);
        table_saidas->horizontalHeader()->setDefaultSectionSize(75);
        table_saidas->horizontalHeader()->setHighlightSections(false);
        table_saidas->verticalHeader()->setVisible(false);
        tabelaVerdade = new QTableWidget(JanelaPrincipal);
        tabelaVerdade->setObjectName(QStringLiteral("tabelaVerdade"));
        tabelaVerdade->setGeometry(QRect(330, 20, 261, 401));
        tabelaVerdade->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        circuito->setCentralWidget(JanelaPrincipal);
        text_circuito->raise();
        table_portas->raise();
        table_saidas->raise();
        tabelaVerdade->raise();
        text_tabelaverdade->raise();
        text_saidas->raise();
        text_portas->raise();
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
        text_circuito->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        text_circuito->setText(QApplication::translate("circuito", "CIRCUITO", nullptr));
#ifndef QT_NO_TOOLTIP
        text_portas->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        text_portas->setText(QApplication::translate("circuito", "PORTAS E CONEX\303\225ES", nullptr));
#ifndef QT_NO_TOOLTIP
        text_saidas->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        text_saidas->setText(QApplication::translate("circuito", "SA\303\215DAS", nullptr));
#ifndef QT_NO_TOOLTIP
        text_tabelaverdade->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        text_tabelaverdade->setText(QApplication::translate("circuito", "TABELA VERDADE", nullptr));
        menuCircuito->setTitle(QApplication::translate("circuito", "Circuito", nullptr));
        menuSimular->setTitle(QApplication::translate("circuito", "Simular", nullptr));
    } // retranslateUi

};

namespace Ui {
    class circuito: public Ui_circuito {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CIRCUITO_H
