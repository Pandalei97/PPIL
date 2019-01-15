/**
* \file Triangle.h
* \brief Classe triangle qui représente une forme spéciale (triangle)
*/
#pragma once
#include "Forme.h"
using namespace std;

class Triangle :public Forme {
	Vecteur2D m_P1, m_P2, m_P3;

	/**
	* \brief Constructeur par défaut interdit donc en privé
	*/
	Triangle() {}
public:

	/**
	* \brief Constructeur à partir des 3 points et d'une couleur par défaut
	* \param P1 Vecteur2D
	* \param P2 Vecteur2D
	* \param P3 Vecteur2D
	*/
	Triangle(const Vecteur2D & P1, const Vecteur2D & P2, const Vecteur2D& P3,const Couleur & coul = Couleur());

	/**
	* \brief Constructeur par recopie d'un triangle
	* \param Triangle Triangle à recopier
	*/
	Triangle(const Triangle & Triangle);

	/**
	* \brief Destructeur
	*/
	~Triangle();

	/**
	* \brief Vérifie si les 3 points sont correctement placés
	* \param P1 Vecteur2D
	* \param P2 vecteur2D
	* \param P3 Vecteur2D
	* \return bool Booléen vrai si les points sont bien placés, faux sinon
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
	* \brief Getter du deuxième point du triangle
	* \return Vecteur2D Le deuxième point du triangle
	*/
	Vecteur2D getP2()const;

	/**
	* \brief Setter du premier point du triangle
	* \param P2 vecteur2D
	*/
	void setP2(const Vecteur2D& P2);

	/**
	* \brief Getter du troisième point du triangle
	* \return Vecteur2D Le troisième point du triangle
	*/
	Vecteur2D getP3()const;

	/**
	* \brief Setter du troisième point du triangle
	* \param P3 Vecteur2D
	*/
	void setP3(const Vecteur2D& P3);

	/**
	* \brief Surcharge de l'opérateur string qui permet de convertir un Triangle en string
	*/
	operator string() const;

	/**
	* \brief Surcharge de l'opérateur == qui permet de tester si deux triangles sont identiques
	* \param objet Triangle à comparer
	* \return bool Booléen vrai si les deux triangles sont identiques, faux sinon
	*/
	bool operator==(const Triangle &objet) const;

	/**
	* \brief Surcharge de l'opérateur !=, qui utilise ==
	* \param objet Le triangle à comparer
	* \return Booléen vrai si les deux triangles sont différents, faux sinon
	*/
	bool operator!= (const Triangle &objet) const;

	/**
	* \brief Surcharge de l'opérateur = qui permet d'affecter les valeur d'un triangle à un autre
	* \param obj Triangle à affecter
	* \return Triangle affecté par les nouvelles valeurs
	*/
	const Triangle & operator = (const Triangle &obj);

	/**
	* \brief Getter pour récupérer l'aire du triangle
	* \return Réel L'aire du triangle 
	*/
	const double getAire() const;

	/**
	* \brief Clone un triangle
	* \return Forme* Un pointeur sur le triangle cloné
	*/
	Forme * clone() const;

	/**
	* \brief Effectue une homotéthie directement sur le triangle
	* \param vectHomothétie Vecteur2D
	* \param k Réel
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
	* \param angle Réel
	*/
	void rotation(const  Vecteur2D & vectCentre, double angle);

	/**
	* \brief Affiche les informations concernant un triangle
	* \param flux Le flux sortant
	* \return ostream Flux sortant
	*/
	ostream & print(ostream & flux) const;

};
