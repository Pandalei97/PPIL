/**
* \file Cercle.h
* \brief Classe cercle qui repr�sente une forme sp�ciale (cercle)
*/
#pragma once

#include "Forme.h"
using namespace std;

class Cercle : public Forme {
	Vecteur2D m_centre;
	double m_rayon;

	/**
	* \brief Constructeur par d�faut interdit donc en priv�
	*/
	Cercle(){}

public:
	/**
	* \brief Constructeur � partir du centre, d'un rayon et d'une couleur.
	* \details La couleur est mise par d�faut avec le constructeur par d�faut Couleur.
	* \param centre Vecteur2D
	* \param rayon R�el
	* \param coul Couleur du cercle
	*/
	Cercle(const Vecteur2D& centre, double rayon, const Couleur & coul = Couleur());

	/**
	* \brief Constructeur par recopie d'un cercle
	* \param obj Cercle � recopier
	*/
	Cercle(const Cercle& obj);

	/**
	* \brief Destructeur
	*/
	~Cercle();

	/**
	* \brief Getter pour r�cup�rer le centre du cercle
	* \return Vecteur2D Le centre du cercle
	*/
	Vecteur2D getCentre() const;

	/**
	* \brief Setter pour modifier le centre du cercle
	* \param centre Vecteur2D correspondant au cercle
	*/
	void setCentre(const Vecteur2D& centre);

	/**
	* \brief Getter pour r�cup�rer le rayon du cercle
	* \return R�el Le rayon du cercle
	*/
	double getRayon()const;

	/**
	* \brief Setter pour modifier le rayon du cercle
	* \param rayon R�el
	*/
	void setRayon(double rayon);

	/**
	* \brief Surcharge de l'op�rateur de  onversion en string
	* \details Convertit un Cercle en string
	*/
	operator string() const;

	/**
	* \brief Surcharge de l'op�rateur ==
	* \details Teste si deux cercles sont identiques
	* \param objet Cercle � comparer
	* \return bool Un bool�en vrai si les deux cercles sont identiques, faux sinon
	*/
	bool operator==(const Cercle &objet) const;

	/**
	* \brief Surcharge de l'op�rateur != 
	* \details Utilise == pour comparer si deux cercles sont diff�rents
	* \param objet Cercle � comparer
	* \return bool Un bool�en vrai si les deux cercles sont diff�rents, faux sinon
	*/
	bool operator!= (const Cercle &objet) const;

	/**
	* \brief Surcharge de l'op�rateur =
	* \details Affecte � un cercle les valeurs d'un autre cercle
	* \param obj Cercle � copier
	*/
	const Cercle & operator = (const Cercle& obj);

	/**
	* \brief Getter pour r�cup�rer l'aire du cercle
	* \return R�el Correspondant � l'aire du cercle
	*/
	const double getAire() const;

	/**
	* \brief Clone un cercle
	* \details M�thode virtuelle pure que l'on red�finit ici
	* \return Forme* Un pointeur sur une Forme (ici un cercle)
	*/
	Forme * clone() const;

	/**
	* \brief Effectue une homot�thie sur le cercle qui modifie directement le cercle
	* \param vectHomotethie Vecteur2D
	* \param k R�el
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
	* \param angle R�el
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