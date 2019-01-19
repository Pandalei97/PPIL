#include "Vecteur2D.h"
#include "Exception.h"
#include <cmath>

Vecteur2D::Vecteur2D(const double& x, const double &y):m_x(x), m_y(y) {}

Vecteur2D::Vecteur2D(const Vecteur2D& v) : m_x(v.m_x), m_y(v.m_y){}

Vecteur2D::~Vecteur2D(){}

const double Vecteur2D::getX()const
{
	return m_x;
}

void Vecteur2D::setX(const double & x)
{
	m_x = x;
}

const double Vecteur2D::getY()const
{
	return m_y;
}

void Vecteur2D::setY(const double & nouveauY)
{
	m_x = nouveauY;
}

const Vecteur2D Vecteur2D::operator+(const Vecteur2D& v)const {
	return Vecteur2D(m_x + v.m_x, m_y + v.m_y);
}

const Vecteur2D Vecteur2D::operator*(const double& a)const {
	return Vecteur2D(a*m_x, a*m_y);
}

const Vecteur2D Vecteur2D::operator-()const {
	return Vecteur2D(-m_x, -m_y);
}

bool Vecteur2D::operator==(const Vecteur2D& v)const {
	return (m_x == v.m_x) && (m_y == v.m_y);
}

bool Vecteur2D::operator!=(const Vecteur2D& v)const {
	return !(*this == v);
}

const Vecteur2D Vecteur2D:: operator = (const Vecteur2D & v)
{
	if (this != &v)
	{
		m_x = v.m_x;
		m_y = v.m_y;
	}
	return (*this);
}
Vecteur2D::operator string() const {
	ostringstream s;
	s << "(" << m_x << ", " << m_y << ")";
	return s.str();
}

ostream & operator << (ostream & os, const Vecteur2D & u)
{
	os << string(u);
	return os;
}

void Vecteur2D::homothetie(const Vecteur2D & pointInvariant, double k)
{
	if (k <= 0)
		throw Exception("k ne doit pas être négatif!");
	(*this) = k * (*this) + (1 - k) * pointInvariant;
}

void Vecteur2D::translation(const Vecteur2D & vectTranslation)
{
	Vecteur2D vect(*this);
	vect = vect + vectTranslation;
	(*this) = vect;
}

void Vecteur2D::rotation(const Vecteur2D & vectCentre, double angle)
{
	double deltaX = m_x - vectCentre.m_x, deltaY = m_y - vectCentre.m_y;
	m_x = deltaX * cos(angle) - deltaY * sin(angle) + vectCentre.m_x;
	m_y = deltaX * sin(angle) + deltaY * cos(angle) + vectCentre.m_y;
}

const double Vecteur2D::determinant(const Vecteur2D & vect) const
{
	return (m_x * vect.m_y) - (m_y * vect.m_x);
}

