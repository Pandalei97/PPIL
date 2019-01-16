#pragma once
#include "ChargerFormeCOR.h"

class ChargerFormeCORTriangle : public ChargerFormeCOR {
public:
	ChargerFormeCORTriangle(ChargerFormeCOR * suivant);
	const string getTypeForme()const;
	Forme* traiterDemande(const string & infoForme)const;
};