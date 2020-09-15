#include <queue>
#include <iostream>
#include <string>

using namespace std;

void popOne(queue<string> &input){
	input.pop();
	return;
}

int main(){
	queue<string> q;
	q.push("zero");
	q.push("one");
	q.push("two");
	q.push("three");

	cout << "size: " << q.size() << endl;
	popOne(q);
	cout << "new size: " << q.size() << endl;



	return 0;
}
