#include "Classdefault.h"

//Ĭ�ϵ�ͼ��Ϣ
mapData defaultMapData[] = "\
########\n\
# .. p #\n\
# oo   #\n\
#      #\n\
########";
lenOfMap lom = 5;
weiOfMap wom = 8;

//����Ϊ��Ŀ���ܵ�ʵ��
void InitMap(Object* mapInfo, mapData* defaultMap, lenOfMap lm, weiOfMap wm) {
	mapData* temp = defaultMap;
	int x = 0, y = 0;

	//��ȡ��������ʼ��ͼ���ݴ�ŵ�mapInfo����
	while (*temp != '\0') {
		Object t;
		switch (*temp) {
		case '#':
			t = WALL;
			break;
		case ' ':
			t = SPACE;
			break;
		case '.':
			t = GOAL;
			break;
		case 'o':
			t = BLOCK;
			break;
		case 'O':
			t = BLOCK_ON_GOAL;
			break;
		case 'p':
			t = MAN;
			break;
		case 'P':
			t = MAN_ON_GOAL;
			break;
		case '\n':
			t = OBJ_DEFAULT;
			x = 0;
			++y;
			break;
		default:
			t = OBJ_DEFAULT;
			break;
		}
		++temp;
		if (t != OBJ_DEFAULT) {
			mapInfo[y * wm + x] = t;
			++x;
		}
	}
	return;
}
void DrawMap(Object* mapInfo, lenOfMap lm, weiOfMap wm) {
	mapData font[] = { ' ', '#', '.', 'o', 'O', 'p', 'P' };
	for (int i = 0; i < lm; ++i) {
		for (int j = 0; j < wm; ++j) {
			Object p = mapInfo[i * wm + j];
			std::cout << font[p];
		}
		std::cout << std::endl;
	}
}
void UpdateMap(Object* mapInfo, lenOfMap lm, weiOfMap wm) {
	std::cout << "Please enter to move the body: " << std::endl;
	//�˴�Ϊ���Ǵ��뽡ȫ�ԣ����´���ʱ���Կ��ǲ���ѭ����ʽ���
	char mov = NULL;
	int dx = 0, dy = 0;
	std::cin >> mov;
	switch (mov) {
	case 'w':
		dy = -1;
		break;
	case 's':
		dy = 1;
		break;
	case 'a':
		dx = -1;
		break;
	case 'd':
		dx = 1;
		break;
	default:
		std::cout << "Nothing changed" << std::endl;
		break;
	}
	//����С��λ��
	int locX = -1, locY = -1;
	for (int loc = 0; loc < lm * wm; ++loc) {
		if (mapInfo[loc] == MAN || mapInfo[loc] == MAN_ON_GOAL) {
			locX = loc % wm;
			locY = loc / wm;
			break;
		}
	}
	if (locX > wm || locX<0 || locY>lm || locY < 0) {
		std::cout << "Error: out of the map" << std::endl;
		return;
	}
	//�ֱ����ڴ����һ�ƶ�λ�ü�����һ���λ��
	int locXT1 = locX + dx, locXT2 = locXT1 + dx;
	int locYT1 = locY + dy, locYT2 = locYT1 + dy;
	//�����������ж�
	if (mapInfo[locY * wm + locX] == MAN) {
		if (mapInfo[locYT1 * wm + locXT1] == SPACE) {
			mapInfo[locYT1 * wm + locXT1] = MAN;
			mapInfo[locY * wm + locX] = SPACE;
		}
		else if (mapInfo[locYT1 * wm + locXT1] == GOAL) {
			mapInfo[locYT1 * wm + locXT1] = MAN_ON_GOAL;
			mapInfo[locY * wm + locX] = SPACE;
		}
		else if (mapInfo[locYT1 * wm + locXT1] == BLOCK) {
			if (mapInfo[locYT2 * wm + locXT2] == SPACE) {
				mapInfo[locYT2 * wm + locXT2] = BLOCK;
				mapInfo[locYT1 * wm + locXT1] = MAN;
				mapInfo[locY * wm + locX] = SPACE;
			}
			else if (mapInfo[locYT2 * wm + locXT2] == GOAL) {
				mapInfo[locYT2 * wm + locXT2] = BLOCK_ON_GOAL;
				mapInfo[locYT1 * wm + locXT1] = MAN;
				mapInfo[locY * wm + locX] = SPACE;
			}
		}
		else if (mapInfo[locYT1 * wm + locXT1] == BLOCK_ON_GOAL) {
			if (mapInfo[locYT2 * wm + locXT2] == SPACE) {
				mapInfo[locYT2 * wm + locXT2] = BLOCK;
				mapInfo[locYT1 * wm + locXT1] = MAN_ON_GOAL;
				mapInfo[locY * wm + locX] = SPACE;
			}
			else if (mapInfo[locYT2 * wm + locXT2] == GOAL) {
				mapInfo[locYT2 * wm + locXT2] = BLOCK_ON_GOAL;
				mapInfo[locYT1 * wm + locXT1] = MAN_ON_GOAL;
				mapInfo[locY * wm + locX] = SPACE;
			}
		}
	}
	else {
		if (mapInfo[locYT1 * wm + locXT1] == SPACE) {
			mapInfo[locYT1 * wm + locXT1] = MAN;
			mapInfo[locY * wm + locX] = GOAL;
		}
		else if (mapInfo[locYT1 * wm + locXT1] == GOAL) {
			mapInfo[locYT1 * wm + locXT1] = MAN_ON_GOAL;
			mapInfo[locY * wm + locX] = GOAL;
		}
		else if (mapInfo[locYT1 * wm + locXT1] == BLOCK) {
			if (mapInfo[locYT2 * wm + locXT2] == SPACE) {
				mapInfo[locYT2 * wm + locXT2] = BLOCK;
				mapInfo[locYT1 * wm + locXT1] = MAN;
				mapInfo[locY * wm + locX] = GOAL;
			}
			else if (mapInfo[locYT2 * wm + locXT2] == GOAL) {
				mapInfo[locYT2 * wm + locXT2] = BLOCK_ON_GOAL;
				mapInfo[locYT1 * wm + locXT1] = MAN;
				mapInfo[locY * wm + locX] = GOAL;
			}
		}
		else if (mapInfo[locYT1 * wm + locXT1] == BLOCK_ON_GOAL) {
			if (mapInfo[locYT2 * wm + locXT2] == SPACE) {
				mapInfo[locYT2 * wm + locXT2] = BLOCK;
				mapInfo[locYT1 * wm + locXT1] = MAN_ON_GOAL;
				mapInfo[locY * wm + locX] = GOAL;
			}
			else if (mapInfo[locYT2 * wm + locXT2] == GOAL) {
				mapInfo[locYT2 * wm + locXT2] = BLOCK_ON_GOAL;
				mapInfo[locYT1 * wm + locXT1] = MAN_ON_GOAL;
				mapInfo[locY * wm + locX] = GOAL;
			}
		}
	}
}
bool CheckClear(Object* mapInfo, lenOfMap lm, weiOfMap wm) {
	for (int i = 0; i < lm; ++i) {
		for (int j = 0; j < wm; ++j) {
			if (mapInfo[i * wm + j] == BLOCK) {
				return false;
			}
		}
	}
	return true;
}