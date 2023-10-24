#pragma once
#ifndef CLASSDEFAULT_H
#define CLASSDEFAULT_H
#include <iostream>

//��ͼ�����õ�����������
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
//��һЩ��Ҫ�õ������ݱ�������������
typedef const char mapData;
typedef const int lenOfMap;
typedef const int weiOfMap;
typedef const char input;
extern lenOfMap lom;
extern weiOfMap wom;
extern mapData defaultMapData[];

//����ԭʼ���ݳ�ʼ����ͼ
void InitMap(Object*, mapData*, lenOfMap = lom, weiOfMap = wom);
//����ͼ�ļ���ӡ�ڵ�ͼ��
void DrawMap(Object*, lenOfMap = lom, weiOfMap = wom);
//�����û�������µ�ͼ
void UpdateMap(Object*, lenOfMap = lom, weiOfMap = wom);
//����Ƿ����ȫ�������Ϊ
bool CheckClear(Object*, lenOfMap = lom, weiOfMap = wom);
#endif // !CLASSDEFAULT_H