/**
* \file VisiteurSauvTXT.h
* \brief Classe qui h�rite de Visiteur qui va enregistrer les informations d'une forme dans un fichier
*/

#pragma once
#include "Visiteur.h"

using namespace std;

/*
	le format de l'info d'une forme simple:
		identifiant-Typeforme:Couleur;donn�e2;donn�es3;...;

	le format de l'info d'un groupe:
		identifiant-Groupe:Couleur;-Typeforme1:Couleur;...;&-Typeforme2:Couleur;...;&...&TypeformeN:Couleur;...;&
*/
class VisiteurSauvTXT : public Visiteur {

	static const string m_chemin;

	/**
	* \brief Cr�e un identifiant unique pour une forme au moment de la sauvegarde
	* \return string L'identifiant de la forme
	*/
	string creerId()const;

	/**
	* \brief Teste si un identifiant existe
	* \param id Identifiant � v�rifier
	*/
	bool idExiste(const string& id)const;

	/**
	* \brief Teste si un identifiant est valide, c'est-�-dire qu'il ne contient pas certains caract�res ("-", ";", "&", ":")
	* \param id Identifiant � v�rifier
	*/
	bool idValide(const string& id)const;
 
	/**
	* \brief Ecriture d'une ligne dans un fichier
	* \param ligne Chaine de caract�re � �crire dans le fichier
	* \param chemin Chemin du fichier dans lequel on veut �crire la ligne
	*/
	void sauvegarde(const string& ligne, const string& chemin = m_chemin)const;
public:

	/**
	* \brief Sauvegarde un segment dans un fichier
	* \param s Pointeur sur le segment � sauvegarder
	*/
	virtual void visite(const Segment* s) const;

	/**
	* \brief Sauvegarde un cercle dans un fichier
	* \param s Pointeur sur le cercle � sauvegarder
	*/
	virtual void visite(const Cercle* c) const;

	/**
	* \brief Sauvegarde un triangle dans un fichier
	* \param s Pointeur sur le triangle � sauvegarder
	*/
	virtual void visite(const Triangle* t) const;

	/**
	* \brief Sauvegarde un polygone dans un fichier
	* \param s Pointeur sur le polygone � sauvegarder
	*/
	virtual void visite(const Polygone* p) const;

	/**
	* \brief Sauvegarde un groupe dans un fichier
	* \param s Pointeur sur le groupe � sauvegarder
	*/
	virtual void visite(const Groupe* g) const;
};