#include "ChargerFormeCORPolygone.h"
#include "Polygone.h"

ChargerFormeCORPolygone::ChargerFormeCORPolygone(ChargerFormeCOR * suivant): ChargerFormeCOR(suivant){}
const string ChargerFormeCORPolygone::getTypeForme()const {
	return "Polygone";
}
Forme* ChargerFormeCORPolygone::traiterDemande(const string & donneeForme)const {
	//On crée une copie de donneeForme car donneeForme est en const mais on veut le modifier
	string copie = donneeForme;
	string couleur = copie.substr(0, copie.find(';'));
	vector<Vecteur2D> tabPoints;
	Vecteur2D point;
	while ((copie = copie.substr(copie.find(';') + 1)) != "")
	{
		point = stringToPoint(copie.substr(0, copie.find(';')));
		tabPoints.push_back(point);
	}
	
	Polygone p = Polygone(tabPoints[0], tabPoints[1], tabPoints[2], Couleur(couleur));
	for (int i = 3; i < tabPoints.size(); i++)
		p = p + tabPoints[i];

	return new Polygone(p);
}