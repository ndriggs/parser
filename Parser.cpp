#include "Parser.h"
#include "DatalogProgram.h"
#include "Predicate.h"
#include "Parameter.h"
#include <string>
#include <queue>
#include <iostream>

void Parser::check(string tokenName, string line){
	size_t comma_pos;
	comma_pos = line.find(",");
	if(line.substr(1, comma_pos - 1) == tokenName)
		return;
	else
		throw(line);	
}

string Parser::returnTokenType(string line){
	size_t comma_pos;
	comma_pos = line.find(",");
	return line.substr(1, comma_pos - 1);
}

string Parser::getTokenValue(string line){
	size_t first_quote, second_quote;
	first_quote = line.find("\"");
	second_quote = line.find("\"", first_quote + 1);
	return line.substr(first_quote + 1, second_quote - first_quote - 1);
}

void Parser::ParseDatalog(queue<string> &input){
	try{
		check("SCHEMES", input.front());
		input.pop();
		check("COLON", input.front());
		input.pop();
		ParseScheme(input);
		ParseSchemeList(input);
		check("FACTS", input.front());
	       	input.pop();	
		check("COLON", input.front());
		input.pop();
		ParseFactList(input);
		check("RULES", input.front());
		input.pop();
		check("COLON", input.front());
		input.pop();
		ParseRuleList(input);
		check("QUERIES", input.front());
		input.pop();
		check("COLON", input.front());
		input.pop();
		ParseQuery(input);
		ParseQueryList(input);
		check("EOF", input.front());
		cout << "Success!" << endl;
		cout << dp.toString() << endl;
	} catch(string line) {
		cout << "Failure!" << endl << line << endl;
	}
}



void Parser::ParseSchemeList(queue<string> &input){
	string tokenType = returnTokenType(input.front());
	if(tokenType != "ID")
		return;
	ParseScheme(input);
	ParseSchemeList(input);
}

void Parser::ParseFactList(queue<string> &input){
	string tokenType = returnTokenType(input.front());
	if(tokenType != "ID")
	       return;
	ParseFact(input);
	ParseFactList(input);
}

void Parser::ParseRuleList(queue<string> &input){
	string tokenType = returnTokenType(input.front());
	if(tokenType != "ID")
		return;
	ParseRule(input);
	ParseRuleList(input);
}

void Parser::ParseQueryList(queue<string> &input){
	if(returnTokenType(input.front()) != "ID")
		return;
	ParseQuery(input);
	ParseQueryList(input);
}

void Parser::ParseScheme(queue<string> &input){
	check("ID", input.front());
	string id = getTokenValue(input.front());
	Predicate* s = new Predicate(id);
    	input.pop();
	check("LEFT_PAREN", input.front());
	input.pop();
	check("ID", input.front());
	id = getTokenValue(input.front());
	vector<string> ids;
	ids.push_back(id);
	input.pop();
	ParseIdList(input, ids);
	for(int i = 0; (unsigned)i < ids.size(); i++){
		s->addParameter(new Parameter(ids[i]));
	}
	check("RIGHT_PAREN", input.front());
	input.pop();
	dp.addScheme(s);
	return;	
}

void Parser::ParseFact(queue<string> &input){
	check("ID", input.front());
	string id = getTokenValue(input.front());
	Predicate* f = new Predicate(id);
	input.pop();
	check("LEFT_PAREN", input.front());
	input.pop();
	check("STRING", input.front());
	string str = getTokenValue(input.front());
	dp.insertDomainString(str);
        f->addParameter(new Parameter(str));	
	input.pop();
	ParseStringList(input, f);
	check("RIGHT_PAREN", input.front());
	input.pop();
	check("PERIOD", input.front());
	input.pop();
	dp.addFact(f);
	return;
}

void Parser::ParseRule(queue<string> &input){
	ParseHeadPredicate(input);
	check("COLON_DASH", input.front());
	input.pop();
	ParsePredicate(input);
	ParsePredicateList(input);
	check("PERIOD", input.front());
	input.pop();
	return;
}

void Parser::ParseQuery(queue<string> &input){
	if(returnTokenType(input.front()) != "ID")
		return;
	ParsePredicate(input);
	check("Q_MARK", input.front());
 	input.pop();
	return;
}

void Parser::ParseHeadPredicate(queue<string> &input){
	check("ID", input.front());
	input.pop();
	check("LEFT_PAREN", input.front());
	input.pop();
	check("ID", input.front());
	input.pop();
	Predicate* s = new Predicate("random string");
	vector<string> ids;
	ParseIdList(input, ids); ////need some changes here
	check("RIGHT_PAREN", input.front());
	input.pop();
	return;
}

void Parser::ParsePredicate(queue<string> &input){
	check("ID", input.front());
	input.pop();
	check("LEFT_PAREN", input.front());
	input.pop();
	ParseParameter(input);
	ParseParameterList(input);
	check("RIGHT_PAREN", input.front());
	input.pop();
	return;
}

void Parser::ParsePredicateList(queue<string> &input){
	if(returnTokenType(input.front()) != "COMMA")
		return;
	input.pop();
	ParsePredicate(input);
	ParsePredicateList(input);
	return;
}

void Parser::ParseParameterList(queue<string> &input){
	if(returnTokenType(input.front()) != "COMMA")
		return;
	input.pop();
	ParseParameter(input);
	ParseParameterList(input);
	return;
}

void Parser::ParseStringList(queue<string> &input, Predicate*& f){
	if(returnTokenType(input.front()) != "COMMA")
		return;
	input.pop();
	check("STRING", input.front());
	string str = getTokenValue(input.front());
	dp.insertDomainString(str);
	f->addParameter(new Parameter(str));
	input.pop();
	ParseStringList(input, f);
	return;
}

void Parser::ParseIdList(queue<string> &input, vector<string> &ids){
	string tokenType = returnTokenType(input.front());
	if(tokenType != "COMMA")
		return;
	input.pop();
	check("ID", input.front());
	string id = getTokenValue(input.front());
	ids.push_back(id);
	input.pop();
	ParseIdList(input, ids);
	return;
}
	
void Parser::ParseParameter(queue<string> &input){
	string tokenType = returnTokenType(input.front());
	if((tokenType == "STRING") || (tokenType == "ID")){
		input.pop();
		return;
	} else{
		ParseExpression(input);
		return;
	}
}

void Parser::ParseExpression(queue<string> &input){
	check("LEFT_PAREN", input.front());
	input.pop();
	ParseParameter(input);
	ParseOperator(input);
	ParseParameter(input);
	check("RIGHT_PAREN", input.front());
	input.pop();
	return;
}

void Parser::ParseOperator(queue<string> &input){
	string tokenType = returnTokenType(input.front());
	if((tokenType == "ADD") || (tokenType == "MULTIPLY")){
		input.pop();
		return;
	}
	else{
		throw(input.front());
	}
}
