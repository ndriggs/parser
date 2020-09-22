#include "DatalogProgram.h"
#include <set>
#include <string>
#include <sstream>
void DatalogProgram::insertDomainString(string str){
	domain.insert(str);
}

string DatalogProgram::toString(){
	stringstream ss;
	set<string>::iterator it = domain.begin();
	while(it != domain.end()){
		ss << *it << endl;
		it++;
	}
	return ss.str();
}
