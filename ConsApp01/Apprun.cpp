#include "Classdefault.h"

int main() {
	Object* mapInfo = new Object[lom * wom];
	InitMap(mapInfo, defaultMapData);
	DrawMap(mapInfo);
	while (!CheckClear(mapInfo)) {
		UpdateMap(mapInfo);
		DrawMap(mapInfo);
	}
	std::cout << "Connn" << std::endl;
	delete[] mapInfo;
	mapInfo = nullptr;
	return 0;
}