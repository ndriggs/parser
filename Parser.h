#pragma once
#include <string>
#include <queue>


using namespace std;

class Parser {
private:
	void check(string tokenName, string line);
	string returnTokenType(string line);
	
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
	void ParseStringList(queue<string> &input);
	void ParseIdList(queue<string> &input);

	void ParseParameter(queue<string> &input);
	void ParseExpression(queue<string> &input);
	void ParseOperator(queue<string> &input);

public:
	void ParseDatalog(queue<string> &input);
};
