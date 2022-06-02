#include<bits/stdc++.h>
using namespace std;

int cnt = 0;

// time complexity: O(N! x M) -- where M is size of dictionary and N is length of string. (prediction)
void get_ways(string str, vector<string> dict){
	int n = str.length();
	// cout << str << endl;
	for(int i = 1; i <= n; i++){
		string temp = str.substr(0, i);
		int m = dict.size();
		for(int j = 0; j < m; j++){
			if(temp == dict[j]){
				// cout << temp << endl;
				if(i == n){
					cnt++;
					return;
				}
				get_ways(str.substr(i, n-i), dict);
				break;
			}
		}
	}
	return;
}

int main(){
    
    get_ways("ilikesamsungmobile", {"i", "like", "sam", "sung", "samsung", "mobile"});
    cout << cnt << endl;
    return 0;
}