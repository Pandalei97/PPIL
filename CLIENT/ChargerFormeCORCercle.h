#pragma once
#include "ChargerFormeCOR.h"

class ChargerFormeCORCercle : public ChargerFormeCOR {
public:
	ChargerFormeCORCercle(ChargerFormeCOR * suivant);
	const string getTypeForme()const;
	Forme* traiterDemande(const string & infoForme)const;
};