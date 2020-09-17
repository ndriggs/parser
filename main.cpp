#include "Parser.h"
#include <string>
#include <queue>
#include <iostream>
#include <fstream>

using namespace std;

int main(){
	queue<string> lines;
	ifstream input_file("tokens.txt");
	string line;
	while(!input_file.eof()){
		getline(input_file, line);
		lines.push(line);
	}
	Parser p;
	p.ParseDatalog(lines);
	return 0;
}	
