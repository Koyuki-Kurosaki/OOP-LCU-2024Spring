//
// Created by 汐茗 on 2024/6/16.
//

// You may need to build the project (run Qt uic code generator) to get "ui_NewRoomInfo.h" resolved

#include "newroominfo.h"
#include "ui_NewRoomInfo.h"


NewRoomInfo::NewRoomInfo(QWidget *parent) :
        QWidget(parent), ui(new Ui::NewRoomInfo) {
    ui->setupUi(this);
}

NewRoomInfo::~NewRoomInfo() {
    delete ui;
}
