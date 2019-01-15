/**
* \file Polygone.h
* \brief Classe polygone qui repr�sente une forme sp�ciale (polygone)
*/
#pragma once
#include "Forme.h"
#include <vector>
using namespace std;
class Polygone :public Forme {
	vector<Vecteur2D> m_tabPoints;

	/**
	* \brief Contructeur par d�faut interdit car un polygone doit �tre initialis� avec au moins 3 points
	*/
	Polygone(){}

public:

	/**
	* \brief Constructeur � partir de 3 points et d'une couleur par d�faut
	* \param P1 Vecteur2D
	* \param P2 vecteur2D
	* \param P3 Vecteur2D
	*/
	Polygone(const Vecteur2D & P1, const Vecteur2D & P2, const Vecteur2D& P3, const Couleur & coul = Couleur());

	/**
	* \brief Constructeur par recopie d'un polygone
	* \param Polygone Le polygone � recopier
	*/
	Polygone(const Polygone & Polygone);

	/**
	* \brief Destructeur
	*/
	~Polygone();

	/**
	* \brief V�rifie si tous les points sont correctement plac�s
	* \param tabPoints Vecteur de points
	* \return bool Bool�en vrai si les points sont bien plac�s, faux sinon
	*/
	bool verifPoints(vector<Vecteur2D>& tabPoints);

	/**
	* \brief Surcharge de l'op�rateur string pour convertir un polygone en string
	*/
	operator string() const;

	/**
	* \brief Surcharge de l'op�rateur == qui teste si deux polygones sont identiques
	* \param objet Polygone � comparer
	* \return bool Bool�en vrai si les deux polygones sont identiques, faux sinon
	*/
	bool operator==(const Polygone &objet) const;

	/**
	* \brief Surcharge de l'op�rateur !=, qui utilise ==
	* \param objet Polygone � comparer
	* \return bool Bool�en vrai si les deux polygones sont diff�rents, faux sinon
	*/
	bool operator!= (const Polygone &objet) const;

	/**
	* \brief Surcharge de l'op�rateur =, pour affecter les valeurs d'un polygone � un autre
	* \param obj Objet � copier
	* \return obj La resultante de l'affectation du polygone
	*/
	const Polygone & operator = (const Polygone&obj);

	/**
	* \brief Surcharge de l'op�rateur [] pour acc�der � un point du polygone par son indice
	* \param indice L'indice du point
	* \return Vecteur2D Le point � l'indice donn� en param�tre 
	*/
	const Vecteur2D & operator[] (int indice)const;

	/**
	* \brief Surcharge de l'op�rateur + pour ajouter un point au polygone
	* \param v Point � ajouter
	* \return Polygone Une copie du nouveau polygone avec le point ajout�
	*/
	Polygone operator + (const Vecteur2D & v)const;

	/**
	* \brief Supprime un pointdu polygone
	* \param indice Indice du point � supprimer
	*/
	void supprimer(int indice);

	/**
	* \brief Getter pour r�cup�rer l'aire du polygone 
	* \return R�el L'aire du polygone
	*/
	const double getAire() const;

	/**
	* \brief Clone un polygone
	* \return Forme* Pointeur sur le polygone clon�
	*/
	Forme * clone() const;

	/**
	* \brief Effectue une homoth�tie directement sur le polygone
	* \param vectHomothetie Vecteur2D
	* \param k R�el
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
	* \param angle R�el
	*/
	void rotation(const  Vecteur2D & vectCentre, double angle);

	/**
	* \brief Affiche les valeurs d'un polygone
	* \param flux Flux de sortie
	* \return ostream FLux de sortie
	*/
	ostream & print(ostream & flux) const;
};