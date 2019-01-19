#include <string>
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
	cout << "             Test des Vecteurs			              " << endl;
	cout << "=====================================================" << endl << endl;

	Vecteur2D v1(2, 3), v2(5);
	cout << "Affichage d'un vecteur v1 : " << v1 << endl;
	cout << "Affichage d'un vecteur v2 : " << v2 << endl;
	cout << "v2 - v1 = " << v2 - v1 << endl;
	cout << "5 * v1 = " << 5 * v1 << endl;
	cout << " -v1 = " << -v1 << endl;
	cout << "Determinant de v1 et v2 :" << v1.determinant(v2) << endl << endl;

	//On crée des copies pour garder v1 intact pour faciliter la verification de resultat
	Vecteur2D vh(v1), vt(v1), vr(v1);
	vh.homothetie(v2, 5);
	cout << "Affichage de l'homothetie de v1 par rapport a v2 avec un ordre de grandeur de 5:" << endl << vh << endl << endl;

	vt.translation(v2);
	cout << "Affichage de la translation de v1 par rapport a v2:" << endl << vt << endl << endl;

	vr.rotation(v2, PI / 4);
	cout << "Affichage de la rotation de v1 a PI/4 dans le sens trigonometrique par rapport a v2:" << endl << vr << endl << endl;


	system("pause");
	cout << endl;

	cout << "=====================================================" << endl;
	cout << "             Test des Couleurs			              " << endl;
	cout << "=====================================================" << endl << endl;


	Couleur *coulDef = new Couleur();
	cout << "Affichage de la couleur par defaut: " << *coulDef << endl << endl;

	Couleur coulRed(RED);
	cout << "Affichage de la couleur rouge: " << coulRed << endl << endl;

	Couleur coulCopie(*coulDef);
	cout << "Affichage de la copie de la couleur par defaut: " << coulCopie << endl << endl;

	cout << "Test sur une couleur qui n'existe pas:" << endl;
	try {
		Couleur coulEx("what");
		cout << "Affichage de la couleur qui n'existe pas:" << endl << endl;
	}
	catch (Exception e) {
		cout << e << endl << endl;
	}

	system("pause");
	cout << endl;

	cout << "=====================================================" << endl;
	cout << "             Test des Cercles			              " << endl;
	cout << "=====================================================" << endl << endl;

	Cercle c(Vecteur2D(250, 250), 100, Couleur(BLUE));

	Cercle ch = c, ct = c, cr = c;

	cout << "Affichage du cercle:" << endl << c << endl << endl;
	ch.homothetie(v2, 5);
	cout << "Affichage de l'homothetie du cercle par rapport a v2 avec un ordre de grandeur de 5:" << endl << ch << endl << endl;

	ct.translation(v2);
	cout << "Affichage de la translation du cercle par rapport a v2:" << endl << ct << endl << endl;

	cr.rotation(v2, PI / 4);
	cout << "Affichage de la rotation du cercle a PI/4 dans le sens trigonometrique par rapport a v2:" << endl << cr << endl << endl;


	system("pause");
	cout << endl;

	cout << "=====================================================" << endl;
	cout << "             Test des Segments				          " << endl;
	cout << "=====================================================" << endl << endl;

	Segment s(Vecteur2D(350, 30), Vecteur2D(490, 190), Couleur(RED));
	cout << "Affichage du Segment :" << endl << s << endl << endl;

	cout << "Test d'un segment avec (1,1), (1,1) comme PO et PE: " << endl;
	try {
		Segment sEx(Vecteur2D(1, 1), Vecteur2D(1, 1));
		cout << "Affichage du Segment avec 2 points identiques:" << endl << sEx << endl << endl;
	}
	catch (Exception e) {
		cout << e << endl << endl;
	}

	Segment sh = s, st = s, sr = s;
	sh.homothetie(v2, 5);
	cout << "Affichage de l'homothetie du segment par rapport a v2 avec un ordre de grandeur de 5:" << endl << sh << endl << endl;

	st.translation(v2);
	cout << "Affichage de la translation du segment par rapport a v2:" << endl << st << endl << endl;

	sr.rotation(v2, PI / 4);
	cout << "Affichage de la rotation du segment a PI/4 dans le sens trigonometrique par rapport a v2:" << endl << sr << endl << endl;

	system("pause");
	cout << endl;

	cout << "=====================================================" << endl;
	cout << "             Test des Triangles			          " << endl;
	cout << "=====================================================" << endl << endl;


	Triangle t(Vecteur2D(250, 400), Vecteur2D(200, 500), Vecteur2D(300, 500), Couleur(BLUE));
	cout << "Affichage du Triangle :" << endl << t << endl << endl;

	cout << "Test d'un triangle avec (1,1), (2,2), (3,3) comme des points: " << endl;
	try {
		Triangle tEx(Vecteur2D(1, 1), Vecteur2D(2, 2), Vecteur2D(3, 3));
		cout << "Affichage du triangle avec les points allignés:" << endl << tEx << endl << endl;
	}
	catch (Exception e) {
		cout << e << endl << endl;
	}

	Triangle th = t, tt = t, tr = t;
	th.homothetie(v2, 5);
	cout << "Affichage de l'homothetie du triangle par rapport a v2 avec un ordre de grandeur de 5:" << endl << th << endl << endl;

	tt.translation(v2);
	cout << "Affichage de la translation du triangle par rapport a v2:" << endl << tt << endl << endl;

	tr.rotation(v2, PI / 4);
	cout << "Affichage de la rotation du triangle a PI/4 dans le sens trigonometrique par rapport a v2:" << endl << tr << endl << endl;

	system("pause");
	cout << endl;

	cout << "=====================================================" << endl;
	cout << "             Test des Polygones					  " << endl;
	cout << "=====================================================" << endl << endl;

	Polygone p(Vecteur2D(350, 400), Vecteur2D(450, 400), Vecteur2D(550, 500), Couleur(BLACK));
	cout << "Affichage du Polygone :" << endl << p << endl << endl;

	p = p + Vecteur2D(450, 600) + Vecteur2D(350, 600);
	cout << "Affichage du Polygone avec (450,600) et (350, 600) en plus:" << endl << p << endl << endl;

	cout << "Test d'ajout de (450,600) dans le polygone (qui existe deja)" << endl;
	try {
		p = p + Vecteur2D(450, 600);
		cout << "Affichage du polygone apres l'ajout d'un point qui existe deja dans le polygone" << endl << endl;
	}
	catch (Exception e) {
		cout << e << endl << endl;
	}

	Polygone ph = p, pt = p, pr = p;
	ph.homothetie(v2, 5);
	cout << "Affichage de l'homothetie du polygone par rapport a v2 avec un ordre de grandeur de 5:" << endl << ph << endl << endl;

	pt.translation(v2);
	cout << "Affichage de la translation du polygone par rapport a v2:" << endl << pt << endl << endl;

	pr.rotation(v2, PI / 4);
	cout << "Affichage de la rotation du polygone a PI/4 dans le sens trigonometrique par rapport a v2:" << endl << pr << endl << endl;


	system("pause");
	cout << endl;

	cout << "=====================================================" << endl;
	cout << "              Test des Groupes						  " << endl;
	cout << "=====================================================" << endl << endl;

	Couleur coul = Couleur(RED);
	Groupe g(coul);
	//Groupe g(RED);  //Fonctionne
	//Groupe g(Couleur(RED)); //Fonctionne pas

	//On fait des copie des formes pour garder les originales intactes
	Cercle cg = Cercle(c);
	Segment sg = Segment(s);
	Triangle tg = Triangle(t);
	Polygone pg = Polygone(p);

	g = g + &cg + &sg + &tg + &pg;
	cout << "Affichage du Groupe :" << endl << g << endl << endl;

	cout << "Test d'ajout une forme qui appartient deja dans le groupe" << endl;
	try {
		g = g + &cg;
		cout << "Affichage du Groupe apres l'insertion d'une forme qui est deja marquee:" << endl << g << endl << endl;
	}
	catch (Exception e) {
		cout << e << endl;
	}


	system("pause");
	cout << endl;

	cout << "=====================================================" << endl;
	cout << "              Test des Sauvegardes					  " << endl;
	cout << "=====================================================" << endl << endl;

	int reponse;
	while(true) {
		cout << "Si vou voulez tester ce terme, saisissez 1, sinon saisissez 0:" << endl;
		cin >> reponse;
		if ((reponse != 0 && reponse != 1) || cin.fail()) {
			cout << "Soyez gentil, donenz une reponse correcte." << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		else
			break;
	}
	cout << endl << endl;
	if (reponse == 1) {
		cout << "Test sauvegarde d'un Cercle: " << endl;
		c.accepteSauvegarder(new VisiteurSauvTXT);
		cout << endl << endl;

		cout << "Test sauvegarde d'un Segment: " << endl;
		s.accepteSauvegarder(new VisiteurSauvTXT);
		cout << endl << endl;

		cout << "Test sauvegarde d'un Triangle: " << endl;
		t.accepteSauvegarder(new VisiteurSauvTXT);
		cout << endl << endl;

		cout << "Test sauvegarde d'un Polygone: " << endl;
		p.accepteSauvegarder(new VisiteurSauvTXT);
		cout << endl << endl;

		cout << "Test sauvegarde d'un Groupe: " << endl;
		g.accepteSauvegarder(new VisiteurSauvTXT);
		cout << endl << endl;
	}

	system("pause");
	cout << endl;

	cout << "=====================================================" << endl;
	cout << "              Test des Chargements					  " << endl;
	cout << "=====================================================" << endl << endl;


	while (true) {
		cout << "Si vou voulez tester ce terme, saisissez 1, sinon saisissez 0:" << endl;
		cin >> reponse;
		if ((reponse != 0 && reponse != 1) || cin.fail()) {
			cout << "Soyez gentil, donenz une reponse correcte." << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		else
			break;
	}

	cout << endl << endl;
	if (reponse == 1) {
		cout << "Pour mieux visualiser le resultat, veuillez donner un id qui correspond au type de forme demande, vous pouvez tester avec les id qui n'existe pas." << endl;
		cout << "Pour l'info, ces id suivants sont pre-engistres dans le fichier: " << endl;
		cout << "MonC, MonS, MonT, MonP, MonG" << endl << endl;

		COR * cor = COR::getInstance();
		ChargerForme *chargeurForme = cor->getChargeurForme();
		Forme* forme = NULL;
		string idForme;

		//Cercle
		cout << "Charger un Cercle:" << endl;
		do {
			
			while (true) {
				cout << "Donenz l'id de la forme: " << endl;
				cin >> idForme;
				if (cin.fail()) {
					cout << "Soyez gentil, donenz une reponse correcte." << endl;
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
				else
					break;
			};
			forme = chargeurForme->charger(idForme);
			if (forme == NULL)
				cout << "Cet id n'existe pas!" << endl;
		} while (forme == NULL);
		cout << "Affichage de Cercle chargee depuis le fichier: " << endl;
		cout << (*forme) << endl << endl;
		forme = NULL;

		//Segment
		cout << "Charger un Segment:" << endl;
		do {
			while (true) {
				cout << "Donenz l'id de la forme: " << endl;
				cin >> idForme;
				if (cin.fail()) {
					cout << "Soyez gentil, donenz une reponse correcte." << endl;
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
				else
					break;
			};
			forme = chargeurForme->charger(idForme);
			if (forme == NULL)
				cout << "Cet id n'existe pas!" << endl;
		} while (forme == NULL);
		cout << "Affichage de Segment chargee depuis le fichier: " << endl;
		cout << (*forme) << endl << endl;
		forme = NULL;

		//Triangle
		cout << "Charger un Triangle:" << endl;
		do {
			while (true) {
				cout << "Donenz l'id de la forme: " << endl;
				cin >> idForme;
				if (cin.fail()) {
					cout << "Soyez gentil, donenz une reponse correcte." << endl;
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
				else
					break;
			};

			forme = chargeurForme->charger(idForme);
			if (forme == NULL)
				cout << "Cet id n'existe pas!" << endl;
		} while (forme == NULL);
		cout << "Affichage de Triangle chargee depuis le fichier: " << endl;
		cout << (*forme) << endl << endl;
		forme = NULL;

		//Polygone
		cout << "Charger un Polygone:" << endl;
		do {
			while (true) {
				cout << "Donenz l'id de la forme: " << endl;
				cin >> idForme;
				if (cin.fail()) {
					cout << "Soyez gentil, donenz une reponse correcte." << endl;
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
				else
					break;
			};
			forme = chargeurForme->charger(idForme);
			if (forme == NULL)
				cout << "Cet id n'existe pas!" << endl;
		} while (forme == NULL);
		cout << "Affichage de Polygone chargee depuis le fichier: " << endl;
		cout << (*forme) << endl << endl;
		forme = NULL;

		cout << "Charger un Groupe:" << endl;
		do {
			while (true) {
				cout << "Donenz l'id de la forme: " << endl;
				cin >> idForme;
				if (cin.fail()) {
					cout << "Soyez gentil, donenz une reponse correcte." << endl;
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
				else
					break;
			};
			forme = chargeurForme->charger(idForme);
			if (forme == NULL)
				cout << "Cet id n'existe pas!" << endl;
		} while (forme == NULL);
		cout << "Affichage de Groupe chargee depuis le fichier: " << endl;
		cout << (*forme) << endl;
		forme = NULL;
	}
	
	system("pause");
	cout << endl;

	cout << "=====================================================" << endl;
	cout << "              Test des Dessins						  " << endl;
	cout << "=====================================================" << endl << endl;
	while (true) {
		cout << "Si vou voulez tester ce terme, saisissez 1, sinon saisissez 0:" << endl;
		cin >> reponse;
		if ((reponse != 0 && reponse != 1) || cin.fail()) {
			cout << "Soyez gentil, donenz une reponse correcte." << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		else
			break;
	}
	cout << endl << endl;

	if (reponse == 1) {
		cout << "Dessin du Cercle :" << endl;
		c.dessiner(new VisiteurDessin);

		cout << endl << endl;

		cout << "Dessin du Segment :" << endl;
		s.dessiner(new VisiteurDessin);

		cout << endl << endl;

		cout << "Dessin du Triangle :" << endl;
		t.dessiner(new VisiteurDessin);

		cout << endl << endl;

		cout << "Dessin du Polygone :" << endl;
		p.dessiner(new VisiteurDessin);

		cout << endl << endl;

		cout << "Dessin du Groupe :" << endl;
		g.dessiner(new VisiteurDessin);
	}
	system("pause");

	return 0;
}