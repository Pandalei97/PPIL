#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include <vector>
#include "Constantes.h"
#include "Couleur.h"
#include "Exception.h"
#include "Vecteur2D.h"


using namespace std;

class Forme {
	Couleur m_couleur;
	bool m_marquee; //On marque les formes qui appartiennent déjà à un groupe
public:
	Forme();
	Forme(const Couleur & couleur);
	Forme(const Forme* forme);
	virtual ~Forme();

	Couleur getCouleur()const;
	void setCouleur(const string & couleur);
	bool estMarquee();
	void setMarquee(bool marquee);

	virtual operator string() const;
	virtual bool operator==(const  Forme &objet) const;
	virtual bool operator != (const Forme &objet) const;
	virtual const Forme* operator = (const Forme&);

	
	virtual const double getAire() const = 0;
	virtual Forme * clone() const = 0;
	virtual void homothetie(const  Vecteur2D & vectHomotethie, double k) = 0;
	virtual void translation(const Vecteur2D & vectTranslation) = 0;
	virtual void rotation(const  Vecteur2D & vectCentre, double angle) = 0;

	virtual ostream & print(ostream & flux) const;
	friend ostream & operator << (ostream & flux, const Forme& forme);
};