package InterpreteurForme;

import java.awt.Color;

import main.COR;
import main.InterfaceGraphic;

/**
 * 
 * Classe qui hérite de InterpreterFormeCOR
 * sans constructeur, qui a pour seul but d'interpréter
 * une forme à partir d'une chaine de caracteres.
 * C'est un expert à part entiere.
 *
 */

public class InterpreteurFormeCORSegment extends InterpreteurFormeCOR {

	/**
	 * Méthode qui interprete directement un segment.
	 * @param forme
	 * 		La chaine de caractere de la couleur a interpréter
	 * Elle ne retourne rien elle dessiner le Polygone.
	 */
	
	public void genererDessin(String forme, InterfaceGraphic objetAwt){
		String couleurNonInterpretee = forme.split(";")[0];
		Color couleur = COR.getInstance().getInterpreteurCouleur().interpreterCouleur(couleurNonInterpretee);
		String pointA = forme.split(";")[1].replace("(","").replace(")", "");
		String pointB = forme.split(";")[2].replace("(","").replace(")", "");
		double pointAxDouble = Double.parseDouble(pointA.split(",")[0]);
		double pointAyDouble = Double.parseDouble(pointA.split(",")[1]);
		double pointBxDouble = Double.parseDouble(pointB.split(",")[0]);
		double pointByDouble = Double.parseDouble(pointB.split(",")[1]);
		int pointAx = (int) Math.round(pointAxDouble);
		int pointAy = (int) Math.round(pointAyDouble);
		int pointBx = (int) Math.round(pointBxDouble);
		int pointBy = (int) Math.round(pointByDouble);
		objetAwt.dessinerSegment(pointAx,pointAy,pointBx,pointBy,couleur);
	}
	/**
     * Méthode pour avoir le type de forme
     * que l'expert sait résoudre.
     * @return type que l'expert sait résoudre.
     * 		ici Segment.
     */
	public String getType(){
		return "Segment";
	}
}