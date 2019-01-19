/**
* \file VisiteurSauvTXT.h
* \brief Classe qui hérite de Visiteur qui va enregistrer les informations d'une forme dans un fichier
*/

#pragma once
#include "Visiteur.h"

using namespace std;

/*
	le format de l'info d'une forme simple:
		identifiant-Typeforme:Couleur;donnée2;données3;...;

	le format de l'info d'un groupe:
		identifiant-Groupe:Couleur;-Typeforme1:Couleur;...;&-Typeforme2:Couleur;...;&...&TypeformeN:Couleur;...;&
*/
class VisiteurSauvTXT : public Visiteur {

	static const string m_chemin;

	/**
	* \brief Crée un identifiant unique pour une forme au moment de la sauvegarde
	* \return string L'identifiant de la forme
	*/
	string creerId()const;

	/**
	* \brief Teste si un identifiant existe
	* \param id Identifiant à vérifier
	*/
	bool idExiste(const string& id)const;

	/**
	* \brief Teste si un identifiant est valide, c'est-à-dire qu'il ne contient pas certains caractères ("-", ";", "&", ":")
	* \param id Identifiant à vérifier
	*/
	bool idValide(const string& id)const;
 
	/**
	* \brief Ecriture d'une ligne dans un fichier
	* \param ligne Chaine de caractère à écrire dans le fichier
	* \param chemin Chemin du fichier dans lequel on veut écrire la ligne
	*/
	void sauvegarde(const string& ligne, const string& chemin = m_chemin)const;
public:

	/**
	* \brief Sauvegarde un segment dans un fichier
	* \param s Pointeur sur le segment à sauvegarder
	*/
	virtual void visite(const Segment* s) const;

	/**
	* \brief Sauvegarde un cercle dans un fichier
	* \param s Pointeur sur le cercle à sauvegarder
	*/
	virtual void visite(const Cercle* c) const;

	/**
	* \brief Sauvegarde un triangle dans un fichier
	* \param s Pointeur sur le triangle à sauvegarder
	*/
	virtual void visite(const Triangle* t) const;

	/**
	* \brief Sauvegarde un polygone dans un fichier
	* \param s Pointeur sur le polygone à sauvegarder
	*/
	virtual void visite(const Polygone* p) const;

	/**
	* \brief Sauvegarde un groupe dans un fichier
	* \param s Pointeur sur le groupe à sauvegarder
	*/
	virtual void visite(const Groupe* g) const;
};