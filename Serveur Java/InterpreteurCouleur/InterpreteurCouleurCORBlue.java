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

public class InterpreteurCouleurCORBlue extends InterpreteurCouleurCOR {

	/**
	 * M�thode qui interprete directement la couleur et la retourne
	 * si elle est bien interpr�t�e.
	 * @return Color.blue
	 */
	
	public Color interpreterCouleur2(){
		return Color.blue;
	}
	/**
     * M�thode pour avoir le type de couleur
     * que l'expert sait r�soudre.
     * @return type que l'expert sait r�soudre.
     * 		ici blue.
     */
	public String getType(){
		return "blue";
	}
}
