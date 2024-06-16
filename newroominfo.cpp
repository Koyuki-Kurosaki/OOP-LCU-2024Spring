//
// Created by 汐茗 on 2024/6/16.
//

// You may need to build the project (run Qt uic code generator) to get "ui_NewRoomInfo.h" resolved

#include "newroominfo.h"
#include "ui_NewRoomInfo.h"
#include <QVBoxLayout>
#include <QLineEdit>
#include <QPushButton>

#include "roomlist.h"

NewRoomInfo::NewRoomInfo(QWidget *parent, RoomList *roomList) :
        QWidget(parent), ui(new Ui::NewRoomInfo) {
    ui->setupUi(this);
    _roomManager = RoomManager();

    QVBoxLayout *layout = new QVBoxLayout(this);

    QLineEdit *lineEdit = new QLineEdit(this);
    lineEdit->setPlaceholderText("请输入房间名");
    layout->addWidget(lineEdit);

    QLineEdit *lineEdit1 = new QLineEdit(this);
    lineEdit1->setPlaceholderText("请输入价格");
    layout->addWidget(lineEdit1);

    QLineEdit *lineEdit2 = new QLineEdit(this);
    lineEdit2->setPlaceholderText("请输入面积");
    layout->addWidget(lineEdit2);

    QLineEdit *lineEdit3 = new QLineEdit(this);
    lineEdit3->setPlaceholderText("请输入床位数");
    layout->addWidget(lineEdit3);

    connect(lineEdit, &QLineEdit::textChanged, this, &NewRoomInfo::onTextChanged);
    connect(lineEdit1, &QLineEdit::textChanged, this, &NewRoomInfo::onTextChanged1);
    connect(lineEdit2, &QLineEdit::textChanged, this, &NewRoomInfo::onTextChanged2);
    connect(lineEdit3, &QLineEdit::textChanged, this, &NewRoomInfo::onTextChanged3);

    //确认
    QPushButton *finishButton = new QPushButton(this);
    layout->addWidget(finishButton);
    finishButton->setText("确认");

    connect(finishButton, &QPushButton::clicked, this, &NewRoomInfo::addNewRoom);
    //关闭窗口
    connect(finishButton, &QPushButton::clicked, this, &NewRoomInfo::close);
    //刷新房间列表
    connect(finishButton, &QPushButton::clicked, roomList, &RoomList::refreshRooms);
}

NewRoomInfo::~NewRoomInfo() {
    delete ui;
}

void NewRoomInfo::onTextChanged(const QString& text)
{
    _editedName = text.toStdString();
}
void NewRoomInfo::onTextChanged1(const QString& text)
{
    _editedPrice = text.toInt();
}
void NewRoomInfo::onTextChanged2(const QString& text)
{
    _editedArea = text.toInt();
}
void NewRoomInfo::onTextChanged3(const QString& text)
{
    _editedBedNum = text.toInt();
}
void NewRoomInfo::addNewRoom() {
    _roomManager.addRoom(_editedName,_editedPrice,_editedArea,_editedBedNum,FREE);
    close();
}