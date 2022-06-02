#include<bits/stdc++.h>
using namespace std;


int main(){
        
	string s1, s2;
	getline(cin, s1);
	getline(cin, s2);
	bool is_permutation = true;
	
	if(s1.size() == s2.size()){
		for(int i = 0; i < int(s1.size()); i++){
			int cnt1 = count(s1.begin(), s1.end(), s1[i]);
			int cnt2 = count(s2.begin(), s2.end(), s1[i]);
			if(cnt1 != cnt2){
				is_permutation = false;
				break;
			}
		}
	} else {
		is_permutation = false;
	}

	if(is_permutation){
		cout << s1 << " and " << s2 << " are permutations of each other." << endl;
	} else {
		cout << s1 << " and " << s2 << " are not permutations." << endl;
	}
    return 0;
}