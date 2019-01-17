package InterpreteurCouleur;

import java.awt.Color;


/**
 * 
 * <b>Classe abstraite représentant la chaine de responsabilité 
 * pour déterminer une couleur à partir d'une chaine de caractere</b>
 *
 */

public abstract class InterpreteurCouleur {
	/**
	 * Seule méthode elle-même aussi abstraite qui retourne une couleur
	 * Cette méthode va être utilisée par interpreteurCouleurCOR
	 * pour appeler la méthode d'interpretation de chaque expert 
	 * et de passer au suivant si la résolution n'a pas fonctionnée
	 * 
	 * @param couleur
	 *  La chaine de caractere de la couleur a interpréter
	 * @return La couleur a interpréter
	 */
	public abstract Color interpreterCouleur(String couleur);
}