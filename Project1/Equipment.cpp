// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com

#include "Equipment.h"
#include <iostream>

void Equipment::setPrice(int p)
{
    price = p;
}

void Equipment::setManufacturer(std::string m)
{
    manufacturer = m;
}

int Equipment::getPrice() const
{
    return(price);
}
std::string Equipment::getManufacturer() const
{
    return(manufacturer);
}

void Equipment::PRINT()
{
    std::cout << "Equipment\n";
}