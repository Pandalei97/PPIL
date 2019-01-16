#pragma once
#include "ChargerFormeCOR.h"

class ChargerFormeCORGroupe : public ChargerFormeCOR {
public:
	ChargerFormeCORGroupe(ChargerFormeCOR * suivant);
	const string getTypeForme()const;
	Forme* traiterDemande(const string & infoForme)const;
	//string& copie n'est pas un const car on veut le modifier
	string getComposant(string& copie)const;
};