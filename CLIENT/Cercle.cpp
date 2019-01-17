#include "Cercle.h"
#include "VisiteurSauvTXT.h"
#include "VisiteurDessin.h"
Cercle::Cercle(const Vecteur2D & centre, double rayon, const Couleur & coul) :Forme(coul) {
	setCentre(centre);
	setRayon(rayon);
}

Cercle::Cercle(const Cercle & obj) :Forme(obj.getCouleur()) {
	setCentre(obj.m_centre);
	setRayon(obj.m_rayon);
}

Cercle:: ~Cercle() {}

Vecteur2D Cercle::getCentre()const {
	return m_centre;
}
void Cercle::setCentre(const Vecteur2D& centre) {
	m_centre = centre;

}

double Cercle::getRayon()const {
	return m_rayon;
}
void Cercle::setRayon(double rayon) {
	if (rayon <= 0)
		throw Exception("Le Rayon ne doit pas être négatif!");
	m_rayon = rayon;
}

Cercle::operator string() const {
	ostringstream oss;
	oss << "Cercle:" << Forme::operator string() << ";" << m_centre << ";" << m_rayon;
	return oss.str();
}
bool Cercle::operator==(const Cercle &obj) const {
	return (getCouleur() == obj.getCouleur()) && (m_centre == obj.m_centre) && (m_rayon == obj.m_rayon);
}
bool Cercle::operator!= (const Cercle &obj) const {
	return !(*this == obj);
}
const Cercle & Cercle::operator = (const Cercle& obj) {
	if (this != &obj)
	{
		Forme::operator=(obj);
		m_centre = obj.m_centre;
		m_rayon = obj.m_rayon;
	}
	return *this;
}

//Fonctions à implémenter depuis Forme
const double Cercle::getAire() const {
	return m_rayon * m_rayon * PI;
}

Forme * Cercle::clone() const {
	return new Cercle(*this);
}

void Cercle::homothetie(const  Vecteur2D & vectHomotethie, double k) {
	m_centre.homothetie(vectHomotethie, k);
	m_rayon *= fabs(k);
}

void Cercle::translation(const Vecteur2D & vectTranslation) {
	m_centre.translation(vectTranslation);
}

void Cercle::rotation(const  Vecteur2D & vectCentre, double angle) {
	m_centre.rotation(vectCentre, angle);
}

ostream & Cercle::print(ostream & flux) const {
	return flux << (string)(*this);
}

void Cercle::accepteSauvegarder(const VisiteurSauvTXT *v)const {
	v->visite(this);
}

void Cercle::dessiner(const VisiteurDessin *v)const {
	v->visite(this);
}