package main;

import InterpreteurCouleur.InterpreteurCouleur;
import InterpreteurCouleur.InterpreteurCouleurCOR;
import InterpreteurCouleur.InterpreteurCouleurCORBlack;
import InterpreteurCouleur.InterpreteurCouleurCORBlue;
import InterpreteurCouleur.InterpreteurCouleurCORCyan;
import InterpreteurCouleur.InterpreteurCouleurCORGreen;
import InterpreteurCouleur.InterpreteurCouleurCORRed;
import InterpreteurCouleur.InterpreteurCouleurCORYellow;
import InterpreteurForme.InterpreteurForme;
import InterpreteurForme.InterpreteurFormeCOR;
import InterpreteurForme.InterpreteurFormeCORCercle;
import InterpreteurForme.InterpreteurFormeCORPolygone;
import InterpreteurForme.InterpreteurFormeCORSegment;
import InterpreteurForme.InterpreteurFormeCORTriangle;
import InterpreteurRequete.InterpreteurRequete;
import InterpreteurRequete.InterpreteurRequeteCOR;
import InterpreteurRequete.InterpreteurRequeteCORDessinerForme;
import InterpreteurRequete.InterpreteurRequeteCOROuvertureFenetre;

/**
 * 
 * Classe utilitaire COR qui nous permet
 * de centraliser les différentes chaînes de
 * responsabilité pour éviter de les déclarer
 * ailleurs dans le code.
 * Elle est développé en tant que singleton
 *
 */
public class COR {
	/**
	 * instance unique de la classe COR
	 */
	private static COR instance = null;
	/**
	 * "Entrée" de la chaine de responsabilité
	 * pour interpréter une requête
	 */
	private InterpreteurRequete interpreteurRequete;
	/**
	 * "Entrée" de la chaine de responsabilité
	 * pour interpréter une forme
	 */
	private InterpreteurForme interpreteurForme;
	/**
	 * "Entrée" de la chaine de responsabilité
	 * pour interpréter une couleur
	 */
	private InterpreteurCouleur interpreteCouleur;
	/**
	 * Constructeur de la classe COR
	 * Assemblage et construction des chaines
	 * de responsabilité
	 */
	private COR(){
		//construction de la chaine de responsabilité pour interpreter une requete
		InterpreteurRequeteCOR interpreteurRequeteDessiner, interpreteurRequeteOuvertureFenetre;
		interpreteurRequeteDessiner = new InterpreteurRequeteCORDessinerForme();
		interpreteurRequeteOuvertureFenetre = new InterpreteurRequeteCOROuvertureFenetre();
		//Assemblage des maillons
		interpreteurRequeteDessiner.setSuivant(interpreteurRequeteOuvertureFenetre);
		interpreteurRequete = interpreteurRequeteDessiner;
		
		//construction de la chaine de responsabilité pour interpreter forme
		InterpreteurFormeCOR dessinateurCercle, dessinateurSegment, dessinateurTriangle, dessinateurPolygone;
		dessinateurCercle = new InterpreteurFormeCORCercle();
		dessinateurSegment = new InterpreteurFormeCORSegment();
		dessinateurTriangle = new InterpreteurFormeCORTriangle();
		dessinateurPolygone = new InterpreteurFormeCORPolygone();
		//assemblage des maillons
		dessinateurCercle.setSuivant(dessinateurPolygone);
		dessinateurSegment.setSuivant(dessinateurCercle);
		dessinateurTriangle.setSuivant(dessinateurSegment);
		interpreteurForme = dessinateurTriangle;
		
		//construction de la chaine de responsabilité pour interpreter une couleur
		InterpreteurCouleurCOR black, blue, cyan, green, red, yellow;
		black = new InterpreteurCouleurCORBlack();
		blue = new InterpreteurCouleurCORBlue();
		cyan = new InterpreteurCouleurCORCyan();
		green = new InterpreteurCouleurCORGreen();
		red = new InterpreteurCouleurCORRed();
		yellow = new InterpreteurCouleurCORYellow();
		//assemblage des maillons
		blue.setSuivant(black);
		cyan.setSuivant(blue);
		green.setSuivant(cyan);
		red.setSuivant(green);
		yellow.setSuivant(red);
		interpreteCouleur = yellow;
	}
	/**
	 * Méthode qui récupère l'instance unique
	 * de la classe COR
	 * @return L'instance unique de la classe COR
	 */
	public static COR getInstance()
	{	
		if(instance == null)
			instance = new COR();
		return instance;
	}
	/**
	 * Méthode qui récupère "l'entrée" de la chaine de
	 * responsabilité pour interpréter une couleur
	 * @return "l'interpréteur de couleur"
	 */
	public InterpreteurCouleur getInterpreteurCouleur(){
		return interpreteCouleur;
	}
	/**
	 * Méthode qui récupère "l'entrée" de la chaine de
	 * responsabilité pour interpréter une requête
	 * @return "l'interpréteur de requête"
	 */
	public InterpreteurRequete getInterpreteurRequete(){
		return interpreteurRequete;
	}
	/**
	 * Méthode qui récupère "l'entrée" de la chaine de
	 * responsabilité pour interpréter une forme
	 * @return "l'interpréteur de forme"
	 */
	public InterpreteurForme getInterpreteurForme(){
		return interpreteurForme;
	}
}
