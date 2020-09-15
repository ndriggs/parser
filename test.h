#pragma once
#include <string>
#include <queue>
using namespace std;

class Test {
private:
public:
	void check(string id, string line);
	void parser(queue<string> lines);
};
