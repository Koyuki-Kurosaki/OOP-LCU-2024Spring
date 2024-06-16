//
// Created by 汐茗 on 2024/6/16.
//

#include "Room.h"

using namespace std;
const char* const ROOM_FILE = "../room.json";
Room::Room(string name, int price, int area, int bedNum, ROOM_STATE state) {
    _name = name;
    _price = price;
    _area = area;
    _bedNum = bedNum;
    _state = state;
    _num = generateNum();
}
string Room::generateNum() {
    time_t now = time(0);
    tm* ltm = localtime(&now);
    string num = to_string(1900 + ltm->tm_year) + to_string(1 + ltm->tm_mon) + to_string(ltm->tm_mday) + to_string(ltm->tm_hour) + to_string(ltm->tm_min) + to_string(ltm->tm_sec);
    return num;
}
bool Room::saveData(map<string, Room>& roomMap) {
    Json::Value root;
    Json::Value room;
    for (auto& i : roomMap) {
        room["num"] = i.second.getNum();
        room["name"] = i.second.getName();
        room["price"] = i.second.getPrice();
        room["area"] = i.second.getArea();
        room["bedNum"] = i.second.getBedNum();
        room["state"] = i.second.getState();
        root.append(room);
    }
    ofstream ofs(ROOM_FILE);
    Json::StreamWriterBuilder writer;
    writer["indentation"] = "\t";
    unique_ptr<Json::StreamWriter> jsonWriter(writer.newStreamWriter());
    jsonWriter->write(root, &ofs);
    return true;
}
map<string, Room> Room::loadData() {
    map<string, Room> roomMap;
    Json::Value root;
    ifstream ifs(ROOM_FILE);
    Json::Reader reader;
    reader.parse(ifs, root);
    for (int i = 0; i < root.size(); i++) {
        Room room;
        room._num = root[i]["num"].asString();
        room._name = root[i]["name"].asString();
        room._price = root[i]["price"].asInt();
        room._area = root[i]["area"].asInt();
        room._bedNum = root[i]["bedNum"].asInt();
        room._state = (ROOM_STATE)root[i]["state"].asInt();
        roomMap[room._num] = room;
    }
    return roomMap;
}
string Room::getNum() {
    return _num;
}
ROOM_STATE Room::getState() {
    return _state;
}
string Room::getName() {
    return _name;
}
int Room::getPrice() {
    return _price;
}
int Room::getArea() {
    return _area;
}
int Room::getBedNum() {
    return _bedNum;
}
void Room::setSate(ROOM_STATE state) {
    _state = state;
}
void Room::setName(string name) {
    _name = name;
}
void Room::setPrice(int price) {
    _price = price;
}
void Room::setArea(int area) {
    _area = area;
}
void Room::setBedNum(int bedNum) {
    _bedNum = bedNum;
}