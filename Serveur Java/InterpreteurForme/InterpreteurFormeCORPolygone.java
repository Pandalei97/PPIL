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

public class InterpreteurFormeCORPolygone extends InterpreteurFormeCOR {

	/**
	 * Méthode qui interprete directement un polygone.
	 * @param forme
	 * 		La chaine de caractere de la couleur a interpréter
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
     * Méthode pour avoir le type de forme
     * que l'expert sait résoudre.
     * @return type que l'expert sait résoudre.
     * 		ici Polygone.
     */
	public String getType(){
		return "Polygone";
	}
}
