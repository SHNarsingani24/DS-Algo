#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;

class Trie;

class Node {
	char data;
	unordered_map<char, Node*> next;	// will store childrens(with address)
	bool isTerminal;
public:
	// constructor.
	Node(char d): data(d){
		isTerminal = false;
	}

	friend class Trie;
};

class Trie{
	Node* root;

	// utility function for exercise problem : prefix_strings
	// will traverse on TRIE in dfs manner, from given head node!
	void dfs(Node* head, vector<string> &ans, string word){
		// if current node is terminal then push word in answer.
		if(head->isTerminal){
			ans.push_back(word);
		}
		// if there are no more childs of current node, we will go back to previous node.
		if(head->next.empty()){
			return;
		}

		// traversing all the childs of current child
		for(auto child: head->next){
			word.push_back(child.first);
			dfs(child.second, ans, word);
			word.pop_back();	// backtracking
		}

		return;
	}
public:
	// constructor
	Trie(){
		root = new Node('\0');
	}

	// method to insert a word in Trie.
	void insert(string word){
		Node *temp = root;
		for(char ch: word){
			// if there doesn't exist current character from current node.
			if(temp->next.count(ch)==0){
				Node *n = new Node(ch);
				temp->next[ch] = n;
			}
			// moving forward.
			temp = temp->next[ch];
		}
		// setting last character as terminal.
		temp->isTerminal = true;
	}

	// method to search word in Trie.
	bool search(string word){
		Node *temp = root;
		for(char ch: word){
			// if there is no further path, which means there doesn't exists current char from current node!
			if(temp->next.count(ch)==0){
				return false;
			}
			temp = temp->next[ch];
		}
		// if last character is stored as terminal then oonly we will return true, false otherwise.
		return temp->isTerminal;
	}

	// exercise problem: return a vector of words in the TRIE that has given prefix as prefix.
	// for example, if prefix = 'ab' and there exists word 'abcd' in TRIE then vector will push 'abcd', 
	// similarly vector with all these words will be returned. 
	vector<string> prefix_strings(string prefix){
		Node *temp = root;
		vector<string> ans;
		string word;
		// going till prefix in TRIE.
		for(char ch: prefix){
			// if prefix itself is not in TRIE.
			if(temp->next.count(ch)==0){
				return {};
			}
			word.push_back(ch);
			temp = temp->next[ch];
		}

		// If prefix itself is a word.
		if(temp->isTerminal){
			ans.push_back(word);
		}

		dfs(temp, ans, word);

		return ans;
	}
};