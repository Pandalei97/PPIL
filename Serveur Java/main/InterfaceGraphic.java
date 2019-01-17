package main;

import java.awt.Color;

// l'objetAwtFenetre va impl�menter ces m�thodes

/**
 * 
 * Interface qui va nous permettre de sp�cifier
 * � notre objetAwt d'impl�menter ces m�thodes
 *
 */
public interface InterfaceGraphic {
	/**
	 * M�thode permettant de cr�er une fen�tre
	 * @param titre
	 * 		le titre de la fen�tre
	 * @param largeur
	 * 		La largeur de la fen�tre
	 * @param hauteur
	 * 		La hauteur de la fen�tre
	 */
	void creerFenetre(String titre, int largeur, int hauteur);
	/**
	 * M�thode permettant de dessiner un cercle
	 * sur la fen�tre cr��e avec l'objet JFRAME.
	 * @param x
	 * 		l'abscisse du centre
	 * @param y
	 * 		l'ordonn�e du centre
	 * @param rayon
	 * 		le rayon du cercle
	 * @param color
	 * 		la couleur de la forme a dessiner
	 */
	void dessinerCercle(int x, int y, int rayon, Color color);
	/**
	 * M�thode permettant de dessiner un Polygone
	 * sur la fen�tre cr��e avec l'objet JFRAME.
	 * @param x
	 * 		Tableau d'abscisse de points
	 * @param y
	 * 		Tableau d'ordonn�es de points
	 * @param taille
	 * 		le nombre de points � traiter
	 * @param color
	 * 		la couleur de la forme a dessiner
	 */
	void dessinerPolygone(int[]x, int[]y, int taille, Color color);
	/**
	 * M�thode permettant de dessiner un Segment
	 * sur la fen�tre cr��e avec l'objet JFRAME.
	 * @param x1
	 * 		l'abscisse du points A
	 * @param y1
	 * 		L'ordonn�e du point A
	 * @param x2
	 * 		l'abscisse du points B
	 * @param y2
	 * 		L'ordonn�e du point B
	 * @param color
	 * 		la couleur de la forme a dessiner
	 */
	void dessinerSegment(int x1, int y1, int x2, int y2, Color color);
	/**
	 * M�thode permettant de dessiner un Triangle
	 * sur la fen�tre cr��e avec l'objet JFRAME.
	 * @param x
	 * 		Tableau d'abscisse de points
	 * @param y
	 * 		Tableau d'ordonn�es de points
	 * @param color
	 * 		la couleur de la forme a dessiner
	 */
	void dessinerTriangle(int[] x, int[] y, Color color);
}