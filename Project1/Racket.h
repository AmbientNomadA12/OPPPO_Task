// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com

#ifndef __RACKET_H_INCLUDED__
#define __RACKET_H_INCLUDED__

#include "Equipment.h"
#include <iostream>

class Racket : public Equipment
{
private:
    int weight;
    int size;

public:

    void setWeight(const int &w);
    void setSize(const int &s);

    const int getWeight() const;
    const int getSize() const;


    Racket(int p, std::string m, int w, int s);

    void PRINT() override;
};


#endif