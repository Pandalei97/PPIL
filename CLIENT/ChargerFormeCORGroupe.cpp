#include "ChargerFormeCORGroupe.h"
#include "Groupe.h"
#include "COR.h"

ChargerFormeCORGroupe::ChargerFormeCORGroupe(ChargerFormeCOR * suivant): ChargerFormeCOR(suivant){}

const string ChargerFormeCORGroupe::getTypeForme()const {
	return "Groupe";
}

string ChargerFormeCORGroupe::getComposant(string& copie)const {
	string res;
	if (copie.substr(1, copie.find(':') - 1) != "Groupe") {
		// on doit pas garder le caractère '-' dans une donnee forme
		res = copie.substr(1, copie.find('&')- 1);
		//cout << "RES = " << res << endl;
		copie = copie.substr(copie.find('&') + 1);
		//cout << "COPIE RESTE:" << copie << endl;
		return res;
	}
	
	int pos = copie.find_last_of("&&");
	res = copie.substr(1, pos-1);
	copie = copie.substr(pos + 1);
	return res;




}
Forme* ChargerFormeCORGroupe::traiterDemande(const string & donneeForme)const {
	//On crée une copie de donneeForme car donneeForme est en const mais on veut le modifier
	string copie = donneeForme;
	//cout << "COPIE DONNEE FORME = " << copie << endl;
	string couleur = copie.substr(0, copie.find(';'));
	//cout << "COULEUR GROUPE = " << couleur << endl;
	copie = copie.substr(copie.find(';') + 1);
	//cout << "COPIE DONNEE FORME = " << copie << endl;
	Groupe g = Groupe(Couleur(couleur));
	Forme* composant;
	string infoForme;
	
	COR *cor = COR::getInstance();
	ChargerForme *chargeurForme = cor->getChargeurForme();
	
	while (copie != "")
	{	
		//getComposant(copie) va retourner un string d'une composante et modifier la copie 
		infoForme = getComposant(copie);
		//cout << "INFO COMPOSANTE = " << infoForme << endl;
		composant = chargeurForme->charger("", infoForme);
		g = g + composant;
	}
	return new Groupe(g);
}