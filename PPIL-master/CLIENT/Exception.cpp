#include "Exception.h"

ostream& operator<< (ostream & flux, const Exception & e) {
	flux << e.getMessage() << endl;
	return flux;
}