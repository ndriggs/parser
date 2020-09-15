#pragma once

using namespace std;

class Parser {
private:

public:
	void check(string tokenName, string line);
	string returnTokenType(string line);
	
	type ParseDatalog();
	
	type ParseSchemeList();
	type ParseFactList();
	type ParseRuleList();
	type ParseQueryList();
	
	type ParseScheme();
	type ParseFact();
	type ParseRule();
	type ParseQuery();

	type ParseHeadPredicate();
	type ParsePredicate();

	type ParsePredicateList();
	type ParseParameterList();
	type ParseStringList()
	type ParseIdList();

	type ParseParameter();
	type ParseExpression();
	type ParseOperator();

};
