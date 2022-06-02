#include<bits/stdc++.h>
using namespace std;

int main(){
        
   	string s("111");

   	int pos = 0, dec = 0;

   	for(int i = int(s.size())-1; i >= 0; i--){
   		if(s[i]=='1'){
   			dec = dec + int(pow(2, pos));
   		}
   		pos++;
   	}

   	cout << s << " : " << dec << endl;
    return 0;
}