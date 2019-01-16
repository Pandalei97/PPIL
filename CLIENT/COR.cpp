#include "COR.h"

COR * COR::instance = NULL;



COR::COR() {
	ChargerFormeCOR *ChargeurCercle, *ChargeurSegment, *ChargeurPolygone, *ChargeurGroupe, *ChargeurTriangle;
	ChargeurCercle = new ChargerFormeCORCercle(NULL);
	ChargeurSegment = new ChargerFormeCORSegment(ChargeurCercle);
	ChargeurPolygone = new ChargerFormeCORPolygone(ChargeurSegment);
	ChargeurGroupe = new ChargerFormeCORGroupe(ChargeurPolygone);
	ChargeurTriangle = new ChargerFormeCORTriangle(ChargeurGroupe);
	chargeurForme = ChargeurTriangle;
}

COR::~COR()
{}

COR * COR::getInstance() {
	if (instance == NULL)
		instance = new COR();
	return instance;
}

ChargerForme * COR::getChargeurForme() {
	return chargeurForme;
}