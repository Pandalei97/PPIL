#pragma once
#include "ChargerForme.h"

//La classe abstraite qui factorise toutes les méthodes en communes des experts
class ChargerFormeCOR : public ChargerForme {
	ChargerFormeCOR *suivant;
protected:
	/*Les méthodes outils pour faciliter les traitements*/
	string getInfoForme(const string& idForme)const;
	//Ici on suppose que infoPoint est tjrs au bon format
	Vecteur2D stringToPoint(const string& infoPoint)const;

public:
	ChargerFormeCOR(ChargerFormeCOR* suivant);

	Forme* charger(const string & idForme, const string &info = "")const;

	


	/*Les méthodes à implémenter dans les sous classes*/

	//Retourner le type de forme que l'expert sait charger
	virtual const string getTypeForme()const = 0;
	//s'il sait traiter ce string, il va décomposer ce string et créer une forme correspondante
	virtual Forme* traiterDemande(const string & infoForme)const = 0;
};