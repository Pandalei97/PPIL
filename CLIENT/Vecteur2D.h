/**
* \file Vecteur2D.h
* \brief  Un vecteur ici est un point, c'est une couple des réels (x,y) dans un plan
* \details Cette classe répresente un point dans une forme.
*/

#pragma once
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

/**
 * \brief Définit l'operateur - binaire.
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
	* \ brief Constructeur à partir des coordonnées x et y.
	* \details Les coordonnées x et y sont par défaut mis à zéro.
	* \param x.
	* \param y.
	*/
	explicit Vecteur2D(const double & x = 0, const double & y = 0);

	/**
	* \ brief Constructeur par copie à partir d'un vecteur.
	* \details Recopie les coordonnées du vecteur passé en paramètre dans \a x et \a y.
	* \param v.
	*/
	Vecteur2D(const Vecteur2D & v);

	/**
	* \ brief Destructeur.
	*/
	virtual ~Vecteur2D();

	/**
	* \ brief getter du champ \a x.
	* \return \e double l'abcisse stockée dans le champ \a x.
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
	* \return \e double l'ordonnée stockée dans le champ \a y.
	*/
	const double getY() const;

	/**
	* \ brief setter du champ \a y.
	* \details modifie la valeur du champ \a y.
	* \param y.
	*/
	void setY(const double &y);

	/**
	* \ brief Opérateur d'addition entre deux vecteurs.
	* \param u.
	*/
	const Vecteur2D operator + (const Vecteur2D & u) const;

	/**
	* \ brief Opérateur de multiplication parune facteur a.
	* \param a.
	*/
	const Vecteur2D operator * (const double & a) const;

	/**
	* \brief - unaire (c'est-à- dire opposé d'un vecteur)
	**/
	const Vecteur2D operator - () const;


	/**
	* \ brief Test d'égalité avec un autre vecteur.
	* \details compare champ à champ les deux vecteurs.
	* \param objet.
	* \return \e bool true si égalité et false sinon.
	*/
	bool operator==(const Vecteur2D& objet) const;

	/**
	* \ brief Test de différence avec un autre vecteur.
	* \details Exploite l'opérateur d'égalité.
	* \param objet.
	* \return \e bool true si inégalité et false sinon.
	*/
	bool operator != (const Vecteur2D&  v) const;

	/**
	* \ brief Opérateur d'affectation.
	* \details Affecte les données du vecteur passé aux différents champs \a x et \a y.
	* \param objet.
	* \return \e Vecteur2D résultat de l'affectaion.
	*/
	const Vecteur2D operator = (const Vecteur2D & objet);


	/**
	* \ brief Operateur de conversion Vecteur2D ===> string.
	* \details convertit les coordonnées du vecteur en des chaines de caractères.
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
	* \ brief Une homothétie est définie par un point invariant et un rapport de grandeurs vectorielles constant (k).
	*\param vectHomotethie, k.
	* Modifie le vecteur.
	*/
	void homothetie(const Vecteur2D & pointInvariant, double k);


	/**
	* \ brief Une translation est définie par un vecteur de translation.
	*\param vectTranslation.
	* Modifie le vecteur.
	*/
	void translation(const Vecteur2D & vectTranslation);

	/**
	* \ brief Une rotation est définie définie par un point invariant (le centre de la rotation) et par un angle signé donné en radians.
	*\param vectCentre, angle.
	* Modifie le vecteur.
	*/
	void rotation(const Vecteur2D & vectCentre, double angle);

	/**
	* \ brief Calcul du déterminant(u , v), ici le déterminant réprésente l'aire du parallélogramme formé par u et v.
	*\param v.
	* \return \e double det(u, v).
	*/
	const double determinant(const Vecteur2D &) const;
};

// Permet d'effectuer l'opération " reel * Vecteur"
inline const Vecteur2D operator* (const double a, const Vecteur2D & v) {
	return v * a;
}