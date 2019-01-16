#pragma once
#include "ChargerFormeCOR.h"

class ChargerFormeCORSegment : ChargerFormeCOR {
	const string getTypeForme()const;
	Forme* traiterDemande(const string & infoForme)const;
};