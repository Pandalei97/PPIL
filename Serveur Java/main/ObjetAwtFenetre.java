package main;
import java.awt.Color;
import java.awt.Graphics;
import java.awt.image.BufferStrategy;

import javax.swing.JFrame;

/**
 * Classe ObjetAwtFenetre h�ritant de InterfaceGraphic
 * C'est cette classe qui permet de d�clarer les JFrame,
 * BufferStrategy ou encore Graphics pour permettre d'int�ragir
 * avec une fen�tre.
 *
 */
public class ObjetAwtFenetre implements InterfaceGraphic {
	/**
	 * Instanciation de l'objet pour int�ragir avec une fen�tre
	 */
	private JFrame frame;
	/**
	 * Outils de buffering pour dessiner
	 */
	private BufferStrategy strategie;
	/**
	 * Classe permettant de d�ssiner sur le composant JFRAME
	 */
	private Graphics graphic;

	/**
	 * M�thode permettant d'obtenir le graphic
	 * car il est d�clar� en priv�
	 * @return graphic
	 * 		le graphic en question
	 */
	public Graphics getGraphique(){
		return graphic;
	}
	/**
	 *M�thode permettant de changer le graphic en cours
	 *@param graph
	 *		Le nouveau graphic
	 */
	public void setGraphique(Graphics graph){
		this.graphic = graph;
	}

	/**
	 * M�thode permettant d'obtenir le JFRAME
	 * car il est d�clar� en priv�
	 * @return frame
	 * 		le JFRAME en question
	 */
	public JFrame getFrame(){
		return frame;
	}

	/**
	 *M�thode permettant de changer le JFRAME en cours
	 *@param f
	 *		Le nouveau JFRAME
	 */
	public void setFrame(JFrame f){
		this.frame = f;
	}

	/**
	 * M�thode permettant d'obtenir le bufferstrategy
	 * car il est d�clar� en priv�
	 * @return strategie
	 * 		le Bufferstrategie en question
	 */
	public BufferStrategy getStrategie(){
		return strategie;
	}

	/**
	 *M�thode permettant de changer le Bufferstrategie en cours
	 *@param strat
	 *		Le nouveau Bufferstrategie
	 */
	public void setStrategie(BufferStrategy strat){
		this.strategie = strat;
	}
	
	/**
	 * M�thode permettant de cr�er une fen�tre
	 * @param titre
	 * 		le titre de la fen�tre
	 * @param largeur
	 * 		La largeur de la fen�tre
	 * @param hauteur
	 * 		La hauteur de la fen�tre
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
	public void dessinerCercle(int x, int y, int rayon, Color color) {
		try{
			int numBuffers = 1;
			getFrame().createBufferStrategy(numBuffers); // cr�e une strat�gie de tampon d'image � 1 tampon vid�o
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
	public void dessinerPolygone(int[] x, int[] y, int taille, Color color){
		try{
			int numBuffers = 1;
			getFrame().createBufferStrategy(numBuffers); // cr�e une strat�gie de tampon d'image � 1 tampon vid�o
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
	public void dessinerSegment(int x1, int y1, int x2, int y2, Color color){
		try {
			int numBuffers = 1;
			getFrame().createBufferStrategy(numBuffers); // cr�e une strat�gie de tampon d'image � 1 tampon vid�o
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
	 * M�thode permettant de dessiner un Triangle
	 * sur la fen�tre cr��e avec l'objet JFRAME.
	 * @param x
	 * 		Tableau d'abscisse de points
	 * @param y
	 * 		Tableau d'ordonn�es de points
	 * @param color
	 * 		la couleur de la forme a dessiner
	 */
	public void dessinerTriangle(int[] x, int[] y, Color color){
		try{
			int numBuffers = 1;
			getFrame().createBufferStrategy(numBuffers); // cr�e une strat�gie de tampon d'image � 1 tampon vid�o
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
