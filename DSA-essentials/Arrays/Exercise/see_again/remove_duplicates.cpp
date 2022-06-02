#include<bits/stdc++.h>
using namespace std;


int main(){
        
    string s("geeksforgeeks");

    for(int i = 0; i < int(s.size()); i++){
        // how to remove all occurances of specific character from the range.
    	s.erase(remove(s.begin()+i+1, s.end(), s[i]), s.end());
        // remove(s.begin()+i+1, s.end(), s[i]);
    }
    sort(s.begin(), s.end());
    cout << s << endl;

    return 0;
}