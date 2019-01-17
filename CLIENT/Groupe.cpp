#include "Groupe.h"
#include "VisiteurSauvTXT.h"
#include "VisiteurDessin.h"
Groupe::Groupe() :Forme(), m_tabFormes() {}
Groupe::Groupe(const Couleur &coul):Forme(coul), m_tabFormes(){}
Groupe::Groupe(const Groupe & groupe):Forme(groupe) {
	for (int i = 0; i < groupe.m_tabFormes.size(); i++) {
		m_tabFormes.push_back(groupe.m_tabFormes[i]->clone());
		m_tabFormes[i]->setCouleur(getCouleur());
		m_tabFormes[i]->setMarquee(true);
	}
		
}
Groupe::~Groupe() {}

int Groupe::getNbFormes() const {
	return m_tabFormes.size();
}

void Groupe::setCouleur(const string& couleur) {
	Forme::setCouleur(couleur);
	for (int i = 0; i < m_tabFormes.size(); i++) {
		m_tabFormes[i]->setCouleur(couleur);
	}
}
Groupe::operator string() const
{
	ostringstream oss;
	oss << "Groupe:" << Forme::operator string();
	for (int i = 0; i < m_tabFormes.size(); ++i)
		oss << " & " << *m_tabFormes[i];
	return oss.str();
}
bool Groupe::operator==(const Groupe &obj) const {
	if (m_tabFormes.size() != obj.m_tabFormes.size() || (getCouleur() != obj.getCouleur()))
		return false;
	for (int i = 0; i < m_tabFormes.size(); i++)
		if (m_tabFormes[i] != obj.m_tabFormes[i])
			return false;
	return true;
}
bool Groupe::operator != (const Groupe &obj) const {
	return (*this) == obj;
}
const Groupe & Groupe::operator = (const Groupe &obj) {
	if (this != &obj)
	{
		Forme::operator=(obj);
		m_tabFormes.clear();
		for (size_t i = 0; i < obj.m_tabFormes.size(); i++)
			m_tabFormes.push_back(obj.m_tabFormes[i]);
	}
	return *this;
}
Forme * Groupe::operator[] (const int indice)const {
	if (indice < 0 || indice >= m_tabFormes.size())
		throw Exception("Indice incorrecte !");
	return m_tabFormes[indice];
}
Groupe Groupe::operator+ (Forme * f)const {
	if (f->estMarquee())
		throw Exception("La forme est deja marquee!");
	Groupe groupe(*this);
	//Marquer et changer la couleur de la forme
	f->setMarquee(true);
	f->setCouleur(getCouleur());
	groupe.m_tabFormes.push_back(f);
	return groupe;
}

void Groupe::supprimer(const int indice) {
	if (indice < 0 || indice >= m_tabFormes.size())
		throw Exception("Indice incorrecte !!!");
	m_tabFormes.erase(m_tabFormes.begin() + indice);
}

//Fonctions à implémentées depuis Forme
const double Groupe::getAire() const {
	double sommeAires = 0.0;
	for (size_t i = 0; i < m_tabFormes.size(); i++)
	{
		sommeAires += m_tabFormes[i]->getAire();
	}
	return sommeAires;
}
Forme * Groupe::clone() const {
	return new Groupe(*this);
}
void Groupe::homothetie(const  Vecteur2D & vectHomotethie, double k) {
	for (int i = 0; i < m_tabFormes.size(); i++)
		m_tabFormes[i]->homothetie(vectHomotethie, k);
}
void Groupe::translation(const Vecteur2D & vectTranslation) {
	for (int i = 0; i < m_tabFormes.size(); i++)
		m_tabFormes[i]->translation(vectTranslation);
}
void Groupe::rotation(const  Vecteur2D & vectCentre, double angle) {
	for (int i = 0; i < m_tabFormes.size(); i++)
		m_tabFormes[i]->rotation(vectCentre, angle);
}
ostream & Groupe::print(ostream & flux) const {
	return flux << (string)(*this);
}

void Groupe::accepteSauvegarder(const VisiteurSauvTXT *v)const {
	v->visite(this);
}

void Groupe::dessiner(const VisiteurDessin *v)const {
	v->visite(this);
}