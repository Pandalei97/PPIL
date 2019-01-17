package main;
import java.awt.Color;
import java.awt.Graphics;
import java.awt.image.BufferStrategy;

import javax.swing.JFrame;

/**
 * Classe ObjetAwtFenetre héritant de InterfaceGraphic
 * C'est cette classe qui permet de déclarer les JFrame,
 * BufferStrategy ou encore Graphics pour permettre d'intéragir
 * avec une fenêtre.
 *
 */
public class ObjetAwtFenetre implements InterfaceGraphic {
	/**
	 * Instanciation de l'objet pour intéragir avec une fenêtre
	 */
	private JFrame frame;
	/**
	 * Outils de buffering pour dessiner
	 */
	private BufferStrategy strategie;
	/**
	 * Classe permettant de déssiner sur le composant JFRAME
	 */
	private Graphics graphic;

	/**
	 * Méthode permettant d'obtenir le graphic
	 * car il est déclaré en privé
	 * @return graphic
	 * 		le graphic en question
	 */
	public Graphics getGraphique(){
		return graphic;
	}
	/**
	 *Méthode permettant de changer le graphic en cours
	 *@param graph
	 *		Le nouveau graphic
	 */
	public void setGraphique(Graphics graph){
		this.graphic = graph;
	}

	/**
	 * Méthode permettant d'obtenir le JFRAME
	 * car il est déclaré en privé
	 * @return frame
	 * 		le JFRAME en question
	 */
	public JFrame getFrame(){
		return frame;
	}

	/**
	 *Méthode permettant de changer le JFRAME en cours
	 *@param f
	 *		Le nouveau JFRAME
	 */
	public void setFrame(JFrame f){
		this.frame = f;
	}

	/**
	 * Méthode permettant d'obtenir le bufferstrategy
	 * car il est déclaré en privé
	 * @return strategie
	 * 		le Bufferstrategie en question
	 */
	public BufferStrategy getStrategie(){
		return strategie;
	}

	/**
	 *Méthode permettant de changer le Bufferstrategie en cours
	 *@param strat
	 *		Le nouveau Bufferstrategie
	 */
	public void setStrategie(BufferStrategy strat){
		this.strategie = strat;
	}
	
	/**
	 * Méthode permettant de créer une fenêtre
	 * @param titre
	 * 		le titre de la fenêtre
	 * @param largeur
	 * 		La largeur de la fenêtre
	 * @param hauteur
	 * 		La hauteur de la fenêtre
	 */
	public void creerFenetre(String titre, int largeur, int hauteur){
		setFrame(new JFrame(titre));
		getFrame().setSize(largeur, hauteur);
		getFrame().setLocationRelativeTo(null);
		getFrame().setResizable(false);
		getFrame().setVisible(true); 
		getFrame().setIgnoreRepaint(true); 
	}

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
	public void dessinerCercle(int x, int y, int rayon, Color color) {
		try{
			int numBuffers = 1;
			getFrame().createBufferStrategy(numBuffers); // crée une stratégie de tampon d'image à 1 tampon vidéo
			setStrategie(getFrame().getBufferStrategy());
			setGraphique(getStrategie().getDrawGraphics());			
			Thread.sleep(150);	
			getGraphique().setColor(color);
			getGraphique().drawOval(x, y, rayon, rayon);
			getStrategie().dispose();
		}
		catch(InterruptedException e){
			e.printStackTrace();
		}
	}

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
	public void dessinerPolygone(int[] x, int[] y, int taille, Color color){
		try{
			int numBuffers = 1;
			getFrame().createBufferStrategy(numBuffers); // crée une stratégie de tampon d'image à 1 tampon vidéo
			setStrategie(getFrame().getBufferStrategy());
			setGraphique(getStrategie().getDrawGraphics());			
			Thread.sleep(50);
			getGraphique().setColor(color);
			getGraphique().drawPolygon(x, y, taille);
			getStrategie().dispose();
		}
		catch(InterruptedException e){
			e.printStackTrace();
		}
	}
	
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
	public void dessinerSegment(int x1, int y1, int x2, int y2, Color color){
		try {
			int numBuffers = 1;
			getFrame().createBufferStrategy(numBuffers); // crée une stratégie de tampon d'image à 1 tampon vidéo
			setStrategie(getFrame().getBufferStrategy());
			setGraphique(getStrategie().getDrawGraphics());			
			Thread.sleep(50);
			getGraphique().setColor(color);
			getGraphique().drawLine(x1, y1, x2, y2);
			getStrategie().dispose();
		}
		catch(InterruptedException e){
			e.printStackTrace();
		}
	}
	
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
	public void dessinerTriangle(int[] x, int[] y, Color color){
		try{
			int numBuffers = 1;
			getFrame().createBufferStrategy(numBuffers); // crée une stratégie de tampon d'image à 1 tampon vidéo
			setStrategie(getFrame().getBufferStrategy());
			setGraphique(getStrategie().getDrawGraphics());			
			Thread.sleep(50);
			getGraphique().setColor(color);
			getGraphique().drawPolygon(x, y, 3);
			getStrategie().dispose();
		}
		catch(InterruptedException e){
			e.printStackTrace();
		}		
	}
}
