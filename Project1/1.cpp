// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com

#include "logic.h"
#include "test.h"

void doProgram()
{
    setlocale(LC_ALL, "ru-RU");
    std::vector<Equipment*> Table;

    //Возможность выбрать режим
    bool choice;
    std::cout << "Выберите режим работы: 0 - чтение из файла; 1 - ручной ввод\n(по умолчанию выбран режим 0)\n";
    std::cin >> choice;

    if (choice)
    {
        readFromConsole(Table);
    }
    else
    {
        readFromFile(Table, "ist.txt");
    }

    std::cout << "\nВывести массив?\n0 - Да; 1 - Нет\n(по умолчанию выбран режим 0)\n\n";
    std::cin >> choice;

    if (!choice)
    {
        commandPrint(Table);
    }
}

int main()
{
    setlocale(LC_ALL, "ru-RU");

    std::cout << testProgram("1.txt") << std::endl;
    std::cout << testProgram("2.txt") << std::endl;
    std::cout << testProgram("3.txt") << std::endl;
    std::cout << testProgram("4.txt") << std::endl;
    std::cout << testProgram("5.txt") << std::endl;
    std::cout << testProgram("6.txt") << std::endl;


    return 0;
}
