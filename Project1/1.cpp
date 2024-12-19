// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com

#include "logic.h"
#include "test.h"


int main()
{
    /*setlocale(LC_ALL, "ru-RU");
    std::vector<Equipment*> Table;

    //Возможность выбрать режим
    bool choice;
    std::string FileName = "ist.txt";
    std::cout << "Выберите режим работы: 0 - чтение из файла; 1 - ручной ввод\n(по умолчанию выбран режим 0)\n";
    std::cin >> choice;

    if (choice)
    {
        readFromConsole(Table);
    }
    else
    {
        readFromFile(Table, FileName);
    }

    std::cout << "\nВывести массив?\n0 - Да; 1 - Нет\n(по умолчанию выбран режим 0)\n\n";
    std::cin >> choice;

    if (!choice)
    {
        commandPrint(Table);
    }*/

    std::string fileName;

    for (int i = 0; i < 8; ++i)
    {
        fileName = "test" + std::to_string(i) + ".txt";
        

        if (testFileInput(fileName, 1))
        {
        	std::cout << "\tТест " << fileName << " пройден!\n";
        }
        else
        {
        	std::cout << "\tТест " << fileName << " НЕ пройден!\n";
        }
    }

    return 0;
}
