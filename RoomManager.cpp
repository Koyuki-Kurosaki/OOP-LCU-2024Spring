//
// Created by 汐茗 on 2024/6/14.
//

#include "RoomManager.h"

using namespace std;
RoomManager::RoomManager() {
    _roomMap = Room().loadData();
}
void RoomManager::addRoom(string name, int price, int area, int bedNum, ROOM_STATE state) {
    Room room(name, price, area, bedNum, state);
    _roomMap[room.getNum()] = room;
    room.saveData(_roomMap);
}
bool RoomManager::deleteRoom(string num) {
    if (_roomMap.find(num) == _roomMap.end()) {
        cout << "Room not found!" << endl;
        return false;
    }
    _roomMap.erase(num);
    Room().saveData(_roomMap);
    return true;
}
bool RoomManager::updateRoomInfo(string num = "", string name = "", int price = -1, int area = -1, int bedNum = -1, ROOM_STATE state = FREE) {
    if (_roomMap.find(num) == _roomMap.end()) {
        cout << "Room not found!" << endl;
        return false;
    }
    if (name != "") {
        _roomMap[num].setName(name);
    }
    if (price != -1) {
        _roomMap[num].setPrice(price);
    }
    if (area != -1) {
        _roomMap[num].setArea(area);
    }
    if (bedNum != -1) {
        _roomMap[num].setBedNum(bedNum);
    }
    if (state != FREE) {
        _roomMap[num].setSate(state);
    }else{
        _roomMap[num].setSate(FREE);
    }
    Room().saveData(_roomMap);
    return true;
}
map<string, Room> RoomManager::getRoom() {
    return _roomMap;
}