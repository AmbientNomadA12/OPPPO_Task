// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com

#ifndef __BICYCLE_H_INCLUDED__
#define __BICYCLE_H_INCLUDED__

#include "Equipment.h"
#include <iostream>

class Bicycle : public Equipment
{
private:

    std::string type;
    int speeds;

public:

    void setType(std::string t);
    void setSpeeds(int s);

    const std::string getType() const;
    const int getSpeeds() const;

    Bicycle(int p, std::string m, std::string t, int s);

    void PRINT() override;

};

#endif