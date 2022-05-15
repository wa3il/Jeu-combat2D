#include"Personnage.h"
#include <stdlib.h>
#include <math.h>



using namespace std;


//constructeur et destructeur
Personnage::Personnage()
{	
	phy = Physic();
	m_vie = 100;
	m_mana = 100;
	m_competence = new Competence();

	
}

Personnage::~Personnage()
{
	delete m_competence;
}


//mouvements

void Personnage::bougerAgauche(float xg){
	this->phy.setPosx(this->phy.getPosx()-xg );
}

void Personnage::bougerAdroite(float xd){
	this->phy.setPosx(this->phy.getPosx()+xd );
}

void Personnage::sauter(float yh){
	this->phy.setPosy(this->phy.getPosy()-yh );
}

void Personnage::sauterAdroite(float deltaTime){
	//Variables méthode 2:
    const double g = 9.81;
    const double pi = 3.14;
    int v_init = 2;
    int angle_init = pi/3;
	double v_x = cos(angle_init)*v_init;
    double v_y = sin(angle_init)*v_init;

	// La position relative 
    Vector2D posRel(0,0);
    
	//On calcule la valeur relative de y:
    posRel.setx((int)(v_x*deltaTime));
    posRel.sety((int)((v_y*deltaTime)-((g*deltaTime*deltaTime)/2000)));

    //On calcule maintenant les valeurs absolues

	this->phy.setPosx(this->phy.getPosx() + posRel.getx());
	this->phy.setPosy(this->phy.getPosy() - posRel.gety());
	
}

void Personnage::sauterAgauche(){

}



//Attaques
void Personnage::recevoirDegats(int nbDegats) 
{
	m_vie -= nbDegats;

	if (m_vie<0) //pour éviter d'avoir une vie négative.
	{
		m_vie = 0;
	}
	cout << " recoit " << nbDegats << " de degats et lui reste donc : " << m_vie <<" points de vie ."<< endl;
}

void Personnage::attaquer(Personnage& cible)
{
	/* if (((cible.getx() - this->getx() > -100 ) && (cible.getx() - this->getx() <= 0)) || ((cible.getx() - this->getx() < 100 ) && (cible.getx() - this->getx() >= 0)) ) {
		if((cible.gety() - this->gety() > -50 && cible.gety() - this->gety() <= 0) || (cible.gety() - this->gety() < 50 && cible.gety() - this->gety() >= 0)) {

			cout << m_nom << " attaque " << cible.getNom() << endl;
			cible.recevoirDegats(m_competence->getDegats());

		}
		
	} */
}

void Personnage::attaqueUltime(Personnage& cible)
{
	/* if (m_mana > 0 && m_vie > 0) 
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
			} */
	
}

void Personnage::changerCompetence(int degatsNouvelleCompetence)
{
	/* m_competence->changer(nomNouvelleCompetence, degatsNouvelleCompetence);
	cout <<"  => Changement de competence : " << nomNouvelleCompetence << endl; */
}



//Vie et Etat

bool Personnage::estVivant() const
{
	if (m_vie>0)
	{
		return true;
	}
	else { return false; }
}

int Personnage::getVie() {

	return m_vie;
}

void Personnage :: setVie(int vie){
	this -> m_vie = vie ;
}


void Personnage::afficherEtat() const
{	
	if (m_vie == 0) { cout  << " a perdu" << endl;}
	cout << "Vie : " << m_vie << endl;
	cout << "Mana : " << m_mana << endl;
	m_competence->afficher();
	
}

void Personnage::boirePotionDeVie(int quantitePotion)
{
	m_vie += quantitePotion;
	if (m_vie > 100)
	{
		m_vie = 100;
	}
	cout  << " boit une potion et se remet a " << m_vie << " points de vie" << endl;
	
}



//test Regression

void Personnage::testRegression() {

    /* //Constructeurs
    Personnage Premier;
    Personnage Deuxieme(10,20);

    //Test sur les accesseurs
    assert(Premier.getx() == 0);
    assert(Premier.gety() == 0);

    assert(Deuxieme.getx() == 10);
    assert(Deuxieme.gety() == 20);

    //Test sur les mouvements
    //Bouger a droite
    Premier.bougerAdroite(10);
    assert(Premier.getx() == 10);

    //Bouger a gauche
    Deuxieme.bougerAgauche(20);
    assert(Deuxieme.getx() == -10);

    //Sauter
    Premier.sauter(50);
    assert(Premier.gety() == -50);

    //Test sur les attaques
    Premier.recevoirDegats(20);  // 100 de vie -20 ce qui fera 80.
    Deuxieme.recevoirDegats(50); //100 - 50 = 50

    //Test sur l'état
    assert(Deuxieme.getVie() == 80); //VieInitiale = 100 - 50  ==> vie = 100


    Premier.attaquer(Deuxieme);  //mp attaque sp avec une competence qui fait 30 de degats
    //on verifie l'etat de sp qui devra avoir 70 points de vie :
    assert(Deuxieme.getVie() == 70);

    //Test sur la fonction qui remet de la vie au personnage
    Deuxieme.boirePotionDeVie(10); //lui remetra 10 points de vie 
    assert(Deuxieme.getVie() == 80);

    //Test sur Est_vivant?
    Deuxieme.estVivant();
    assert(Deuxieme.estVivant() == true); */

}