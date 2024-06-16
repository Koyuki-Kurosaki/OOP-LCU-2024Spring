//
// Created by 汐茗 on 2024/6/16.
//

#ifndef OOP_LCU_2024SPRING_NEWROOMINFO_H
#define OOP_LCU_2024SPRING_NEWROOMINFO_H

#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui { class NewRoomInfo; }
QT_END_NAMESPACE

class NewRoomInfo : public QWidget {
Q_OBJECT

public:
    explicit NewRoomInfo(QWidget *parent = nullptr);

    ~NewRoomInfo() override;

private:
    Ui::NewRoomInfo *ui;
};


#endif //OOP_LCU_2024SPRING_NEWROOMINFO_H
