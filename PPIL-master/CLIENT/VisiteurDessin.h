/**
* \file VisiteurDessin.h
* \brief Classe qui hérite de Visiteur qui va envoyer une requête au serveur en fonction de la forme à dessiner
*/

#pragma once
#include "Visiteur.h"
#include "Constantes.h"
class VisiteurDessin : public Visiteur {
	/**
	* \brief Demande à l'utilisateur les informations concernant la création de la fenêtre
	* \param titreFenetre Nom à donner à la fenêtre
	* \param largeur Largeur de la fenêtre (entier)
	* \param hauteur Hauteur de la fenêtre (entier)
	*/
	void InitInfoFenetre(string &titreFenetre, int &largeur, int &hauteur)const;

	/**
	* \brief Structure une requête pour la création de la fenêtre par le serveur
	* \param titreFenetre Nom de la fenêtre
	* \param largeur Largeur de la fenêtre (par défaut la constante LARGEUR est appelée)
	* \param hauteur Hauteur de la fenêtre (par défaut la constante HAUTEUR est appelée)
	*/
	const string RequeteOuvertureFenetre(const string& titreFenetre, const int largeur = LARGEUR, const int hauteur = HAUTEUR)const;

	/**
	* \brief Envoie une requête de dessin d'une forme vers le serveur
	* \param infoForme Données concernant la forme à dessiner
	* \param estMarquee Booléen qui informe si la forme est dans un groupe (true) ou pas (false)
	*/
	void demandeDessiner(const string& infoForme,bool estMarquee)const;

	/**
	* \brief Envoie une requête de création de la fenêtre vers le serveur
	*/
	void ouvrirFenetre()const;

public:

	/**
	* \brief Initialise une connexion vers le serveur, dessine un segment puis ferme la connexion
	* \param s Pointeur sur le segment à dessiner
	*/
	virtual void visite(const Segment* s) const;

	/**
	* \brief Initialise une connexion vers le serveur, dessine un cercle puis ferme la connexion
	* \param s Pointeur sur le cercle à dessiner
	*/
	virtual void visite(const Cercle* c) const;

	/**
	* \brief Initialise une connexion vers le serveur, dessine un triangle puis ferme la connexion
	* \param s Pointeur sur le triangle à dessiner
	*/
	virtual void visite(const Triangle* t) const;

	/**
	* \brief Initialise une connexion vers le serveur, dessine un polygone puis ferme la connexion
	* \param s Pointeur sur le polygone à dessiner
	*/
	virtual void visite(const Polygone* p) const;

	/**
	* \brief Initialise une connexion vers le serveur, dessine un groupe puis ferme la connexion
	* \param s Pointeur sur le groupe à dessiner
	*/
	virtual void visite(const Groupe* g) const;
};