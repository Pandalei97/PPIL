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
	*	\brief Constructeur par d�faut priv�
	*/
	SingletonConnexion();

	/**
	*	\brief Destructeur
	*/
	~SingletonConnexion();
public:

	/**
	* \brief Retourne une instance unique
	* \details Va cr�er l'instance si celle-ci n'existe pas ou bien juste la retourner dans le cas contraire
	* \return SingletonConnexion* Pointeur sur l'instance unique
	*/
	static SingletonConnexion *getInstance();

	/**
	* \brief Ferme l'instance unique en cours
	*/
	static void killInstance();

	/**
	* \brief Initialise la connexion vers le serveur
	* \return bool Bool�en vrai si la connexion est r�ussie, faux sinon
	*/
	bool initialiserConnexion();

	/**
	* \brief Ferme la connexion vers le serveur
	*/
	void fermerConnexion();

	/**
	* \brief Envoie une requ�te au serveur
	* \param str La chaine de caract�re � envoyer au serveur
	*/
	void envoyerRequete(const string &str);

	/**
	* \brief Teste si une requ�te a �t� trait�e par le serveur
	* \return bool Bool�en vrai si la requ�te a �t� trait�e, faux sinon
	*/
	bool serveurATraiteRequete();
};