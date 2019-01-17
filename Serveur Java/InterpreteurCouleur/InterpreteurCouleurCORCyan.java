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

public class InterpreteurCouleurCORCyan extends InterpreteurCouleurCOR {

	/**
	 * M�thode qui interprete directement la couleur et la retourne
	 * si elle est bien interpr�t�e.
	 * @return Color.cyan
	 */
	
	public Color interpreterCouleur2(){
		return Color.cyan;
	}
	/**
     * M�thode pour avoir le type de couleur
     * que l'expert sait r�soudre.
     * @return type que l'expert sait r�soudre.
     * 		ici cyan.
     */
	public String getType(){
		return "cyan";
	}
}
