#include "Forme.h"
Forme::Forme() :m_couleur(DEFAULT), m_marquee(false) {}
Forme::Forme(const Forme* forme) : m_couleur(forme->m_couleur), m_marquee(false) {}
Forme::Forme(const Couleur & couleur) : m_couleur(couleur), m_marquee(false){}
Forme::~Forme(){}

Couleur Forme::getCouleur() const{
	return m_couleur;
}

void Forme::setCouleur(const string & couleur) {
	m_couleur.setCouleur(couleur);
}

bool Forme::estMarquee() {
	return m_marquee;
}

void Forme::setMarquee(bool marquee) {
	m_marquee = marquee;
}

Forme::operator string() const
{
	ostringstream oss;
	oss << (string)m_couleur;
	return oss.str();
}

bool Forme::operator==(const Forme &obj) const {
	return m_couleur == obj.m_couleur;
}

bool Forme::operator!= (const Forme &obj) const {
	return !(*this == obj);
}
const Forme* Forme::operator= (const Forme& obj) {
	if (this != &obj)
	{
		m_couleur = obj.getCouleur();
	}
	return this;
}

ostream& Forme::print(ostream & flux) const {
	flux << "Couleur = " << m_couleur;
	return flux;
}

ostream & operator << (ostream & flux, const Forme& forme) {
	return forme.print(flux);
}




