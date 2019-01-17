package main;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.net.Socket;

/**
 * Classe ReceveurEnvoyeur qui hérite de Thread
 * Car à chaque nouveau client on va lui attribuer un thread 
 * pour pouvoir rendre l'applciation multi-client.
 *
 */
public class ReceveurEnvoyeur extends Thread{
	/**
	 * Déclaration du socket
	 */
	Socket socket;
	/**
	 * int pour le numéro de la connexion
	 */
	int noConnexion;
	
	/**
	 * Buffer permettant de lire ce qui arrive sur le réseau
	 */
	BufferedReader fluxEntrant;
	/**
	 * Flux permettant d'ecrire à travers le réseau
	 */
	PrintStream fluxSortant;
	
	/**
	 * Constructeur de la classe ReceveurEnvoyeur
	 * @param socket
	 * 		Le socket de la classe
	 * @param groupe
	 * 		Groupe de thread
	 * @param noConnexion
	 *		Le numéro de la connexion
	 * @throws IOException
	 * 		permettant de gérer les exceptions d'entrée/sortie
	 */
	public ReceveurEnvoyeur(Socket socket, ThreadGroup groupe, int noConnexion) throws IOException{
		super(groupe,"receveurEnvoyeur");
		this.socket = socket;
		this.noConnexion = noConnexion;
		fluxEntrant = new BufferedReader(new InputStreamReader(this.socket.getInputStream()));
		fluxSortant = new PrintStream(this.socket.getOutputStream());
	}
	/**
	 * Méthode run du thread qui est actif tant qu'il n'y sort pas
	 */
	public void run(){
		/**
		 * La requête reçue en provenance du client
		 */
		String requete;
		/**
		 * Notre objet pour intéragir avec la fenetre
		 */
		InterfaceGraphic objetAwt = new ObjetAwtFenetre();
		try{
			while (!isInterrupted()){
				//On lit le flux d'entrée
				requete = fluxEntrant.readLine();
				//Si c'est non null
				if(requete != null){
					System.out.println(" le client n° "+this.noConnexion+" a envoyé : ");
					System.out.println(requete);
				}
				requete = requete.trim();
				
				//interpretation de la requete avec la COR
				boolean interpreteOk = COR.getInstance().getInterpreteurRequete().interpreterRequete(requete, objetAwt, fluxSortant);
				if(!interpreteOk)
					System.out.println("Requete non interpretee");
				sleep(5);
			}
		}
		//Gestion des erreurs
		catch(NullPointerException erreur){}
		catch(InterruptedException erreur) {}
		catch(IOException erreur) { System.err.println(" on ne peut pas lire sur le socket provenant du client");}
		 
	}
}

