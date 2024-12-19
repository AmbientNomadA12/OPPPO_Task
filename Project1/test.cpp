#include "test.h"

bool testFileInput(std::string& fileName, const int vectroSize)
{
	setlocale(LC_ALL, "ru-RU");
	std::vector<Equipment*> Table;

	readFromFile(Table, fileName);
	return(Table.size() == vectroSize);
}