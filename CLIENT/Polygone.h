#pragma once
#include "Forme.h"
#include <vector>
using namespace std;
class Polygone :public Forme {
	vector<Vecteur2D> m_tabPoints;
	//Un polygone doit être initialisé avec au moins 3 points
	Polygone(){}
public:
	Polygone(const Vecteur2D & P1, const Vecteur2D & P2, const Vecteur2D& P3, const Couleur & coul = Couleur());
	Polygone(const Polygone & Polygone);
	~Polygone();

	bool verifPoints(vector<Vecteur2D>& tabPoints);

	operator string() const;
	bool operator==(const Polygone &objet) const;
	bool operator!= (const Polygone &objet) const;
	const Polygone & operator = (const Polygone&obj);
	const Vecteur2D & operator[] (int indice)const;
	Polygone operator + (const Vecteur2D & v)const;
	void supprimer(int indice);

	//Fonctions à implémentées depuis Forme
	const double getAire() const;
	Forme * clone() const;
	void homothetie(const  Vecteur2D & vectHomotethie, double k);
	void translation(const Vecteur2D & vectTranslation);
	void rotation(const  Vecteur2D & vectCentre, double angle);
	ostream & print(ostream & flux) const;
};