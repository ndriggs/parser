#include "Parser.h"
#include <string>
#include <queue>

Parser::Parser(){}

void Parser::check(string tokenName, string line){
	size_t comma_pos;
	comma_pos = line.find(",");
	if(line.substr(1, comma_pos - 1) == tokenName)
		return;
	else
		throw(line);	
}

type Parser::ParseIdList(){
	if(first val is not comma)
		return; //it's a lambda
	//check ID
	ParseIdList(); //recursion
}

type ParseDatalog(queue<string> input){
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
	} catch(string line) {
		cout << "Failure!" << endl << line << endl;
	}
}



void ParseSchemeList(queue<string> &input);
void ParseFactList(queue<string> &input);
void ParseRuleList(queue<string> &input);
void ParseQueryList(queue<string> &input);

void Parser::ParseScheme(queue<string> &input){
	check("ID", input.front());
    	input.pop();
	check("LEFT_PAREN", input.front());
	input.pop();
	check("ID", input.front());
	input.pop();
	ParseSchemeList(input);
	check("RIGHT_PAREN", input.front());
	return;	
}

void ParseFact();
void ParseRule();
void ParseQuery              
void ParseHeadPredicate();        
void ParsePredicate();     
void ParsePredicateList();
void ParseParameterList();	        
void ParseStringList()
void ParseIdList();
void ParseParameter();   
void ParseExpresion();
void ParseOperator();
