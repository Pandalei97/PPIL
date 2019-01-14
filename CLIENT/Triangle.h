#pragma once
#include "Forme.h"
using namespace std;

class Triangle :public Forme {
	Vecteur2D m_P1, m_P2, m_P3;
	//Pas de constructeur par défaut, donc en privée
	Triangle() {}
public:

	Triangle(const Vecteur2D & P1, const Vecteur2D & P2, const Vecteur2D& P3,const Couleur & coul = Couleur());
	Triangle(const Triangle & Triangle);
	~Triangle();

	bool verifPoints(const Vecteur2D & P1, const Vecteur2D & P2, const Vecteur2D& P3);
	Vecteur2D getP1()const;
	void setP1(const Vecteur2D& P1);
	Vecteur2D getP2()const;
	void setP2(const Vecteur2D& P2);
	Vecteur2D getP3()const;
	void setP3(const Vecteur2D& P3);

	operator string() const;
	bool operator==(const Triangle &objet) const;
	bool operator!= (const Triangle &objet) const;
	const Triangle & operator = (const Triangle&obj);

	//Fonctions à implémentées depuis Forme
	const double getAire() const;
	Forme * clone() const;
	void homothetie(const  Vecteur2D & vectHomotethie, double k);
	void translation(const Vecteur2D & vectTranslation);
	void rotation(const  Vecteur2D & vectCentre, double angle);
	ostream & print(ostream & flux) const;

};
