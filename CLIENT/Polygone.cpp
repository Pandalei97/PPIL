#include "Polygone.h"
#include "VisiteurSauvTXT.h"
#include <set>
Polygone::Polygone(const Vecteur2D & P1, const Vecteur2D & P2, const Vecteur2D& P3, const Couleur & coul) :Forme(coul){
	m_tabPoints.clear();
	m_tabPoints.push_back(P1);
	m_tabPoints.push_back(P2);
	m_tabPoints.push_back(P3);
	if (!verifPoints(m_tabPoints))
		throw Exception("Tous les points ne sont pas valides!");
}
Polygone::Polygone(const Polygone & obj) : Forme(obj.getCouleur()){
	//Vider le tableau avant de faire l'affectation
	m_tabPoints.clear();
	for (int i = 0; i < obj.m_tabPoints.size(); i++)
		m_tabPoints.push_back(obj.m_tabPoints[i]);
}
Polygone::~Polygone(){}

int Polygone::getNbPoints() const {
	return m_tabPoints.size();
}

bool Polygone::verifPoints(vector<Vecteur2D>& tabPoints) {
	//Vérifier s'il existe des doublons
	for (int i = 0; i < tabPoints.size() - 1; i++) {
		for (int j = i + 1; j < tabPoints.size(); j++) {
			if (tabPoints[i] == tabPoints[j])
				return false;
		}
			
	}
	
	//Vérifier s'il existe des points alignés
	double pentePrec = fabs((tabPoints[tabPoints.size() - 1].getY() - tabPoints[0].getY()) / (tabPoints[tabPoints.size() - 1].getX() - tabPoints[0].getX()));
	double penteSuiv;
	for (int i = 0; i < tabPoints.size() - 1; i++)
	{
		penteSuiv = fabs((tabPoints[i + 1].getY() - tabPoints[i].getY()) / (tabPoints[i + 1].getX() - tabPoints[i].getX()));
		if (pentePrec == penteSuiv)
			return false;
		pentePrec = penteSuiv;
	}
	return true;
}

Polygone::operator string() const {
	ostringstream oss;
	oss << "Polygone:" << Forme::operator string();
	for (int i = 0; i < m_tabPoints.size(); i++)
		oss << ";" << (string)m_tabPoints[i];

	return oss.str();
}
bool Polygone::operator==(const Polygone &obj) const {
	if (m_tabPoints.size() != obj.m_tabPoints.size() || (getCouleur() != obj.getCouleur()))
		return false;
	for (int i = 0; i < m_tabPoints.size(); i++)
		if (m_tabPoints[i] != obj.m_tabPoints[i])
			return false;
	return true;
}
bool Polygone::operator!= (const Polygone &obj) const {
	return !(*this == obj);
}
const Polygone & Polygone::operator = (const Polygone& obj) {
	if (this != &obj)
	{
		Forme::operator=(obj);
		m_tabPoints.clear();
		for (int i = 0; i < obj.m_tabPoints.size(); i++)
			m_tabPoints.push_back(obj.m_tabPoints[i]);
	}
	return *this;
}

const Vecteur2D & Polygone::operator[] (int indice)const{
	if (indice < 0 || indice >= m_tabPoints.size())
		throw Exception("Indice incorrecte !");
	return m_tabPoints[indice];
}

Polygone Polygone::operator + (const Vecteur2D & point)const{
	Polygone poly(*this);
	poly.m_tabPoints.push_back(point);
	if (!poly.verifPoints(poly.m_tabPoints)) {
		poly.m_tabPoints.pop_back();
		throw Exception("Ce point exixste déjà! Insertion n'est pas faite.");
	}

	return poly;
}

void Polygone::supprimer(int indice)
{
	if (indice < 0 || indice >= m_tabPoints.size())
		throw Exception("Indice incorrecte !");
	m_tabPoints.erase(m_tabPoints.begin() + indice);
}

//Fonctions à implémenter depuis Forme
const double Polygone::getAire() const {
	//S = 1/2 *(Somme(xi*yi+1 - xi+1*yi)) <-- déterminant
	double somme = m_tabPoints[m_tabPoints.size() - 1].determinant(m_tabPoints[0]);
	for (int i = 0; i < m_tabPoints.size() - 1; i++)
		somme += m_tabPoints[i].determinant(m_tabPoints[i + 1]);
	return 0.5 * fabs(somme);
	
}

Forme * Polygone::clone() const{
	return new Polygone(*this);
}
void Polygone::homothetie(const  Vecteur2D & vectHomotethie, double k) {
	for (int i = 0; i < m_tabPoints.size(); i++)
		m_tabPoints[i].homothetie(vectHomotethie, k);
}
void Polygone::translation(const Vecteur2D & vectTranslation) {
	for (int i = 0; i < m_tabPoints.size(); i++)
		m_tabPoints[i].translation(vectTranslation);
}
void Polygone::rotation(const  Vecteur2D & vectCentre, double angle) {
	for (int i = 0; i < m_tabPoints.size(); i++)
		m_tabPoints[i].rotation(vectCentre, angle);
}
ostream & Polygone::print(ostream & flux) const {
	return flux << (string)(*this);
}

void Polygone::accepteSauvegarder(const VisiteurSauvTXT *v)const {
	v->visite(this);
}