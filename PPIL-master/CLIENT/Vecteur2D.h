/**
* \file Vecteur2D.h
* \brief  Un vecteur ici est un point, c'est une couple des r�els (x,y) dans un plan, repr�sente un point dans une forme
*/

#pragma once
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

/**
 * \brief D�finit le template de l'operateur -
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
	* \brief Constructeur � partir des coordonn�es x et y.
	* \details Les coordonn�es x et y sont par d�faut mis � 0.
	* \param x R�el
	* \param y R�el
	*/
	explicit Vecteur2D(const double & x = 0, const double & y = 0);

	/**
	* \brief Constructeur par copie � partir d'un vecteur.
	* \details Recopie les coordonn�es du vecteur pass� en param�tre dans \a x et \a y.
	* \param v Vecteur de points
	*/
	Vecteur2D(const Vecteur2D & v);

	/**
	* \brief Destructeur
	*/
	virtual ~Vecteur2D();

	/**
	* \brief Getter de l'attribut priv� x.
	* \return Un r�el : l'abcisse stock�e dans l'attribut priv� x
	*/
	const double getX() const;

	/**
	* \brief Setter de l'attribut priv� x.
	* \details Modifie la valeur de l'attribut priv� x.
	* \param x
	*/
	void setX(const double & x);

	/**
	* \brief Getter de l'attribut y.
	* \return Un r�el : l'ordonn�e stock�e dans l'attribut y.
	*/
	const double getY() const;

	/**
	* \brief Setter de l'attribut y.
	* \details Modifie la valeur de l'attribut y.
	* \param y
	*/
	void setY(const double &y);

	/**
	* \ brief Op�rateur d'addition entre deux vecteurs.
	* \param u Vecteur2D
	* \return Vecteur2D Une copie du r�sultat de l'op�ration
	*/
	const Vecteur2D operator + (const Vecteur2D & u) const;

	/**
	* \brief Op�rateur de multiplication par un facteur a.
	* \param a R�el
	* \return Vecteur2D Une copie du r�sultat de l'op�ration
	*/
	const Vecteur2D operator * (const double & a) const;

	/**
	* \brief Op�rateur de soustraction (surcharg� ici comme oppos� d'un vecteur)
	* \return Vecteur2D Une copie du r�sultat de l'op�ration
	**/
	const Vecteur2D operator - () const;


	/**
	* \brief Test d'�galit� avec un autre vecteur.
	* \details Compare champ � champ les deux vecteurs.
	* \param objet Vecteur2D
	* \return Un bool�en true si �galit� et false sinon.
	*/
	bool operator==(const Vecteur2D& objet) const;

	/**
	* \ brief Test de diff�rence avec un autre vecteur.
	* \details Utilise l'op�rateur d'�galit�.
	* \param objet Vecteur2D
	* \return Un bool�en true si in�galit� et false sinon.
	*/
	bool operator != (const Vecteur2D&  v) const;

	/**
	* \brief Op�rateur d'affectation.
	* \details Modifie les attributs x et y en fonction du Vecteur2D pass� en param�tre.
	* \param objet Vecteur2D
	* \return \e Vecteur2D r�sultat de l'affectaion.
	*/
	const Vecteur2D operator = (const Vecteur2D & objet);


	/**
	* \brief Operateur de conversion Vecteur2D en string.
	* \details Conversion des coordonn�es du vecteur en chaines de caract�res.
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
	* \brief Une homoth�tie est d�finie par un point invariant et un rapport de grandeurs vectorielles constant (k) qui modifie directement le vecteur.
	* \param pointInvariant Vecteur2D, k R�el
	*/
	void homothetie(const Vecteur2D & pointInvariant, double k);


	/**
	* \brief Une translation est d�finie par un vecteur de translation qui modifie directement le vecteur.
	* \param vectTranslation Vecteur2D.
	*/
	void translation(const Vecteur2D & vectTranslation);

	/**
	* \brief Une rotation est d�finie par un point invariant (le centre de la rotation) et par un angle sign� donn� en radians. Modifie directement le vecteur.
	* \param vectCentre Vecteur2D, angle R�el.
	*/
	void rotation(const Vecteur2D & vectCentre, double angle);

	/**
	* \brief Calcul du d�terminant(u , v), ici le d�terminant r�pr�sente l'aire du parall�logramme form� par u et v.
	* \param v Vecteur2D.
	* \return Un R�el r�sultat de det(u, v).
	*/
	const double determinant(const Vecteur2D &v) const;
};

/**
* \brief Permet d'effectuer l'op�ration "reel * Vecteur" avec une surcharge de l'op�rateur *
* \param v Vecteur2D
* \param a R�el
* \return Un Vecteur2D r�sultat de l'op�ration.
*/
inline const Vecteur2D operator* (const double a, const Vecteur2D & v) {
	return v * a;
}