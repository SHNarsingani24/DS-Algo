#include<iostream>
#include<queue>
#include<vector>
#include<climits>
using namespace std;

vector<char> getFirstNonRepeatingChar(string inp){
	vector<int> cnt(CHAR_MAX, 0);	// for count of occurences of each latter in input string.
	vector<char> ans;
	queue<char> q;	// utilized to track first non-repeating letter till the current index.
	for(int i=0; i<inp.size(); i++){
		// pushing current letter in queue and increasing its count.
		q.push(inp[i]);
		cnt[inp[i]-'a']++;

		// we will either get non-repeating char or all the elements from queue will be popped.
		while(!q.empty()){
			if(cnt[q.front()-'a']>1){
				q.pop();
			} else {
				ans.push_back(q.front());
				break;
			}
		}
		
		// if queue was empty it means there are no non-repeating letters till index i.
		if(q.empty()){
			ans.push_back('0');
		}
	}
	return ans;
}

int main(){
	string input;
	cin >> input;
	vector<char> ans = getFirstNonRepeatingChar(input);
	for(char i: ans){
		cout << i << " ";
	}
	return 0;
}