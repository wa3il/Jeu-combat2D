#include"Personnage.h"
#include <stdlib.h>


using namespace std;



Personnage::Personnage()
{	
	phy = Physic(10,15);
	m_vie = 100;
	m_mana = 100;
	m_competence = new Competence();
	
}

Personnage::Personnage(int x,int y)
{
	phy = Physic(x,y);
	m_vie = 100;
	m_mana = 100;
	m_competence = new Competence();
	
}

Personnage::Personnage(string nom ,string nomCompetence, int degatsCompetence) : m_nom(nom), m_vie(100), m_mana(100)
{
	phy = Physic();
	m_competence = new Competence(nomCompetence, degatsCompetence);
}


Personnage::Personnage(string nom, int vie, int mana) : m_nom(nom), m_vie(vie), m_mana(mana), m_competence(0)
{
	phy = Physic();
	m_competence = new Competence("Epee rouillee", (10));
}


Personnage::Personnage(Personnage const& personnageACopier) : m_vie(personnageACopier.m_vie), m_mana(personnageACopier.m_mana), m_competence(0)
{
	m_competence = new Competence(*(personnageACopier.m_competence));
}




string Personnage::getNom() const
{
	return m_nom;
}

//getter pour avoir la position x :
int Personnage :: getx()const{ return phy.getPosx(); }
int Personnage :: gety()const{ return phy.getPosy(); }

//getter pour avoir la position y :
void Personnage :: setxy(int x,int y){ phy.setPos(x,y); }

void Personnage :: sety(int y){ phy.setPosy(y);}

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
	m_competence->afficher();
	if (m_vie == 0) { cout << m_nom << " a perdu" << endl; }
}



int Personnage::getVie() {

	return m_vie;
}

//mouvements

void Personnage::bougerAgauche(int xg){
	//m_position.getx() = m_position.getx() - xg;
	phy.setPosx((this->getx())-xg);
}

void Personnage::bougerAdroite(int xd){
	//m_position.getx() = m_position.getx() + xd;
	phy.setPosx((this->getx())+xd);
}

void Personnage::sauter(int yh){
	//m_position.gety() = m_position.gety() - yh;
	//phy.setVity((this->phy.getVit().gety())-yh);
	phy.setPosy(this->gety()-yh);
}


void Personnage::changerCompetence(std::string nomNouvelleCompetence, int degatsNouvelleCompetence)
{
	m_competence->changer(nomNouvelleCompetence, degatsNouvelleCompetence);
	cout << m_nom << "  => Changement de competence : " <<nomNouvelleCompetence<< endl;
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
	if (((cible.getx() - this->getx() > -100 ) && (cible.getx() - this->getx() <= 0)) || ((cible.getx() - this->getx() < 100 ) && (cible.getx() - this->getx() >= 0)) ) {
		if((cible.gety() - this->gety() > -50 && cible.gety() - this->gety() <= 0) || (cible.gety() - this->gety() < 50 && cible.gety() - this->gety() >= 0)) {

			cout << m_nom << " attaque " << cible.getNom() << endl;
			cible.recevoirDegats(m_competence->getDegats());

		}
		
	}
}





void Personnage::attaqueUltime(Personnage& cible)
{
	if (m_mana > 0 && m_vie > 0) 
	{
			cout << m_nom << " lance l'attaque ultime sur " << cible.getNom() << endl;
			m_mana -= 50;
			cible.recevoirDegats(50);
	}
		else if(m_mana<=0) 
		{ 
			cout << m_nom << " n a pas assez de mana pour lancer l'attque ultime !" << endl; 
			m_mana = 0;
		}

			else 
			{ 
				cout << m_nom << " est mort !" << endl; 
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


Personnage::~Personnage()
{
	delete m_competence;
}

void Personnage:: ticks(float deltaTime){

	phy.ticks(deltaTime);


}





void Personnage::testRegression() {

	Personnage Premier;
	Personnage Deuxieme(10,20);
	Personnage mp("luffy", "GumGum ballooon", 30);
	Personnage sp("Ichigo" , 100, 100);

	Personnage Luffy("Luffy", 100, 100);

	Personnage Luffy_Copier(Luffy);

	assert(Luffy_Copier.getx() == 0);
	assert(Luffy_Copier.gety() == 0);

	assert(Deuxieme.getx() == 10);
	assert(Deuxieme.gety() == 20);

	assert(mp.getNom() == "luffy");

	Premier.bougerAdroite(10);
	assert(Premier.getx() == 10);

	Deuxieme.bougerAgauche(20);
	assert(Deuxieme.getx() == -10);

	Premier.sauter(50);
	assert(Premier.gety() == -50);

	Luffy.recevoirDegats(20);  // 100 de vie -20 ce qui fera 80.

	assert(Luffy.getVie() == 80);

	mp.attaquer(sp);  //mp attaque sp avec une competence qui fait 30 de degats
	 //on verifie l'etat de sp qui devra avoir 70 points de vie :
	assert(sp.getVie() == 70);

	sp.boirePotionDeVie(10); //lui remetra 10 points de vie 

	assert(sp.getVie() == 80);

	mp.changerCompetence("jet Pistol", 50);  // cela change sa competence en un autre : On peut le verifier grace a la fonction Affciher Etat.
}