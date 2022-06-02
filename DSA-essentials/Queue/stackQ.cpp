#include<iostream>
#include "stackQ.h"
using namespace std;

int main(){
	Stack<int> s;
	s.push(1);
	s.push(3);
	s.push(5);
	s.push(7);
	s.pop();
	s.push(9);

	cout << s.top() << endl;

	s.print();	// will empty the stack.


	return 0;
}