//
// Created by 汐茗 on 2024/6/16.
//

#ifndef OOP_LCU_2024SPRING_NEWROOMINFO_H
#define OOP_LCU_2024SPRING_NEWROOMINFO_H

#include <QWidget>
#include "RoomManager.h"

class RoomList;

QT_BEGIN_NAMESPACE
namespace Ui { class NewRoomInfo; }
QT_END_NAMESPACE

class NewRoomInfo : public QWidget {
Q_OBJECT

public:
    explicit NewRoomInfo(QWidget *parent, RoomList *roomList);

    ~NewRoomInfo() override;

public slots:
    void onTextChanged(const QString& text);
    void onTextChanged1(const QString& text);
    void onTextChanged2(const QString& text);
    void onTextChanged3(const QString& text);
    void addNewRoom();

private:
    Ui::NewRoomInfo *ui;
    RoomManager _roomManager;
    int _editedPrice;
    int _editedBedNum;
    int _editedArea;
    string _editedName;
};


#endif //OOP_LCU_2024SPRING_NEWROOMINFO_H
