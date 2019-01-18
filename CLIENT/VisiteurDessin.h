#pragma once
#include "Visiteur.h"
#include "Constantes.h"
class VisiteurDessin : public Visiteur {
	void InitInfoFenetre(string &titreFenetre, int &largeur, int &hauteur)const;
	const string RequeteOuvertureFenetre(const string& titreFenetre, const int laugeur = LARGEUR, const int hauteur = HAUTEUR)const;
	void demandeDessiner(const string& infoForme,bool estMarquee)const;
	void ouvrirFenetre()const;
public:
	virtual void visite(const Segment* s) const;
	virtual void visite(const Cercle* c) const;
	virtual void visite(const Triangle* t) const;
	virtual void visite(const Polygone* p) const;
	virtual void visite(const Groupe* g) const;
};