/**
* \file Vecteur2D.h
* \brief  Un vecteur ici est un point, c'est une couple des r�els (x,y) dans un plan
* \details Cette classe r�presente un point dans une forme.
*/

#pragma once
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

/**
 * \brief D�finit l'operateur - binaire.
 * \tparam T u.
 * \tparam T v.
 * \return u + (-v).
 */

template <class T>
const T operator-(const T& u, const T& v) {
	return u + -v;
}


class Vecteur2D {
	double m_x, m_y;
public:
	/**
	* \ brief Constructeur � partir des coordonn�es x et y.
	* \details Les coordonn�es x et y sont par d�faut mis � z�ro.
	* \param x.
	* \param y.
	*/
	explicit Vecteur2D(const double & x = 0, const double & y = 0);

	/**
	* \ brief Constructeur par copie � partir d'un vecteur.
	* \details Recopie les coordonn�es du vecteur pass� en param�tre dans \a x et \a y.
	* \param v.
	*/
	Vecteur2D(const Vecteur2D & v);

	/**
	* \ brief Destructeur.
	*/
	virtual ~Vecteur2D();

	/**
	* \ brief getter du champ \a x.
	* \return \e double l'abcisse stock�e dans le champ \a x.
	*/
	const double getX() const;

	/**
	* \ brief setter du champ \a x.
	* \details modifie la valeur du champ \a x.
	* \param x.
	*/
	void setX(const double & x);

	/**
	* \ brief getter du champ \a y.
	* \return \e double l'ordonn�e stock�e dans le champ \a y.
	*/
	const double getY() const;

	/**
	* \ brief setter du champ \a y.
	* \details modifie la valeur du champ \a y.
	* \param y.
	*/
	void setY(const double &y);

	/**
	* \ brief Op�rateur d'addition entre deux vecteurs.
	* \param u.
	*/
	const Vecteur2D operator + (const Vecteur2D & u) const;

	/**
	* \ brief Op�rateur de multiplication parune facteur a.
	* \param a.
	*/
	const Vecteur2D operator * (const double & a) const;

	/**
	* \brief - unaire (c'est-�- dire oppos� d'un vecteur)
	**/
	const Vecteur2D operator - () const;


	/**
	* \ brief Test d'�galit� avec un autre vecteur.
	* \details compare champ � champ les deux vecteurs.
	* \param objet.
	* \return \e bool true si �galit� et false sinon.
	*/
	bool operator==(const Vecteur2D& objet) const;

	/**
	* \ brief Test de diff�rence avec un autre vecteur.
	* \details Exploite l'op�rateur d'�galit�.
	* \param objet.
	* \return \e bool true si in�galit� et false sinon.
	*/
	bool operator != (const Vecteur2D&  v) const;

	/**
	* \ brief Op�rateur d'affectation.
	* \details Affecte les donn�es du vecteur pass� aux diff�rents champs \a x et \a y.
	* \param objet.
	* \return \e Vecteur2D r�sultat de l'affectaion.
	*/
	const Vecteur2D operator = (const Vecteur2D & objet);


	/**
	* \ brief Operateur de conversion Vecteur2D ===> string.
	* \details convertit les coordonn�es du vecteur en des chaines de caract�res.
	*/
	operator string() const;

	/**
	* \ brief Surcharge l'affichage dans un flux.
	* \param flux.
	* \param u.
	* \return \e ostream flux.
	*/
	friend ostream & operator << (ostream & os, const Vecteur2D & u);

	/**
	* \ brief Une homoth�tie est d�finie par un point invariant et un rapport de grandeurs vectorielles constant (k).
	*\param vectHomotethie, k.
	* Modifie le vecteur.
	*/
	void homothetie(const Vecteur2D & pointInvariant, double k);


	/**
	* \ brief Une translation est d�finie par un vecteur de translation.
	*\param vectTranslation.
	* Modifie le vecteur.
	*/
	void translation(const Vecteur2D & vectTranslation);

	/**
	* \ brief Une rotation est d�finie d�finie par un point invariant (le centre de la rotation) et par un angle sign� donn� en radians.
	*\param vectCentre, angle.
	* Modifie le vecteur.
	*/
	void rotation(const Vecteur2D & vectCentre, double angle);

	/**
	* \ brief Calcul du d�terminant(u , v), ici le d�terminant r�pr�sente l'aire du parall�logramme form� par u et v.
	*\param v.
	* \return \e double det(u, v).
	*/
	const double determinant(const Vecteur2D &) const;
};

// Permet d'effectuer l'op�ration " reel * Vecteur"
inline const Vecteur2D operator* (const double a, const Vecteur2D & v) {
	return v * a;
}