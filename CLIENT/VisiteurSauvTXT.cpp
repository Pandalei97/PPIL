#include <fstream>
#include <string>
#include <algorithm>
#include <ctype.h>
#include "VisiteurSauvTXT.h"
#include "Constantes.h"


using namespace std;

const string VisiteurSauvTXT::m_chemin = CHEMIN;

bool VisiteurSauvTXT::idExiste(const string& id)const {
	ifstream fichier(m_chemin, ios::in);
	string ligne;
	string idForme;
	while (getline(fichier, ligne)) {
		idForme = ligne.substr(0, ligne.find('-'));
		if (id == idForme) {
			cout << "Le nom" << id <<"existe deja" << endl;
			return true;
		}
	}
	return false;
}

bool VisiteurSauvTXT::idValide(const string& id)const {
	return ((id.find('-') == -1) && (id.find(':') == -1) && (id.find(';') == -1) && (id.find('&') == -1));
}

void VisiteurSauvTXT::visite(const Segment* s) const {
	string id;
	do {
		cout << "Quel nom voulez-vous donner a la forme ?" << endl;
		cin >> id;
	} while (idExiste(id));

	ofstream fichier(m_chemin, ios::app);
	/*on sauvegarde la forme avec son nom un & et la transofrmation
	l'operateur string de la forme*/
	string ligne = (string)(*s);

	//On supprimes les espaces potentiels dans le message
	remove_if(ligne.begin(), ligne.end(), isspace);
	fichier << id + "-" << ligne << endl;
	fichier.close();
}
void VisiteurSauvTXT::visite(const Cercle* c) const {

}
void VisiteurSauvTXT::visite(const Triangle* t) const {

}
void VisiteurSauvTXT::visite(const Polygone* s) const {

}
void VisiteurSauvTXT::visite(const Groupe* g) const {

}