package InterpreteurForme;

import main.InterfaceGraphic;

/**
 * 
 * 
 * <b>Classe abstraite représentant la chaine de responsabilité 
 * pour déterminer une forme à partir d'une chaine de caractere</b>
 * 
 * 
 */

public abstract class InterpreteurForme {
	/**
	 * Seule méthode elle-même aussi abstraite qui retourne un boolén
	 * vrai si elle trouve et faux sinon.
	 * Cette méthode va être utilisée par interpreteurFormeCOR
	 * pour appeler la méthode de dessin de chaque expert 
	 * et de passer au suivant si la résolution n'a pas fonctionnée
	 * 
	 * @param forme
	 *  La chaine de caractere de la forme a interpréter
	 * @param objetAwt
	 * 		Notre objet permettant d'intéragir avec la fenêtre
	 * 		du thread courant
	 * @return Un booléen un fonction de la trouvaille
	 */
	
	public abstract boolean dessiner(String forme, InterfaceGraphic objetAwt);
}