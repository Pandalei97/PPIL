/**
* \file Cercle.h
* \brief Classe cercle qui représente une forme spéciale (cercle)
*/
#pragma once

#include "Forme.h"
using namespace std;

class Cercle : public Forme {
	Vecteur2D m_centre;
	double m_rayon;

	/**
	* \brief Constructeur par défaut interdit donc en privé
	*/
	Cercle(){}

public:
	/**
	* \brief Constructeur à partir du centre, d'un rayon et d'une couleur.
	* \details La couleur est mise par défaut avec le constructeur par défaut Couleur.
	* \param centre Vecteur2D
	* \param rayon Réel
	* \param coul Couleur du cercle
	*/
	Cercle(const Vecteur2D& centre, double rayon, const Couleur & coul = Couleur());

	/**
	* \brief Constructeur par recopie d'un cercle
	* \param obj Cercle à recopier
	*/
	Cercle(const Cercle& obj);

	/**
	* \brief Destructeur
	*/
	~Cercle();

	/**
	* \brief Getter pour récupérer le centre du cercle
	* \return Vecteur2D Le centre du cercle
	*/
	Vecteur2D getCentre() const;

	/**
	* \brief Setter pour modifier le centre du cercle
	* \param centre Vecteur2D correspondant au cercle
	*/
	void setCentre(const Vecteur2D& centre);

	/**
	* \brief Getter pour récupérer le rayon du cercle
	* \return Réel Le rayon du cercle
	*/
	double getRayon()const;

	/**
	* \brief Setter pour modifier le rayon du cercle
	* \param rayon Réel
	*/
	void setRayon(double rayon);

	/**
	* \brief Surcharge de l'opérateur de  onversion en string
	* \details Convertit un Cercle en string
	*/
	operator string() const;

	/**
	* \brief Surcharge de l'opérateur ==
	* \details Teste si deux cercles sont identiques
	* \param objet Cercle à comparer
	* \return bool Un booléen vrai si les deux cercles sont identiques, faux sinon
	*/
	bool operator==(const Cercle &objet) const;

	/**
	* \brief Surcharge de l'opérateur != 
	* \details Utilise == pour comparer si deux cercles sont différents
	* \param objet Cercle à comparer
	* \return bool Un booléen vrai si les deux cercles sont différents, faux sinon
	*/
	bool operator!= (const Cercle &objet) const;

	/**
	* \brief Surcharge de l'opérateur =
	* \details Affecte à un cercle les valeurs d'un autre cercle
	* \param obj Cercle à copier
	*/
	const Cercle & operator = (const Cercle& obj);

	/**
	* \brief Getter pour récupérer l'aire du cercle
	* \return Réel Correspondant à l'aire du cercle
	*/
	const double getAire() const;

	/**
	* \brief Clone un cercle
	* \details Méthode virtuelle pure que l'on redéfinit ici
	* \return Forme* Un pointeur sur une Forme (ici un cercle)
	*/
	Forme * clone() const;

	/**
	* \brief Effectue une homotéthie sur le cercle qui modifie directement le cercle
	* \param vectHomotethie Vecteur2D
	* \param k Réel
	*/
	void homothetie(const  Vecteur2D & vectHomotethie, double k);

	/**
	* \brief Effectue une translation sur le cercle qui modifie directement le cercle
	* \param vectTranslation Vecteur2D
	*/
	void translation(const Vecteur2D & vectTranslation);

	/**
	* \brief Effectue une rotation sur le cercle qui modifie directement le cercle
	* \param vectCentre Vecteur2D
	* \param angle Réel
	*/
	void rotation(const  Vecteur2D & vectCentre, double angle);

	/**
	* \brief Affiche les informations sur le cercle
	* \param flux Flux de sortie
	* \return ostream Un flux de sortie
	*/
	ostream& print(ostream & flux) const;


	void accepteSauvegarder(const VisiteurSauvTXT *v)const;
};