#pragma once
#include "ChargerForme.h"

//La classe abstraite qui factorise toutes les méthodes en communes des experts
class ChargerFormeCOR : public ChargerForme {
	ChargerFormeCOR *suivant;
protected:
	
	/**
	* \brief Récupère les informations d'une forme en fonction de son identifiant
	* \param idForme Identifiant de la forme
	* \return string Informations de la forme
	*/
	string getInfoForme(const string& idForme)const;

	/**
	* \brief Convertion d'une chaine de caractères correspondant à un point en un Vecteur2D
	* \return Vecteur2D Point converti depuis une chaine de caractères
	*/
	Vecteur2D stringToPoint(const string& infoPoint)const;

public:

	/**
	* \brief Constructeur à partir d'un pointeur sur l'expert suivant
	* \param suivant Pointeur sur l'expert suivant
	*/
	ChargerFormeCOR(ChargerFormeCOR* suivant);

	/**
	* \brief Appelle un expert pour charger la forme, si l'expert ne sait pas résoudre le problème alors on passe à l'expert suivant
	*\ param idForme Chaine de cractère correspondant à l'identifiant de la forme à charger
	* \param info Chaine de caractère contenant les informations de la forme à charger (vide par défaut)
	* \return Forme* Pointeur sur la forme chargée
	*/
	Forme* charger(const string & idForme, const string &info = "")const;

	

	/**
	* \brief Méthode virtuelle pure qui retourne le type de la forme
	* \return string Type de la forme 
	*/
	virtual const string getTypeForme()const = 0;

	/**
	* \brief Méthode virtuelle pure. Extrait les données d'une forme à partir d'une chaine de caractères
	* \param infoForme Chaine de caractères correspondant aux données de la forme
	* \return Forme* Un pointeur sur la forme 
	*/
	virtual Forme* traiterDemande(const string & infoForme)const = 0;
};