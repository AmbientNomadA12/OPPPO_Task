// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com

#ifndef __BALL_H_INCLUDED__
#define __BALL_H_INCLUDED__

#include "Equipment.h"

class Ball : public Equipment
{
private:
    int size;
    std::string material;

public:
    void setSize(const int &s);
    void setMaterial(const std::string &m);

    int getSize() const;
    std::string getMaterial() const;

    Ball(int p, std::string m, int s, std::string mm);

    void PRINT() override;
};

#endif