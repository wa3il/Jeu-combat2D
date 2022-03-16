#ifndef ARME_H
#define ARME_H

#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <cassert>
#include <time.h>




class Arme
{
public:

    Arme();
    Arme(std::string nom, int degats);
    void changer(std::string nom, int degats);
    void afficher() const;
    int getDegats() const;
    ~Arme();

private:

    std::string m_nom;
    int m_degats;
};

#endif