/********************************************************************************
** Form generated from reading UI file 'modificarsaida.ui'
**
** Created by: Qt User Interface Compiler version 5.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODIFICARSAIDA_H
#define UI_MODIFICARSAIDA_H

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
    QVBoxLayout *verticalLayout;
    QHBoxLayout *linha_saida;
    QLabel *text_saida;
    QLabel *text_numSaida;
    QHBoxLayout *linha_origem;
    QLabel *text_origem;
    QSpinBox *spinBox_numOrigem;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QStringLiteral("Dialog"));
        Dialog->resize(244, 125);
        buttonBox = new QDialogButtonBox(Dialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(-142, 83, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        widget = new QWidget(Dialog);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(8, 16, 211, 61));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        linha_saida = new QHBoxLayout();
        linha_saida->setObjectName(QStringLiteral("linha_saida"));
        text_saida = new QLabel(widget);
        text_saida->setObjectName(QStringLiteral("text_saida"));

        linha_saida->addWidget(text_saida);

        text_numSaida = new QLabel(widget);
        text_numSaida->setObjectName(QStringLiteral("text_numSaida"));

        linha_saida->addWidget(text_numSaida);


        verticalLayout->addLayout(linha_saida);

        linha_origem = new QHBoxLayout();
        linha_origem->setObjectName(QStringLiteral("linha_origem"));
        text_origem = new QLabel(widget);
        text_origem->setObjectName(QStringLiteral("text_origem"));

        linha_origem->addWidget(text_origem);

        spinBox_numOrigem = new QSpinBox(widget);
        spinBox_numOrigem->setObjectName(QStringLiteral("spinBox_numOrigem"));

        linha_origem->addWidget(spinBox_numOrigem);


        verticalLayout->addLayout(linha_origem);


        retranslateUi(Dialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), Dialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Dialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", nullptr));
        text_saida->setText(QApplication::translate("Dialog", "SA\303\215DA:", nullptr));
        text_numSaida->setText(QApplication::translate("Dialog", "null", nullptr));
        text_origem->setText(QApplication::translate("Dialog", "Id da origem:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODIFICARSAIDA_H
