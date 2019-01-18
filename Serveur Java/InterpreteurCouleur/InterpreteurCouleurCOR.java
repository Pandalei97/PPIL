package InterpreteurCouleur;

import java.awt.Color;

/**
 * 
 * <b>Classe abstraite représentant la chaine de responsabilité 
 * pour déterminer une couleur à partir d'une chaine de caracteres.
 * Elle hérite de InterpreteurCouleur</b>
 * Les différents "experts" heriterons de cette classe pour
 * déterminer une couleur à partir d'une chaine de caracteres.
 * 
 * suivant est Le maillon suivant dans la chaine de responsabilité
 *
 */
public abstract class InterpreteurCouleurCOR extends InterpreteurCouleur{
	private InterpreteurCouleurCOR suivant;
	/**
	 * Cette méthode "accroche" les différents experts entre eux.
	 * 
	 * @param suiv
	 * L'expert de la chaine suivant
	 */
    public void setSuivant(InterpreteurCouleurCOR suiv) {
        suivant = suiv;
    }

    /**
     * Cette méthode essai d'interpréter indirectement la couleur
     * à partir d'une chaine de caracteres en envoyant la chaine
     * à la méthode suivant interpreterCouleur1
     * @return c
     * 		Retourne la couleur si trouvé dans la chaine
     * 		Sinon NULL pour passer au maillon suivant 
     * 		ou comme résultat final c'est à dire que la chaine
     * 		de responsabilité n'a pas trouvé la couleur.
     */
    public Color interpreterCouleur(String couleur) {
    	Color c = null;
    	if(couleur.equals(this.getType()))
    		c = getCouleur();
 
    	if(c != null){
        	return c;
        }
        else{
        	if(suivant != null){
        		return suivant.interpreterCouleur(couleur);
        	}
        	else{
        		return null;
        	}
        }
    }
    
    /**
     * Méthode abstraite qui sera implémentée
     * dans les classes qui hériteront de celle-ci.
     * Elle retourne la couleur interprétée.
     * @return Couleur interprétée
     */
    public abstract Color getCouleur(); 
    /**
     * Méthode pour avoir le type de couleur
     * que l'expert sait résoudre.
     * @return type que l'expert sait résoudre.
     */
    public abstract String getType();
}