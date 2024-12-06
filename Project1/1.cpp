// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com

#include "logic.h"

int main()
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
        readFromFile(Table);
    }

    std::cout << "\nВывести массив?\n0 - Да; 1 - Нет\n(по умолчанию выбран режим 0)\n\n";
    std::cin >> choice;

    if (!choice)
    {
        commandPrint(Table);
    }

    return 0;
}
