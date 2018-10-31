/********************************************************************************
** Form generated from reading UI file 'novocircuito.ui'
**
** Created by: Qt User Interface Compiler version 5.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NOVOCIRCUITO_H
#define UI_NOVOCIRCUITO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
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
    QHBoxLayout *bloco_informacoes;
    QVBoxLayout *coluna_text;
    QLabel *text_entradas;
    QLabel *text_saidas;
    QLabel *text_portas;
    QVBoxLayout *coluna_spinbox;
    QSpinBox *spinBox_entradas;
    QSpinBox *spinBox_saidas;
    QSpinBox *spinBox_portas;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QStringLiteral("Dialog"));
        Dialog->setWindowModality(Qt::NonModal);
        Dialog->setEnabled(true);
        Dialog->resize(239, 167);
        buttonBox = new QDialogButtonBox(Dialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(-136, 130, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        widget = new QWidget(Dialog);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(5, 13, 231, 111));
        bloco_informacoes = new QHBoxLayout(widget);
        bloco_informacoes->setObjectName(QStringLiteral("bloco_informacoes"));
        bloco_informacoes->setContentsMargins(0, 0, 0, 0);
        coluna_text = new QVBoxLayout();
        coluna_text->setObjectName(QStringLiteral("coluna_text"));
        text_entradas = new QLabel(widget);
        text_entradas->setObjectName(QStringLiteral("text_entradas"));

        coluna_text->addWidget(text_entradas);

        text_saidas = new QLabel(widget);
        text_saidas->setObjectName(QStringLiteral("text_saidas"));

        coluna_text->addWidget(text_saidas);

        text_portas = new QLabel(widget);
        text_portas->setObjectName(QStringLiteral("text_portas"));

        coluna_text->addWidget(text_portas);


        bloco_informacoes->addLayout(coluna_text);

        coluna_spinbox = new QVBoxLayout();
        coluna_spinbox->setObjectName(QStringLiteral("coluna_spinbox"));
        spinBox_entradas = new QSpinBox(widget);
        spinBox_entradas->setObjectName(QStringLiteral("spinBox_entradas"));

        coluna_spinbox->addWidget(spinBox_entradas);

        spinBox_saidas = new QSpinBox(widget);
        spinBox_saidas->setObjectName(QStringLiteral("spinBox_saidas"));

        coluna_spinbox->addWidget(spinBox_saidas);

        spinBox_portas = new QSpinBox(widget);
        spinBox_portas->setObjectName(QStringLiteral("spinBox_portas"));

        coluna_spinbox->addWidget(spinBox_portas);


        bloco_informacoes->addLayout(coluna_spinbox);


        retranslateUi(Dialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), Dialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Dialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Novo Circuito", nullptr));
        text_entradas->setText(QApplication::translate("Dialog", "N\303\272mero de entradas:", nullptr));
        text_saidas->setText(QApplication::translate("Dialog", "N\303\272mero de sa\303\255das:", nullptr));
        text_portas->setText(QApplication::translate("Dialog", "N\303\272mero de portas:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NOVOCIRCUITO_H
