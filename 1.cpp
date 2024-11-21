
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cmath>

using namespace std;

class Equipment
{
private:
    int price;
    string manufacturer;

public:

    void setPrice(int p)
    {
        price = p;
    }
    void setManufacturer(string m)
    {
        manufacturer = m;
    }

    int getPrice()
    {
        return(price);
    }
    string getManufacturer()
    {
        return(manufacturer);
    }

    virtual void PRINT()
    {
        cout << "Equipment\n";
    }
};

class Ball : public Equipment
{
private:
    int size;
    string material;

public:

    void setSize(int s)
    {
        size = s;
    }
    void setMaterial(string m)
    {
        material = m;
    }

    const int getSize()
    {
        return(size);
    }
    const string getMaterial()
    {
        return(material);
    }

    Ball(int p, string m, int s, string mm)
    {
        setPrice(p);
        setManufacturer(m);

        setSize(s);
        setMaterial(mm);
    }

    virtual void PRINT()
    {
        cout << "Мяч: цена - " << getPrice() << ", производитель - " << getManufacturer() << ", размер - " << getSize() << ", материал - " << getMaterial() << "\n";
    }

};

class Racket : public Equipment
{
private:
    int weight;
    int size;

public:

    void setWeight(int w)
    {
        weight = w;
    }
    void setSize(int s)
    {
        size = s;
    }

    const int getWeight()
    {
        return(weight);
    }
    const int getSize()
    {
        return(size);
    }


    Racket(int p, string m, int w, int s)
    {
        setPrice(p);
        setManufacturer(m);

        setWeight(w);
        setSize(s);
    }

    virtual void PRINT()
    {
        cout << "Ракетка: цена - " << getPrice() << ", производитель - " << getManufacturer() << ", вес - " << getWeight() << ", размер головки - " << getSize() << "\n";
    }
};

class Bicycle : public Equipment
{
private:
    string type;
    int speeds;

public:

    void setType(string t)
    {
        type = t;
    }
    void setSpeeds(int s)
    {
        speeds = s;
    }

    const string getType()
    {
        return(type);
    }
    const int getSpeeds()
    {
        return(speeds);
    }


    Bicycle(int p, string m, string t, int s)
    {
        setPrice(p);
        setManufacturer(m);

        setType(t);
        setSpeeds(s);
    }

    virtual void PRINT()
    {
        cout << "Велосипед: цена - " << getPrice() << ", производитель - " << getManufacturer() << ", тип - " << getType() << ", кол-во скоростей - " << getSpeeds() << "\n";
    }

};

int checkNumberOfThings(string s)
{
    int temp = 0;

    for (int i = 0; i < s.size(); ++i)
    {
        if (s[i] == ';')
            ++temp;
    }

    return(temp);
}

bool stringParserHelper (string s, int index, string* &properties, int N)
{
    //Thing is symbol ;
    if (checkNumberOfThings(s) != 6)
    {
        return(false);
    }

    for (int i = 0; i < N; ++i)
    {
        index = s.find_first_of(";", index + 1);
        int index2 = s.find_first_of(";", index + 1);

        if (index == -1 || index2 == -1)
        {
            return(false);
        }

        properties[i] = s.substr(index + 1, index2 - index - 1);
    }

    return(true);

    
}

void commandAdd(string s, int index, vector<Equipment*>& Table)
{
    string type = s.substr(index + 1, s.find_first_of(";", index + 1) - index - 1);

    int N = 4;
    string* properties = new string[N];

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
            cout << "В строке \"" << s << "\" обнаружена ошибка!\n";
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
            cout << "В строке \"" << s << "\" обнаружена ошибка!\n";
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
            cout << "В строке \"" << s << "\" обнаружена ошибка!\n";
        }

        delete[] properties;
    }
    else
    {
        cout << "Ошибка! Тип " << type << " не распознан!\n";
    }
}

//< > <= >= == !=
int commandRemHelper(string symbol, int price, vector<Equipment*>& Table)
{
    //Удалено элементов
    int counter = 0;
    
    auto it = Table.begin();

    if (symbol == "<")
    {
        while (it != Table.end())
        {
            if ((*it)->getPrice() < price)
            {
                delete* it;
                it = Table.erase(it);
                ++counter;
            }
            else
            {
                ++it;
            }
        }
    }
    else if (symbol == ">")
    {
        while (it != Table.end())
        {
            if ((*it)->getPrice() > price)
            {
                delete* it;
                it = Table.erase(it);
                ++counter;
            }
            else
            {
                ++it;
            }
        }
    }
    else if (symbol == "<=")
    {
        while (it != Table.end())
        {
            if ((*it)->getPrice() <= price)
            {
                delete* it;
                it = Table.erase(it);
                ++counter;
            }
            else
            {
                ++it;
            }
        }
    }
    else if (symbol == ">=")
    {
        while (it != Table.end())
        {
            if ((*it)->getPrice() >= price)
            {
                delete* it;
                it = Table.erase(it);
                ++counter;
            }
            else
            {
                ++it;
            }
        }
    }
    else if (symbol == "==")
    {
        while (it != Table.end())
        {
            if ((*it)->getPrice() == price)
            {
                delete* it;
                it = Table.erase(it);
                ++counter;
            }
            else
            {
                ++it;
            }
        }
    }
    else if (symbol == "!=")
    {
        while (it != Table.end())
        {
            if ((*it)->getPrice() != price)
            {
                delete* it;
                it = Table.erase(it);
                ++counter;
            }
            else
            {
                ++it;
            }
        }
    }
    else
    {
        return(-1);
    }
    return(counter);
}

void commandRem(string s, int index, vector<Equipment*>& Table)
{
    if (Table.size() > 0)
    {
        int index2 = s.find_first_of(";", index + 1);
        string whatRemove = s.substr(index + 1, index2 - index - 1);

        if (whatRemove == "price")
        {

            if (checkNumberOfThings(s) == 4)
            {
                index = index2;
                index2 = s.find_first_of(";", index + 1);
                string symbol = s.substr(index + 1, index2 - index - 1);

                index = index2;
                index2 = s.find_first_of(";", index + 1);
                string price = s.substr(index + 1, index2 - index - 1);

                int temp = commandRemHelper(symbol, stoi(price), Table);

                if (temp != -1)
                {
                    cout << "Было удалено " << temp << " элементов!\n";
                }
                else
                {
                    cout << "Символ \"" << symbol << "\" не распознан!\n";
                }

            }
            else
            {
                cout << "В строке \"" << s << "\" обнаружена ошибка!\n";
            }

        }
        else if (whatRemove == "manufacturer")
        {
            if (checkNumberOfThings(s) == 3)
            {
                index = index2;
                index2 = s.find_first_of(";", index + 1);

                string manufacturer = s.substr(index + 1, index2 - index - 1);

                int counter = 0;

                auto it = Table.begin();

                while (it != Table.end())
                {
                    if ((*it)->getManufacturer() == manufacturer)
                    {
                        delete* it;
                        it = Table.erase(it);
                        ++counter;
                    }
                    else
                    {
                        ++it;
                    }
                }

                cout << "Было удалено " << counter << " элементов!\n";

            }
            else
            {
                cout << "В строке \"" << s << "\" обнаружена ошибка!\n";
            }

        }
        else
        {
            cout << "Команда \"" << whatRemove << "\" на удаление не распознана!\n";
        }
    }
    else
    {
        cout << "Ошибка REM! Массив пустой! Нечего удалять!\n";
    }
    
}

void commandPrint(vector<Equipment*>& Table)
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
        cout << "Ошибка PRINT! Массив пустой! Нечего печатать!\n";
    }
}

void stringParser(string s, vector<Equipment*>& Table)
{
    int index = s.find_first_of(";");

    if (index != -1)
    {
        string command = s.substr(0, index);

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
            cout << "Ошибка! Команда " << command << " не распознана!\n";
        }
    }
    else
    {
        cout << "Ошибка!\n";
    }
}

void readFromFile(vector<Equipment*> &Table)
{
    ifstream commands("ist.txt");

    if (commands)
    {
        string singleline;

        while (getline(commands, singleline))
        {
            stringParser(singleline, Table);
        }

        cout << "Работа с файлом выполнена\n";
    }
    else
    {
        cout << "Ошибка открытия файла";
    }

    commands.close();
}

void readFromConsole(vector<Equipment*> &Table)
{
    cout << "Введите -1 чтобы выйти из режима работы с консолью\n\n";

    string singleline;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    while (getline(cin, singleline))
    {
        if (singleline == "-1")
        {
            break;
        }
        stringParser(singleline, Table);
    }

    cout << "Работа с файлом выполнена\n";
}

int main()
{
    setlocale(LC_ALL, "rus");
    vector<Equipment*> Table;

    //Возможность выбрать режим
    bool choice;
    cout << "Выберите режим работы: 0 - чтение из файла; 1 - ручной ввод\n(по умолчанию выбран режим 0)\n";
    cin >> choice;

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

    cout << "\nВывести массив?\n0 - Да; 1 - Нет\n(по умолчанию выбран режим 0)\n\n";
    cin >> choice;

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
