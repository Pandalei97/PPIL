#include "ChargerFormeCORCercle.h"
#include "Cercle.h"

ChargerFormeCORCercle::ChargerFormeCORCercle(ChargerFormeCOR * suivant): ChargerFormeCOR(suivant){}

const string ChargerFormeCORCercle::getTypeForme()const {
	return "Cercle";
}
Forme* ChargerFormeCORCercle::traiterDemande(const string & donneeForme)const {
	//donneeForme sera sous forme: Couleur;Centre;rayon;

	//On crée une copie de donneeForme car donneeForme est en const mais on veut le modifier
	string copie = donneeForme;
	string couleur = copie.substr(0, copie.find(';'));
	//cout << "COULEUR = " << couleur << endl;
	
	//On prend le reste de la copie
	copie = copie.substr(copie.find(';') + 1);
	//cout << "INFO RESTE = " << copie << endl;
	Vecteur2D centre = stringToPoint(copie.substr(0, copie.find(';')));
	//cout << "CENTRE = " << centre << endl;
	//On prend le reste de la copie
	copie = copie.substr(copie.find(';') + 1);
	//cout << "INFO RESTE = " << copie << endl;
	double rayon = stod(copie.substr(0, copie.find(';')));
	//cout << "RAYON = " << rayon << endl;
	return new Cercle(centre, rayon, Couleur(couleur));
}