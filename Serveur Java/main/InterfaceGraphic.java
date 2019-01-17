package main;

import java.awt.Color;

// l'objetAwtFenetre va implémenter ces méthodes

/**
 * 
 * Interface qui va nous permettre de spécifier
 * à notre objetAwt d'implémenter ces méthodes
 *
 */
public interface InterfaceGraphic {
	/**
	 * Méthode permettant de créer une fenêtre
	 * @param titre
	 * 		le titre de la fenêtre
	 * @param largeur
	 * 		La largeur de la fenêtre
	 * @param hauteur
	 * 		La hauteur de la fenêtre
	 */
	void creerFenetre(String titre, int largeur, int hauteur);
	/**
	 * Méthode permettant de dessiner un cercle
	 * sur la fenêtre créée avec l'objet JFRAME.
	 * @param x
	 * 		l'abscisse du centre
	 * @param y
	 * 		l'ordonnée du centre
	 * @param rayon
	 * 		le rayon du cercle
	 * @param color
	 * 		la couleur de la forme a dessiner
	 */
	void dessinerCercle(int x, int y, int rayon, Color color);
	/**
	 * Méthode permettant de dessiner un Polygone
	 * sur la fenêtre créée avec l'objet JFRAME.
	 * @param x
	 * 		Tableau d'abscisse de points
	 * @param y
	 * 		Tableau d'ordonnées de points
	 * @param taille
	 * 		le nombre de points à traiter
	 * @param color
	 * 		la couleur de la forme a dessiner
	 */
	void dessinerPolygone(int[]x, int[]y, int taille, Color color);
	/**
	 * Méthode permettant de dessiner un Segment
	 * sur la fenêtre créée avec l'objet JFRAME.
	 * @param x1
	 * 		l'abscisse du points A
	 * @param y1
	 * 		L'ordonnée du point A
	 * @param x2
	 * 		l'abscisse du points B
	 * @param y2
	 * 		L'ordonnée du point B
	 * @param color
	 * 		la couleur de la forme a dessiner
	 */
	void dessinerSegment(int x1, int y1, int x2, int y2, Color color);
	/**
	 * Méthode permettant de dessiner un Triangle
	 * sur la fenêtre créée avec l'objet JFRAME.
	 * @param x
	 * 		Tableau d'abscisse de points
	 * @param y
	 * 		Tableau d'ordonnées de points
	 * @param color
	 * 		la couleur de la forme a dessiner
	 */
	void dessinerTriangle(int[] x, int[] y, Color color);
}