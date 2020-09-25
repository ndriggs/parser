#include "DatalogProgram.h"
#include <set>
#include <string>
#include <sstream>
#include <vector>
void DatalogProgram::insertDomainString(string str){
	domain.insert(str);
}

void DatalogProgram::addScheme(Predicate* scheme){
	schemes.push_back(scheme);
}

void DatalogProgram::addFact(Predicate* fact){
	facts.push_back(fact);
}

void DatalogProgram::addQuery(Predicate* query){
	queries.push_back(query);
}

void DatalogProgram::addRule(Rule* rule){
	rules.push_back(rule);
}

string DatalogProgram::toString(){
	stringstream ss;
	ss << "Schemes(" << schemes.size() << "):" << endl;
	for(int i = 0; (unsigned)i < schemes.size(); i++){
		ss << "  " << schemes[i]->toString();
	}
	ss << "Facts(" << facts.size() << "):" << endl;
	for(int i = 0; (unsigned)i < facts.size(); i++){
		ss << "  " << facts[i]->toString();
	}
	//rules
	ss << "Queries(" << queries.size() << "):" << endl;
	for(int i = 0; (unsigned)i < queries.size(); i++){
		ss << "  " << queries[i]->toString();
	}
	
	
	set<string>::iterator it = domain.begin();
	while(it != domain.end()){
		ss << *it << endl;
		it++;
	}
	return ss.str();
}
