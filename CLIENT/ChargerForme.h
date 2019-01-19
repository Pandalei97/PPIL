

#pragma once
#include "Forme.h"
using namespace std;

class ChargerForme {
public:

	/**
	* \brief Méthode virtuelle pure qui va appeler un expert pour charger la forme, si l'expert ne sait pas résoudre le problème alors on passe à l'expert suivant
	*\ param idForme Chaine de cractère correspondant à l'identifiant de la forme à charger
	* \param info Chaine de caractère contenant les informations de la forme à charger (vide par défaut)
	* \return Forme* Pointeur sur la forme chargée
	*/
	virtual Forme* charger(const string & idForme, const string &info = "")const = 0;
};
