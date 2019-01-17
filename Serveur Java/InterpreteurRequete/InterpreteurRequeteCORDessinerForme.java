package InterpreteurRequete;

import java.io.PrintStream;

import main.COR;
import main.InterfaceGraphic;

/**
 * 
 * Classe qui hérite de InterpreterRequeteCOR
 * sans constructeur, qui a pour seul but d'interpréter
 * une requete à partir d'une chaine de caracteres.
 * C'est un expert à part entiere.
 *
 */

public class InterpreteurRequeteCORDessinerForme extends InterpreteurRequeteCOR {

	/**
	 * Méthode qui interprete une requete de type DESSIN.
	 * @param forme
	 * 		La chaine de caractere de la requete a interpréter
	 * @param objetAwt
	 * 		Notre objet InterfaceGraphic
	 * @param fluxSortant
	 * 		Notre objet Printstream pour répondre au client
	 * Elle ne retourne rien mais effectue le dessin de la forme
	 * à travers une autre chaîne de responsabilité.
	 */
	
	public void interpreterRequete2(String forme, InterfaceGraphic objetAwt, PrintStream fluxSortant){
		//on dessine grâce à la chaine de repsonsabilité
		boolean dessinOK = COR.getInstance().getInterpreteurForme().dessiner(forme, objetAwt);
		if(!dessinOK){
			System.out.println("La forme n'a pas été reconnue par le serveur");
			fluxSortant.print("0");
		}
		else
			fluxSortant.print("1");
	}
	/**
     * Méthode pour avoir le type de requete
     * que l'expert sait résoudre.
     * @return type que l'expert sait résoudre.
     * 		ici D pour Dessiner.
     */
	public String getType(){
		return "D";
	}
}