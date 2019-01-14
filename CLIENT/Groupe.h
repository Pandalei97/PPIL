#pragma once
#include "Forme.h"
#include <vector>

class Groupe :public Forme {
	vector<Forme *> m_tabFormes;
public:
	Groupe();
	Groupe(const Couleur &coul);
	Groupe(const Groupe & groupe);
	~Groupe();

	int getNbFormes() const;
	void setCouleur(const string& couleur);
	operator string() const;
	bool operator==(const  Groupe &obj) const;
	bool operator != (const Groupe &obj) const;
	const Groupe & operator = (const Groupe &obj);
	Forme * operator[] (const int indice)const;
	Groupe operator + (Forme * f)const;
	void supprimer(const int indice);

	//Fonctions à implémentées depuis Forme
	const double getAire() const;
	Forme * clone() const;
	void homothetie(const  Vecteur2D & vectHomotethie, double k);
	void translation(const Vecteur2D & vectTranslation);
	void rotation(const  Vecteur2D & vectCentre, double angle);
	ostream & print(ostream & flux) const;
};