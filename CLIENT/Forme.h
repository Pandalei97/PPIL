/**
* \file Forme.h
* \brief Classe forme qui repr�sente une forme
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
	bool m_marquee; //On marque les formes qui appartiennent d�j� � un groupe
public:

	/**
	* \brief Constructeur par d�faut de Forme
	*/
	Forme();

	/**
	* \brief Constructeur � partir d'une couleur
	* \param couleur Une couleur � appliquer � la forme
	*/
	Forme(const Couleur & couleur);

	/**
	* \brief Constructeur de recopie � partir d'un pointeur de Forme
	* \details Les coordonn�es x et y sont par d�faut mis � 0.
	* \param x R�el
	* \param y R�el
	*/
	Forme(const Forme* forme);

	/**
	* \brief Destructeur virtual qui sera appel� pour tous les h�ritiers de Forme
	*/
	virtual ~Forme();

	/**
	* \brief Getter pour r�cup�rer la couleur d'une forme
	* \return Couleur La couleur de la forme
	*/
	Couleur getCouleur()const;

	/**
	* \brief Setter pour modifier la couleur de la forme
	* \param couleur Chaine de caract�re correspondant � la couleur
	*/
	virtual void setCouleur(const string & couleur);

	/**
	* \brief Getter pour savoir si une forme fait parti d'un groupe
	* \return bool un bool�en vrai si la forme est dans un groupe, faux sinon
	*/
	bool estMarquee()const;

	/**
	* \brief Setter qui permet de marquer une forme si elle fait parti d'un groupe
	* \param marquee Marquer la forme par vrai ou faux
	*/
	void setMarquee(bool marquee);


	/**
	* \brief Surcharge de l'op�rateur string permettant de convertir des formes en string 
	*/
	virtual operator string() const;

	/**
	* \brief Surcharge de l'op�rateur == qui teste si deux formes sont identiques
	* \param objet La forme � comparer
	* \return bool Un bool�en vrai si les deux formes sont identiques, faux sinon
	*/
	virtual bool operator==(const Forme &objet) const;

	/**
	* \brief Surcharge de l'op�rateur != qui utilise ==
	* \details Teste si deux formes sont diff�rentes
	* \param objet La forme � comparer
	* \return bool Un bool�en vrai si les deux formes sont diff�rentes, faux sinon
	*/
	virtual bool operator != (const Forme &objet) const;

	/**
	* \brief Surcharge de l'op�rateur = qui permet d'affcter une forme � une autre
	* \param forme La forme � affecter
	* \return Forme* Un pointeur sur Forme
	*/
	virtual const Forme* operator = (const Forme& forme);

	/**
	* \brief Getter recup�re l'aire de la forme propre � chaque forme (m�thode virtuelle pure)
	* \return L'aire de la forme
	*/
	virtual const double getAire() const = 0;

	/**
	* \brief Clone une forme (m�thode virtuelle pure)
	* \return Forme* Un pointeur sur l'objet clon�
	*/
	virtual Forme * clone() const = 0;

	/**
	* \brief Effectue une homot�thie sur la forme (M�thode vitruelle pure)
	* \param vectHomotethie Vecteur2D
	* \param k R�el
	*/
	virtual void homothetie(const  Vecteur2D & vectHomotethie, double k) = 0;

	/**
	* \brief Effectue une translation sur la forme (M�thode virtuelle pure)
	* \param vectTranslation Vecteur2D
	*/
	virtual void translation(const Vecteur2D & vectTranslation) = 0;

	/**
	* \brief Effectue une rotation sur la forme
	* \param vectCentre Vecteur2D
	* \param angle R�el
	*/
	virtual void rotation(const  Vecteur2D & vectCentre, double angle) = 0;

	/**
	* \brief M�thode permettant d'afficher les informations concernant la forme
	* \param flux Flux de sortie
	* \return ostream Flux de sortie
	*/
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// Pas m�thode virtuelle pure ?
	virtual ostream & print(ostream & flux) const;

	/**
	* \brief Surcharge de l'op�rateur << pour l'affichage d'une forme
	* \param flux Flux de sortie
	* \param forme La forme � afficher
	* \return ostream Flux de sortie
	*/
	friend ostream & operator << (ostream & flux, const Forme& forme);

	virtual void accepteSauvegarder(const VisiteurSauvTXT *v)const = 0;
};