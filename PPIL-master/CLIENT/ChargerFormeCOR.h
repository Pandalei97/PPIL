#pragma once
#include "ChargerForme.h"

//La classe abstraite qui factorise toutes les m�thodes en communes des experts
class ChargerFormeCOR : public ChargerForme {
	ChargerFormeCOR *suivant;
protected:
	
	/**
	* \brief R�cup�re les informations d'une forme en fonction de son identifiant
	* \param idForme Identifiant de la forme
	* \return string Informations de la forme
	*/
	string getInfoForme(const string& idForme)const;

	/**
	* \brief Convertion d'une chaine de caract�res correspondant � un point en un Vecteur2D
	* \return Vecteur2D Point converti depuis une chaine de caract�res
	*/
	Vecteur2D stringToPoint(const string& infoPoint)const;

public:

	/**
	* \brief Constructeur � partir d'un pointeur sur l'expert suivant
	* \param suivant Pointeur sur l'expert suivant
	*/
	ChargerFormeCOR(ChargerFormeCOR* suivant);

	/**
	* \brief Appelle un expert pour charger la forme, si l'expert ne sait pas r�soudre le probl�me alors on passe � l'expert suivant
	*\ param idForme Chaine de cract�re correspondant � l'identifiant de la forme � charger
	* \param info Chaine de caract�re contenant les informations de la forme � charger (vide par d�faut)
	* \return Forme* Pointeur sur la forme charg�e
	*/
	Forme* charger(const string & idForme, const string &info = "")const;

	

	/**
	* \brief M�thode virtuelle pure qui retourne le type de la forme
	* \return string Type de la forme 
	*/
	virtual const string getTypeForme()const = 0;

	/**
	* \brief M�thode virtuelle pure. Extrait les donn�es d'une forme � partir d'une chaine de caract�res
	* \param infoForme Chaine de caract�res correspondant aux donn�es de la forme
	* \return Forme* Un pointeur sur la forme 
	*/
	virtual Forme* traiterDemande(const string & infoForme)const = 0;
};