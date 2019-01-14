#include "Exception.h"
#include "Vecteur2D.h"
#include "Constantes.h"
#include "Couleur.h"
#include "Segment.h"
#include "Cercle.h"
#include "Triangle.h"
#include "Polygone.h"
#include "Groupe.h"
int main(int argc, char** argv) {
	//Teste classe Vecteur2D
	cout << "essai des vecteurs 2D \n";

	Vecteur2D u1(2, 3), u2(2, 3), v(5), w(1), u3(3, 4), u4(3, -4), u5;

	cout << " u1 = " << u1 << endl;
	cout << " u2 = " << u2 << endl;
	cout << " u1 - u2 = " << u1 - u2 << endl;
	cout << " 5*u1 = " << 5 * u1 << endl;
	
	w.translation(v);
	cout << " w = " << w << endl;
	w.homothetie(v, 3);
	cout << " w = " << w << endl;
	w.rotation(v, 3.1415);
	cout << " w = " << w << endl << endl << endl;

	//Teste classe Couleur
	cout << "essai des Culeurs" << endl;
	Couleur c1,c2(BLACK), c3("green"), c4(c2);

	cout << " c1 = " << c1 << endl;
	cout << " c2 = " << c2 << endl;
	cout << " c3 = " << c3 << endl;
	cout << " c4 = " << c4 << endl;
	
	try {
		Couleur c5("haha");
		cout << " c5 = " << c4 << endl;
	}
	catch (Exception e) {
		cout << e;
	}

	cout << endl << endl;

	//Teste classe Segment
	cout <<"essai des Segment \n";
	try {
		Segment s1(u1, u1);
		cout << " s1 = " << c1 << endl;
	}
	catch (Exception e) {
		cout << e;
	}

	Vecteur2D v1(0, 1), v2(2, 1), v3 (1,0);
	Segment s2(v2, v3), s3(v1, v2, GREEN), s4(s3);

	
	cout << " s2 = " << s2 << endl;
	cout << " s3 = " << s3 << endl;
	cout << " s4 = " << s4 << endl;

	
	s2.translation(v1);
	cout << " s2 = " << s2 << endl;
	s3.homothetie(v3, 3);
	cout << " s3 = " << s3 << endl;
	s4.rotation(v3, 180);
	cout << " s4 = " << s4 << endl << endl << endl;


	//Teste classe Cercle
	cout << "essai des Cercle \n";
	try {
		Cercle cerc1(v1, 0);
		cout << " s1 = " << c1 << endl;
	}
	catch (Exception e) {
		cout << e;
	}

	Cercle cerc2(v1, 3), cerc3(v1, 4, GREEN), cerc4(cerc3);


	cout << " cerc2 = " << cerc2 << endl;
	cout << " cerc3 = " << cerc3 << endl;
	cout << " cerc4 = " << cerc4 << endl;


	cerc2.translation(v1);
	cout << " cerc2 = " << cerc2 << endl;
	cerc3.homothetie(v3, 3);
	cout << " cerc3 = " << cerc3 << endl;
	cerc4.rotation(v3, 180);
	cout << " cerc4 = " << cerc4 << endl << endl << endl;

	//Teste classe Triangle
	Triangle t1(Vecteur2D(0, 0), Vecteur2D(1, 1), Vecteur2D(2, 0),BLUE);
	cout << t1 << endl;
	cout << "Aire:" << t1.getAire() << endl;
	
	try
	{
		Triangle t2(Vecteur2D(0, 0), Vecteur2D(1, 1), Vecteur2D(2, 2), BLUE);
		cout << t2 << endl;
	}
	catch (Exception  e)
	{
		cout << e.getMessage();
	}
	

	cout << endl << endl;
	// Teste classe polygone
	Polygone p1(Vecteur2D(1, 1), Vecteur2D(1, 2), Vecteur2D(2, 2));
	cout << p1 << endl;
	cout << "Aire:" << p1.getAire() << endl;

	p1 = p1 + Vecteur2D(2, 1);
	cout << p1 << endl;
	cout << "Aire:" << p1.getAire() << endl;

	try
	{
		p1 = p1 + Vecteur2D(2, 1);
		cout << p1 << endl;
		cout << "Aire:" << p1.getAire() << endl;
	}
	catch (Exception e)
	{
		cout << e;
	}

	cout << endl << endl;
	// Teste classe polygone
	Groupe g1(RED);
	Forme *cerc5 = new Cercle(Vecteur2D(53,54),35,BLUE);
	Forme *s6 = new Segment(Vecteur2D(45,63),  Vecteur2D(66,95), BLUE);
	Forme *t6 = new Triangle(Vecteur2D(63,174),Vecteur2D(131,154),Vecteur2D(98,95),YELLOW);
	Forme *s7 = new Segment(Vecteur2D(45,83),  Vecteur2D(96,55));
	Forme *t7 = new Triangle(Vecteur2D(113,214),Vecteur2D(141,164),Vecteur2D(118,115),GREEN);
	cout << *cerc5 << endl;
	g1 = g1 + cerc5;
	cout << g1 << endl;
	Groupe g2(BLACK);
	g2 = g2 + s6 + t6;
	g1 = g1 + &g2;
	cout << g1 << endl;
	try{

		g2 = g2 + t6;
		cout << g2 << endl;
	}

	catch (Exception e)
	{
		cout << e << endl;
	}


	system("pause");
	return 0;
}