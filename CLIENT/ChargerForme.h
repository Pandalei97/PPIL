#pragma once
#include "Forme.h"
using namespace std;

class ChargerForme {
public:
	//Passer l'info de la forme � un expert, s'il ne sait pas r�soudre, on le passe � l'expert suivant
	virtual Forme* charger(const string & infoForme)const = 0;
};
