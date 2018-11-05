/********************************************************************************
** Form generated from reading UI file 'errofile.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ERRO_H
#define UI_ERRO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_erro
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;

    void setupUi(QDialog *erro)
    {
        if (erro->objectName().isEmpty())
            erro->setObjectName(QString::fromUtf8("erro"));
        erro->resize(400, 104);
        buttonBox = new QDialogButtonBox(erro);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(30, 60, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(erro);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 30, 371, 20));

        retranslateUi(erro);
        QObject::connect(buttonBox, SIGNAL(accepted()), erro, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), erro, SLOT(reject()));

        QMetaObject::connectSlotsByName(erro);
    } // setupUi

    void retranslateUi(QDialog *erro)
    {
        erro->setWindowTitle(QApplication::translate("erro", "Dialog", nullptr));
        label->setText(QApplication::translate("erro", "Arquivo corrompido!", nullptr));
    } // retranslateUi

};

namespace Ui {
    class erro: public Ui_erro {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ERRO_H
