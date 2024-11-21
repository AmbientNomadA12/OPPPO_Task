// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com


#include "Ball.h"
#include <iostream>

void Ball::setSize(const int &s)
{
    size = s;
}

void Ball::setMaterial(const std::string &m)
{
    material = m;
}

int Ball::getSize() const
{
    return size;
}

std::string Ball::getMaterial() const
{
    return material;
}

Ball::Ball(int p, std::string m, int s, std::string mm) : Equipment(), size(s), material(mm)
{
    setPrice(p);
    setManufacturer(m);
}

void Ball::PRINT()
{
    std::cout << "ћ€ч: цена - " << getPrice() << ", производитель - " << getManufacturer() << ", размер - " << getSize() << ", материал - " << getMaterial() << "\n";
}