package InterpreteurRequete;

import java.io.PrintStream;

import main.COR;
import main.InterfaceGraphic;

/**
 * 
 * Classe qui h�rite de InterpreterRequeteCOR
 * sans constructeur, qui a pour seul but d'interpr�ter
 * une requete � partir d'une chaine de caracteres.
 * C'est un expert � part entiere.
 *
 */

public class InterpreteurRequeteCORDessinerForme extends InterpreteurRequeteCOR {

	/**
	 * M�thode qui interprete une requete de type DESSIN.
	 * @param forme
	 * 		La chaine de caractere de la requete a interpr�ter
	 * @param objetAwt
	 * 		Notre objet InterfaceGraphic
	 * @param fluxSortant
	 * 		Notre objet Printstream pour r�pondre au client
	 * Elle ne retourne rien mais effectue le dessin de la forme
	 * � travers une autre cha�ne de responsabilit�.
	 */
	
	public void interpreterRequete2(String forme, InterfaceGraphic objetAwt, PrintStream fluxSortant){
		//on dessine gr�ce � la chaine de repsonsabilit�
		boolean dessinOK = COR.getInstance().getInterpreteurForme().dessiner(forme, objetAwt);
		if(!dessinOK){
			System.out.println("La forme n'a pas �t� reconnue par le serveur");
			fluxSortant.print("0");
		}
		else
			fluxSortant.print("1");
	}
	/**
     * M�thode pour avoir le type de requete
     * que l'expert sait r�soudre.
     * @return type que l'expert sait r�soudre.
     * 		ici D pour Dessiner.
     */
	public String getType(){
		return "D";
	}
}