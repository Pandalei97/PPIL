#pragma once

#include <iostream>
#include <vector>
#include <sstream>
#include "Constantes.h"
#include "Exception.h"
using namespace std;

class Couleur {
	static vector<string> InitTabCouleur() {
		vector<string> v;
		v.push_back(DEFAULT);
		v.push_back(BLACK);
		v.push_back(BLUE);
		v.push_back(RED);
		v.push_back(GREEN);
		v.push_back(YELLOW);
		v.push_back(CYAN);
		return v;
	}

	static vector<string> tab_couleur;
	string m_couleur;

public:
	Couleur();
	Couleur(const string & couleur);
	Couleur(const Couleur & couleur);
	virtual ~Couleur();

	//Si une couleur existe
	bool contains(string couleur);

	const string & getCouleur() const;
	void setCouleur(const string & couleur);

	operator string() const;
	bool operator==(const  Couleur &objet) const;
	bool operator != (const Couleur &objet) const;
	const Couleur operator = (const Couleur&);
	friend ostream & operator << (ostream & flux, const Couleur& coul);
};
