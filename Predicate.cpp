#include "Predicate.h"
#include <string>
#include <vector>
#include <sstream>
using namespace std;

Predicate::Predicate(string id){
	this->id = id;
}

void Predicate::addId(string id){
	this->id = id;
}

void Predicate::addParameter(Parameter* p){
	parameters.push_back(p);
}

string Predicate::toString(){
	stringstream ss;
	ss << id << "(" << parameters[0]->toString();
	for(int i = 1; unsigned(i) < parameters.size(); i++){
		ss << "," << parameters[i]->toString();
	}
	ss << ")" << endl;
	return ss.str();
}
