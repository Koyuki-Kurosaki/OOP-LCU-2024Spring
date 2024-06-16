//
// Created by 汐茗 on 2024/6/16.
//

// You may need to build the project (run Qt uic code generator) to get "ui_RoomInfo.h" resolved

#include "roominfo.h"
#include "ui_RoomInfo.h"
#include <QVBoxLayout>
#include <QPushButton>
#include <QLineEdit>

#include "roomlist.h"

RoomInfo::RoomInfo(QWidget *parent, Room room , RoomList *roomList) :
        QWidget(parent), ui(new Ui::RoomInfo) {
    ui->setupUi(this);

    _room = room;
    _state = room.getState();
    this->setWindowTitle(QString::fromStdString(room.getName()));
    //垂直布局
    QVBoxLayout *layout = new QVBoxLayout(this);
    //设置新按钮
    QPushButton *button = new QPushButton(this);
    layout->addWidget(button);
    if(room.getState()==FREE) {
        button->setText("入住");
        connect(button, &QPushButton::clicked, this, &RoomInfo::checkIn);
    }
    else if(room.getState()==CHECK_IN) {
        button->setText("退房");
        connect(button, &QPushButton::clicked, this, &RoomInfo::checkOut);
    }

    QPushButton *deleteButton = new QPushButton(this);
    layout->addWidget(deleteButton);
    deleteButton->setText("删除");
    connect(deleteButton, &QPushButton::clicked, this, &RoomInfo::deleteRoom);
    //修改客房信息
    QLineEdit *lineEdit = new QLineEdit(this);
    layout->addWidget(lineEdit);
    lineEdit->setText(QString::fromStdString(room.getName()));
    QLineEdit *lineEdit1 = new QLineEdit(this);
    layout->addWidget(lineEdit1);
    lineEdit1->setText(QString::number(room.getPrice()));
    QLineEdit *lineEdit2 = new QLineEdit(this);
    layout->addWidget(lineEdit2);
    lineEdit2->setText(QString::number(room.getArea()));
    QLineEdit *lineEdit3 = new QLineEdit(this);
    layout->addWidget(lineEdit3);
    lineEdit3->setText(QString::number(room.getBedNum()));

    //完成
    QPushButton *finishButton = new QPushButton(this);
    layout->addWidget(finishButton);
    finishButton->setText("完成");

    connect(lineEdit, &QLineEdit::textChanged, this, &RoomInfo::onTextChanged);
    connect(lineEdit1, &QLineEdit::textChanged, this, &RoomInfo::onTextChanged1);
    connect(lineEdit2, &QLineEdit::textChanged, this, &RoomInfo::onTextChanged2);
    connect(lineEdit3, &QLineEdit::textChanged, this, &RoomInfo::onTextChanged3);

    connect(finishButton, &QPushButton::clicked, this, &RoomInfo::updateRoomTexts);
    //关闭窗口
    connect(finishButton, &QPushButton::clicked, this, &RoomInfo::close);
    connect(finishButton, &QPushButton::clicked, roomList, &RoomList::refreshRooms);

}

RoomInfo::~RoomInfo() {
    delete ui;
}

void RoomInfo::checkIn() {
    _roomManager.updateRoomInfo(_room.getNum(),"",-1,-1,-1,CHECK_IN);
    _state = CHECK_IN;
}
void RoomInfo::checkOut() {
    _roomManager.updateRoomInfo(_room.getNum(),"",-1,-1,-1,FREE);
    _state = FREE;
}
void RoomInfo::deleteRoom() {
    _roomManager.deleteRoom(_room.getNum());
}
void RoomInfo::updateRoomTexts() {
    _roomManager.updateRoomInfo(_room.getNum(),_editedName,_editedPrice,_editedArea,_editedBedNum,_state);
}

void RoomInfo::onTextChanged(const QString& text)
{
    _editedName = text.toStdString();
}
void RoomInfo::onTextChanged1(const QString& text)
{
    _editedPrice = text.toInt();
}
void RoomInfo::onTextChanged2(const QString& text)
{
    _editedArea = text.toInt();
}
void RoomInfo::onTextChanged3(const QString& text)
{
    _editedBedNum = text.toInt();
}