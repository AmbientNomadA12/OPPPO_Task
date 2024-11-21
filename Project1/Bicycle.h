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

    void setType(const std::string &t);
    void setSpeeds(int s);

    std::string getType() const;
    int getSpeeds() const;

    Bicycle(int p, const std::string &m, const std::string &t, int s);

    void PRINT() override;

};

#endif