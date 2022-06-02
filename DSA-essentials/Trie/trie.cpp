#include<iostream>
#include "trie.h"
using namespace std;

int main(){
	Trie t;
	string words[] = {"apple", "ape", "no", "news", "orange", "mango"};

	for(string word: words){
		t.insert(word);
	}

	string query;
	cin >> query;
	cout << t.search(query) << endl;

	vector<string>v = t.prefix_strings(query);

	for(auto str: v){
		cout << str << " ";
	}

}
