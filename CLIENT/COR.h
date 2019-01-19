#pragma once
#include "ChargerFormeCORCercle.h"
#include "ChargerFormeCORGroupe.h"
#include "ChargerFormeCORPolygone.h"
#include "ChargerFormeCORSegment.h"
#include "ChargerFormeCORTriangle.h"

//La classe qui d�finit l'ordre des des chargeurs
class COR {
private:
	ChargerForme *chargeurForme;
	static COR* instance;
	
	/**
	* \brief Constructeur par d�faut priv� 
	*/
	COR();

	/**
	* \brief Destructeur priv�
	*/
	~COR();

public:

	
	/**
	*	\brief m�thode pour r�cup�rer l'instance de la classe.
	*	\return COR * l'instance.
	*/
	static COR *getInstance();

	/**
	*	\brief m�thode pour r�cup�rer le chargeur forme.
	*	\return COR * l'instance.
	*/
	ChargerForme * getChargeurForme();
};