#include "ChargerFormeCORSegment.h"
#include "Segment.h"

ChargerFormeCORSegment::ChargerFormeCORSegment(ChargerFormeCOR * suivant): ChargerFormeCOR(suivant){}

const string ChargerFormeCORSegment::getTypeForme()const {
	return "Segment";
}
Forme* ChargerFormeCORSegment::traiterDemande(const string & donneeForme)const {
	//donneeForme sera sous forme: Couleur;P1;P2;

	//On crée une copie de donneeForme car donneeForme est en const mais on veut le modifier
	string copie = donneeForme;
	string couleur = copie.substr(0, copie.find(';'));

	//On prend le reste de la copie
	copie = copie.substr(copie.find(';') + 1);
	Vecteur2D po = stringToPoint(copie.substr(0, copie.find(';')));

	//On prend le reste de la copie
	copie = copie.substr(copie.find(';') + 1);
	Vecteur2D pe = stringToPoint(copie.substr(0, copie.find(';')));
	return new Segment(po, pe, Couleur(couleur));
}