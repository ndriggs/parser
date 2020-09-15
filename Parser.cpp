#include "Parser.h"
#include <string>

Parser::Parser(){}

string Parser::checkToken(string tokenToCheck, string lineFromLexer){
	
}

type Parser::ParseScheme(){
	//check ID 
	//check left paren
	//check ID
	ParseIdList();
	//check right paren
	return;
}

type Parser::ParseIdList(){
	if(first val is not comma)
		return; //it's a lambda
	//check ID
	ParseIdList(); //recursion
}

type ParseDatalog();
type ParseSchemeList();
type ParseFactList();
type ParseRuleList();
type ParseQueryList();

type Parser::ParseScheme(string linesOfTokens){
	checkToken('ID'); // what should it do if it's not an ID... if it is? 
}
type ParseFact();
type ParseRule();
type ParseQuery              
type ParseHeadPredicate();        
type ParsePredicate();     
type ParsePredicateList();
type ParseParameterList();	        
type ParseStringList()
type ParseIdList();
type ParseParameter();   
type ParseExpresion();
type ParseOperator();
