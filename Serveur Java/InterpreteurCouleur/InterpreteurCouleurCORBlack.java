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
public class InterpreteurCouleurCORBlack extends InterpreteurCouleurCOR {

	/**
	 * Méthode qui interprete directement la couleur et la retourne
	 * si elle est bien interprétée.
	 * @return Color.black
	 */
	public Color interpreterCouleur2(){
		return Color.black;
	}
	/**
     * Méthode pour avoir le type de couleur
     * que l'expert sait résoudre.
     * @return type que l'expert sait résoudre.
     * 		ici black.
     */
	public String getType(){
		return "black";
	}
}
