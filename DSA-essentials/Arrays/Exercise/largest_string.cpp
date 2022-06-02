#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, max_len = INT_MIN;
    cin >> n;
    cin.get(); // just to deal with '\n' after the input value of n.
    char sentance[1000], largest[100];

    while(n--){
    	cin.getline(sentance, 1000, '\n');
    	int len = strlen(sentance);
    	if(len > max_len){
    		max_len = len;
    		strcpy(largest, sentance);
    	}
    }

    cout << "Largest String is: '" << largest << "'." << endl;

    return 0;
}