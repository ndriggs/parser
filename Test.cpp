#include "test.h"
#include <string>
#include <iostream>
#include <queue>
//Test::Test(){}

void Test::check(string id, string line){
	size_t comma;
	comma = line.find(",");
	if(line.substr(1,comma - 1) == id)
		return;
	else
		throw(line);
}

void Test::parser(queue<string> lines){
	try{
		check("SCHEMES", lines.front());
		cout << "a schemes object was added" << endl;
	} catch(string line) {
		cout << "Failure!" << endl << line << endl;
	}
}
