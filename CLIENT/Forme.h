/**
* \file Forme.h
* \brief Classe forme qui représente une forme
*/
#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include <vector>
#include "Constantes.h"
#include "Couleur.h"
#include "Exception.h"
#include "Vecteur2D.h"
class VisiteurSauvTXT;


using namespace std;

class Forme {
	Couleur m_couleur;
	bool m_marquee; //On marque les formes qui appartiennent déjà à un groupe
public:

	/**
	* \brief Constructeur par défaut de Forme
	*/
	Forme();

	/**
	* \brief Constructeur à partir d'une couleur
	* \param couleur Une couleur à appliquer à la forme
	*/
	Forme(const Couleur & couleur);

	/**
	* \brief Constructeur de recopie à partir d'un pointeur de Forme
	* \details Les coordonnées x et y sont par défaut mis à 0.
	* \param x Réel
	* \param y Réel
	*/
	Forme(const Forme* forme);

	/**
	* \brief Destructeur virtual qui sera appelé pour tous les héritiers de Forme
	*/
	virtual ~Forme();

	/**
	* \brief Getter pour récupérer la couleur d'une forme
	* \return Couleur La couleur de la forme
	*/
	Couleur getCouleur()const;

	/**
	* \brief Setter pour modifier la couleur de la forme
	* \param couleur Chaine de caractère correspondant à la couleur
	*/
	virtual void setCouleur(const string & couleur);

	/**
	* \brief Getter pour savoir si une forme fait parti d'un groupe
	* \return bool un booléen vrai si la forme est dans un groupe, faux sinon
	*/
	bool estMarquee()const;

	/**
	* \brief Setter qui permet de marquer une forme si elle fait parti d'un groupe
	* \param marquee Marquer la forme par vrai ou faux
	*/
	void setMarquee(bool marquee);


	/**
	* \brief Surcharge de l'opérateur string permettant de convertir des formes en string 
	*/
	virtual operator string() const;

	/**
	* \brief Surcharge de l'opérateur == qui teste si deux formes sont identiques
	* \param objet La forme à comparer
	* \return bool Un booléen vrai si les deux formes sont identiques, faux sinon
	*/
	virtual bool operator==(const Forme &objet) const;

	/**
	* \brief Surcharge de l'opérateur != qui utilise ==
	* \details Teste si deux formes sont différentes
	* \param objet La forme à comparer
	* \return bool Un booléen vrai si les deux formes sont différentes, faux sinon
	*/
	virtual bool operator != (const Forme &objet) const;

	/**
	* \brief Surcharge de l'opérateur = qui permet d'affcter une forme à une autre
	* \param forme La forme à affecter
	* \return Forme* Un pointeur sur Forme
	*/
	virtual const Forme* operator = (const Forme& forme);

	/**
	* \brief Getter recupère l'aire de la forme propre à chaque forme (méthode virtuelle pure)
	* \return L'aire de la forme
	*/
	virtual const double getAire() const = 0;

	/**
	* \brief Clone une forme (méthode virtuelle pure)
	* \return Forme* Un pointeur sur l'objet cloné
	*/
	virtual Forme * clone() const = 0;

	/**
	* \brief Effectue une homotéthie sur la forme (Méthode vitruelle pure)
	* \param vectHomotethie Vecteur2D
	* \param k Réel
	*/
	virtual void homothetie(const  Vecteur2D & vectHomotethie, double k) = 0;

	/**
	* \brief Effectue une translation sur la forme (Méthode virtuelle pure)
	* \param vectTranslation Vecteur2D
	*/
	virtual void translation(const Vecteur2D & vectTranslation) = 0;

	/**
	* \brief Effectue une rotation sur la forme
	* \param vectCentre Vecteur2D
	* \param angle Réel
	*/
	virtual void rotation(const  Vecteur2D & vectCentre, double angle) = 0;

	/**
	* \brief Méthode permettant d'afficher les informations concernant la forme
	* \param flux Flux de sortie
	* \return ostream Flux de sortie
	*/
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// Pas méthode virtuelle pure ?
	virtual ostream & print(ostream & flux) const;

	/**
	* \brief Surcharge de l'opérateur << pour l'affichage d'une forme
	* \param flux Flux de sortie
	* \param forme La forme à afficher
	* \return ostream Flux de sortie
	*/
	friend ostream & operator << (ostream & flux, const Forme& forme);

	virtual void accepteSauvegarder(const VisiteurSauvTXT *v)const = 0;
};