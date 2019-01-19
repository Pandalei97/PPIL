#include "Segment.h"
#include "VisiteurSauvTXT.h"
#include "VisiteurDessin.h"

Segment::Segment(const Vecteur2D & PO, const Vecteur2D & PE, const Couleur & coul):Forme(coul){
	if (PO == PE)
		throw Exception("Les deux points ne doivent pas être identiques!");
	m_PO = PO;
	m_PE = PE;
}

Segment::Segment(const Segment & obj):Forme(obj.getCouleur()) {
	m_PO = obj.m_PO;
	m_PE = obj.m_PE;
}

Segment:: ~Segment() {}

Vecteur2D Segment::getPO()const {
	return m_PO;
}
void Segment::setPO(const Vecteur2D& PO) {
	if(PO == m_PE)
		throw Exception("Les deux points ne doivent pas être identiques!");
	m_PO = PO;

}
Vecteur2D Segment::getPE()const {
	return m_PE;
}
void Segment::setPE(const Vecteur2D& PE) {
	if (PE == m_PO)
		throw Exception("Les deux points ne doivent pas être identiques!");
	m_PE = PE;
}

Segment::operator string() const {
	ostringstream oss;
	oss << "Segment[ " << (estMarquee() ? "Marquee; " : "Non Marquee; ") << Forme::operator string() << "; " << m_PO << "; " << m_PE << "; Aire: " << getAire() << "]" << endl;
	return oss.str();
}
bool Segment::operator==(const Segment &obj) const {
	return (getCouleur() == obj.getCouleur()) && (m_PO == obj.m_PO) && (m_PE == obj.m_PE);
}
bool Segment::operator!= (const Segment &obj) const {
	return !(*this == obj);
}
const Segment & Segment::operator = (const Segment& obj) {
	if (this != &obj)
	{
		Forme::operator=(obj);
		m_PO = obj.m_PO;
		m_PE = obj.m_PE;
	}
	return *this;
}

//Fonctions à implémenter depuis Forme
const double Segment::getAire() const {
	return 0;
}

Forme * Segment::clone() const {
	return new Segment(*this);
}

void Segment::homothetie(const  Vecteur2D & vectHomotethie, double k) {
	m_PO.homothetie(vectHomotethie, k);
	m_PE.homothetie(vectHomotethie, k);
}

void Segment::translation(const Vecteur2D & vectTranslation) {
	m_PO.translation(vectTranslation);
	m_PE.translation(vectTranslation);
}

void Segment::rotation(const  Vecteur2D & vectCentre, double angle) {
	m_PO.rotation(vectCentre, angle);
	m_PE.rotation(vectCentre, angle);
}

ostream & Segment::print(ostream & flux) const {
	return flux << (string)(*this);
}

void Segment::accepteSauvegarder(const VisiteurSauvTXT *v)const {
	v->visite(this);
}

void Segment::dessiner(const VisiteurDessin *v)const {
	v->visite(this);
}