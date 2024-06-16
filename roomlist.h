//
// Created by 汐茗 on 2024/6/16.
//

#ifndef OOP_LCU_2024SPRING_ROOMLIST_H
#define OOP_LCU_2024SPRING_ROOMLIST_H

#include <QWidget>
#include "RoomManager.h"


QT_BEGIN_NAMESPACE
namespace Ui { class RoomList; }
QT_END_NAMESPACE

class RoomList : public QWidget {
Q_OBJECT

public:
    explicit RoomList(QWidget *parent = nullptr);

    ~RoomList() override;

public slots:
    void addNewRoom();
    void refreshRooms();

private:
    Ui::RoomList *ui;
    map<string, Room> _roomMap;
    RoomManager _roomManager;

private slots:
    void on_pushButton_exit_clicked();
};


#endif //OOP_LCU_2024SPRING_ROOMLIST_H
