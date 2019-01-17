#include "Exception.h"
#include "Vecteur2D.h"
#include "Constantes.h"
#include "Couleur.h"
#include "Segment.h"
#include "Cercle.h"
#include "Triangle.h"
#include "Polygone.h"
#include "Groupe.h"
#include "VisiteurSauvTXT.h"
#include "VisiteurDessin.h"
#include "COR.h"
int main(int argc, char** argv) {
	cout << "=====================================================" << endl;
	cout << "|  Bienvenue sur l'application de dessin de formes  |" << endl;
	cout << "=====================================================" << endl << endl;
	cout << "\"Pas de menu, les tests se feront directement dans le fichier main.cpp\"" << endl << endl;

	//Test Cercle
	cout << "=====================================================" << endl;
	cout << "|            Test de dessin d'un cercle             |" << endl;
	cout << "=====================================================" << endl << endl;

	Cercle c(Vecteur2D(200, 500), 90,Couleur(BLUE));
	cout << "Affichage du cercle :" << endl << c << endl << endl;
	cout << "Dessin du Cercle :" << endl;
	c.dessiner(new VisiteurDessin);

	//Test Segment
	cout << "=====================================================" << endl;
	cout << "|            Test de dessin d'un Segment            |" << endl;
	cout << "=====================================================" << endl << endl;

	Segment s(Vecteur2D(50, 40), Vecteur2D(30, 90),Couleur(RED));
	cout << "Affichage du Segment :" << endl << s << endl << endl;
	cout << "Dessin du Segment :" << endl;
	s.dessiner(new VisiteurDessin);

	//Test triangle
	cout << "=====================================================" << endl;
	cout << "|            Test de dessin d'un Triangle            |" << endl;
	cout << "=====================================================" << endl << endl;

	Triangle t(Vecteur2D(200, 100), Vecteur2D(150, 190), Vecteur2D(250, 200), Couleur(BLUE));
	cout << "Affichage du Triangle :" << endl << t << endl << endl;
	cout << "Dessin du Triangle :" << endl;
	t.dessiner(new VisiteurDessin);

	//Test Polygone
	cout << "=====================================================" << endl;
	cout << "|            Test de dessin d'un Polygone           |" << endl;
	cout << "=====================================================" << endl << endl;

	Polygone p(Vecteur2D(30, 40), Vecteur2D(90, 114), Vecteur2D(80, 55), Couleur(YELLOW));
	p = p + Vecteur2D(75, 120) + Vecteur2D(49, 67);
	cout << "Affichage du Polygone :" << endl << p << endl << endl;
	cout << "Dessin du Polygone :" << endl;
	p.dessiner(new VisiteurDessin);
	
	//Test Groupe
	cout << "=====================================================" << endl;
	cout << "|             Test de dessin d'un Groupe            |" << endl;
	cout << "=====================================================" << endl << endl;
	
	Groupe g(GREEN);
	g = g + &c + &s + &t + &p;
	cout << "Affichage du Groupe :" << endl << g << endl << endl;
	cout << "Dessin du Groupe :" << endl;
	g.dessiner(new VisiteurDessin);
	
	system("pause");
	return 0;
}