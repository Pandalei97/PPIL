#pragma once
#include "ChargerFormeCORCercle.h"
#include "ChargerFormeCORGroupe.h"
#include "ChargerFormeCORPolygone.h"
#include "ChargerFormeCORSegment.h"
#include "ChargerFormeCORTriangle.h"

//La classe qui définit l'ordre des des chargeurs
class COR {
private:
	ChargerForme *chargeurForme;
	static COR* instance;
	
	/**
	* \brief Constructeur par défaut privé 
	*/
	COR();

	/**
	* \brief Destructeur privé
	*/
	~COR();

public:

	
	/**
	*	\brief méthode pour récupérer l'instance de la classe.
	*	\return COR * l'instance.
	*/
	static COR *getInstance();

	/**
	*	\brief méthode pour récupérer le chargeur forme.
	*	\return COR * l'instance.
	*/
	ChargerForme * getChargeurForme();
};