#pragma once
#include <string>
#include <queue>
#include "DatalogProgram.h"

using namespace std;

class Parser {
private:
	DatalogProgram dp;
	
	void check(string tokenName, string line);
	string returnTokenType(string line);
	string getTokenValue(string line);	

	void ParseSchemeList(queue<string> &input);
	void ParseFactList(queue<string> &input);
	void ParseRuleList(queue<string> &input);
	void ParseQueryList(queue<string> &input);
	
	void ParseScheme(queue<string> &input);
	void ParseFact(queue<string> &input);
	void ParseRule(queue<string> &input);
	void ParseQuery(queue<string> &input);

	void ParseHeadPredicate(queue<string> &input);
	void ParsePredicate(queue<string> &input);

	void ParsePredicateList(queue<string> &input);
	void ParseParameterList(queue<string> &input);
	void ParseStringList(queue<string> &input, Predicate*& f);
	void ParseIdList(queue<string> &input, vector<string> &ids);

	void ParseParameter(queue<string> &input);
	void ParseExpression(queue<string> &input);
	void ParseOperator(queue<string> &input);

public:
	void ParseDatalog(queue<string> &input);
};
