#pragma once
#include "Forme.h"
using namespace std;
class Cercle : public Forme {
	Vecteur2D m_centre;
	double m_rayon;
	//pas de Constructeur par défaut, donc en privé
	Cercle(){}
public:

	Cercle(const Vecteur2D& centre, double rayon, const Couleur & coul = Couleur());
	Cercle(const Cercle& obj);
	~Cercle();

	Vecteur2D getCentre() const;
	void setCentre(const Vecteur2D& centre);
	double getRayon()const;
	void setRayon(double rayon);

	operator string() const;
	bool operator==(const Cercle &objet) const;
	bool operator!= (const Cercle &objet) const;
	const Cercle & operator = (const Cercle& obj);

	//Fonctions à implémentées depuis Forme
	const double getAire() const;
	Forme * clone() const;
	void homothetie(const  Vecteur2D & vectHomotethie, double k);
	void translation(const Vecteur2D & vectTranslation);
	void rotation(const  Vecteur2D & vectCentre, double angle);
	ostream& print(ostream & flux) const;


};