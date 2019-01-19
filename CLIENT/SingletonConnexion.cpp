#include "SingletonConnexion.h"
#pragma warning(disable:4996) 
#undef max

SingletonConnexion * SingletonConnexion::instance = NULL;

SingletonConnexion::SingletonConnexion() {
	sock = NULL;
}
SingletonConnexion::~SingletonConnexion()
{}

/*la méthode construit l'instance si elle n'existe pas
sinon elle la retourne*/
SingletonConnexion * SingletonConnexion::getInstance() {
	if (instance == NULL)
		instance = new SingletonConnexion();
	return instance;
}

void SingletonConnexion::killInstance() {
	if (instance != NULL) {
		delete instance;
		instance = NULL;
	}
}

bool SingletonConnexion::initialiserConnexion() {
	if (sock != NULL) {
		//throw Exception("Initialisation deja effectuee");
	}
	try {
		int r;
		// structure contenant les données de lalibrairie winsock à initialiser
		WSADATA wsaData;

		// MAKEWORD(2,0) sert à indiquer la version de la librairie à utiliser : 1 pour winsock et 2 pour winsock2
		r = WSAStartup(MAKEWORD(2, 0), &wsaData);
		if (r)
			throw Exception("L'initialisation a echoue");

		cout << "Initialisation de winsock effectuee" << endl;

		//Initialisation du socket
		int familleAdresses = AF_INET;         // IPv4
		int typeSocket = SOCK_STREAM;           // mode connecté TCP
		int protocole = IPPROTO_TCP;            // protocole.

		sock = socket(familleAdresses, typeSocket, protocole);

		if (sock == INVALID_SOCKET) {
			ostringstream oss;
			oss << "la creation du socket a echoue : code d'Exception = " << WSAGetLastError() << endl;
			throw Exception(oss.str().c_str());
		}
		cout << "Socket cree" << endl;

		//Information du serveur
		string adresseServeur;
		short portServeur;

		//Saisir l'adresse IP et le port
		while (true) {
			cout << "tapez l'adresse IP du serveur de dessin : " << endl;
			cin >> adresseServeur;

			if (inet_addr(adresseServeur.c_str()) == INADDR_NONE) {
				cout << "Soyez gentil, donenz un ip correct." << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
			else
				break;
		}

		while (true) {
			cout << "tapez le port du serveur du serveur de dessin : " << endl;
			cin >> portServeur;
			if (cin.fail()) {
				cout << "Soyez gentil, donenz un port correct." << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
			else
				break;
		}

		sockaddr.sin_family = AF_INET;

		// inet_addr() convertit de l'ASCII en entier
		// il faut desavtiver #pragma warning(disable:4996)  
		sockaddr.sin_addr.s_addr = inet_addr(adresseServeur.c_str());

		sockaddr.sin_port = htons(portServeur);

		//Connexion
		r = connect(sock, (SOCKADDR *)&sockaddr, sizeof(sockaddr));
		if (r == SOCKET_ERROR)
			throw Exception("La connexion a echoue");
		cout << "Connexion au serveur de dessin effectuee" << endl;
		return true;
	}
	catch (Exception e) {
		cerr << e << endl;
		return false;
	}
}

void SingletonConnexion::fermerConnexion() {
	try {
		int r;
		r = shutdown(sock, SD_BOTH);
		if (r == SOCKET_ERROR)
			throw Exception("La coupure de connexion a echoue");
		r = closesocket(sock);
		if (r)
			throw Exception("La fermeture du socket a echoue");
		WSACleanup();
		cout << "Fermeture de la connexion effectuee" << endl;
		sock = NULL;
	}
	catch (Exception Exception) {
		cerr << Exception << endl;
	}
}

void SingletonConnexion::envoyerRequete(const string & req) {
	int r;
	string requete = req + "\r\n";
	r = send(sock, requete.c_str(), requete.size(), 0);
	if (r == SOCKET_ERROR)
		throw Exception("Echec de l'envoi de la requête");
}

bool SingletonConnexion::serveurATraiteRequete() {
	char t[10];
	recv(sock, t, 10, 0);
	/*le serveur renvoie '1' si la requete précédente
	a été traitée*/
	if (t[0] == '1')
		return true;
	return false;
}