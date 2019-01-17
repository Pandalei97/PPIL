package InterpreteurForme;

import main.InterfaceGraphic;

/**
 * 
 * 
 * <b>Classe abstraite repr�sentant la chaine de responsabilit� 
 * pour d�terminer une forme � partir d'une chaine de caractere</b>
 * 
 * 
 */

public abstract class InterpreteurForme {
	/**
	 * Seule m�thode elle-m�me aussi abstraite qui retourne un bool�n
	 * vrai si elle trouve et faux sinon.
	 * Cette m�thode va �tre utilis�e par interpreteurFormeCOR
	 * pour appeler la m�thode de dessin de chaque expert 
	 * et de passer au suivant si la r�solution n'a pas fonctionn�e
	 * 
	 * @param forme
	 *  La chaine de caractere de la forme a interpr�ter
	 * @param objetAwt
	 * 		Notre objet permettant d'int�ragir avec la fen�tre
	 * 		du thread courant
	 * @return Un bool�en un fonction de la trouvaille
	 */
	
	public abstract boolean dessiner(String forme, InterfaceGraphic objetAwt);
}