/**
* \file Triangle.h
* \brief Classe triangle qui repr�sente une forme sp�ciale (triangle)
*/
#pragma once
#include "Forme.h"
using namespace std;

class Triangle :public Forme {
	Vecteur2D m_P1, m_P2, m_P3;

	/**
	* \brief Constructeur par d�faut interdit donc en priv�
	*/
	Triangle() {}
public:

	/**
	* \brief Constructeur � partir des 3 points et d'une couleur par d�faut
	* \param P1 Vecteur2D
	* \param P2 Vecteur2D
	* \param P3 Vecteur2D
	*/
	Triangle(const Vecteur2D & P1, const Vecteur2D & P2, const Vecteur2D& P3,const Couleur & coul = Couleur());

	/**
	* \brief Constructeur par recopie d'un triangle
	* \param Triangle Triangle � recopier
	*/
	Triangle(const Triangle & Triangle);

	/**
	* \brief Destructeur
	*/
	~Triangle();

	/**
	* \brief V�rifie si les 3 points sont correctement plac�s
	* \param P1 Vecteur2D
	* \param P2 vecteur2D
	* \param P3 Vecteur2D
	* \return bool Bool�en vrai si les points sont bien plac�s, faux sinon
	*/
	bool verifPoints(const Vecteur2D & P1, const Vecteur2D & P2, const Vecteur2D& P3);

	/**
	* \brief Getter du premier point du triangle
	* \return Vecteur2D Le premier point du triangle
	*/
	Vecteur2D getP1()const;

	/**
	* \brief Setter du premier point du triangle.
	* \param P1 Vecteur2D
	*/
	void setP1(const Vecteur2D& P1);

	/**
	* \brief Getter du deuxi�me point du triangle
	* \return Vecteur2D Le deuxi�me point du triangle
	*/
	Vecteur2D getP2()const;

	/**
	* \brief Setter du premier point du triangle
	* \param P2 vecteur2D
	*/
	void setP2(const Vecteur2D& P2);

	/**
	* \brief Getter du troisi�me point du triangle
	* \return Vecteur2D Le troisi�me point du triangle
	*/
	Vecteur2D getP3()const;

	/**
	* \brief Setter du troisi�me point du triangle
	* \param P3 Vecteur2D
	*/
	void setP3(const Vecteur2D& P3);

	/**
	* \brief Surcharge de l'op�rateur string qui permet de convertir un Triangle en string
	*/
	operator string() const;

	/**
	* \brief Surcharge de l'op�rateur == qui permet de tester si deux triangles sont identiques
	* \param objet Triangle � comparer
	* \return bool Bool�en vrai si les deux triangles sont identiques, faux sinon
	*/
	bool operator==(const Triangle &objet) const;

	/**
	* \brief Surcharge de l'op�rateur !=, qui utilise ==
	* \param objet Le triangle � comparer
	* \return Bool�en vrai si les deux triangles sont diff�rents, faux sinon
	*/
	bool operator!= (const Triangle &objet) const;

	/**
	* \brief Surcharge de l'op�rateur = qui permet d'affecter les valeur d'un triangle � un autre
	* \param obj Triangle � affecter
	* \return Triangle affect� par les nouvelles valeurs
	*/
	const Triangle & operator = (const Triangle &obj);

	/**
	* \brief Getter pour r�cup�rer l'aire du triangle
	* \return R�el L'aire du triangle 
	*/
	const double getAire() const;

	/**
	* \brief Clone un triangle
	* \return Forme* Un pointeur sur le triangle clon�
	*/
	Forme * clone() const;

	/**
	* \brief Effectue une homot�thie directement sur le triangle
	* \param vectHomoth�tie Vecteur2D
	* \param k R�el
	*/
	void homothetie(const  Vecteur2D & vectHomotethie, double k);

	/**
	* \brief Effectue une translation directement sur le triangle
	* \param vectTranslation Vecteur2D
	*/
	void translation(const Vecteur2D & vectTranslation);

	/**
	* \brief Effectue une rotation directement sur le triangle
	* \param vectCentre Vecteur2D
	* \param angle R�el
	*/
	void rotation(const  Vecteur2D & vectCentre, double angle);

	/**
	* \brief Affiche les informations concernant un triangle
	* \param flux Le flux sortant
	* \return ostream Flux sortant
	*/
	ostream & print(ostream & flux) const;

};
