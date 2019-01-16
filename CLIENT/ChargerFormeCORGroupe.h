#pragma once
#include "ChargerFormeCOR.h"

class ChargerFormeCORGroupe : ChargerFormeCOR {
	const string getTypeForme()const;
	Forme* traiterDemande(const string & infoForme)const;
};