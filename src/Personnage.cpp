#include"Personnage.h"


using namespace std;



Personnage::Personnage()
{	
	m_position = Vector2D();
	cout << "Entre le nom de votre personnage : " << endl;
	cin >> m_nom;
	m_vie = 100;
	m_mana = 100;
	m_competence = new Competence();
	
}

Personnage::Personnage(int x,int y)
{
	m_position = Vector2D(x,y);
	m_vie = 100;
	m_mana = 100;
	m_competence = new Competence();
	
}

Personnage::Personnage(string nom ,string nomCompetence, int degatsCompetence) : m_nom(nom), m_vie(100), m_mana(100)
{
	m_competence = new Competence(nomCompetence, degatsCompetence);
}


Personnage::Personnage(string nom, int vie, int mana) : m_nom(nom), m_vie(vie), m_mana(mana), m_competence(0)
{
	m_competence = new Competence("Epee rouillee", (10));
}


Personnage::Personnage(Personnage const& personnageACopier)
	: m_vie(personnageACopier.m_vie), m_mana(personnageACopier.m_mana), m_competence(0)
{
	m_competence = new Competence(*(personnageACopier.m_competence));
}


string Personnage::getNom() const
{
	return m_nom;
}

int& Personnage :: getx(){ return m_position.getx(); }
int& Personnage :: gety(){ return m_position.gety(); }

void Personnage :: setx(int x){ m_position.setx(x); }
void Personnage :: sety(int y){ m_position.sety(y); }

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



//mouvements

void Personnage::bougerAgauche(int xg){

	m_position.getx() = m_position.getx() - xg;
}

void Personnage::bougerAdroite(int xd){
	m_position.getx() = m_position.getx() + xd;
}

void Personnage::sauter(int yh){
	m_position.gety() = m_position.gety() - yh;
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
	cout << m_nom << " attaque " << cible.getNom() << endl;
	cible.recevoirDegats(m_competence->getDegats());	
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

