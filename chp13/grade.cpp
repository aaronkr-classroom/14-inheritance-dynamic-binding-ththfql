#include <algorithm>
#include <list>
#include <vector>
#include <stdexcept>

#include "grade.h"

using namespace std;


double grade(double mt, double ft, double hw) {
	return 0.2 * mt + 0.4 * ft + 0.4 * hw;
}

double grade(mt, double ft, const vector<double>& hw) {
	if (hw.size() == 0)
		throw domain_error("No homework!");

	return grade(mt, ft, median(hw));
}