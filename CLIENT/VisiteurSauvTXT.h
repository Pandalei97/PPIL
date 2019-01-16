#pragma once
#include "Visiteur.h"

using namespace std;

/*
	le format de l'info d'une forme simple:
		identifiant-Typeforme:Couleur;donnée2;données3;...;

	le format de l'info d'un groupe:
		identifiant-Groupe:Couleur;-Typeforme1:Couleur;...;&-Typeforme2:Couleur;...;&...&TypeformeN:Couleur;...;&
*/
class VisiteurSauvTXT : public Visiteur {

	static const string m_chemin;

	string creerId()const;
	//On distribue un identifiant à la forme au moment du sauvgarde pour faciliter le chargement de la forme
	//Pour cela, l'identifiant doit être unique;
	bool idExiste(const string& id)const;

	//l'identifiant ne doit pas contenir certains caractères spéciaux (les séparateurs pour distinguer les chanmps) 
	bool idValide(const string& id)const;

	//cette méthode va ecrire une ligne dans un fichier(sans ajouter 'endl' automatiquement) 
	void sauvegarde(const string& ligne, const string& chemin = m_chemin)const;
public:

	virtual void visite(const Segment* s) const;
	virtual void visite(const Cercle* c) const;
	virtual void visite(const Triangle* t) const;
	virtual void visite(const Polygone* p) const;
	virtual void visite(const Groupe* g) const;
};