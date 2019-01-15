/**
* \file Vecteur2D.h
* \brief  Un vecteur ici est un point, c'est une couple des réels (x,y) dans un plan, représente un point dans une forme
*/

#pragma once
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

/**
 * \brief Définit le template de l'operateur -
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
	* \brief Constructeur à partir des coordonnées x et y.
	* \details Les coordonnées x et y sont par défaut mis à 0.
	* \param x Réel
	* \param y Réel
	*/
	explicit Vecteur2D(const double & x = 0, const double & y = 0);

	/**
	* \brief Constructeur par copie à partir d'un vecteur.
	* \details Recopie les coordonnées du vecteur passé en paramètre dans \a x et \a y.
	* \param v Vecteur de points
	*/
	Vecteur2D(const Vecteur2D & v);

	/**
	* \brief Destructeur
	*/
	virtual ~Vecteur2D();

	/**
	* \brief Getter de l'attribut privé x.
	* \return Un réel : l'abcisse stockée dans l'attribut privé x
	*/
	const double getX() const;

	/**
	* \brief Setter de l'attribut privé x.
	* \details Modifie la valeur de l'attribut privé x.
	* \param x
	*/
	void setX(const double & x);

	/**
	* \brief Getter de l'attribut y.
	* \return Un réel : l'ordonnée stockée dans l'attribut y.
	*/
	const double getY() const;

	/**
	* \brief Setter de l'attribut y.
	* \details Modifie la valeur de l'attribut y.
	* \param y
	*/
	void setY(const double &y);

	/**
	* \ brief Opérateur d'addition entre deux vecteurs.
	* \param u Vecteur2D
	* \return Vecteur2D Une copie du résultat de l'opération
	*/
	const Vecteur2D operator + (const Vecteur2D & u) const;

	/**
	* \brief Opérateur de multiplication par un facteur a.
	* \param a Réel
	* \return Vecteur2D Une copie du résultat de l'opération
	*/
	const Vecteur2D operator * (const double & a) const;

	/**
	* \brief Opérateur de soustraction (surchargé ici comme opposé d'un vecteur)
	* \return Vecteur2D Une copie du résultat de l'opération
	**/
	const Vecteur2D operator - () const;


	/**
	* \brief Test d'égalité avec un autre vecteur.
	* \details Compare champ à champ les deux vecteurs.
	* \param objet Vecteur2D
	* \return Un booléen true si égalité et false sinon.
	*/
	bool operator==(const Vecteur2D& objet) const;

	/**
	* \ brief Test de différence avec un autre vecteur.
	* \details Utilise l'opérateur d'égalité.
	* \param objet Vecteur2D
	* \return Un booléen true si inégalité et false sinon.
	*/
	bool operator != (const Vecteur2D&  v) const;

	/**
	* \brief Opérateur d'affectation.
	* \details Modifie les attributs x et y en fonction du Vecteur2D passé en paramètre.
	* \param objet Vecteur2D
	* \return \e Vecteur2D résultat de l'affectaion.
	*/
	const Vecteur2D operator = (const Vecteur2D & objet);


	/**
	* \brief Operateur de conversion Vecteur2D en string.
	* \details Conversion des coordonnées du vecteur en chaines de caractères.
	*/
	operator string() const;

	/**
	* \brief Surcharge l'affichage dans un flux de sortie
	* \param os Flux de sortie
	* \param u Vecteur2D
	* \return Le flux ostream
	*/
	friend ostream & operator << (ostream & os, const Vecteur2D & u);

	/**
	* \brief Une homothétie est définie par un point invariant et un rapport de grandeurs vectorielles constant (k) qui modifie directement le vecteur.
	* \param pointInvariant Vecteur2D, k Réel
	*/
	void homothetie(const Vecteur2D & pointInvariant, double k);


	/**
	* \brief Une translation est définie par un vecteur de translation qui modifie directement le vecteur.
	* \param vectTranslation Vecteur2D.
	*/
	void translation(const Vecteur2D & vectTranslation);

	/**
	* \brief Une rotation est définie par un point invariant (le centre de la rotation) et par un angle signé donné en radians. Modifie directement le vecteur.
	* \param vectCentre Vecteur2D, angle Réel.
	*/
	void rotation(const Vecteur2D & vectCentre, double angle);

	/**
	* \brief Calcul du déterminant(u , v), ici le déterminant réprésente l'aire du parallélogramme formé par u et v.
	* \param v Vecteur2D.
	* \return Un Réel résultat de det(u, v).
	*/
	const double determinant(const Vecteur2D &v) const;
};

/**
* \brief Permet d'effectuer l'opération "reel * Vecteur" avec une surcharge de l'opérateur *
* \param v Vecteur2D
* \param a Réel
* \return Un Vecteur2D résultat de l'opération.
*/
inline const Vecteur2D operator* (const double a, const Vecteur2D & v) {
	return v * a;
}