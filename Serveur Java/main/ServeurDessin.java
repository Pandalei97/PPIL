package main;

import java.net.InetAddress;
import java.net.ServerSocket;
import java.net.Socket;
import java.net.SocketException;

/**
 * Classe principale du serveur, elle contient le MAIN
 *
 */
public class ServeurDessin{
	/**
	 * Méthode MAIN
	 * @param args
	 * 		Les arguments passés à la méthode main
	 * @throws Exception
	 * 		Permet de gérer les diverses exceptions
	 * 		
	 */
	public static void main(String[] args) throws Exception{
		/**
		 * ServerSocket  permettant la connexion avec le client
		 */
		ServerSocket serveur;
		serveur = new ServerSocket(4444); 
		
		System.out.println("Serveur de dessin démarré : "+serveur);
		
		/**
		 * Adresse locale de la machine sur laquelle
		 * est lancée le serveur
		 */
		InetAddress machineLocale;
		/**
		 * Port sur lequel le serveur doit écouter
		 */
		int portLocal;
		/**
		 * Groupe de thread
		 */
		ThreadGroup groupe;
		
		portLocal = serveur.getLocalPort();
		
		machineLocale = InetAddress.getLocalHost();
		
		System.out.println("adresse IP du serveur de majuscule : "+machineLocale.getHostAddress());
		System.out.println("port du serveur : "+portLocal);
		
		//Création d'un nouveau groupe de threads
		
		groupe = new ThreadGroup("socketsClients");
		//On initialise le numéro de connexion
		int noConnexion = 0;
		while(true){
			try{
				/**
				 * Socket pour le nouveau client connecté
				 */
				Socket nouveauClientSocket;
				/**
				 * Instanciation de la classe ReceveurEnvoyeur
				 * pour lancer un thread par client
				 */
				ReceveurEnvoyeur nouveauClientThread;
				
				//Client se connecte au serveur
				nouveauClientSocket = serveur.accept(); 
				//On incrémente le numéro de connexion
				++noConnexion;
				System.out.println("Connexion réussie n° : "+noConnexion);
				
				//On instancie une nouvelle instance de l'objet ReceveurEnvoyeur
				nouveauClientThread = new ReceveurEnvoyeur(nouveauClientSocket, groupe, noConnexion); 
				//On lance le thread
				nouveauClientThread.start();
			}
			catch(SocketException erreur){
				//Si une erreur alors on ferme la connexion
				serveur.close();
			}
		}
	}
}
