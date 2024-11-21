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

    void setWeight(int w);
    void setSize(int s);

    int getWeight() const;
    int getSize() const;


    Racket(int p, const std::string &m, int w, int s);

    void PRINT() override;
};


#endif