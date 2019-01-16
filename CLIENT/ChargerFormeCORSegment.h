#pragma once
#include "ChargerFormeCOR.h"

class ChargerFormeCORSegment : public ChargerFormeCOR {
public:
	ChargerFormeCORSegment(ChargerFormeCOR * suivant);
	const string getTypeForme()const;
	Forme* traiterDemande(const string & infoForme)const;
};