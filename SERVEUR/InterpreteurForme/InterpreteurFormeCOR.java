package InterpreteurForme;

import main.InterfaceGraphic;

/**
 * 
 * <b>Classe abstraite représentant la chaine de responsabilité 
 * pour déterminer une couleur à partir d'une chaine de caracteres.
 * Elle hérite de InterpreteurForme</b>
 * Les différents "experts" heriterons de cette classe pour
 * déterminer une forme à partir d'une chaine de caracteres.
 * 
 * suivant est Le maillon suivant dans la chaine de responsabilité
 *
 */

public abstract class InterpreteurFormeCOR extends InterpreteurForme{
	private InterpreteurFormeCOR suivant;
	/**
	 * Cette méthode "accroche" les différents experts entre eux.
	 * 
	 * @param suiv
	 * L'expert de la chaine suivant
	 */
	
    public void setSuivant(InterpreteurFormeCOR suiv) {
        suivant = suiv;
    }
    /**
     * Cette méthode essai d'interpréter indirectement la forme
     * à partir d'une chaine de caracteres en envoyant la chaine
     * à la méthode suivant Dessiner1
     * @return booléen
     * 		Retourne vrai si la forme a été trouvé et donc dessinée,
     * 		Sinon faux.
     */
    
    public boolean dessiner(String forme, InterfaceGraphic objetAwt) {
        if(dessinable(forme, objetAwt)){
        	return true;
        }
        else{
        	if(suivant != null){
        		return suivant.dessiner(forme, objetAwt);
        	}
        	else{
        		return false;
        	}
        }
    }
    /**
     * C'est la méthode qui se charge d'interpréter 
     * (grâce à la méthode dessiner2) les formes à partir d'une 
     * chaine de caracteres. 
     * @param forme
     * 		La chaine de caractere de la forme a interpréter
	 * @param objetAwt
	 * 		Notre objet permettant d'intéragir avec la fenêtre
	 * 		du thread courant
     * @return booléen
     * 		Retourne vrai si la forme a été trouvé et donc dessinée,
     * 		Sinon faux si l'expert ne sait pas interpréter la forme.
     */
    
    public boolean dessinable(String forme, InterfaceGraphic objetAwt)
    {
    	String typeForme = forme.split(":")[0];
    	if(!typeForme.equals(this.getType()))
    		return false;
    	else{
    		String infosForme = forme.split(":")[1];
    		genererDessin(infosForme, objetAwt);
    		return true;
    	}
    }
    /**
     * Méthode abstraite qui sera implémentée
     * dans les classes qui hériteront de celle-ci.
     * Elle ne retourne rien mais s'occupe de dessiner la forme
     * @param forme
     * 		La chaine de caractere de la forme à dessiner
     * @param objetAwt
     * 		Notre objet InterfaceGraphic
     */
    public abstract void genererDessin(String forme, InterfaceGraphic objetAwt);
    /**
     * Méthode pour avoir le type de forme
     * que l'expert sait résoudre.
     * @return type que l'expert sait résoudre.
     */
    public abstract String getType();
}
