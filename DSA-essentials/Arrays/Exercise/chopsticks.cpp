#include<bits/stdc++.h>
using namespace std;

// Problem: Given N sticks and an array of length , where each length [i]
// represents length of each stick. Make max number of pairs of these sticks such that the difference
// between the length of two sticks is at most D. A stick can't be part of more than 1 pair.

int pairSticks(vector<int>v, int D){
	int cnt = 0, N = v.size();
	vector<bool>picked (N, false);
	for(int i = 0; i < N-1; i++){
			for(int j = i+1; j < N; j++){
				if(!picked[i] and !picked[j]){
					if(abs(v[j] - v[i]) <= D){
						cnt++, picked[i] = true, picked[j] = true;
					}
				}
			}
	}
	return cnt;
}

int main(){
	int N, D;
    cin >> N >> D;
    
    vector<int>v;
    for(int i = 0; i < N; i++){
		int x;
		cin >> x;
        v.push_back(x);
    }
 
    cout << "Ans: " << pairSticks(v, D) << endl;
    return 0;
}