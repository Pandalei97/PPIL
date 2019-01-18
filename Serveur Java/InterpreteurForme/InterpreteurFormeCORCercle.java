package InterpreteurForme;

import java.awt.Color;

import main.COR;
import main.InterfaceGraphic;

/**
 * 
 * Classe qui h�rite de InterpreterFormeCOR
 * sans constructeur, qui a pour seul but d'interpr�ter
 * une forme � partir d'une chaine de caracteres.
 * C'est un expert � part entiere.
 *
 */

public class InterpreteurFormeCORCercle extends InterpreteurFormeCOR {

	/**
	 * M�thode qui interprete directement un cercle.
	 * @param forme
	 * 		La chaine de caractere de la couleur a interpr�ter
	 * Elle ne retourne rien elle dessiner le cercle.
	 */
	public void genererDessin(String forme, InterfaceGraphic objetAwt){
		String couleurNonInterpretee = forme.split(";")[0];
		Color couleur = COR.getInstance().getInterpreteurCouleur().interpreterCouleur(couleurNonInterpretee);
		String[] attributsForme = forme.split(";");
		double rayonDouble = Double.parseDouble(attributsForme[2]);
		rayonDouble *=2;
		int rayon = (int) Math.round(rayonDouble);
		String centre = attributsForme[1].replace("(","").replace(")", "");
		double xCentreDouble = Double.parseDouble(centre.split(",")[0]);
		xCentreDouble = xCentreDouble-(rayon/2);
		double yCentreDouble = Double.parseDouble(centre.split(",")[1]);
		yCentreDouble = yCentreDouble-(rayon/2);
		int xCentre = (int) Math.round(xCentreDouble);
		int yCentre = (int) Math.round(yCentreDouble);
		objetAwt.dessinerCercle(xCentre, yCentre, rayon, couleur);
	}
	/**
     * M�thode pour avoir le type de forme
     * que l'expert sait r�soudre.
     * @return type que l'expert sait r�soudre.
     * 		ici cercle.
     */
	public String getType(){
		return "Cercle";
	}
}