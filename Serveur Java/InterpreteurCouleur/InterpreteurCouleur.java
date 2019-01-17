package InterpreteurCouleur;

import java.awt.Color;


/**
 * 
 * <b>Classe abstraite repr�sentant la chaine de responsabilit� 
 * pour d�terminer une couleur � partir d'une chaine de caractere</b>
 *
 */

public abstract class InterpreteurCouleur {
	/**
	 * Seule m�thode elle-m�me aussi abstraite qui retourne une couleur
	 * Cette m�thode va �tre utilis�e par interpreteurCouleurCOR
	 * pour appeler la m�thode d'interpretation de chaque expert 
	 * et de passer au suivant si la r�solution n'a pas fonctionn�e
	 * 
	 * @param couleur
	 *  La chaine de caractere de la couleur a interpr�ter
	 * @return La couleur a interpr�ter
	 */
	public abstract Color interpreterCouleur(String couleur);
}