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

public class InterpreteurFormeCORPolygone extends InterpreteurFormeCOR {

	/**
	 * M�thode qui interprete directement un polygone.
	 * @param forme
	 * 		La chaine de caractere de la couleur a interpr�ter
	 * Elle ne retourne rien elle dessiner le Polygone.
	 */
	
	public void genererDessin(String forme, InterfaceGraphic objetAwt){
		//donnesPolygone contient [couleur,point1,point2,point3,......,pointn]
		String[] donneesPolygone = forme.split(";");
		String couleurNonInterpretee = donneesPolygone[0];
		Color couleur = COR.getInstance().getInterpreteurCouleur().interpreterCouleur(couleurNonInterpretee);
		int taille = donneesPolygone.length -1;
		int[] x = new int[taille];
		int[] y = new int[taille];
		double xTemp;
		double yTemp;
		for(int i = 1; i< donneesPolygone.length; i++){
			xTemp =Double.parseDouble(donneesPolygone[i].replace("(","").replace(")", "").split(",")[0]);
			yTemp = Double.parseDouble(donneesPolygone[i].replace("(","").replace(")", "").split(",")[1]);
			x[i-1] = (int)Math.round(xTemp);
			y[i-1] = (int)Math.round(yTemp);
		}
		objetAwt.dessinerPolygone(x,y, taille, couleur);
	}
	/**
     * M�thode pour avoir le type de forme
     * que l'expert sait r�soudre.
     * @return type que l'expert sait r�soudre.
     * 		ici Polygone.
     */
	public String getType(){
		return "Polygone";
	}
}
