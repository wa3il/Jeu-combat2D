#include <iostream>
#include<string>
#include"Personnage.h"
#include "Arme.h"

using namespace std;

Personnage::Personnage()
{
	cout << "Entre le nom de votre personnage : " << endl;
	cin >> m_nom;
	m_arme = 0;
	m_vie = 100;
	m_mana = 100;
	m_arme = new Arme();
	
}

Personnage::Personnage(string nom ,string nomArme, int degatsArme) : m_nom(nom), m_vie(100), m_mana(100)
{
	m_arme = new Arme(nomArme, degatsArme);
}


Personnage::Personnage(string nom, int vie, int mana) : m_nom(nom), m_vie(vie), m_mana(mana), m_arme(0)
{
	m_arme = new Arme("Epee rouillee", (10));
}


Personnage::Personnage(Personnage const& personnageACopier)
	: m_vie(personnageACopier.m_vie), m_mana(personnageACopier.m_mana), m_arme(0)
{
	m_arme = new Arme(*(personnageACopier.m_arme));
}





Personnage::~Personnage()
{
	delete m_arme;
}

string Personnage::getNom() const
{
	return m_nom;
}



void Personnage::recevoirDegats(int nbDegats) 
{
	m_vie -= nbDegats;

	if (m_vie<0) //pour éviter d'avoir une vie négative.
	{
		m_vie = 0;
	}
	cout << m_nom <<" :"<< endl;
	cout << " recoit " << nbDegats << " de degats et lui reste donc : " << m_vie <<" points de vie ."<< endl;
}


void Personnage::attaquer(Personnage& cible)
{
	cout << m_nom << " attaque " << cible.getNom() << endl;
	cible.recevoirDegats(m_arme->getDegats());	
}





void Personnage::attaqueMagique(Personnage& cible)
{
	if (m_mana > 0 && m_vie > 0) 
	{
			cout << m_nom << " lance une attaque magique sur " << cible.getNom() << endl;
			m_mana -= 50;
			cible.recevoirDegats(50);
	}
		else if(m_mana<=0) 
		{ 
			cout << m_nom << " n a pas assez de mana pour lancer une attaque magique !" << endl; 
		}

			else 
			{ 
				cout << m_nom << " est mort !" << endl; 
			}

	if (m_mana < 0)
		{
			m_mana = 0;
		}
	
	
}







void Personnage::boirePotionDeVie(int quantitePotion)
{
	m_vie += quantitePotion;
	if (m_vie > 100)
	{
		m_vie = 100;
	}
	cout << m_nom << " boit une potion et se remet a " << m_vie << " points de vie" << endl;
	
}

void Personnage::changerArme(std::string nomNouvelleArme, int degatsNouvelleArme)
{
	m_arme->changer(nomNouvelleArme, degatsNouvelleArme);
	cout << m_nom << "  => Changement d'arme : " <<nomNouvelleArme<< endl;
}


bool Personnage::estVivant() const
{
	if (m_vie>0)
	{
		return true;
	}
	else { return false; }
}

void Personnage::afficherEtat() const
{

	cout << "Nom : " << m_nom << endl;
	cout << "Vie : " << m_vie << endl;
	cout << "Mana : " << m_mana << endl;
	m_arme->afficher();
	if (m_vie == 0) { cout << m_nom << " a perdu" << endl; }
}








