#include "Triangle.h"
#include "VisiteurSauvTXT.h"


Triangle::Triangle(const Vecteur2D & P1, const Vecteur2D & P2, const Vecteur2D & P3, const Couleur & coul) :Forme(coul) {
	if (!verifPoints(P1, P2, P3))
		throw Exception("Les 3 points fornis ne peuvent pas former un triangle.");
	m_P1 = P1;
	m_P2 = P2;
	m_P3 = P3;
}

Triangle::Triangle(const Triangle & obj) :Forme(obj.getCouleur()) {
	if (!verifPoints(obj.getP1(), obj.getP2(), obj.getP3()))
		throw Exception("Les 3 points fornis ne peuvent pas former un triangle.");
	m_P1 = obj.m_P1;
	m_P2 = obj.m_P2;
	m_P3 = obj.m_P3;
}

Triangle:: ~Triangle() {}

bool Triangle::verifPoints(const Vecteur2D & P1, const Vecteur2D & P2, const Vecteur2D& P3) {
	//Les points doivent être différents
	if ((P1 == P2) || (P2 == P3) || (P1 == P3))
		return false;


	double pente1 = (P2.getY() - P1.getY()) / (P2.getX() - P1.getX());
	double pente2 = (P3.getY() - P1.getY()) / (P3.getX() - P1.getX());

	return fabs(pente1) != fabs(pente2);

}
Vecteur2D Triangle::getP1()const {
	return m_P1;
}

void Triangle::setP1(const Vecteur2D& P1) {
	if (!verifPoints(P1, m_P2, m_P3))
		throw("La modification sur P1 ne permet pas de former un triangle.");
	m_P1 = P1;
}

Vecteur2D Triangle::getP2()const {
	return m_P2;
}

void Triangle::setP2(const Vecteur2D& P2) {
	if (!verifPoints(m_P1, P2, m_P3))
		throw("La modification sur P2 ne permet pas de former un triangle.");
	m_P2 = P2;
}

Vecteur2D Triangle::getP3()const {
	return m_P3;
}

void Triangle::setP3(const Vecteur2D& P3) {
	if (!verifPoints(m_P1, m_P2, P3)){}
		throw("La modification sur P3 ne permet pas de former un triangle.");
	m_P3 = P3;
}

Triangle::operator string() const {
	ostringstream oss;
	oss << "Triangle:" << Forme::operator string() << ";" << m_P1 << ";" << m_P2 << ";" << m_P3;
	return oss.str();
}
bool Triangle::operator==(const Triangle &obj) const {
	return (getCouleur() == obj.getCouleur()) && (m_P1 == obj.m_P1) && (m_P2 == obj.m_P2) && (m_P3 == obj.m_P3);
}
bool Triangle::operator!= (const Triangle &obj) const {
	return !(*this == obj);
}
const Triangle & Triangle::operator = (const Triangle& obj) {
	if (this != &obj)
	{
		Forme::operator=(obj);
		m_P1 = obj.m_P1;
		m_P2 = obj.m_P2;
		m_P3 = obj.m_P3;
	}
	return *this;
}

//Fonctions à implémenter depuis Forme
const double Triangle::getAire() const {
	double somme = m_P1.determinant(m_P2);
	somme += m_P2.determinant(m_P3);
	somme += m_P3.determinant(m_P1);
	return 0.5* fabs(somme);
}

Forme * Triangle::clone() const {
	return new Triangle(*this);
}

void Triangle::homothetie(const  Vecteur2D & vectHomotethie, double k) {
	m_P1.homothetie(vectHomotethie, k);
	m_P2.homothetie(vectHomotethie, k);
	m_P3.homothetie(vectHomotethie, k);
}

void Triangle::translation(const Vecteur2D & vectTranslation) {
	m_P1.translation(vectTranslation);
	m_P2.translation(vectTranslation);
	m_P3.translation(vectTranslation);
}

void Triangle::rotation(const  Vecteur2D & vectCentre, double angle) {
	m_P1.rotation(vectCentre, angle);
	m_P2.rotation(vectCentre, angle);
	m_P3.rotation(vectCentre, angle);
}

ostream & Triangle::print(ostream & flux) const {
	return flux << (string)(*this);
}

void Triangle::accepteSauvegarder(VisiteurSauvTXT *v)const {
	v->visite(this);
}