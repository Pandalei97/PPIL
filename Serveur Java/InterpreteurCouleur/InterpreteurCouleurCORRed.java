package InterpreteurCouleur;

import java.awt.Color;

/**
 * 
 * Classe qui hérite de InterpreterCouleurCOR
 * sans constructeur, qui a pour seul but d'interpréter
 * une couleur à partir d'une chaine de caracteres.
 * C'est un expert à part entiere.
 *
 */

public class InterpreteurCouleurCORRed extends InterpreteurCouleurCOR {

	/**
	 * Méthode qui interprete directement la couleur et la retourne
	 * si elle est bien interprétée.
	 * @return Color.red
	 */
	
	public Color interpreterCouleur2(){
		return Color.red;
	}
	/**
     * Méthode pour avoir le type de couleur
     * que l'expert sait résoudre.
     * @return type que l'expert sait résoudre.
     * 		ici red.
     */
	public String getType(){
		return "red";
	}
}
