/**
* \file Segment.h
* \brief Classe segment qui représente une forme spéciale (segment)
*/
#pragma once
#include "Forme.h"
using namespace std;
class Segment :public Forme {
	Vecteur2D m_PO, m_PE; //point d'origine et point d'extrémité
	
	/**
	* \brief Constructeur par défaut interdit donc en privé
	*/
	Segment(){}
public:
	
	/**
	* \brief Constructeur à partir du point d'origine et du point de l'autre extrémité
	* \param PO Vecteur2D
	* \param PE vecteur2D
	* \param coul Couleur par défaut
	*/
	Segment(const Vecteur2D & PO, const Vecteur2D & PE, const Couleur & coul = Couleur());

	/**
	* \brief Constructeur par recopie d'un segment
	* \param segment Le segment à copier
	*/
	Segment(const Segment & segment);

	/**
	* \brief Destructeur
	*/
	~Segment();

	/**
	* \brief Getter pour récupérer le point d'origine du segment
	* \return Vecteur2D Le point d'origine
	*/
	Vecteur2D getPO()const;

	/**
	* \brief Setter pour modifier le point d'origine du segment
	* \param PO Vecteur2D
	*/
	void setPO(const Vecteur2D& PO);

	/**
	* \brief Getter pour récupérer le point d'extrémité du segment
	* \return Vecteur2D Le point d'extrémité
	*/
	Vecteur2D getPE()const;

	/**
	* \brief Setter pour modifier le point d'extrémité du segment
	* \param PE Vecteur2D
	*/
	void setPE(const Vecteur2D& PE);

	/**
	* \brief Surcharge de string pour convertir des segments en string
	*/
	operator string() const;

	/**
	* \brief Surcharge de l'opérateur == pour tester si deux segments sont identiques
	* \param objet Segment à comparer
	* \return bool Booléen vrai si les deux segments sont identiques, faux sinon
	*/
	bool operator==(const Segment &objet) const;

	/**
	* \brief Surcharge de l'opérateur !=, utilise ==
	* \param objet Segment à comparer
	* \return bool Booléen vrai si les deux semgents sont différents, faux sinon
	*/
	bool operator!= (const Segment &objet) const;

	/**
	* \brief Surcharge de l'opérateur =, pour affecter les valeurs d'un segment à un autre
	* \param obj Objet à copier
	* \return Segment La resultante de l'affectation du segment
	*/
	const Segment & operator = (const Segment&obj);

	/**
	* \brief Getter pour récupérer l'aire du segment (toujours = 0)
	* \return Rél Aire du segment (=0)
	*/
	const double getAire() const;

	/**
	* \brief Clone un segment
	* \return Forme* Pointeur sur le segment cloné
	*/
	Forme * clone() const;

	/**
	* \brief Effectue une homothétie directement sur le segment
	* \param vectHomothetie Vecteur2D
	* \param k Réel
	*/
	void homothetie(const  Vecteur2D & vectHomotethie, double k);

	/**
	* \brief Effectue une translation directement sur le segment
	* \param vectTranslation Vecteur2D
	*/
	void translation(const Vecteur2D & vectTranslation);

	/**
	* \brief Effectue une rotation directement sur le segment
	* \param vectTranslation Vecteur2D
	* \param angle Réel
	*/
	void rotation(const  Vecteur2D & vectCentre, double angle);

	/**
	* \brief Affiche les informations d'un segment
	* \param flux Flux de sortie
	* \return ostream Flux de sortie
	*/
	ostream & print(ostream & flux) const;

	void accepteSauvegarder(const VisiteurSauvTXT *v)const;

};
