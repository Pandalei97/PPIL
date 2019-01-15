/**
* \file Couleur.h
* \brief Classe couleur qui représente la couleur d'une forme/groupe
*/
#pragma once

#include <iostream>
#include <vector>
#include <sstream>
#include "Constantes.h"
#include "Exception.h"
using namespace std;

class Couleur {
	/**
	* \brief Méthode privée qui initialise un vecteur de couleurs
	* \details On utilise les constantes de Constantes.h
	* \return vector<string> Un vecteur de string contenant toutes les couleurs
	*/
	static vector<string> InitTabCouleur() {
		vector<string> v;
		v.push_back(DEFAULT);
		v.push_back(BLACK);
		v.push_back(BLUE);
		v.push_back(RED);
		v.push_back(GREEN);
		v.push_back(YELLOW);
		v.push_back(CYAN);
		return v;
	}

	static vector<string> tab_couleur;
	string m_couleur;

public:
	/**
	* \brief Constructeur par défaut d'une couleur
	*/
	Couleur();

	/**
	* \brief Constructeur à partir d'une chaine de caractères
	* \param couleur Une chaine de caractère représentant la couleur
	*/
	Couleur(const string & couleur);

	/**
	* \brief Constructeur à partir d'une couleur
	* \param couleur Une couleur
	*/
	Couleur(const Couleur & couleur);

	/**
	* \brief Destructeur
	*/
	virtual ~Couleur();

	/**
	* \brief Teste si une couleur existe
	* \param bool Renvoie vrai si la couleur existe, faux sinon
	*/
	bool contains(string couleur);

	/**
	* \brief Getter pour récupérer la couleur
	* \return string Une chaine de caractère correspondant à la couleur
	*/
	const string & getCouleur() const;

	/**
	* \brief Setter pour modifier la couleur
	* \param couleur Une chaine de caractère correspondant à la couleur à modifier
	*/
	void setCouleur(const string & couleur);

	/**
	* \brief Surcharge de l'opérateur pour convertir une couleur en string
	* \details COnversion d'une couleur en chaine de caractères
	*/
	operator string() const;

	/**
	* \brief Surcharge de l'opérateur == pour comparer deux couleurs
	* \param objet La couleur à comparer
	* \return bool Un booléen vrai si les deux couleurs dont identiques, faux sinon
	*/
	bool operator==(const  Couleur &objet) const;

	/**
	* \brief Surcharge de l'opérateur != pour comparer deux couleurs, on utilise ==
	* \param objet La couleur à comparer
	* \param y Réel
	*/
	bool operator != (const Couleur &objet) const;

	/**
	* \brief Surcharge de l'opérateur = pour affecter les valeurs d'une couleur à une autre
	* \param couleur La couleur à affecter 
	* \return Coulur Objet constant de la couleur qui a été affectée
	*/
	const Couleur operator = (const Couleur& couleur);

	/**
	* \brief Surcharge de l'opérateur << pour l'affichage des couleurs
	* \param flux Le flux de sortie
	* \param coul La couleur à afficher
	* \return ostream Le flux de sortie
	*/
	friend ostream & operator << (ostream & flux, const Couleur& coul);
};
