#include "VisiteurDessin.h"
#include "SingletonConnexion.h"
#undef max

bool VisiteurDessin::titreValide(const string& id)const {
	if ((id.find('-') == -1) && (id.find(':') == -1) &&
		(id.find(';') == -1) && (id.find('&') == -1) &&
		(id.find('(') == -1) && (id.find(')') == -1) &&
		(id.find(',') == -1) && (id.find('$') == -1))
		return true;

	cout << "nom de la fenetre non valide, car il contient des caracteres non autorises" << endl;
	return false;
}
void VisiteurDessin::InitInfoFenetre(string &titreFenetre, int &largeur, int &hauteur)const{
	do{
		cout << "Donner un titre pour la fenetre : " << endl;
		cin >> titreFenetre;
	}while(!titreValide(titreFenetre));

	while (true) {
		cout << "Donner un entier pour la largeur de la fenetre, tapez 0 pour la largeur par default : " << endl;
		cin >> largeur;
		if (cin.fail() || largeur < 0) {
			cout << "Soyez gentil, donenz une reponse correcte." << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		else
			break;
	}

	if (largeur == 0)
		largeur = LARGEUR;

	while (true) {
		cout << "Donner un entier pour la hauteur de la fenetre, tapez 0 pour la largeur par default : " << endl;
		cin >> hauteur;
		if (cin.fail() || hauteur < 0) {
			cout << "Soyez gentil, donenz une reponse correcte." << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		else
			break;
	}
	if (hauteur == 0)
		hauteur = HAUTEUR;
	
}
const string VisiteurDessin::RequeteOuvertureFenetre(const string& titreFenetre, const int largeur, const int hauteur) const{
	return "F$" + titreFenetre + ";" + std::to_string(largeur) + ";" + std::to_string(hauteur) + ";";
}

void VisiteurDessin::ouvrirFenetre()const {
	//Initialisation des params d'une fenetre
	string titreFenetre;
	int largeur, hauteur;
	InitInfoFenetre(titreFenetre, largeur, hauteur);
	//Envoyer la requete pour ouvrir une fenetre
	SingletonConnexion::getInstance()->envoyerRequete(RequeteOuvertureFenetre(titreFenetre, largeur, hauteur));
	cout << "Requete ouverture de fenetre envoyee" << endl;
	cout << "Attente de la reponse du serveur..." << endl;
	if (SingletonConnexion::getInstance()->serveurATraiteRequete())
		cout << "La fenetre est ouverte" << endl;
	else
		cout << "Le serveur n'a pas ouvert la fenetre" << endl;
}
void VisiteurDessin::demandeDessiner(const string& infoForme, bool estMarquee)const {
	try {
		if (!estMarquee)
			ouvrirFenetre();

		SingletonConnexion::getInstance()->envoyerRequete(infoForme);
		cout << "Requete de dessin envoyee" << endl;
		cout << "Attente de la reponse du serveur..." << endl;
		/*Attendre de la reponse du serveur pour savoir s'il a dessiner
		avant de fermer la connexion*/
		if (SingletonConnexion::getInstance()->serveurATraiteRequete())
			cout << "Le serveur a traite la requete : la forme a ete dessinee" << endl;
		else {
			cout << "Le serveur n'a pas dessiner la forme" << endl;
			cout << "Car il ne l'a pas reconnue" << endl;
		}
		
	}
	catch (Exception e) {
		cerr << e << endl;
	}
}
void VisiteurDessin::visite(const Segment* s) const {
	ostringstream infoForme;
	infoForme << "D$" <<"Segment:" << s->getCouleur() << ";" << s->getPO() << ";" << s->getPE() << ";";

	try {
		//Connexion si la forme est indépendante
		if(!s->estMarquee())
			SingletonConnexion::getInstance()->initialiserConnexion();
		
		demandeDessiner(infoForme.str(), s->estMarquee());

		//Donnexion si la forme est indépendante
		if (!s->estMarquee()) {
			SingletonConnexion::getInstance()->fermerConnexion();
			SingletonConnexion::getInstance()->killInstance();
		}
		

	}
	catch (Exception e) {
		cerr << e << endl;
	}
	
}
void VisiteurDessin::visite(const Cercle* c) const {
	ostringstream infoForme;
	infoForme << "D$" << "Cercle:" << c->getCouleur() << ";" << c->getCentre() << ";" << c->getRayon() << ";";

	try {
		//Connexion si la forme est indépendante
		if (!c->estMarquee())
			SingletonConnexion::getInstance()->initialiserConnexion();

		demandeDessiner(infoForme.str(), c->estMarquee());

		//Donnexion si la forme est indépendante
		if (!c->estMarquee()) {
			SingletonConnexion::getInstance()->fermerConnexion();
			SingletonConnexion::getInstance()->killInstance();
		}


	}
	catch (Exception e) {
		cerr << e << endl;
	}
}
void VisiteurDessin::visite(const Triangle* t) const {
	ostringstream infoForme;
	infoForme << "D$" << "Triangle:" << t->getCouleur() << ";" << t->getP1() << ";" << t->getP2() << ";" << t->getP3() << ";";

	try {
		//Connexion si la forme est indépendante
		if (!t->estMarquee())
			SingletonConnexion::getInstance()->initialiserConnexion();

		demandeDessiner(infoForme.str(), t->estMarquee());

		//Donnexion si la forme est indépendante
		if (!t->estMarquee()) {
			SingletonConnexion::getInstance()->fermerConnexion();
			SingletonConnexion::getInstance()->killInstance();
		}
	}
	catch (Exception e) {
		cerr << e << endl;
	}
}
void VisiteurDessin::visite(const Polygone* p) const {
	ostringstream infoForme;
	infoForme << "D$" << "Polygone:" << p->getCouleur() << ";";
	for (int i = 0; i < p->getNbPoints(); i++) {
		infoForme << (*p)[i] << ";";
	}

	try {
		//Connexion si la forme est indépendante
		if (!p->estMarquee())
			SingletonConnexion::getInstance()->initialiserConnexion();

		demandeDessiner(infoForme.str(), p->estMarquee());

		//Donnexion si la forme est indépendante
		if (!p->estMarquee()) {
			SingletonConnexion::getInstance()->fermerConnexion();
			SingletonConnexion::getInstance()->killInstance();
		}
	}
	catch (Exception e) {
		cerr << e << endl;
	}
}
void VisiteurDessin::visite(const Groupe* g) const {
	ostringstream infoForme;
	

	try {
		//Connexion si la forme est indépendante
		if (!g->estMarquee()) {
			SingletonConnexion::getInstance()->initialiserConnexion();
			ouvrirFenetre();
		}
			

		for (int i = 0; i < g->getNbFormes(); i++) {
			(*g)[i]->dessiner(this);
		}

		//Donnexion si la forme est indépendante
		if (!g->estMarquee()) {
			SingletonConnexion::getInstance()->fermerConnexion();
			SingletonConnexion::getInstance()->killInstance();
		}
	}
	catch (Exception e) {
		cerr << e << endl;
	}
}