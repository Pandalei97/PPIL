/**
* \file Constantes.h
* \brief Fichier qui contient toutes les cpnstantes nécessaires au programme
*/
#pragma once
#include <iostream>
#include <string>

//Taille fenetre pour dessin dans serveur
const int LARGEUR = 1000;
const int HAUTEUR = 700;

/** couleurs*/
const std::string DEFAULT = "unknown";
const std::string BLACK = "black";
const std::string BLUE = "blue";
const std::string RED = "red";
const std::string GREEN = "green";
const std::string YELLOW = "yellow";
const std::string CYAN = "cyan";

// Chemin du fichier sauvgarde
const std::string CHEMIN = ".//Sauvgardes.txt";

/*Les séparateurs
'-' entre l'identifiant et la forme
':' entre le type de forme et les donnees de la forme
';' entre les donnee
'&' dans un groupe, ce caractère est utilisé pour séparer les différents formes du groupe
*/

const double PI = 3.14159265358979323846;


