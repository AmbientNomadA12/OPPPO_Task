// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com

#include "Racket.h"
#include <string>

void Racket::setWeight(int w)
{
    weight = w;
}
void Racket::setSize(int s)
{
    size = s;
}

const int Racket::getWeight() const
{
    return(weight);
}
const int Racket::getSize() const
{
    return(size);
}


Racket::Racket(int p, std::string m, int w, int s)
{
    setPrice(p);
    setManufacturer(m);

    setWeight(w);
    setSize(s);
}

void Racket::PRINT()
{
    std::cout << "–акетка: цена - " << getPrice() << ", производитель - " << getManufacturer() << ", вес - " << getWeight() << ", размер головки - " << getSize() << "\n";
}