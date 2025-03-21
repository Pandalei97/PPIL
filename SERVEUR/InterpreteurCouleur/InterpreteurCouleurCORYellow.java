package InterpreteurCouleur;

import java.awt.Color;

/**
 * 
 * Classe qui h�rite de InterpreterCouleurCOR
 * sans constructeur, qui a pour seul but d'interpr�ter
 * une couleur � partir d'une chaine de caracteres.
 * C'est un expert � part entiere.
 *
 */

public class InterpreteurCouleurCORYellow extends InterpreteurCouleurCOR {

	/**
	 * M�thode qui interprete directement la couleur et la retourne
	 * si elle est bien interpr�t�e.
	 * @return Color.yellow
	 */	
	public Color getCouleur(){
		return Color.yellow;
	}
	/**
     * M�thode pour avoir le type de couleur
     * que l'expert sait r�soudre.
     * @return type que l'expert sait r�soudre.
     * 		ici yellow.
     */
	public String getType(){
		return "yellow";
	}
}
