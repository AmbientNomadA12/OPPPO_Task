// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com

#include "logic.h"
#include "test.h"

void doProgram()
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
        readFromFile(Table, "ist.txt");
    }

    std::cout << "\n������� ������?\n0 - ��; 1 - ���\n(�� ��������� ������ ����� 0)\n\n";
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
