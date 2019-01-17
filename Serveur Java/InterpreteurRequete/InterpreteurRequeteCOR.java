package InterpreteurRequete;

import java.io.PrintStream;

import main.InterfaceGraphic;

/**
 * 
 * <b>Classe abstraite représentant la chaine de responsabilité 
 * pour interpréter à partir d'une chaine de caracteres.
 * Elle hérite de InterpreteurRequete</b>
 * Les différents "experts" heriterons de cette classe pour
 * interpréter une requete à partir d'une chaine de caracteres.
 * 
 * suivant est Le maillon suivant dans la chaine de responsabilité
 *
 */

public abstract class InterpreteurRequeteCOR extends InterpreteurRequete{
	private InterpreteurRequeteCOR suivant;
	/**
	 * Cette méthode "accroche" les différents experts entre eux.
	 * 
	 * @param suiv
	 * L'expert de la chaine suivant
	 */
	
    public void setSuivant(InterpreteurRequeteCOR suiv) {
        suivant = suiv;
    }
    
    /**
     * Cette méthode essai d'interpréter indirectement la requete
     * à partir d'une chaine de caracteres en envoyant la chaine
     * à la méthode suivant interpreterRequete1
     * @return booléen
     * 		Retourne vrai si la requete a été interprétée et donc traitée
     * 		Sinon faux.
     */
    
    public boolean interpreterRequete(String requete, InterfaceGraphic objetAwt,  PrintStream fluxSortant) {
        if(interpreterRequete1(requete, objetAwt, fluxSortant)){
        	return true;
        }
        else{
        	if(suivant != null){
        		return suivant.interpreterRequete(requete, objetAwt, fluxSortant);
        	}
        	else{
        		return false;
        	}
        }
    }
    /**
     * C'est la méthode qui se charge d'interpréter 
     * (grâce à la méthode interpreterRequete2) 
     * les requetes à partir d'une chaine de caracteres. 
     * @param requete
     * 		La chaine de caractere de la requete a interpréter
     * @param objetAwt
     * 		Notre objet pour intéragir avec la fenêtre pour ce thread
     * @param fluxSortant
     * 		Notre flux nous permettant d'envoyer un message
     * 		au client via le réseau
     * @return booléen
     * 		Retourne vrai si la requete a été interprétée et donc traitée
     * 		Sinon faux si l'expert ne sais pas interpréter la requete.
     */
    
    public boolean interpreterRequete1(String requete, InterfaceGraphic objetAwt,  PrintStream fluxSortant){
    	String type = requete.split("\\$")[0];
    	String donnees_requete = requete.split("\\$")[1];
		if(!type.equals(this.getType()))
			return false;
		else{
			interpreterRequete2(donnees_requete, objetAwt, fluxSortant);
			return true;
		}
    }
    /**
     * Méthode abstraite qui sera implémentée
     * dans les classes qui hériteront de celle-ci.
     * Elle ne retourne rien mais s'occupe de traiter la requete
     * et de faire une action en fonction de la requête.
     * @param requete
     * 		la chaine de caractere de la requete à interprétéer
     * @param objetAwt
     * 		Notre objet InterfaceGraphic
     * @param fluxSortant
     * 		Notre PrintStream pour répondre au client
     */
    public abstract void interpreterRequete2(String requete, InterfaceGraphic objetAwt,  PrintStream fluxSortant);
    /**
     * Méthode pour avoir le type de requete
     * que l'expert sait résoudre.
     * @return type que l'expert sait résoudre.
     */
    public abstract String getType();
}