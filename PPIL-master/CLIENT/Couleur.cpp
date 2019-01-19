#include "Couleur.h"

//Initialiser le tableau des couleurs disponibles
vector<string> Couleur::tab_couleur = Couleur::InitTabCouleur();

Couleur::Couleur(){
	setNomCouleur(DEFAULT);
}
Couleur::Couleur(const string & couleur) {
	setNomCouleur(couleur);
}
Couleur::Couleur(const Couleur& couleur){
	setNomCouleur(couleur.m_nomCouleur);
}
Couleur::~Couleur(){}

bool Couleur::contains(string couleur) {
	for (int i = 0; i < tab_couleur.size(); i++)
	{
		if (tab_couleur[i] == couleur)
			return true;
	}
	return false;

}

const string & Couleur::getNomCouleur() const {
	return m_nomCouleur;
}
void Couleur::setNomCouleur(const string & couleur){
	
	if (!contains(couleur)) {
		ostringstream s;
		s << "Couleur " << couleur << " n'existe pas dans tab_couleur";
		throw Exception(s.str());
	}
	m_nomCouleur = couleur;
}

Couleur::operator string() const {
	ostringstream oss;
	oss << m_nomCouleur;
	return oss.str();
}

bool Couleur::operator==(const  Couleur &obj) const {
	return m_nomCouleur == obj.m_nomCouleur;
}
bool Couleur::operator != (const Couleur &obj) const {
	return !((*this) == obj);
}
const Couleur Couleur::operator = (const Couleur& couleur) {
	if (this != &couleur)
	{
		m_nomCouleur = couleur.m_nomCouleur;
	}
	return (*this);
}
ostream & operator << (ostream & flux, const Couleur& coul) {
	flux << string(coul);
	return flux;
}

