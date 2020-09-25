#include "Parser.h"
#include <string>
#include <queue>
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char** argv){
	queue<string> lines;
	ifstream input_file(argv[1]);
	string line;
	while(!input_file.eof()){
		getline(input_file, line);
		lines.push(line);
	}
	Parser p;
	p.ParseDatalog(lines);
	return 0;
}	
