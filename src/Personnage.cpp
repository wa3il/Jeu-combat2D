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

void Personnage::bougerAgauche(terrain& t){
	//if(t.posisvalide(this->phy.getPosx()-10, this->phy.getPosy()))
		this->phy.setPosx(this->phy.getPosx()- (t.getDimx()/200) );
		
}

void Personnage::bougerAdroite(terrain& t){
	if(t.posisvalide(this->phy.getPosx()+10, this->phy.getPosy()))
		this->phy.setPosx(this->phy.getPosx()+(t.getDimx()/200) );
}

void Personnage::sauter(terrain& t){
	if(t.posisvalide(this->phy.getPosx(), this->phy.getPosy()+10))
		this->phy.setPosy(this->phy.getPosy()- (t.getDimx()/100) );

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
	if (((cible.phy.getPosx() - this->phy.getPosx() > -100 ) && 
		(cible.phy.getPosx() - this->phy.getPosx() <= 0)) || 
		((cible.phy.getPosx() - this->phy.getPosx() < 100 ) && 
		(cible.phy.getPosx() - this->phy.getPosx() >= 0))) 
		{
			if((cible.phy.getPosy() - this->phy.getPosy() > -50 && cible.phy.getPosy() - this->phy.getPosy() <= 0) || 
				(cible.phy.getPosy() - this->phy.getPosy() < 50 && cible.phy.getPosy() - this->phy.getPosy() >= 0)) 
				{
					cout << "MP ou SP" << " attaque " << "MP ou SP" << endl;
					cible.recevoirDegats(m_competence->getDegats());

				}
		
		}
}

void Personnage::attaqueUltime(Personnage& cible)
{
	if (((cible.phy.getPosx() - this->phy.getPosx() > -100 ) && 
		(cible.phy.getPosx() - this->phy.getPosx() <= 0)) || 
		((cible.phy.getPosx() - this->phy.getPosx() < 100 ) && 
		(cible.phy.getPosx() - this->phy.getPosx() >= 0))) 
		{
			if (m_mana > 0 && m_vie > 0) 
			{
					cout << "MP ou SP" << " lance l'attaque ultime sur " << "MP ou SP" << endl;
					m_mana -= 50;
					cible.recevoirDegats(10);
			}
				else if(m_mana<=0) 
				{ 
					cout << "MP ou SP" << " n a pas assez de mana pour lancer l'attque ultime !" << endl; 
					m_mana = 0;
				}

					else 
					{ 
						cout << "MP ou SP" << " est mort !" << endl; 
					}
		}	
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