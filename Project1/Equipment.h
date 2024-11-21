// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com

#ifndef __EQUIPMENT_H_INCLUDED__
#define __EQUIPMENT_H_INCLUDED__

#include <string>

class Equipment
{
private:

    int price;
    std::string manufacturer;

public:

    void setPrice(int p);
    void setManufacturer(std::string m);

    int getPrice() const;
    std::string getManufacturer() const;

    virtual void PRINT();
};

#endif