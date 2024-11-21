// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com

#include "logic.h"

int main()
{
    setlocale(LC_ALL, "rus");
    std::vector<Equipment*> Table;

    //����������� ������� �����
    bool choice;
    std::cout << "�������� ����� ������: 0 - ������ �� �����; 1 - ������ ����\n(�� ��������� ������ ����� 0)\n";
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

    std::cout << "\n������� ������?\n0 - ��; 1 - ���\n(�� ��������� ������ ����� 0)\n\n";
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
