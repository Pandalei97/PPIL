#pragma once
#include "ChargerFormeCOR.h"

class ChargerFormeCORCercle : ChargerFormeCOR {
	const string getTypeForme()const;
	Forme* traiterDemande(const string & infoForme)const;
};