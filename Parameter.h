#pragma once
#include <string>
using namespace std;

class Parameter {
private:
	string value;	
public:
	
	Parameter(string value);
	void addSome(string c);
	string toString();
};
