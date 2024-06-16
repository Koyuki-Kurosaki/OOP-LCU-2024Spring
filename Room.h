//
// Created by 汐茗 on 2024/6/16.
//

#ifndef OOP_LCU_2024SPRING_ROOM_H
#define OOP_LCU_2024SPRING_ROOM_H
#include <iostream>
#include <fstream>
#include <iomanip>
#include <ctime>
#include <string>
#include <map>
#include "Enums.h"
#include "json/json.h"
using namespace std;

class Room {
public:
    Room(){}
    Room(string, int, int, int, ROOM_STATE);
    string generateNum();
    bool saveData( map<string, Room>& );
    map<string, Room> loadData();

    string getNum();
    string getName();
    int getPrice();
    int getArea();
    int getBedNum();
    ROOM_STATE getState();
    void setSate(ROOM_STATE);
    void setName(string);
    void setPrice(int);
    void setArea(int);
    void setBedNum(int);
private:
    string _num;
    string _name;
    int _price;
    int _area;
    int _bedNum;
    ROOM_STATE _state;
};



#endif //OOP_LCU_2024SPRING_ROOM_H
