/********************************************************************************
** Form generated from reading UI file 'mainsudoku.ui'
**
** Created by: Qt User Interface Compiler version 5.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINSUDOKU_H
#define UI_MAINSUDOKU_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainSudoku
{
public:
    QAction *actionReiniciar;
    QAction *actionNovo;
    QAction *actionPreencher_Imediatas;
    QAction *actionSair;
    QAction *actionResolver;
    QWidget *centralWidget;
    QPushButton *button_continuar;
    QTableWidget *table_inicial;
    QWidget *layoutWidget;
    QVBoxLayout *carac_linhas;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *info_jogo;
    QTableWidget *tab_atual;
    QSplitter *carac_num_inicial;
    QLabel *label_24;
    QLabel *label_25;
    QLabel *label_26;
    QLabel *label_27;
    QLabel *label_28;
    QLabel *label_29;
    QLabel *label_30;
    QLabel *label_31;
    QLabel *label_32;
    QSplitter *splitter_jogo;
    QLabel *label_valor;
    QSpinBox *spinbox_valor;
    QPushButton *button_jogar;
    QSplitter *info_tab;
    QLabel *label;
    QLabel *label_2;
    QSplitter *carac_num_atual;
    QLabel *label_15;
    QLabel *label_16;
    QLabel *label_17;
    QLabel *label_18;
    QLabel *label_19;
    QLabel *label_20;
    QLabel *label_21;
    QLabel *label_22;
    QLabel *label_23;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout;
    QSplitter *info_linhas_e_colunas;
    QLabel *label_12;
    QLabel *label_13;
    QVBoxLayout *verticalLayout;
    QLabel *NumL;
    QLabel *NumC;
    QLabel *label_11;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QMenuBar *menuBar;
    QMenu *menuSudoku;

    void setupUi(QMainWindow *MainSudoku)
    {
        if (MainSudoku->objectName().isEmpty())
            MainSudoku->setObjectName(QStringLiteral("MainSudoku"));
        MainSudoku->resize(601, 420);
        actionReiniciar = new QAction(MainSudoku);
        actionReiniciar->setObjectName(QStringLiteral("actionReiniciar"));
        actionReiniciar->setCheckable(false);
        actionNovo = new QAction(MainSudoku);
        actionNovo->setObjectName(QStringLiteral("actionNovo"));
        actionPreencher_Imediatas = new QAction(MainSudoku);
        actionPreencher_Imediatas->setObjectName(QStringLiteral("actionPreencher_Imediatas"));
        actionSair = new QAction(MainSudoku);
        actionSair->setObjectName(QStringLiteral("actionSair"));
        actionResolver = new QAction(MainSudoku);
        actionResolver->setObjectName(QStringLiteral("actionResolver"));
        centralWidget = new QWidget(MainSudoku);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        button_continuar = new QPushButton(centralWidget);
        button_continuar->setObjectName(QStringLiteral("button_continuar"));
        button_continuar->setGeometry(QRect(470, 330, 101, 25));
        button_continuar->setInputMethodHints(Qt::ImhNone);
        table_inicial = new QTableWidget(centralWidget);
        if (table_inicial->columnCount() < 9)
            table_inicial->setColumnCount(9);
        if (table_inicial->rowCount() < 9)
            table_inicial->setRowCount(9);
        table_inicial->setObjectName(QStringLiteral("table_inicial"));
        table_inicial->setGeometry(QRect(320, 31, 271, 271));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(table_inicial->sizePolicy().hasHeightForWidth());
        table_inicial->setSizePolicy(sizePolicy);
        table_inicial->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        table_inicial->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        table_inicial->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);
        table_inicial->setAutoScroll(true);
        table_inicial->setTabKeyNavigation(true);
        table_inicial->setWordWrap(true);
        table_inicial->setRowCount(9);
        table_inicial->setColumnCount(9);
        table_inicial->horizontalHeader()->setVisible(false);
        table_inicial->horizontalHeader()->setDefaultSectionSize(30);
        table_inicial->horizontalHeader()->setMinimumSectionSize(30);
        table_inicial->verticalHeader()->setVisible(false);
        table_inicial->verticalHeader()->setHighlightSections(true);
        table_inicial->verticalHeader()->setMinimumSectionSize(30);
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(292, 32, 16, 241));
        carac_linhas = new QVBoxLayout(layoutWidget);
        carac_linhas->setSpacing(6);
        carac_linhas->setContentsMargins(11, 11, 11, 11);
        carac_linhas->setObjectName(QStringLiteral("carac_linhas"));
        carac_linhas->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setAlignment(Qt::AlignCenter);

        carac_linhas->addWidget(label_3);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setAlignment(Qt::AlignCenter);

        carac_linhas->addWidget(label_4);

        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setAlignment(Qt::AlignCenter);

        carac_linhas->addWidget(label_5);

        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setAlignment(Qt::AlignCenter);

        carac_linhas->addWidget(label_6);

        label_7 = new QLabel(layoutWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setAlignment(Qt::AlignCenter);

        carac_linhas->addWidget(label_7);

        label_8 = new QLabel(layoutWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setAlignment(Qt::AlignCenter);

        carac_linhas->addWidget(label_8);

        label_9 = new QLabel(layoutWidget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setAlignment(Qt::AlignCenter);

        carac_linhas->addWidget(label_9);

        label_10 = new QLabel(layoutWidget);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setAlignment(Qt::AlignCenter);

        carac_linhas->addWidget(label_10);

        info_jogo = new QLabel(centralWidget);
        info_jogo->setObjectName(QStringLiteral("info_jogo"));
        info_jogo->setGeometry(QRect(10, 303, 521, 17));
        QFont font;
        font.setPointSize(10);
        info_jogo->setFont(font);
        tab_atual = new QTableWidget(centralWidget);
        if (tab_atual->columnCount() < 9)
            tab_atual->setColumnCount(9);
        if (tab_atual->rowCount() < 9)
            tab_atual->setRowCount(9);
        tab_atual->setObjectName(QStringLiteral("tab_atual"));
        tab_atual->setGeometry(QRect(10, 31, 271, 271));
        sizePolicy.setHeightForWidth(tab_atual->sizePolicy().hasHeightForWidth());
        tab_atual->setSizePolicy(sizePolicy);
        tab_atual->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tab_atual->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tab_atual->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);
        tab_atual->setAutoScroll(true);
        tab_atual->setTabKeyNavigation(true);
        tab_atual->setWordWrap(true);
        tab_atual->setRowCount(9);
        tab_atual->setColumnCount(9);
        tab_atual->horizontalHeader()->setVisible(false);
        tab_atual->horizontalHeader()->setDefaultSectionSize(30);
        tab_atual->horizontalHeader()->setMinimumSectionSize(30);
        tab_atual->verticalHeader()->setVisible(false);
        tab_atual->verticalHeader()->setHighlightSections(true);
        tab_atual->verticalHeader()->setMinimumSectionSize(30);
        carac_num_inicial = new QSplitter(centralWidget);
        carac_num_inicial->setObjectName(QStringLiteral("carac_num_inicial"));
        carac_num_inicial->setGeometry(QRect(320, 15, 271, 17));
        carac_num_inicial->setOrientation(Qt::Horizontal);
        label_24 = new QLabel(carac_num_inicial);
        label_24->setObjectName(QStringLiteral("label_24"));
        label_24->setAlignment(Qt::AlignCenter);
        carac_num_inicial->addWidget(label_24);
        label_25 = new QLabel(carac_num_inicial);
        label_25->setObjectName(QStringLiteral("label_25"));
        label_25->setAlignment(Qt::AlignCenter);
        carac_num_inicial->addWidget(label_25);
        label_26 = new QLabel(carac_num_inicial);
        label_26->setObjectName(QStringLiteral("label_26"));
        label_26->setAlignment(Qt::AlignCenter);
        carac_num_inicial->addWidget(label_26);
        label_27 = new QLabel(carac_num_inicial);
        label_27->setObjectName(QStringLiteral("label_27"));
        label_27->setAlignment(Qt::AlignCenter);
        carac_num_inicial->addWidget(label_27);
        label_28 = new QLabel(carac_num_inicial);
        label_28->setObjectName(QStringLiteral("label_28"));
        label_28->setAlignment(Qt::AlignCenter);
        carac_num_inicial->addWidget(label_28);
        label_29 = new QLabel(carac_num_inicial);
        label_29->setObjectName(QStringLiteral("label_29"));
        label_29->setAlignment(Qt::AlignCenter);
        carac_num_inicial->addWidget(label_29);
        label_30 = new QLabel(carac_num_inicial);
        label_30->setObjectName(QStringLiteral("label_30"));
        label_30->setAlignment(Qt::AlignCenter);
        carac_num_inicial->addWidget(label_30);
        label_31 = new QLabel(carac_num_inicial);
        label_31->setObjectName(QStringLiteral("label_31"));
        label_31->setAlignment(Qt::AlignCenter);
        carac_num_inicial->addWidget(label_31);
        label_32 = new QLabel(carac_num_inicial);
        label_32->setObjectName(QStringLiteral("label_32"));
        label_32->setAlignment(Qt::AlignCenter);
        carac_num_inicial->addWidget(label_32);
        splitter_jogo = new QSplitter(centralWidget);
        splitter_jogo->setObjectName(QStringLiteral("splitter_jogo"));
        splitter_jogo->setGeometry(QRect(160, 330, 241, 26));
        splitter_jogo->setOrientation(Qt::Horizontal);
        label_valor = new QLabel(splitter_jogo);
        label_valor->setObjectName(QStringLiteral("label_valor"));
        splitter_jogo->addWidget(label_valor);
        spinbox_valor = new QSpinBox(splitter_jogo);
        spinbox_valor->setObjectName(QStringLiteral("spinbox_valor"));
        splitter_jogo->addWidget(spinbox_valor);
        button_jogar = new QPushButton(splitter_jogo);
        button_jogar->setObjectName(QStringLiteral("button_jogar"));
        splitter_jogo->addWidget(button_jogar);
        info_tab = new QSplitter(centralWidget);
        info_tab->setObjectName(QStringLiteral("info_tab"));
        info_tab->setGeometry(QRect(0, 0, 601, 20));
        info_tab->setOrientation(Qt::Horizontal);
        label = new QLabel(info_tab);
        label->setObjectName(QStringLiteral("label"));
        label->setLayoutDirection(Qt::LeftToRight);
        label->setFrameShadow(QFrame::Plain);
        label->setAlignment(Qt::AlignCenter);
        info_tab->addWidget(label);
        label_2 = new QLabel(info_tab);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setAlignment(Qt::AlignCenter);
        info_tab->addWidget(label_2);
        carac_num_atual = new QSplitter(centralWidget);
        carac_num_atual->setObjectName(QStringLiteral("carac_num_atual"));
        carac_num_atual->setGeometry(QRect(10, 16, 271, 17));
        carac_num_atual->setOrientation(Qt::Horizontal);
        label_15 = new QLabel(carac_num_atual);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setAlignment(Qt::AlignCenter);
        carac_num_atual->addWidget(label_15);
        label_16 = new QLabel(carac_num_atual);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setAlignment(Qt::AlignCenter);
        carac_num_atual->addWidget(label_16);
        label_17 = new QLabel(carac_num_atual);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setAlignment(Qt::AlignCenter);
        carac_num_atual->addWidget(label_17);
        label_18 = new QLabel(carac_num_atual);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setAlignment(Qt::AlignCenter);
        carac_num_atual->addWidget(label_18);
        label_19 = new QLabel(carac_num_atual);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setAlignment(Qt::AlignCenter);
        carac_num_atual->addWidget(label_19);
        label_20 = new QLabel(carac_num_atual);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setAlignment(Qt::AlignCenter);
        carac_num_atual->addWidget(label_20);
        label_21 = new QLabel(carac_num_atual);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setAlignment(Qt::AlignCenter);
        carac_num_atual->addWidget(label_21);
        label_22 = new QLabel(carac_num_atual);
        label_22->setObjectName(QStringLiteral("label_22"));
        label_22->setAlignment(Qt::AlignCenter);
        carac_num_atual->addWidget(label_22);
        label_23 = new QLabel(carac_num_atual);
        label_23->setObjectName(QStringLiteral("label_23"));
        label_23->setAlignment(Qt::AlignCenter);
        carac_num_atual->addWidget(label_23);
        layoutWidget1 = new QWidget(centralWidget);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 320, 112, 40));
        horizontalLayout = new QHBoxLayout(layoutWidget1);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        info_linhas_e_colunas = new QSplitter(layoutWidget1);
        info_linhas_e_colunas->setObjectName(QStringLiteral("info_linhas_e_colunas"));
        info_linhas_e_colunas->setOrientation(Qt::Vertical);
        label_12 = new QLabel(info_linhas_e_colunas);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setFont(font);
        info_linhas_e_colunas->addWidget(label_12);
        label_13 = new QLabel(info_linhas_e_colunas);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setFont(font);
        info_linhas_e_colunas->addWidget(label_13);

        horizontalLayout->addWidget(info_linhas_e_colunas);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        NumL = new QLabel(layoutWidget1);
        NumL->setObjectName(QStringLiteral("NumL"));
        NumL->setFont(font);

        verticalLayout->addWidget(NumL);

        NumC = new QLabel(layoutWidget1);
        NumC->setObjectName(QStringLiteral("NumC"));
        NumC->setFont(font);

        verticalLayout->addWidget(NumC);


        horizontalLayout->addLayout(verticalLayout);

        label_11 = new QLabel(centralWidget);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(280, 274, 41, 25));
        label_11->setAlignment(Qt::AlignCenter);
        MainSudoku->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(MainSudoku);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainSudoku->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainSudoku);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainSudoku->setStatusBar(statusBar);
        menuBar = new QMenuBar(MainSudoku);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 601, 22));
        menuSudoku = new QMenu(menuBar);
        menuSudoku->setObjectName(QStringLiteral("menuSudoku"));
        MainSudoku->setMenuBar(menuBar);

        menuBar->addAction(menuSudoku->menuAction());
        menuSudoku->addAction(actionReiniciar);
        menuSudoku->addAction(actionNovo);
        menuSudoku->addAction(actionPreencher_Imediatas);
        menuSudoku->addAction(actionResolver);
        menuSudoku->addSeparator();
        menuSudoku->addAction(actionSair);

        retranslateUi(MainSudoku);

        QMetaObject::connectSlotsByName(MainSudoku);
    } // setupUi

    void retranslateUi(QMainWindow *MainSudoku)
    {
        MainSudoku->setWindowTitle(QApplication::translate("MainSudoku", "Sudoku - Quadrados Magicos", nullptr));
        actionReiniciar->setText(QApplication::translate("MainSudoku", "Reiniciar", nullptr));
        actionNovo->setText(QApplication::translate("MainSudoku", "Novo", nullptr));
        actionPreencher_Imediatas->setText(QApplication::translate("MainSudoku", "Preencher Imediatas", nullptr));
        actionSair->setText(QApplication::translate("MainSudoku", "Sair", nullptr));
        actionResolver->setText(QApplication::translate("MainSudoku", "Resolver", nullptr));
        button_continuar->setText(QApplication::translate("MainSudoku", "CONTINUAR", nullptr));
        label_3->setText(QApplication::translate("MainSudoku", "A", nullptr));
        label_4->setText(QApplication::translate("MainSudoku", "B", nullptr));
        label_5->setText(QApplication::translate("MainSudoku", "C", nullptr));
        label_6->setText(QApplication::translate("MainSudoku", "D", nullptr));
        label_7->setText(QApplication::translate("MainSudoku", "E", nullptr));
        label_8->setText(QApplication::translate("MainSudoku", "F", nullptr));
        label_9->setText(QApplication::translate("MainSudoku", "G", nullptr));
        label_10->setText(QApplication::translate("MainSudoku", "H", nullptr));
        info_jogo->setText(QApplication::translate("MainSudoku", "Escolha a casa (clique no tabuleiro) e o valor da jogada (1 a 9 ou apagar): ", nullptr));
        label_24->setText(QApplication::translate("MainSudoku", "1", nullptr));
        label_25->setText(QApplication::translate("MainSudoku", "2", nullptr));
        label_26->setText(QApplication::translate("MainSudoku", "3", nullptr));
        label_27->setText(QApplication::translate("MainSudoku", "4", nullptr));
        label_28->setText(QApplication::translate("MainSudoku", "5", nullptr));
        label_29->setText(QApplication::translate("MainSudoku", "6", nullptr));
        label_30->setText(QApplication::translate("MainSudoku", "7", nullptr));
        label_31->setText(QApplication::translate("MainSudoku", "8", nullptr));
        label_32->setText(QApplication::translate("MainSudoku", "9", nullptr));
        label_valor->setText(QApplication::translate("MainSudoku", "VALOR:", nullptr));
        button_jogar->setText(QApplication::translate("MainSudoku", "JOGAR", nullptr));
        label->setText(QApplication::translate("MainSudoku", "TABULEIRO ATUAL", nullptr));
        label_2->setText(QApplication::translate("MainSudoku", "TABULEIRO INICIAL", nullptr));
        label_15->setText(QApplication::translate("MainSudoku", "1", nullptr));
        label_16->setText(QApplication::translate("MainSudoku", "2", nullptr));
        label_17->setText(QApplication::translate("MainSudoku", "3", nullptr));
        label_18->setText(QApplication::translate("MainSudoku", "4", nullptr));
        label_19->setText(QApplication::translate("MainSudoku", "5", nullptr));
        label_20->setText(QApplication::translate("MainSudoku", "6", nullptr));
        label_21->setText(QApplication::translate("MainSudoku", "7", nullptr));
        label_22->setText(QApplication::translate("MainSudoku", "8", nullptr));
        label_23->setText(QApplication::translate("MainSudoku", "9", nullptr));
        label_12->setText(QApplication::translate("MainSudoku", "Linha:", nullptr));
        label_13->setText(QApplication::translate("MainSudoku", "Coluna:", nullptr));
        NumL->setText(QString());
        NumC->setText(QString());
        label_11->setText(QApplication::translate("MainSudoku", "I", nullptr));
        menuSudoku->setTitle(QApplication::translate("MainSudoku", "Sudoku", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainSudoku: public Ui_MainSudoku {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINSUDOKU_H
