#include "Classdefault.h"
#include <fstream>


int main() {
	std::ifstream inputFile("stageData.txt", std::ifstream::binary);
	inputFile.seekg(0, inputFile.end);
	int fileSize = 0;
	fileSize = static_cast<int>(inputFile.tellg());
	inputFile.seekg(0, inputFile.beg);





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