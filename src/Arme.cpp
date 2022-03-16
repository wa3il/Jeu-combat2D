#include "Arme.h"

using namespace std;

Arme::Arme() : m_nom("epee rouillee"), m_degats(10)
{

}

Arme::Arme(std::string nom, int degats) : m_nom(nom), m_degats(degats)
{

}

void Arme::changer(std::string nom, int degats)
{
	m_nom = nom;
	m_degats = degats;
}

void Arme::afficher() const
{
	cout << "arme : " << m_nom << "(  Degats : " << m_degats <<" )"<< endl;
}

int Arme::getDegats() const
{
	return m_degats;
}


Arme::~Arme()
{

}