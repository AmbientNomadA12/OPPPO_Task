// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com

#include "logic.h"

int main()
{
    setlocale(LC_ALL, "ru-RU");
    std::vector<Equipment*> Table;

    //����������� ������� �����
    bool choice;
    std::cout << "�������� ����� ������: 0 - ������ �� �����; 1 - ������ ����\n(�� ��������� ������ ����� 0)\n";
    std::cin >> choice;

    if (choice)
    {
        readFromConsole(Table);
    }
    else
    {
        readFromFile(Table);
    }

    std::cout << "\n������� ������?\n0 - ��; 1 - ���\n(�� ��������� ������ ����� 0)\n\n";
    std::cin >> choice;

    if (!choice)
    {
        commandPrint(Table);
    }

    return 0;
}
