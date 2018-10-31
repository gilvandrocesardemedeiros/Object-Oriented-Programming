/********************************************************************************
** Form generated from reading UI file 'modificarporta.ui'
**
** Created by: Qt User Interface Compiler version 5.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODIFICARPORTA_H
#define UI_MODIFICARPORTA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *widget;
    QVBoxLayout *bloco_instrucoes;
    QHBoxLayout *linha_text;
    QLabel *text_porta;
    QLabel *text_numPorta;
    QHBoxLayout *linha_tipoPorta;
    QLabel *text_tipoPorta;
    QComboBox *comboBox_tipoPorta;
    QHBoxLayout *linha_numEntradas;
    QLabel *text_numEntradas;
    QSpinBox *spinBox_numEntradas;
    QHBoxLayout *linha_entrada1;
    QLabel *text_idEntrada1;
    QSpinBox *spinBox_idEntrada1;
    QHBoxLayout *horizontalLayout_5;
    QLabel *text_idEntrada1_2;
    QSpinBox *spinBox_idEntrada2;
    QHBoxLayout *horizontalLayout_6;
    QLabel *text_idEntrada1_3;
    QSpinBox *spinBox_idEntrada3;
    QHBoxLayout *horizontalLayout_7;
    QLabel *text_idEntrada4;
    QSpinBox *spinBox_idEntrada4;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QStringLiteral("Dialog"));
        Dialog->resize(275, 293);
        buttonBox = new QDialogButtonBox(Dialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(-120, 250, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        widget = new QWidget(Dialog);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(13, 8, 241, 211));
        bloco_instrucoes = new QVBoxLayout(widget);
        bloco_instrucoes->setObjectName(QStringLiteral("bloco_instrucoes"));
        bloco_instrucoes->setContentsMargins(0, 0, 0, 0);
        linha_text = new QHBoxLayout();
        linha_text->setObjectName(QStringLiteral("linha_text"));
        text_porta = new QLabel(widget);
        text_porta->setObjectName(QStringLiteral("text_porta"));

        linha_text->addWidget(text_porta);

        text_numPorta = new QLabel(widget);
        text_numPorta->setObjectName(QStringLiteral("text_numPorta"));

        linha_text->addWidget(text_numPorta);


        bloco_instrucoes->addLayout(linha_text);

        linha_tipoPorta = new QHBoxLayout();
        linha_tipoPorta->setObjectName(QStringLiteral("linha_tipoPorta"));
        text_tipoPorta = new QLabel(widget);
        text_tipoPorta->setObjectName(QStringLiteral("text_tipoPorta"));

        linha_tipoPorta->addWidget(text_tipoPorta);

        comboBox_tipoPorta = new QComboBox(widget);
        comboBox_tipoPorta->setObjectName(QStringLiteral("comboBox_tipoPorta"));

        linha_tipoPorta->addWidget(comboBox_tipoPorta);


        bloco_instrucoes->addLayout(linha_tipoPorta);

        linha_numEntradas = new QHBoxLayout();
        linha_numEntradas->setObjectName(QStringLiteral("linha_numEntradas"));
        text_numEntradas = new QLabel(widget);
        text_numEntradas->setObjectName(QStringLiteral("text_numEntradas"));

        linha_numEntradas->addWidget(text_numEntradas);

        spinBox_numEntradas = new QSpinBox(widget);
        spinBox_numEntradas->setObjectName(QStringLiteral("spinBox_numEntradas"));

        linha_numEntradas->addWidget(spinBox_numEntradas);


        bloco_instrucoes->addLayout(linha_numEntradas);

        linha_entrada1 = new QHBoxLayout();
        linha_entrada1->setObjectName(QStringLiteral("linha_entrada1"));
        text_idEntrada1 = new QLabel(widget);
        text_idEntrada1->setObjectName(QStringLiteral("text_idEntrada1"));

        linha_entrada1->addWidget(text_idEntrada1);

        spinBox_idEntrada1 = new QSpinBox(widget);
        spinBox_idEntrada1->setObjectName(QStringLiteral("spinBox_idEntrada1"));

        linha_entrada1->addWidget(spinBox_idEntrada1);


        bloco_instrucoes->addLayout(linha_entrada1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        text_idEntrada1_2 = new QLabel(widget);
        text_idEntrada1_2->setObjectName(QStringLiteral("text_idEntrada1_2"));

        horizontalLayout_5->addWidget(text_idEntrada1_2);

        spinBox_idEntrada2 = new QSpinBox(widget);
        spinBox_idEntrada2->setObjectName(QStringLiteral("spinBox_idEntrada2"));

        horizontalLayout_5->addWidget(spinBox_idEntrada2);


        bloco_instrucoes->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        text_idEntrada1_3 = new QLabel(widget);
        text_idEntrada1_3->setObjectName(QStringLiteral("text_idEntrada1_3"));

        horizontalLayout_6->addWidget(text_idEntrada1_3);

        spinBox_idEntrada3 = new QSpinBox(widget);
        spinBox_idEntrada3->setObjectName(QStringLiteral("spinBox_idEntrada3"));

        horizontalLayout_6->addWidget(spinBox_idEntrada3);


        bloco_instrucoes->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        text_idEntrada4 = new QLabel(widget);
        text_idEntrada4->setObjectName(QStringLiteral("text_idEntrada4"));

        horizontalLayout_7->addWidget(text_idEntrada4);

        spinBox_idEntrada4 = new QSpinBox(widget);
        spinBox_idEntrada4->setObjectName(QStringLiteral("spinBox_idEntrada4"));

        horizontalLayout_7->addWidget(spinBox_idEntrada4);


        bloco_instrucoes->addLayout(horizontalLayout_7);


        retranslateUi(Dialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), Dialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Dialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", nullptr));
        text_porta->setText(QApplication::translate("Dialog", "PORTA:", nullptr));
        text_numPorta->setText(QApplication::translate("Dialog", "null", nullptr));
        text_tipoPorta->setText(QApplication::translate("Dialog", "Tipo da porta:", nullptr));
        text_numEntradas->setText(QApplication::translate("Dialog", "N\302\272 de entradas:", nullptr));
        text_idEntrada1->setText(QApplication::translate("Dialog", "Id da entrada 1:", nullptr));
        text_idEntrada1_2->setText(QApplication::translate("Dialog", "Id da entrada 2:", nullptr));
        text_idEntrada1_3->setText(QApplication::translate("Dialog", "Id da entrada 3:", nullptr));
        text_idEntrada4->setText(QApplication::translate("Dialog", "Id da entrada 4:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODIFICARPORTA_H
