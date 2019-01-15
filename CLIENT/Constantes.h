/**
* \file Constantes.h
* \brief Fichier qui contient toutes les cpnstantes nécessaires au programme
*/
#pragma once
#include <iostream>
#include <string>

//Taille fenetre pour dessin dans serveur
#define LARGEUR "1000"
#define HAUTEUR "700"

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
/*
#define DEFAULT "unknown"
#define BLACK "black"
#define BLUE "blue"
#define RED "red"
#define GREEN "green"
#define YELLOW "yellow"
#define CYAN "cyan"
*/
const double PI = 3.141592;



