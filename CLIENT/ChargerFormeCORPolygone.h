#pragma once
#include "ChargerFormeCOR.h"

class ChargerFormeCORPolygone : public ChargerFormeCOR {
public:
	ChargerFormeCORPolygone(ChargerFormeCOR * suivant);
	const string getTypeForme()const;
	Forme* traiterDemande(const string & infoForme)const;
};