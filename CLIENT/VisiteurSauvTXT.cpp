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
	} while (idExiste(id) || !idValide(id));
	return id;
}
bool VisiteurSauvTXT::idExiste(const string& id)const {
	ifstream fichier(m_chemin, ios::in);
	string ligne;
	string idForme;
	while (getline(fichier, ligne)) {
		idForme = ligne.substr(0, ligne.find('-'));
		if (id == idForme) {
			cout << "Le nom " << id <<" existe deja" << endl;
			return true;
		}
	}
	return false;
}

bool VisiteurSauvTXT::idValide(const string& id)const {
	return ((id.find('-') == -1) && (id.find(':') == -1) && (id.find(';') == -1) && (id.find('&') == -1));
}

void VisiteurSauvTXT::sauvegarde(const string& ligne, const string& chemin)const{
	ofstream fichier(chemin, ios::app);
	fichier << ligne;
	fichier.close();
}


void VisiteurSauvTXT::visite(const Segment* s) const {
	//En gros il s'agit de réecrire un string qui conforme à notre fichier .txt 
	//Comme ça peu importe ce que j'ai écrit dans l'opérator string dans la classe Segment,
	//on peut tjrs obtenir mettre le bon texte dans le fichier txt
	//Donc cette méthode visite(const Segment* s) est un peu comme un autre méthode "toString"
	//qui transforme un objet en une chaine formaté et elle est indépendante de l'opérator string() dans la classe
	ostringstream oss;
	
	//si la forme est juste un composant d'un groupe, on demande pas à l'utilisateur de donner un id;
	if (!s->estMarquee())
		oss << creerId();

	oss << "-Segment:" << s->getCouleur() << ";" << s->getPO() << ";" << s->getPE() << ";";

	//si la forme est juste un composant d'un groupe,on ajoutera pas le saute ligne;
	if (!s->estMarquee())
		oss << endl;

	string ligne = oss.str();
	//On supprime les espaces potentiels dans le message
	ligne.erase(remove(ligne.begin(), ligne.end(), ' '), ligne.end());
	sauvegarde(ligne,m_chemin);
}
void VisiteurSauvTXT::visite(const Cercle* c) const {
	ostringstream oss;
	if (!c->estMarquee())
		oss << creerId();

	oss << "-Cercle:" << c->getCouleur() << ";" << c->getCentre() << ";" << c->getRayon() << ";";

	if (!c->estMarquee())
		oss << endl;
	string ligne = oss.str();
	//On supprime les espaces potentiels dans le message
	ligne.erase(remove(ligne.begin(), ligne.end(), ' '), ligne.end());
	sauvegarde(ligne, m_chemin);
}
void VisiteurSauvTXT::visite(const Triangle* t) const {
	ostringstream oss;
	if (!t->estMarquee())
		oss << creerId();

	oss << "-Triangle:" << t->getCouleur() << ";" << t->getP1() << ";" << t->getP2() << ";" << t->getP3() << ";";

	if (!t->estMarquee())
		oss << endl;

	string ligne = oss.str();
	//On supprime les espaces potentiels dans le message
	ligne.erase(remove(ligne.begin(), ligne.end(), ' '), ligne.end());
	sauvegarde(ligne, m_chemin);
}
void VisiteurSauvTXT::visite(const Polygone* p) const {
	ostringstream oss;
	if (!p->estMarquee())
		oss << creerId();

	oss << "-Polygone:" << p->getCouleur() << ";";
	for (int i = 0; i < p->getNbPoints(); i++){
		oss << (*p)[i] << ";";
	}

	if (!p->estMarquee())
		oss << endl;
	string ligne = oss.str();
	//On supprimes les espaces potentiels dans le message
	ligne.erase(remove(ligne.begin(), ligne.end(), ' '), ligne.end());
	sauvegarde(ligne, m_chemin);
}
void VisiteurSauvTXT::visite(const Groupe* g) const {
	ostringstream oss;
	if (!g->estMarquee())
		oss << creerId();
	oss << "-Groupe:" << g->getCouleur() << ";";
	sauvegarde(oss.str(), m_chemin);
	
	for (int i = 0; i < g->getNbFormes(); i++) {
		(*g)[i]->accepteSauvegarder(this);
		//on écrit un séparateur pour séparer les formes du groupe
		sauvegarde("&", m_chemin);
	}
	
	if (!g->estMarquee())
		sauvegarde("\n", m_chemin);
}