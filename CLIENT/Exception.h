/**
* \file Exception.h
* \brief Exception.
*/

#pragma once
#include<iostream>
#include<string>

using namespace std;

class Exception {
	string m_msg;  /*! \le message d'exception*/
public:
	/**
	* \ brief Constructeur .
	* \param msg
	*/
	Exception(const string&  msg) :m_msg(msg) {}

	/**
	* \ brief getter du champ \a m_msg.
	* \return \e string le message stockée dans le champ \a m_msg.
	*/
	const string & getMessage() const { return this->m_msg; }


	/**
	* \ brief Surcharge l'affichage dans un flux.
	* \param flux.
	* \param exception.
	* \return \e ostream flux.
	*/
	friend ostream & operator << (ostream & flux, const Exception & e);
};