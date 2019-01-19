

#pragma once
#include "Forme.h"
using namespace std;

class ChargerForme {
public:

	/**
	* \brief M�thode virtuelle pure qui va appeler un expert pour charger la forme, si l'expert ne sait pas r�soudre le probl�me alors on passe � l'expert suivant
	*\ param idForme Chaine de cract�re correspondant � l'identifiant de la forme � charger
	* \param info Chaine de caract�re contenant les informations de la forme � charger (vide par d�faut)
	* \return Forme* Pointeur sur la forme charg�e
	*/
	virtual Forme* charger(const string & idForme, const string &info = "")const = 0;
};
