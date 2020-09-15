#include "test.h"
#include <string>
#include <queue>
#include <iostream>

using namespace std;

int main(){
	queue<string> lines;
	lines.push("zero");
	lines.push("one");
	lines.push("two");
	lines.push("three");
	cout << lines.front() << endl;
	lines.pop();
	cout << lines.front() << endl;	

	string input = "(SCHEMES,\"Schemes\",4)";
	Test t;
	t.parser(lines);
	return 0;
}	
