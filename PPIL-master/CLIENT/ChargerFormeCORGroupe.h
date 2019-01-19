#pragma once
#include "ChargerFormeCOR.h"

class ChargerFormeCORGroupe : public ChargerFormeCOR {
public:

	/**
	* \brief Constructeur à partir d'un pointeur sur l'expert suivant
	* \param suivant Pointeur sur l'expert suivant
	*/
	ChargerFormeCORGroupe(ChargerFormeCOR * suivant);

	/**
	* \brief Retourne le type de la forme que l'expert peut traiter (ici un groupe)
	* \return string Type de la forme 
	*/
	const string getTypeForme()const;

	/**
	* \brief Extrait les données d'une forme à partir d'une chaine de caractères
	* \param infoForme Chaine de caractères correspondant aux données de la forme
	* \return Forme* Un pointeur sur la forme 
	*/
	Forme* traiterDemande(const string & infoForme)const;

	/**
	* \brief Récupère une forme d'un groupe. La forme est ensuite supprimée du groupe pour par la suite accéder aux autre formes de ce même groupe
	* \param copier Chaine de caractère correspondant au groupe
	* \return string Chaine de caractère correspondant à la forme extraite
	*/
	string getComposant(string& copie)const;
};