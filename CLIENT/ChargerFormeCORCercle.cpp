#include "ChargerFormeCORCercle.h"
#include "Cercle.h"
const string ChargerFormeCORCercle::getTypeForme()const {
	return "Cercle";
}
Forme* ChargerFormeCORCercle::traiterDemande(const string & donneeForme)const {
	//donneeForme sera sous forme: Couleur;Centre;rayon;

	//On crée une copie de donneeForme car donneeForme est en const mais on veut le modifier
	string copie = donneeForme;
	string couleur = copie.substr(0, copie.find(';'));
	
	//On prend le reste de la copie
	copie = copie.substr(copie.find(';') + 1);
	Vecteur2D centre = stringToPoint(copie.substr(0, copie.find(';')));
	
	//On prend le reste de la copie
	copie = copie.substr(copie.find(';') + 1);
	double rayon = stod(copie.substr(0, copie.find(';')));
	return new Cercle(centre, rayon, couleur);
}