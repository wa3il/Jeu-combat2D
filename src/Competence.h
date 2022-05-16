/**
 * @file Competence.h
 * @brief fichier de déclaration de la class competance
 * @version 0.1
 * @date 2022-05-16
 * 
 * @copyright Copyright (c) 2022
 * 
 */

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
    /**
     * @brief Construct a new Competence object
     * 
     */
    Competence();

    /**
     * @brief Construct a new Competence object
     * 
     * @param nom 
     * @param degats 
     */
    Competence(std::string nom, int degats);

    /**
     * @brief fonction changer de competance
     * 
     * @param nom 
     * @param degats 
     */
    void changer(std::string nom, int degats);

    /**
     * @brief fonction afficher la competances
     * 
     */
    void afficher() const;

    /**
     * @brief Get the Degats object
     * 
     * @return int 
     */
    int getDegats() const;

    /**
     * @brief Destroy the Competence object
     * 
     */
    ~Competence();

private:

    std::string m_nom;/*!< nom de la competance */
    int m_degats;/*!< degat de la competance */
};

#endif