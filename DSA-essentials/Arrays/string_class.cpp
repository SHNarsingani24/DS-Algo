#include<bits/stdc++.h>
using namespace std;

int main(){
    
    // string is the class and we are making an object of that class.    
    string s; 

    // function to get input in string.
    // getline(cin, s, '\n'); - 3rd parameter is optional and it is for the termination character. default: '\n'.

    // Using the constructor to initialize the string object.
    string s1("Sagar H. Narsingani");
    cout << s1 << endl;

    // Iterating character by character.
    for(char x: s1){
    	cout << x << ", ";
    }
    cout << endl;

    // storing multiple strings.
    vector<string> sarr;
    int n = 3;
    while(n--){
    	getline(cin, s, '\n'); // replaces the previous value each time.
    	sarr.push_back(s);
    }
    // itterating through each string stored in vector.
    for(string x: sarr){
    	cout << x << ", " << endl;
    }
    return 0;
}