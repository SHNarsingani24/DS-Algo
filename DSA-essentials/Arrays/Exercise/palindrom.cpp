#include<bits/stdc++.h>
using namespace std;


int main(){
        
    string s;
    getline(cin, s);

    int i = 0, j = s.size()-1;
    bool isPalindrome = true;
    while(i <= j){
    	if(s[i++] != s[j--]){
    		isPalindrome = false;
    		break;
    	}
    }

    if(isPalindrome){
    	cout << "String " << s << ", is palindrome." << endl;
    } else {
    	cout << "String " << s << ", is not palindrome." << endl;
    }



    return 0;
}