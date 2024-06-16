//
// Created by 汐茗 on 2024/6/16.
//

#ifndef OOP_LCU_2024SPRING_ROOMINFO_H
#define OOP_LCU_2024SPRING_ROOMINFO_H

#include <QWidget>
#include "RoomManager.h"

class RoomList;

QT_BEGIN_NAMESPACE
namespace Ui { class RoomInfo; }
QT_END_NAMESPACE

class RoomInfo : public QWidget {
Q_OBJECT

public:
    explicit RoomInfo(QWidget *parent, Room room, RoomList *roomList);

    ~RoomInfo() override;

public slots:
    void checkIn();
    void checkOut();
    void deleteRoom();
    void updateRoomTexts();
    void onTextChanged(const QString& text);
    void onTextChanged1(const QString& text);
    void onTextChanged2(const QString& text);
    void onTextChanged3(const QString& text);

private:
    Ui::RoomInfo *ui;
    RoomManager _roomManager;
    Room _room;
    int _editedPrice;
    int _editedBedNum;
    int _editedArea;
    string _editedName;
    ROOM_STATE _state;
};


#endif //OOP_LCU_2024SPRING_ROOMINFO_H
