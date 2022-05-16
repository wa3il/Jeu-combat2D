#include "Competence.h"

using namespace std;

Competence::Competence() : m_nom("Attaque A"), m_degats(2)
{

}

Competence::Competence(std::string nom, int degats) : m_nom(nom), m_degats(degats)
{

}

void Competence::changer(std::string nom, int degats)
{
	m_nom = nom;
	m_degats = degats;
}

void Competence::afficher() const
{
	cout << "Competence : " << m_nom << "(  Degats : " << m_degats <<" )"<< endl;
}

int Competence::getDegats() const
{
	return m_degats;
}


Competence::~Competence()
{

}