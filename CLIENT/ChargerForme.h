#pragma once
#include "Forme.h"
using namespace std;

class ChargerForme {
public:
	//Passer l'identifiant de la forme à un expert, s'il ne sait pas résoudre, on le passe à l'expert suivant
	virtual Forme* charger(const string & idForme)const = 0;
};
