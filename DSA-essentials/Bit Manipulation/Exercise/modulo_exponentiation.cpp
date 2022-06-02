#include<bits/stdc++.h>
using namespace std;

int earthLevel(int k){
	int curr_stage = 0, cnt = 0;
	while(curr_stage < k){
		int i = 1;
		while(true){
			if(curr_stage + (1 << i) > k){
				curr_stage += (1 << (i-1));
				break; 
			}
			i++;
		}
		cnt++;
	}
	return cnt;
}
int modulo_exponentiation(int x, int y, int mod){
	int res = 1;
	x = x % mod;
	if(x == 0) return 0;

	while(y){
		if(y&1){
			res = (res * x) % mod;
		}

		x = (x * x) % mod;
		y = y >> 1;
	}
	return res;
}

int main(){
    
    cout << modulo_exponentiation(12, 25, 10007) << endl;
    cout << earthLevel(7) << endl;
    return 0;
}