/**
* \file Polygone.h
* \brief Classe polygone qui représente une forme spéciale (polygone)
*/
#pragma once
#include "Forme.h"
#include <vector>
using namespace std;
class Polygone :public Forme {
	vector<Vecteur2D> m_tabPoints;

	/**
	* \brief Contructeur par défaut interdit car un polygone doit être initialisé avec au moins 3 points
	*/
	Polygone(){}

public:

	/**
	* \brief Constructeur à partir de 3 points et d'une couleur par défaut
	* \param P1 Vecteur2D
	* \param P2 vecteur2D
	* \param P3 Vecteur2D
	*/
	Polygone(const Vecteur2D & P1, const Vecteur2D & P2, const Vecteur2D& P3, const Couleur & coul = Couleur());

	/**
	* \brief Constructeur par recopie d'un polygone
	* \param Polygone Le polygone à recopier
	*/
	Polygone(const Polygone & Polygone);

	/**
	* \brief Destructeur
	*/
	~Polygone();

	/**
	* \brief Vérifie si tous les points sont correctement placés
	* \param tabPoints Vecteur de points
	* \return bool Booléen vrai si les points sont bien placés, faux sinon
	*/
	bool verifPoints(vector<Vecteur2D>& tabPoints);

	/**
	* \brief Surcharge de l'opérateur string pour convertir un polygone en string
	*/
	operator string() const;

	/**
	* \brief Surcharge de l'opérateur == qui teste si deux polygones sont identiques
	* \param objet Polygone à comparer
	* \return bool Booléen vrai si les deux polygones sont identiques, faux sinon
	*/
	bool operator==(const Polygone &objet) const;

	/**
	* \brief Surcharge de l'opérateur !=, qui utilise ==
	* \param objet Polygone à comparer
	* \return bool Booléen vrai si les deux polygones sont différents, faux sinon
	*/
	bool operator!= (const Polygone &objet) const;

	/**
	* \brief Surcharge de l'opérateur =, pour affecter les valeurs d'un polygone à un autre
	* \param obj Objet à copier
	* \return obj La resultante de l'affectation du polygone
	*/
	const Polygone & operator = (const Polygone&obj);

	/**
	* \brief Surcharge de l'opérateur [] pour accéder à un point du polygone par son indice
	* \param indice L'indice du point
	* \return Vecteur2D Le point à l'indice donné en paramètre 
	*/
	const Vecteur2D & operator[] (int indice)const;

	/**
	* \brief Surcharge de l'opérateur + pour ajouter un point au polygone
	* \param v Point à ajouter
	* \return Polygone Une copie du nouveau polygone avec le point ajouté
	*/
	Polygone operator + (const Vecteur2D & v)const;

	/**
	* \brief Supprime un pointdu polygone
	* \param indice Indice du point à supprimer
	*/
	void supprimer(int indice);

	/**
	* \brief Getter pour récupérer l'aire du polygone 
	* \return Réel L'aire du polygone
	*/
	const double getAire() const;

	/**
	* \brief Clone un polygone
	* \return Forme* Pointeur sur le polygone cloné
	*/
	Forme * clone() const;

	/**
	* \brief Effectue une homothétie directement sur le polygone
	* \param vectHomothetie Vecteur2D
	* \param k Réel
	*/
	void homothetie(const  Vecteur2D & vectHomotethie, double k);

	/**
	* \brief Effectue une translation directement sur le polygone
	* \param vectTranslation Vecteur2D
	*/
	void translation(const Vecteur2D & vectTranslation);

	/**
	* \brief Effectue une rotation directement sur le polygone
	* \param vectCentre Vecteur2D
	* \param angle Réel
	*/
	void rotation(const  Vecteur2D & vectCentre, double angle);

	/**
	* \brief Affiche les valeurs d'un polygone
	* \param flux Flux de sortie
	* \return ostream FLux de sortie
	*/
	ostream & print(ostream & flux) const;
};