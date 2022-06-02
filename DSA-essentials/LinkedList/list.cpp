#include<iostream>
#include "list.h"
using namespace std;

int main(){
	List l;
	l.push_back(5);
	l.push_front(20);
	l.push_front(10);

	l.insert(1, 30);

	// cout << l.linear_search(-1) << endl;
	// cout << l.recursive_search(-1) << endl;

	// l.pop_front();
	// l.pop_back();

	// l.pop(0);
	// l = l.reverse();

	// cout << l.get_last_kth_node(2) << endl;

	l.print();
	cout << endl;

	l.bubble_sort();
	l.print();

	// List r;
	// r.push_front(4);
	// r.push_back(5);
	// r.push_back(6);
	// r.push_back(7);

	// r.print();
	// cout << endl;

	// List p = l.merge_lists(r);

	// p.print();
	
	return 0;
}