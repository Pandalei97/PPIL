package InterpreteurRequete;

import java.io.PrintStream;

import main.InterfaceGraphic;

/**
 * 
 * 
 * <b>Classe abstraite repr�sentant la chaine de responsabilit� 
 * pour interpr�ter une requete � partir d'une chaine de caractere</b>
 * 
 * 
 */

public abstract class InterpreteurRequete {
	public abstract boolean interpreterRequete(String requete, InterfaceGraphic objetAwt, PrintStream fluxSortant);
}