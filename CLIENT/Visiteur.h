#pragma once
#include "Segment.h"
#include "Cercle.h"
#include "Triangle.h"
#include "Polygone.h"
#include "Groupe.h"

class Visiteur {
public:
	virtual void visite(const Segment* s) const = 0;
	virtual void visite(const Cercle* c) const = 0;
	virtual void visite(const Triangle* t) const = 0;
	virtual void visite(const Polygone* s) const = 0;
	virtual void visite(const Groupe* g) const = 0;
};

