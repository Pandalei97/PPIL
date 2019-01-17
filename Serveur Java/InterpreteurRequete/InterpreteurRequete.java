package InterpreteurRequete;

import java.io.PrintStream;

import main.InterfaceGraphic;

/**
 * 
 * 
 * <b>Classe abstraite représentant la chaine de responsabilité 
 * pour interpréter une requete à partir d'une chaine de caractere</b>
 * 
 * 
 */

public abstract class InterpreteurRequete {
	public abstract boolean interpreterRequete(String requete, InterfaceGraphic objetAwt, PrintStream fluxSortant);
}