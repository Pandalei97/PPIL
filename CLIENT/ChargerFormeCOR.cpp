#include "ChargerFormeCOR.h"

ChargerFormeCOR::ChargerFormeCOR(ChargerFormeCOR * s):suivant(s){}

Forme* ChargerFormeCOR::charger(const string & infoForme)const {
	string typeForme = infoForme.substr(0, infoForme.find('-'));
	if (typeForme == getTypeForme()){
		string donneesForme = infoForme.substr(infoForme.find('#') + 1);
		return traiterDemande(donneesForme);
	}
	//cet expert ne peut pas résoudre le problème, on le passe au suivant si le suivant n'est pas NULL;
	if (suivant == NULL)
		return NULL;

	return suivant->charger(infoForme);
}