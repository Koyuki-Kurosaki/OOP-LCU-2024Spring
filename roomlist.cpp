//
// Created by 汐茗 on 2024/6/16.
//

// You may need to build the project (run Qt uic code generator) to get "ui_RoomList.h" resolved

#include "roomlist.h"
#include "ui_RoomList.h"
#include <QPushButton>

#include "roominfo.h"

RoomList::RoomList(QWidget *parent) :
        QWidget(parent), ui(new Ui::RoomList) {
    ui->setupUi(this);

    refreshRooms();
}

RoomList::~RoomList() {
    delete ui;
}

void RoomList::refreshRooms() {
    _roomManager = RoomManager();
    _roomMap = _roomManager.getRoom();
    int total = _roomMap.size();
    int rowColUnderNumber;
    if (total<=15) {
        rowColUnderNumber = 4;
    }
    else if (total<=24) {
        rowColUnderNumber = 5;
    }
    else if (total<=35) {
        rowColUnderNumber = 6;
    }
    else if (total<=48) {
        rowColUnderNumber = 7;
    }
    else if (total<=64-1) {
        rowColUnderNumber = 8;
    }
    else if (total<=81-1) {
        rowColUnderNumber = 9;
    }
    else if (total<=100-1) {
        rowColUnderNumber = 10;
    }
    else {
        rowColUnderNumber = 11;
    }
    int buttonSize;
    if(total<=25-1) {
        buttonSize = 100;
    }
    else if(total<=36-1) {
        buttonSize = 80;
    }
    else if(total<=49-1) {
        buttonSize = 70;
    }
    else if(total<=64-1) {
        buttonSize = 60;
    }
    else if(total<=81-1) {
        buttonSize = 50;
    }
    else if(total<=100-1) {
        buttonSize = 40;
    }
    else {
        buttonSize = 30;
    }

    // 根据房间数量增加按钮数量，一个按钮表示一个房间
    int i = 0;
    for (auto &room : _roomMap) {
        QPushButton *button = new QPushButton(this);
        button->setFixedSize(buttonSize, buttonSize);
        if(room.second.getState() == FREE) {
            // 未入住是浅绿色
            button->setStyleSheet("background-color: lightgreen");
        } else if(room.second.getState() == CHECK_IN) {
            // 已入住是浅黄色
            button->setStyleSheet("background-color: lightyellow");
        }
        button->setText(QString::fromStdString(room.second.getName() + "\n¥" + to_string(room.second.getPrice()) + "\n" + to_string(room.second.getArea()) + "m²\n床数" + to_string(room.second.getBedNum()) ));
        ui->gridLayout->addWidget(button, i / rowColUnderNumber, i % rowColUnderNumber);
        ++i;

        RoomInfo *roomInfo = new RoomInfo(nullptr, room.second, this);
        connect(button, &QPushButton::clicked, roomInfo, &QWidget::show);


    }
    //添加房间按钮
    QPushButton *button = new QPushButton(this);
    button->setFixedSize(buttonSize, buttonSize);
    button->setText("+添加房间");
    ui->gridLayout->addWidget(button, i / rowColUnderNumber, i % rowColUnderNumber);
    connect(button, &QPushButton::clicked, this, &RoomList::addNewRoom);
}

void RoomList::on_pushButton_exit_clicked() {
    this->close();
}

void RoomList::addNewRoom() {

}