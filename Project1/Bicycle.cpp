// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com

#include "Bicycle.h"
#include <string>

void Bicycle::setType(const std::string &t)
{
    type = t;
}
void Bicycle::setSpeeds(int s)
{
    speeds = s;
}

std::string Bicycle::getType() const
{
    return type;
}
int Bicycle::getSpeeds() const
{
    return speeds;
}


Bicycle::Bicycle(int p, const std::string &m, const std::string &t, int s) : Equipment(), type(t), speeds(s)
{
    setPrice(p);
    setManufacturer(m);

    setType(t);
    setSpeeds(s);
}

void Bicycle::PRINT()
{
    std::cout << "Велосипед: цена - " << getPrice() << ", производитель - " << getManufacturer() << ", тип - " << getType() << ", кол-во скоростей - " << getSpeeds() << "\n";
}