/**
* \file Visiteur.h
* \brief Classe visiteur qui va appeler les bonnes méthodes en fonction de la forme
*/
#pragma once
#include "Segment.h"
#include "Cercle.h"
#include "Triangle.h"
#include "Polygone.h"
#include "Groupe.h"

class Visiteur {
public:
	/**
	* \brief Méthode virtuelle pure, va être appelée par un segment
	*/
	virtual void visite(const Segment* s) const = 0;

	/**
	* \brief Méthode virtuelle pure, va être appelée par un cercle
	*/
	virtual void visite(const Cercle* c) const = 0;

	/**
	* \brief Méthode virtuelle pure, va être appelée par un triangle
	*/
	virtual void visite(const Triangle* t) const = 0;

	/**
	* \brief Méthode virtuelle pure, va être appelée par un polygone
	*/
	virtual void visite(const Polygone* s) const = 0;

	/**
	* \brief Méthode virtuelle pure, va être appelée par un groupe
	*/
	virtual void visite(const Groupe* g) const = 0;
};

