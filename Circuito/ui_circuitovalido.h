/********************************************************************************
** Form generated from reading UI file 'circuitovalido.ui'
**
** Created by: Qt User Interface Compiler version 5.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CIRCUITOVALIDO_H
#define UI_CIRCUITOVALIDO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_circuitovalido
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QDialog *circuitovalido)
    {
        if (circuitovalido->objectName().isEmpty())
            circuitovalido->setObjectName(QStringLiteral("circuitovalido"));
        circuitovalido->resize(400, 120);
        buttonBox = new QDialogButtonBox(circuitovalido);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(30, 80, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(circuitovalido);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(50, 30, 401, 16));
        label_2 = new QLabel(circuitovalido);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(50, 50, 251, 20));

        retranslateUi(circuitovalido);
        QObject::connect(buttonBox, SIGNAL(accepted()), circuitovalido, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), circuitovalido, SLOT(reject()));

        QMetaObject::connectSlotsByName(circuitovalido);
    } // setupUi

    void retranslateUi(QDialog *circuitovalido)
    {
        circuitovalido->setWindowTitle(QApplication::translate("circuitovalido", "Dialog", nullptr));
        label->setText(QApplication::translate("circuitovalido", "O Circuito n\303\243o est\303\241 completamente definido.", nullptr));
        label_2->setText(QApplication::translate("circuitovalido", "Ele n\303\243o pode ser simulado ou salvo.", nullptr));
    } // retranslateUi

};

namespace Ui {
    class circuitovalido: public Ui_circuitovalido {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CIRCUITOVALIDO_H
