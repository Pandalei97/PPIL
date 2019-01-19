#include "ChargerFormeCORTriangle.h"
#include "Triangle.h"
ChargerFormeCORTriangle::ChargerFormeCORTriangle(ChargerFormeCOR * suivant): ChargerFormeCOR(suivant){}
const string ChargerFormeCORTriangle::getTypeForme()const {
	return "Triangle";
}
Forme* ChargerFormeCORTriangle::traiterDemande(const string & donneeForme)const {
	//On crée une copie de donneeForme car donneeForme est en const mais on veut le modifier
	string copie = donneeForme;
	string couleur = copie.substr(0, copie.find(';'));

	//On prend le reste de la copie
	copie = copie.substr(copie.find(';') + 1);
	Vecteur2D p1 = stringToPoint(copie.substr(0, copie.find(';')));

	//On prend le reste de la copie
	copie = copie.substr(copie.find(';') + 1);
	Vecteur2D p2 = stringToPoint(copie.substr(0, copie.find(';')));

	//On prend le reste de la copie
	copie = copie.substr(copie.find(';') + 1);
	Vecteur2D p3 = stringToPoint(copie.substr(0, copie.find(';')));
	return new Triangle(p1, p2, p3, Couleur(couleur));
}