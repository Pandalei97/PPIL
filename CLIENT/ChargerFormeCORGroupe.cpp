#include "ChargerFormeCORGroupe.h"
#include "Groupe.h"
const string ChargerFormeCORGroupe::getTypeForme()const {
	return "Groupe";
}
Forme* ChargerFormeCORGroupe::traiterDemande(const string & donneeForme)const {
	//On crée une copie de donneeForme car donneeForme est en const mais on veut le modifier
	string copie = donneeForme;
	string couleur = copie.substr(0, copie.find(';'));
	vector<Forme*> tabForme;
	Forme* composant;
	string infoForme;
	while ((infoForme = copie.substr(0, copie.find('&'))) != "")
	{
		composant = charger("", infoForme);
		tabForme.push_back(composant);
		copie = copie.substr(0, copie.find('&')+1);
	}


	return new Polygone(p);
}