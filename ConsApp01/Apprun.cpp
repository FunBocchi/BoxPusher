#include "Classdefault.h"
#include "FileRead.h"
int main() {
	std::ifstream inputFile("stageData.txt", std::ifstream::binary);
	inputFile.seekg(0, std::ifstream::end);

	int fileSize = static_cast<int>(inputFile.tellg());
	inputFile.seekg(0, std::ifstream::beg);
	char* fileImage = new char[fileSize];
	inputFile.read(fileImage, fileSize);

	std::cout.write(fileImage, fileSize);
	std::cout << std::endl;







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