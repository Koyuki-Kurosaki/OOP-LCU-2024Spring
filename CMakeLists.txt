cmake_minimum_required(VERSION 3.27)
project(OOP_LCU_2024Spring)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(OOP_LCU_2024Spring main.cpp
        roomlist.cpp
        roomlist.h
        roomlist.ui
        roominfo.cpp
        roominfo.h
        roominfo.ui
        Enums.h
        Room.cpp
        Room.h
        RoomManager.cpp
        RoomManager.h
        json/json.h
        json/json-forwards.h
        jsoncpp.cpp
        newroominfo.cpp
        newroominfo.h
        newroominfo.ui)
target_link_libraries(OOP_LCU_2024Spring
        Qt::Core
        Qt::Gui
        Qt::Widgets
)

