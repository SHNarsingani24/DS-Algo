#include<iostream>
#include<vector>
#include "tree.h"
using namespace std;

int main(){
	vector<int>v = {1, 2, 4, -1, -1, 5, 7, -1, -1, -1, 3, -1, 6, -1, -1};
	Tree<int> t(v, -1);
	t.postorder_traversal(t.root);
	cout << endl;
	t.levelorder_traversal();
	cout << endl;
	Tree<int>t2(t.levelorder_build(vector<int>{1, 2, 3, 4, 5, -1, 6, -1, -1, 7, -1, -1, -1, -1, -1}));
	t2.postorder_traversal(t2.root);
	cout << endl;
	cout << t2.height() << endl;
	return 0;
}