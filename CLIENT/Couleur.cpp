#include "Couleur.h"

//Initialiser le tableau des couleurs disponibles
vector<string> Couleur::tab_couleur = Couleur::InitTabCouleur();

Couleur::Couleur(){
	setCouleur(DEFAULT);
}
Couleur::Couleur(const string & couleur) {
	setCouleur(couleur);
}
Couleur::Couleur(const Couleur& couleur){
	setCouleur(couleur.m_couleur);
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

const string & Couleur::getCouleur() const {
	return m_couleur;
}
void Couleur::setCouleur(const string & couleur){
	
	if (!contains(couleur)) {
		ostringstream s;
		s << "Couleur " << couleur << " n'existe pas dans tab_couleur";
		throw Exception(s.str());
	}
	m_couleur = couleur;
}

Couleur::operator string() const {
	ostringstream oss;
	oss << m_couleur;
	return oss.str();
}

bool Couleur::operator==(const  Couleur &obj) const {
	return m_couleur == obj.m_couleur;
}
bool Couleur::operator != (const Couleur &obj) const {
	return !((*this) == obj);
}
const Couleur Couleur::operator = (const Couleur& couleur) {
	if (this != &couleur)
	{
		m_couleur = couleur.m_couleur;
	}
	return (*this);
}
ostream & operator << (ostream & flux, const Couleur& coul) {
	flux << string(coul);
	return flux;
}

