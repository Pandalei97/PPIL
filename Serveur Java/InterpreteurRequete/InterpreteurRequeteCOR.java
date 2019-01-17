package InterpreteurRequete;

import java.io.PrintStream;

import main.InterfaceGraphic;

/**
 * 
 * <b>Classe abstraite repr�sentant la chaine de responsabilit� 
 * pour interpr�ter � partir d'une chaine de caracteres.
 * Elle h�rite de InterpreteurRequete</b>
 * Les diff�rents "experts" heriterons de cette classe pour
 * interpr�ter une requete � partir d'une chaine de caracteres.
 * 
 * suivant est Le maillon suivant dans la chaine de responsabilit�
 *
 */

public abstract class InterpreteurRequeteCOR extends InterpreteurRequete{
	private InterpreteurRequeteCOR suivant;
	/**
	 * Cette m�thode "accroche" les diff�rents experts entre eux.
	 * 
	 * @param suiv
	 * L'expert de la chaine suivant
	 */
	
    public void setSuivant(InterpreteurRequeteCOR suiv) {
        suivant = suiv;
    }
    
    /**
     * Cette m�thode essai d'interpr�ter indirectement la requete
     * � partir d'une chaine de caracteres en envoyant la chaine
     * � la m�thode suivant interpreterRequete1
     * @return bool�en
     * 		Retourne vrai si la requete a �t� interpr�t�e et donc trait�e
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
     * C'est la m�thode qui se charge d'interpr�ter 
     * (gr�ce � la m�thode interpreterRequete2) 
     * les requetes � partir d'une chaine de caracteres. 
     * @param requete
     * 		La chaine de caractere de la requete a interpr�ter
     * @param objetAwt
     * 		Notre objet pour int�ragir avec la fen�tre pour ce thread
     * @param fluxSortant
     * 		Notre flux nous permettant d'envoyer un message
     * 		au client via le r�seau
     * @return bool�en
     * 		Retourne vrai si la requete a �t� interpr�t�e et donc trait�e
     * 		Sinon faux si l'expert ne sais pas interpr�ter la requete.
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
     * M�thode abstraite qui sera impl�ment�e
     * dans les classes qui h�riteront de celle-ci.
     * Elle ne retourne rien mais s'occupe de traiter la requete
     * et de faire une action en fonction de la requ�te.
     * @param requete
     * 		la chaine de caractere de la requete � interpr�t�er
     * @param objetAwt
     * 		Notre objet InterfaceGraphic
     * @param fluxSortant
     * 		Notre PrintStream pour r�pondre au client
     */
    public abstract void interpreterRequete2(String requete, InterfaceGraphic objetAwt,  PrintStream fluxSortant);
    /**
     * M�thode pour avoir le type de requete
     * que l'expert sait r�soudre.
     * @return type que l'expert sait r�soudre.
     */
    public abstract String getType();
}