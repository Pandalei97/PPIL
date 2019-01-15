#pragma once
#include <iostream>
#include "Visiteur.h"
#include "Forme.h"

using namespace std;

class VisiteurSauvTXT : public Visiteur {

	static const string m_chemin;
	//On distribue un identifiant � la forme au moment du sauvgarde pour faciliter le chargement de la forme
	//Pour cela, l'identifiant doit �tre unique;
	bool idExiste(const string& id)const;

	//l'identifiant ne doit pas contenir certains caract�res sp�ciaux (les s�parateurs pour distinguer les chanmps) 
	bool idValide(const string& id)const;
public:

	virtual void visite(const Segment* s) const;
	virtual void visite(const Cercle* c) const;
	virtual void visite(const Triangle* t) const;
	virtual void visite(const Polygone* s) const;
	virtual void visite(const Groupe* g) const;
};