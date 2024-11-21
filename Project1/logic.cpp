// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com

#include "logic.h"
#include "Equipment.h"
#include "Ball.h"
#include "Racket.h"
#include "Bicycle.h"

int checkNumberOfThings(const std::string &s)
{
    int temp = 0;

    for (int i = 0; i < s.size(); ++i)
    {
        if (s[i] == ';')
        {
            ++temp;
        }

    }

    return(temp);
}

bool stringParserHelper(const std::string &s, int index, std::string*& properties, int N)
{
    //Thing is symbol ;
    if (checkNumberOfThings(s) != 6)
    {
        return(false);
    }

    for (int i = 0; i < N; ++i)
    {
        index = s.find_first_of(';', index + 1);
        int index2 = s.find_first_of(';', index + 1);

        if (index == -1 || index2 == -1)
        {
            return(false);
        }

        properties[i] = s.substr(index + 1, index2 - index - 1);
    }

    return(true);

}

void commandAdd(const std::string &s, int index, std::vector<Equipment*>& Table)
{
    std::string type = s.substr(index + 1, s.find_first_of(';', index + 1) - index - 1);

    int N = 4;
    std::string* properties = new std::string[N];

    if (type == "ball")
    {

        if (stringParserHelper(s, index, properties, N))
        {
            Ball* ball = new Ball(
                stoi(properties[0]),
                properties[1],
                stoi(properties[2]),
                properties[3]
            );

            Table.push_back(ball);
        }
        else
        {
            std::cout << "В строке \"" << s << "\" обнаружена ошибка!\n";
        }

        delete[] properties;

    }
    else if (type == "rack")
    {
        if (stringParserHelper(s, index, properties, N))
        {
            Racket* racket = new Racket(
                stoi(properties[0]),
                properties[1],
                stoi(properties[2]),
                stoi(properties[3])
            );

            Table.push_back(racket);
        }
        else
        {
            std::cout << "В строке \"" << s << "\" обнаружена ошибка!\n";
        }

        delete[] properties;
    }
    else if (type == "bicy")
    {
        if (stringParserHelper(s, index, properties, N))
        {
            Bicycle* bicycle = new Bicycle(
                stoi(properties[0]),
                properties[1],
                properties[2],
                stoi(properties[3])
            );

            Table.push_back(bicycle);
        }
        else
        {
            std::cout << "В строке \"" << s << "\" обнаружена ошибка!\n";
        }

        delete[] properties;
    }
    else
    {
        std::cout << "Ошибка! Тип " << type << " не распознан!\n";
    }
}

//< > <= >= == !=
int commandRemHelper(const std::string &symbol, int price, std::vector<Equipment*>& Table)
{
    //Удалено элементов
    int counter = 0;

    if (symbol == "<")
    {
        for (int i = 0; i < Table.size(); ++i)
        {
            if (Table[i]->getPrice() < price)
            {
                ++counter;
                Table.erase(Table.begin() + i);
            }
        }
    }
    else if (symbol == ">")
    {
        for (int i = 0; i < Table.size(); ++i)
        {
            if (Table[i]->getPrice() > price)
            {
                ++counter;
                Table.erase(Table.begin() + i);
            }
        }
    }
    else if (symbol == "<=")
    {
        for (int i = 0; i < Table.size(); ++i)
        {
            if (Table[i]->getPrice() <= price)
            {
                ++counter;
                Table.erase(Table.begin() + i);
            }
        }
    }
    else if (symbol == ">=")
    {
        for (int i = 0; i < Table.size(); ++i)
        {
            if (Table[i]->getPrice() >= price)
            {
                ++counter;
                Table.erase(Table.begin() + i);
            }
        }
    }
    else if (symbol == "==")
    {
        for (int i = 0; i < Table.size(); ++i)
        {
            if (Table[i]->getPrice() == price)
            {
                ++counter;
                Table.erase(Table.begin() + i);
            }
        }
    }
    else if (symbol == "!=")
    {
        for (int i = 0; i < Table.size(); ++i)
        {
            if (Table[i]->getPrice() != price)
            {
                ++counter;
                Table.erase(Table.begin() + i);
            }
        }
    }
    else
    {
        return(-1);
    }
    return(counter);
}

void commandRem(const std::string &s, int index, std::vector<Equipment*>& Table)
{
    if (Table.size() > 0)
    {
        int index2 = s.find_first_of(';', index + 1);
        std::string whatRemove = s.substr(index + 1, index2 - index - 1);

        if (whatRemove == "price")
        {

            if (checkNumberOfThings(s) == 4)
            {
                index = index2;
                index2 = s.find_first_of(';', index + 1);
                std::string symbol = s.substr(index + 1, index2 - index - 1);

                index = index2;
                index2 = s.find_first_of(';', index + 1);
                std::string price = s.substr(index + 1, index2 - index - 1);

                int temp = commandRemHelper(symbol, stoi(price), Table);

                if (temp != -1)
                {
                    std::cout << "Было удалено " << temp << " элементов!\n";
                }
                else
                {
                    std::cout << "Символ \"" << symbol << "\" не распознан!\n";
                }

            }
            else
            {
                std::cout << "В строке \"" << s << "\" обнаружена ошибка!\n";
            }

        }
        else if (whatRemove == "manufacturer")
        {
            if (checkNumberOfThings(s) == 3)
            {
                index = index2;
                index2 = s.find_first_of(';', index + 1);

                std::string manufacturer = s.substr(index + 1, index2 - index - 1);

                int counter = 0;

                for (int i = 0; i < Table.size(); ++i)
                {
                    if (Table[i]->getManufacturer() == manufacturer)
                    {
                        ++counter;
                        Table.erase(Table.begin() + i);
                    }
                }

                std::cout << "Было удалено " << counter << " элементов!\n";

            }
            else
            {
                std::cout << "В строке \"" << s << "\" обнаружена ошибка!\n";
            }

        }
        else
        {
            std::cout << "Команда \"" << whatRemove << "\" на удаление не распознана!\n";
        }
    }
    else
    {
        std::cout << "Ошибка REM! Массив пустой! Нечего удалять!\n";
    }

}

void commandPrint(std::vector<Equipment*>& Table)
{
    if (Table.size() > 0)
    {
        for (int i = 0; i < Table.size(); ++i)
        {
            Table[i]->PRINT();
        }
    }
    else
    {
        std::cout << "Ошибка PRINT! Массив пустой! Нечего печатать!\n";
    }
}

void stringParser(const std::string &s, std::vector<Equipment*>& Table)
{
    int index = s.find_first_of(';');

    if (index != -1)
    {
        std::string command = s.substr(0, index);

        if (command == "ADD")
        {
            commandAdd(s, index, Table);
        }
        else if (command == "REM")
        {
            commandRem(s, index, Table);
        }
        else if (command == "PRINT")
        {
            commandPrint(Table);
        }
        else
        {
            std::cout << "Ошибка! Команда " << command << " не распознана!\n";
        }
    }
    else
    {
        std::cout << "Ошибка!\n";
    }
}

void readFromFile(std::vector<Equipment*>& Table)
{
    std::ifstream commands("ist.txt");

    if (commands)
    {
        std::string singleline;

        while (getline(commands, singleline))
        {
            stringParser(singleline, Table);
        }

        std::cout << "Работа с файлом выполнена\n";
    }
    else
    {
        std::cout << "Ошибка открытия файла";
    }

    commands.close();
}

void readFromConsole(std::vector<Equipment*>& Table)
{
    std::cout << "Введите -1 чтобы выйти из режима работы с консолью\n\n";

    std::string singleline;

    while (getline(std::cin, singleline))
    {
        if (singleline == "-1")
        {
            break;
        }
        stringParser(singleline, Table);
    }

    std::cout << "Работа с файлом выполнена\n";
}