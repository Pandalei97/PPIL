#include "ChargerFormeCOR.h"
#include "Constantes.h"
#include <fstream>
ChargerFormeCOR::ChargerFormeCOR(ChargerFormeCOR * s):suivant(s){}

string ChargerFormeCOR::getInfoForme(const string& idForme)const {
	ifstream fichier(CHEMIN, ios::in);
	string ligne;
	while (getline(fichier,ligne)) {
		string id = ligne.substr(0, ligne.find('-'));
		//cout << id << endl;
		if (id == idForme) {
			fichier.close();
			return ligne.substr(ligne.find('-') + 1);
		}
			
	}
	fichier.close();
	return "";
}

Vecteur2D ChargerFormeCOR::stringToPoint(const string& infoPoint)const {
	string x = infoPoint.substr(1, infoPoint.find(',') - 1);
	//cout << "STRING X = " << x << endl;
	string y = infoPoint.substr(infoPoint.find(',') + 1 , infoPoint.find(')') - infoPoint.find(','));
	//cout << "STRING Y = " << y << endl;
	//stod(s) transforme un string en double
	return Vecteur2D(stod(x), stod(y));
}

Forme* ChargerFormeCOR::charger(const string & idForme, const string &info)const {
	string infoForme;

	if (info == "") {
		//cout << "CEST UNE FORME AVEC ID" << endl;
		infoForme = getInfoForme(idForme);
	}
		
	else {
		//cout << "ON A PASSE UNE COMPOSANT MAIS PAS ID" << endl;
		infoForme = info;
	}
		

	//Si idForme n'existe pas, on retourne directement NULL
	if (infoForme == "")
		return NULL;

	//cout << infoForme << endl;
	//On extrait la partie de la chaine qui repr�sente le type de la forme
	string typeForme = infoForme.substr(0, infoForme.find(':'));
	//cout << typeForme << endl;
	//Chaque expert ne peut que r�soudre un type de forme, sa capacit� est d�crit par getTypeForme();
	if (typeForme == getTypeForme()){
		//Si le type pass� corresponds � sa capacit�, on lui passe les donn�es de la chaine et il va d�compos� les donn�es
		string donneesForme = infoForme.substr(infoForme.find(':') + 1);
		//cout << donneesForme << endl;
		return traiterDemande(donneesForme);
	}
	//cet expert ne peut pas r�soudre le probl�me, on le passe au suivant si le suivant n'est pas NULL;
	if (suivant == NULL)
		return NULL;

	return suivant->charger(idForme, infoForme);
}