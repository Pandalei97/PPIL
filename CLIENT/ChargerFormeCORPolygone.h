#pragma once
#include "ChargerFormeCOR.h"

class ChargerFormeCORPolygone : ChargerFormeCOR {
	const string getTypeForme()const;
	Forme* traiterDemande(const string & infoForme)const;
};