# OOP大作业——酒店管理系统
Kit: Desktop (arm-darwin-generic-mach_o-64bit)
## 1. 项目简介
本项目基于Qt6和C++开发，实现了一个简单的酒店管理系统。主要功能包括：
1. 房间信息的增删改查
2. 房间信息的图形化展示
3. 以颜色代表房间状态：绿色表示空闲，黄色表示入住

## 2. 项目结构
1. 图形化部分使用Qt，roomlist是主界面，roominfo是房间信息编辑界面，newroom是新建房间界面
2. 数据存储使用json文件，解析库使用jsoncpp
