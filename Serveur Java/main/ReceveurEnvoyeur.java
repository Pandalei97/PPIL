package main;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.net.Socket;

/**
 * Classe ReceveurEnvoyeur qui h�rite de Thread
 * Car � chaque nouveau client on va lui attribuer un thread 
 * pour pouvoir rendre l'applciation multi-client.
 *
 */
public class ReceveurEnvoyeur extends Thread{
	/**
	 * D�claration du socket
	 */
	Socket socket;
	/**
	 * int pour le num�ro de la connexion
	 */
	int noConnexion;
	
	/**
	 * Buffer permettant de lire ce qui arrive sur le r�seau
	 */
	BufferedReader fluxEntrant;
	/**
	 * Flux permettant d'ecrire � travers le r�seau
	 */
	PrintStream fluxSortant;
	
	/**
	 * Constructeur de la classe ReceveurEnvoyeur
	 * @param socket
	 * 		Le socket de la classe
	 * @param groupe
	 * 		Groupe de thread
	 * @param noConnexion
	 *		Le num�ro de la connexion
	 * @throws IOException
	 * 		permettant de g�rer les exceptions d'entr�e/sortie
	 */
	public ReceveurEnvoyeur(Socket socket, ThreadGroup groupe, int noConnexion) throws IOException{
		super(groupe,"receveurEnvoyeur");
		this.socket = socket;
		this.noConnexion = noConnexion;
		fluxEntrant = new BufferedReader(new InputStreamReader(this.socket.getInputStream()));
		fluxSortant = new PrintStream(this.socket.getOutputStream());
	}
	/**
	 * M�thode run du thread qui est actif tant qu'il n'y sort pas
	 */
	public void run(){
		/**
		 * La requ�te re�ue en provenance du client
		 */
		String requete;
		/**
		 * Notre objet pour int�ragir avec la fenetre
		 */
		InterfaceGraphic objetAwt = new ObjetAwtFenetre();
		try{
			while (!isInterrupted()){
				//On lit le flux d'entr�e
				requete = fluxEntrant.readLine();
				//Si c'est non null
				if(requete != null){
					System.out.println(" le client n� "+this.noConnexion+" a envoy� : ");
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

