#pragma once
#include "ChargerForme.h"

class ChargerFormeCOR : public ChargerForme {
	ChargerFormeCOR *suivant;

public:
	ChargerFormeCOR(ChargerFormeCOR* suivant);

	Forme* charger(const string & infoForme)const;
	//Retourner le type de forme que l'expert sait charger
	virtual const string getTypeForme()const = 0;
	virtual Forme* traiterDemande(const string & infoForme)const = 0;
};