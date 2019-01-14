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
	*	\brief constructeur priv�.
	*/
	SingletonConnexion();

	/**
	*	\brief destructeur priv�.
	*/
	~SingletonConnexion();
public:
	//m�thode qui retourne l'instance unique (la cr�er si non cr��e et la retourne si d�j� cr��e)
	static SingletonConnexion *getInstance();
	//m�thode pour d�truire l'instance
	static void killInstance();
	//m�thode pour initialiser la connexion vers un serveur
	bool initialiserConnexion();
	//fermer une connexion
	void fermerConnexion();
	//envoie d'une requete vers le serveur connect�
	void envoyerRequete(const string &);
	//m�tohde qui attend la r�ponse d'un serveur (bloquant)
	bool serveurATraiteRequete();
};