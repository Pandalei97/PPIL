#pragma once
#include "ChargerFormeCOR.h"

class ChargerFormeCORTriangle : ChargerFormeCOR {
	const string getTypeForme()const;
	Forme* traiterDemande(const string & infoForme)const;
};