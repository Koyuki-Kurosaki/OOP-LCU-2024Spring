//
// Created by 汐茗 on 2024/6/16.
//

#ifndef OOP_LCU_2024SPRING_ROOMMANAGER_H
#define OOP_LCU_2024SPRING_ROOMMANAGER_H

#include "Room.h"
#include <map>
#include <iostream>
#include <string>
class RoomManager {
public:
    RoomManager();
    // CRUD
    void addRoom(string, int, int, int, ROOM_STATE);
    bool deleteRoom(string);
    bool updateRoomInfo(string, string, int, int, int, ROOM_STATE);
    map<string, Room> getRoom();
private:
    map<string, Room> _roomMap;
};


#endif //OOP_LCU_2024SPRING_ROOMMANAGER_H
