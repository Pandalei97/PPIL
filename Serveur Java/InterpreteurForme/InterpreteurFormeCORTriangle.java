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

public class InterpreteurFormeCORTriangle extends InterpreteurFormeCOR {
	
	/**
	 * M�thode qui interprete directement triangle.
	 * @param forme
	 * 		La chaine de caractere de la couleur a interpr�ter
	 * Elle ne retourne rien elle dessiner le Polygone.
	 */
	
	public void genererDessin(String forme, InterfaceGraphic objetAwt){
		//donnesTriangle contient [couleur,point1,point2,point3]
		String[] donneesTriangle = forme.split(";");
		String couleurNonInterpretee = donneesTriangle[0];
		Color couleur = COR.getInstance().getInterpreteurCouleur().interpreterCouleur(couleurNonInterpretee);
		int[] x = new int[3];
		int[] y = new int[3];
		double xTemp;
		double yTemp;
		for(int i = 1; i< donneesTriangle.length; i++){
			xTemp = Double.parseDouble(donneesTriangle[i].replace("(","").replace(")", "").split(",")[0]);
			yTemp = Double.parseDouble(donneesTriangle[i].replace("(","").replace(")", "").split(",")[1]);
			x[i-1] = (int)Math.round(xTemp);
			y[i-1] = (int)Math.round(yTemp);
		}
		objetAwt.dessinerTriangle(x,y,couleur);
	}
	/**
     * M�thode pour avoir le type de forme
     * que l'expert sait r�soudre.
     * @return type que l'expert sait r�soudre.
     * 		ici Triangle.
     */
	public String getType(){
		return "Triangle";
	}
}
