#pragma once
#include <string>
#include <vector>
#include "Parameter.h"
using namespace std;

class Predicate {
private:
	string id;
	vector<Parameter*> parameters;
public:
	Predicate(string id);
	void addParameter(Parameter* p);
	string toString();
};
