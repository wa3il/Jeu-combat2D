#ifndef COMPETENCE_H
#define COMPETENCE_H

#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <cassert>
#include <time.h>




class Competence
{
public:

    Competence();
    Competence(std::string nom, int degats);
    void changer(std::string nom, int degats);
    void afficher() const;
    int getDegats() const;
    ~Competence();

private:

    std::string m_nom;
    int m_degats;
};

#endif