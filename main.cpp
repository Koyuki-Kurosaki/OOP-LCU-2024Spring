#include <QApplication>
#include "roomlist.h"
#include "RoomManager.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    RoomList w = RoomList();
    w.show();
    return QApplication::exec();
}
