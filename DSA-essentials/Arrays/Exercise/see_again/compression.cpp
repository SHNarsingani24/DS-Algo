#include<bits/stdc++.h>
using namespace std;

// {'a', 'a', 'b', 'b', 'c', 'c', 'c'} should be compressed to a2b2c3, we need to return the compressed length.
// if {'a', 'b', 'b', 'c', 'c', 'c'} is there then compressed string will be ab2c3 (no need to mention 1).
int main(){
    vector<char> chars = {'a', 'a', 'b', 'b', 'c', 'c', 'c', 'c', 'c', 'c', 'c', 'c', 'c', 'c', 'c', 'c'};
    int len = 0;

    for(int i = 0; i < int(chars.size()); i++){
    	int cnt = 1;
    	char curr_char = chars[i];
    	int j = i+1;
    	while(chars[j] == chars[i] and j < int(chars.size())){
    		cnt++;
    		j++;
    	}
    	if(cnt > 1){
    		i = i + cnt -1;
    		int dig = 0;
    		while(cnt > 0){
    			cnt = cnt / 10;
    			dig++;
    		}
    		len = len + dig + 1;
    	} if(cnt == 1){
    		len++;
    	}
    }
  
    cout << "Ans: " << len << endl;

    return 0;
}