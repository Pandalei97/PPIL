/**
* \file SingletonConnexion.h
* \brief Classe singleton pour assurer une seule instance d'une connexion.
*/
#pragma once
#include <winsock2.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "Exception.h"
using namespace std;
#pragma comment(lib, "ws2_32.lib")


class SingletonConnexion {
private:
	SOCKET sock;
	//Structures for handling internet addresses
	SOCKADDR_IN sockaddr;

	static SingletonConnexion *instance;  /*! \a  instance qui est de type SingletonConnexion *, unique instance du singleton. */


	/**
	*	\brief constructeur privé.
	*/
	SingletonConnexion();

	/**
	*	\brief destructeur privé.
	*/
	~SingletonConnexion();
public:
	//méthode qui retourne l'instance unique (la créer si non créée et la retourne si déjà créée)
	static SingletonConnexion *getInstance();
	//méthode pour détruire l'instance
	static void killInstance();
	//méthode pour initialiser la connexion vers un serveur
	bool initialiserConnexion();
	//fermer une connexion
	void fermerConnexion();
	//envoie d'une requete vers le serveur connecté
	void envoyerRequete(const string &);
	//métohde qui attend la réponse d'un serveur (bloquant)
	bool serveurATraiteRequete();
};