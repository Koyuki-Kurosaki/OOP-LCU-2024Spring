/********************************************************************************
** Form generated from reading UI file 'RoomInfo.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ROOMINFO_H
#define UI_ROOMINFO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RoomInfo
{
public:

    void setupUi(QWidget *RoomInfo)
    {
        if (RoomInfo->objectName().isEmpty())
            RoomInfo->setObjectName("RoomInfo");
        RoomInfo->resize(400, 300);

        retranslateUi(RoomInfo);

        QMetaObject::connectSlotsByName(RoomInfo);
    } // setupUi

    void retranslateUi(QWidget *RoomInfo)
    {
        RoomInfo->setWindowTitle(QCoreApplication::translate("RoomInfo", "RoomOperate", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RoomInfo: public Ui_RoomInfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ROOMINFO_H
