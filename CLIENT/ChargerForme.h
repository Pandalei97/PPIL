#pragma once
#include "Forme.h"
using namespace std;

class ChargerForme {
public:
	//Passer l'identifiant (info est en option) de la forme � un expert, s'il ne sait pas r�soudre, on le passe � l'expert suivant
	virtual Forme* charger(const string & idForme, const string &info = "")const = 0;
};
