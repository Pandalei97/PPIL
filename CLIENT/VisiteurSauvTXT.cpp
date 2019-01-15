#include <fstream>
#include <string>
#include <algorithm>
#include <ctype.h>
#include "VisiteurSauvTXT.h"
#include "Constantes.h"


using namespace std;

const string VisiteurSauvTXT::m_chemin = CHEMIN;

string VisiteurSauvTXT::creerId()const{
	string id;
	do {
		cout << "Quel nom voulez-vous donner a la forme ?" << endl;
		cin >> id;
	} while (idExiste(id));
	return id;
}
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

void VisiteurSauvTXT::sauvgarde(const string& ligne, const string& chemin)const{
	ofstream fichier(chemin, ios::app);
	fichier << ligne << endl;
	fichier.close();
}


void VisiteurSauvTXT::visite(const Segment* s) const {
	//En gros il s'agit de réecrire un string qui conforme à notre fichier .txt 
	//Comme ça peu importe ce que j'ai écrit dans l'opérator string dans la classe Segment,
	//on peut tjrs obtenir mettre le bon texte dans le fichier txt
	//Donc cette méthode visite(const Segment* s) est un peu comme un autre méthode "toString"
	//qui transforme un objet en une chaine formaté et elle est indépendante de l'opérator string() dans la classe
	ostringstream ligne;
	ligne << creerId() << "-Segment:" << s->getCouleur() << ";" << s->getPO() << ";" << s->getPE();
	sauvgarde(ligne.str(),m_chemin);
}
void VisiteurSauvTXT::visite(const Cercle* c) const {
	
}
void VisiteurSauvTXT::visite(const Triangle* t) const {

}
void VisiteurSauvTXT::visite(const Polygone* s) const {

}
void VisiteurSauvTXT::visite(const Groupe* g) const {
	string res;
	/*
		foreach forme in g->m_tabFormes{
			res += visite(forme);
		}
	*/
	sauvgarde(res,m_chemin);
	

}