/**
* \file Groupe.h
* \brief Classe groupe qui représente un groupe de formes
*/
#pragma once
#include "Forme.h"
#include <vector>

class Groupe :public Forme {
	vector<Forme *> m_tabFormes;

public:

	/**
	* \brief Constructeur par défaut d'un groupe (vide)
	*/
	Groupe();

	/**
	* \brief Constructeur à partir d'une couleur
	* \param coul Couleur
	*/
	Groupe(const Couleur &coul);

	/**
	* \brief Constructeur dpar recopie d'un groupe
	* \param groupe Groupe à recopier
	*/
	Groupe(const Groupe & groupe);

	/**
	* \brief Destructeur
	*/
	~Groupe();

	/**
	* \brief Getter pour récupérer le nombre de formes du groupe
	* \return int Nombre de formes du groupe
	*/
	int getNbFormes() const;

	/**
	* \brief Setter pour modifier la couleur du groupe
	* \param couleur Chaine de caractères correspondant à la couleur
	*/
	void setCouleur(const string& couleur);

	/**
	* \brief Surcharge de string pour convertir un groupe en chaine de caractères
	*/
	operator string() const;

	/**
	* \brief Surcharge de l'opérateur == qui teste si deux groupes sont identiques
	* \param obj Groupe à comparer
	* \return bool Booléen vrai si les deux groupes sont identiques, faux sinon
	*/
	bool operator==(const  Groupe &obj) const;

	/**
	* \brief Surcharge de l'opérateur !=, qui utilise ==
	* \param obj Groupe à comparer
	* \return bool Booléen vrai si les deux groupes sont différents, faux sinon
	*/
	bool operator != (const Groupe &obj) const;

	/**
	* \brief Surcharge de l'opérateur =, pour affecter les valeurs d'un groupe à un autre
	* \param obj Objet à copier
	* \return obj La resultante de l'affectation du groupe
	*/
	const Groupe & operator = (const Groupe &obj);

	/**
	* \brief Surcharge de l'opérateur [] qui permet d'accéder à une forme d'un groupe
	* \param indice Indice de la forme à récupérer
	* \returnForme* Un pointeur sur la forme se trouvant à l'indice donné en paramètre
	*/
	Forme * operator[] (const int indice)const;

	/**
	* \brief Surcharge de l'opérateur + pour ajouter une forme dans un groupe
	* \param f Pointeur sur la forme à ajouter au groupe
	* \return Groupe Copie du nouveau groupe avec la nouvelle forme ajoutée
	*/
	Groupe operator + (Forme * f)const;

	/**
	* \brief Supprime une forme du groupe
	* \param indice Indice de la forme à supprimer
	*/
	void supprimer(const int indice);

	/**
	* \brief Récupère l'aire totale de toutes les formes du groupe
	* \return Réel Somme de l'aire de toutes les formes du groupe
	*/
	const double getAire() const;

	/**
	* \brief Clone un groupe
	* \return Forme* Pointeur sur le groupe cloné
	*/
	Forme * clone() const;

	/**
	* \brief Effectue une homothétie directement sur le groupe
	* \param vectHomothetie Vecteur2D
	* \param k Réel
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
	* \param angle Réel
	*/
	void rotation(const  Vecteur2D & vectCentre, double angle);

	/**
	* \brief Affiche les valeurs d'un groupe
	* \param flux Flux de sortie
	* \return ostream FLux de sortie
	*/
	ostream & print(ostream & flux) const;
};