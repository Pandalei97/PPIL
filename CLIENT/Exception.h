/**
* \file Exception.h
* \brief Exception.
*/

#pragma once
#include <iostream>
#include <string>

using namespace std;

class Exception {
	string m_msg;  /*! \le message d'exception*/
public:
	/**
	* \brief Seul constructeur de la classe Exception
	* \param string msg
	*/
	Exception(const string&  msg) :m_msg(msg) {}

	/**
	* \brief Getter de l'attribut privé m_msg.
	* \return string Ce que contient l'attribut privé m_msg
	*/
	const string & getMessage() const { return this->m_msg; }


	/**
	* \ brief Surcharge l'affichage dans un flux.
	* \param flux Flux sortant
	* \param e Exception
	* \return ostream Flux sortant
	*/
	friend ostream & operator << (ostream & flux, const Exception & e);
};