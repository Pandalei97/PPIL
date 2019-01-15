/**
* \file Groupe.h
* \brief Classe groupe qui repr�sente un groupe de formes
*/
#pragma once
#include "Forme.h"
#include <vector>

class Groupe :public Forme {
	vector<Forme *> m_tabFormes;

public:

	/**
	* \brief Constructeur par d�faut d'un groupe (vide)
	*/
	Groupe();

	/**
	* \brief Constructeur � partir d'une couleur
	* \param coul Couleur
	*/
	Groupe(const Couleur &coul);

	/**
	* \brief Constructeur dpar recopie d'un groupe
	* \param groupe Groupe � recopier
	*/
	Groupe(const Groupe & groupe);

	/**
	* \brief Destructeur
	*/
	~Groupe();

	/**
	* \brief Getter pour r�cup�rer le nombre de formes du groupe
	* \return int Nombre de formes du groupe
	*/
	int getNbFormes() const;

	/**
	* \brief Setter pour modifier la couleur du groupe
	* \param couleur Chaine de caract�res correspondant � la couleur
	*/
	void setCouleur(const string& couleur);

	/**
	* \brief Surcharge de string pour convertir un groupe en chaine de caract�res
	*/
	operator string() const;

	/**
	* \brief Surcharge de l'op�rateur == qui teste si deux groupes sont identiques
	* \param obj Groupe � comparer
	* \return bool Bool�en vrai si les deux groupes sont identiques, faux sinon
	*/
	bool operator==(const  Groupe &obj) const;

	/**
	* \brief Surcharge de l'op�rateur !=, qui utilise ==
	* \param obj Groupe � comparer
	* \return bool Bool�en vrai si les deux groupes sont diff�rents, faux sinon
	*/
	bool operator != (const Groupe &obj) const;

	/**
	* \brief Surcharge de l'op�rateur =, pour affecter les valeurs d'un groupe � un autre
	* \param obj Objet � copier
	* \return obj La resultante de l'affectation du groupe
	*/
	const Groupe & operator = (const Groupe &obj);

	/**
	* \brief Surcharge de l'op�rateur [] qui permet d'acc�der � une forme d'un groupe
	* \param indice Indice de la forme � r�cup�rer
	* \returnForme* Un pointeur sur la forme se trouvant � l'indice donn� en param�tre
	*/
	Forme * operator[] (const int indice)const;

	/**
	* \brief Surcharge de l'op�rateur + pour ajouter une forme dans un groupe
	* \param f Pointeur sur la forme � ajouter au groupe
	* \return Groupe Copie du nouveau groupe avec la nouvelle forme ajout�e
	*/
	Groupe operator + (Forme * f)const;

	/**
	* \brief Supprime une forme du groupe
	* \param indice Indice de la forme � supprimer
	*/
	void supprimer(const int indice);

	/**
	* \brief R�cup�re l'aire totale de toutes les formes du groupe
	* \return R�el Somme de l'aire de toutes les formes du groupe
	*/
	const double getAire() const;

	/**
	* \brief Clone un groupe
	* \return Forme* Pointeur sur le groupe clon�
	*/
	Forme * clone() const;

	/**
	* \brief Effectue une homoth�tie directement sur le groupe
	* \param vectHomothetie Vecteur2D
	* \param k R�el
	*/
	void homothetie(const  Vecteur2D & vectHomotethie, double k);

	/**
	* \brief Effectue une translation directement sur le groupe
	* \param vectTranslation Vecteur2D
	*/
	void translation(const Vecteur2D & vectTranslation);

	/**
	* \brief Effectue une rotation directement sur le groupe
	* \param vectCentre Vecteur2D
	* \param angle R�el
	*/
	void rotation(const  Vecteur2D & vectCentre, double angle);

	/**
	* \brief Affiche les valeurs d'un groupe
	* \param flux Flux de sortie
	* \return ostream FLux de sortie
	*/
	ostream & print(ostream & flux) const;
};