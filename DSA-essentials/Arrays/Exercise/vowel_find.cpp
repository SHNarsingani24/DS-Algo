#include<bits/stdc++.h>
using namespace std;


int main(){
        
    std::vector<char> v = {'a', 'e', 'i', 'o', 'u'};

    string s("aeoibsddaeioudb");

    for(int i = 0; i < int(s.size()); i++){
    	bool is_vowel = find(v.begin(), v.end(), s[i]) != v.end();
    	if(!is_vowel){
    		s.erase(s.begin()+i);
    		i--;
    	}
    }

    cout << s << endl;
    return 0;
}