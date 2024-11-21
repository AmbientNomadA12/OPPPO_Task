// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com

#include "logic.h"

int main()
{
    setlocale(LC_ALL, "rus");
    std::vector<Equipment*> Table;

    //Возможность выбрать режим
    bool choice;
    std::cout << "Выберите режим работы: 0 - чтение из файла; 1 - ручной ввод\n(по умолчанию выбран режим 0)\n";
    std::cin >> choice;

    switch (choice)
    {
        case false: 
            readFromFile(Table);
            break;

        case true:
            readFromConsole(Table);
            break;

        default:
            readFromFile(Table);
            break;
    }

    std::cout << "\nВывести массив?\n0 - Да; 1 - Нет\n(по умолчанию выбран режим 0)\n\n";
    std::cin >> choice;

    switch (choice)
    {
    case false:
        commandPrint(Table);
        break;

    case true:
        break;

    default:
        commandPrint(Table);
        break;
    }

    return(0);
}
