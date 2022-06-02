#include<iostream>
#include "queueLL.h"
using namespace std;


int main(){
	Queue<int> q;
	q.push(2);
	q.push(4);
	q.push(6);
	q.push(8);
	q.push(10);
	q.push(12);
	q.push(14);

	q.pop();

	q.push(24);

	q.print();

	cout << q.front() << endl;
	return 0;
}