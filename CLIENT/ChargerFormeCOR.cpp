#include "ChargerFormeCOR.h"
#include "Constantes.h"
#include <fstream>
ChargerFormeCOR::ChargerFormeCOR(ChargerFormeCOR * s):suivant(s){}

string ChargerFormeCOR::getInfoForme(const string& idForme)const {
	ifstream fichier(CHEMIN, ios::in);
	string ligne;
	while (getline(fichier,ligne)) {
		string id = ligne.substr(0, ligne.find('-'));
		if (id == idForme)
			return ligne.substr(0, ligne.find('-') + 1);
	}
	return "";
}

Vecteur2D ChargerFormeCOR::stringToPoint(const string& infoPoint)const {
	string x = infoPoint.substr(1, infoPoint.find(',') - 1);
	string y = infoPoint.substr(infoPoint.find(','), infoPoint.find(')') - infoPoint.find(','));
	//stod(s) transforme un string en double
	return Vecteur2D(stod(x), stod(y));
}

Forme* ChargerFormeCOR::charger(const string & idForme, const string &info)const {
	string infoForme;
	if (info == "")
		infoForme = getInfoForme(idForme);
	else
		infoForme = info;


	//Si idForme n'existe pas, on retourne directement NULL
	if (infoForme == "")
		return NULL;

	//On extrait la partie de la chaine qui repr�sente le type de la forme
	string typeForme = infoForme.substr(0, infoForme.find(':'));
	//Chaque expert ne peut que r�soudre un type de forme, sa capacit� est d�crit par getTypeForme();
	if (typeForme == getTypeForme()){
		//Si le type pass� corresponds � sa capacit�, on lui passe les donn�es de la chaine et il va d�compos� les donn�es
		string donneesForme = infoForme.substr(infoForme.find(':') + 1);
		return traiterDemande(donneesForme);
	}
	//cet expert ne peut pas r�soudre le probl�me, on le passe au suivant si le suivant n'est pas NULL;
	if (suivant == NULL)
		return NULL;

	return suivant->charger(infoForme);
}