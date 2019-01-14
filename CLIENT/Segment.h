#pragma once
#include "Forme.h"
using namespace std;
class Segment :public Forme {
	Vecteur2D m_PO, m_PE; //point d'origine et point d'extrémité
	//Pas de constructeur par défaut, donc en privée
	Segment(){}
public:
	
	Segment(const Vecteur2D & PO, const Vecteur2D & PE, const Couleur & coul = Couleur());
	Segment(const Segment & segment);
	~Segment();

	Vecteur2D getPO()const;
	void setPO(const Vecteur2D& PO);
	Vecteur2D getPE()const;
	void setPE(const Vecteur2D& PE);

	operator string() const;
	bool operator==(const Segment &objet) const;
	bool operator!= (const Segment &objet) const;
	const Segment & operator = (const Segment&obj);

	//Fonctions à implémentées depuis Forme
	const double getAire() const;
	Forme * clone() const;
	void homothetie(const  Vecteur2D & vectHomotethie, double k);
	void translation(const Vecteur2D & vectTranslation);
	void rotation(const  Vecteur2D & vectCentre, double angle);
	ostream & print(ostream & flux) const;

};
