#pragma once
#ifndef CLASSDEFAULT_H
#define CLASSDEFAULT_H
#include <iostream>

//地图可能用到的土块类型
enum Object {
	SPACE,
	WALL,
	GOAL,
	BLOCK,
	BLOCK_ON_GOAL,
	MAN,
	MAN_ON_GOAL,

	OBJ_DEFAULT,
};
//对一些需要用到的数据变量进行重命名
typedef const char mapData;
typedef const int lenOfMap;
typedef const int weiOfMap;
typedef const char input;
extern lenOfMap lom;
extern weiOfMap wom;
extern mapData defaultMapData[];

//利用原始数据初始化地图
void InitMap(Object*, mapData*, lenOfMap = lom, weiOfMap = wom);
//将地图文件打印在地图上
void DrawMap(Object*, lenOfMap = lom, weiOfMap = wom);
//按照用户输入更新地图
void UpdateMap(Object*, lenOfMap = lom, weiOfMap = wom);
//检查是否完成全部方块归为
bool CheckClear(Object*, lenOfMap = lom, weiOfMap = wom);
#endif // !CLASSDEFAULT_H