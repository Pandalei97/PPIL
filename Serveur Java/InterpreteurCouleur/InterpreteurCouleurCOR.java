package InterpreteurCouleur;

import java.awt.Color;

/**
 * 
 * <b>Classe abstraite repr�sentant la chaine de responsabilit� 
 * pour d�terminer une couleur � partir d'une chaine de caracteres.
 * Elle h�rite de InterpreteurCouleur</b>
 * Les diff�rents "experts" heriterons de cette classe pour
 * d�terminer une couleur � partir d'une chaine de caracteres.
 * 
 * suivant est Le maillon suivant dans la chaine de responsabilit�
 *
 */
public abstract class InterpreteurCouleurCOR extends InterpreteurCouleur{
	private InterpreteurCouleurCOR suivant;
	/**
	 * Cette m�thode "accroche" les diff�rents experts entre eux.
	 * 
	 * @param suiv
	 * L'expert de la chaine suivant
	 */
    public void setSuivant(InterpreteurCouleurCOR suiv) {
        suivant = suiv;
    }

    /**
     * Cette m�thode essai d'interpr�ter indirectement la couleur
     * � partir d'une chaine de caracteres en envoyant la chaine
     * � la m�thode suivant interpreterCouleur1
     * @return c
     * 		Retourne la couleur si trouv� dans la chaine
     * 		Sinon NULL pour passer au maillon suivant 
     * 		ou comme r�sultat final c'est � dire que la chaine
     * 		de responsabilit� n'a pas trouv� la couleur.
     */
    public Color interpreterCouleur(String couleur) {
    	Color c = interpreterCouleur1(couleur);
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
     * C'est la m�thode qui se charge
     * d'interpr�ter les couleurs (� l'aide de la m�thode
     * interpreterCouleur2) � partir d'une 
     * chaine de caracteres. 
     * @param couleur
     * 		La chaine de caractere de la couleur a interpr�ter
     * @return La couleur si elle a �t� trouv�e
     * 		NULL si l'expert ne sait pas r�soudre la couleur
     * 		et passe au suivant
     */
    public Color interpreterCouleur1(String couleur){
		if(!couleur.equals(this.getType()))
			return null;
		else
			return interpreterCouleur2();
    }
    /**
     * M�thode abstraite qui sera impl�ment�e
     * dans les classes qui h�riteront de celle-ci.
     * Elle retourne la couleur interpr�t�e.
     * @return Couleur interpr�t�e
     */
    public abstract Color interpreterCouleur2(); 
    /**
     * M�thode pour avoir le type de couleur
     * que l'expert sait r�soudre.
     * @return type que l'expert sait r�soudre.
     */
    public abstract String getType();
}