/********************************************************************************
** Form generated from reading UI file 'NewRoomInfo.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWROOMINFO_H
#define UI_NEWROOMINFO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NewRoomInfo
{
public:

    void setupUi(QWidget *NewRoomInfo)
    {
        if (NewRoomInfo->objectName().isEmpty())
            NewRoomInfo->setObjectName("NewRoomInfo");
        NewRoomInfo->resize(400, 300);

        retranslateUi(NewRoomInfo);

        QMetaObject::connectSlotsByName(NewRoomInfo);
    } // setupUi

    void retranslateUi(QWidget *NewRoomInfo)
    {
        NewRoomInfo->setWindowTitle(QCoreApplication::translate("NewRoomInfo", "NewRoomInfo", nullptr));
    } // retranslateUi

};

namespace Ui {
    class NewRoomInfo: public Ui_NewRoomInfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWROOMINFO_H
