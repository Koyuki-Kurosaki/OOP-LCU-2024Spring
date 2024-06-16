/********************************************************************************
** Form generated from reading UI file 'RoomList.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ROOMLIST_H
#define UI_ROOMLIST_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RoomList
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QPushButton *pushButton_exit;

    void setupUi(QWidget *RoomList)
    {
        if (RoomList->objectName().isEmpty())
            RoomList->setObjectName("RoomList");
        RoomList->resize(731, 577);
        gridLayoutWidget = new QWidget(RoomList);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(70, 20, 591, 471));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_exit = new QPushButton(RoomList);
        pushButton_exit->setObjectName("pushButton_exit");
        pushButton_exit->setGeometry(QRect(320, 510, 100, 32));
        QIcon icon(QIcon::fromTheme(QString::fromUtf8("application-exit")));
        pushButton_exit->setIcon(icon);

        retranslateUi(RoomList);

        QMetaObject::connectSlotsByName(RoomList);
    } // setupUi

    void retranslateUi(QWidget *RoomList)
    {
        RoomList->setWindowTitle(QCoreApplication::translate("RoomList", "RoomList", nullptr));
        pushButton_exit->setText(QCoreApplication::translate("RoomList", "\351\200\200\345\207\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RoomList: public Ui_RoomList {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ROOMLIST_H
