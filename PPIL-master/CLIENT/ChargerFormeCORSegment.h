#pragma once
#include "ChargerFormeCOR.h"

class ChargerFormeCORSegment : public ChargerFormeCOR {
public:

	/**
	* \brief Constructeur à partir d'un pointeur sur l'expert suivant
	* \param suivant Pointeur sur l'expert suivant
	*/
	ChargerFormeCORSegment(ChargerFormeCOR * suivant);

	/**
	* \brief Retourne le type de la forme que l'expert peut traiter (ici un segment)
	* \return string Type de la forme 
	*/
	const string getTypeForme()const;

	/**
	* \brief Extrait les données d'une forme à partir d'une chaine de caractères
	* \param infoForme Chaine de caractères correspondant aux données de la forme
	* \return Forme* Un pointeur sur la forme 
	*/
	Forme* traiterDemande(const string & infoForme)const;
};