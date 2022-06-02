#include<bits/stdc++.h>
using namespace std;


queue<int> interleave_queue(queue<int> q, int n){
	int half = n/2;
	queue<int> half_q, ans;

	// making the given queue half.
	for(int i = 0; i < n/2; i++){
		half_q.push(q.front());
		q.pop();
	}

	// there are two halves now, half_q and q.

	// in ans we are adding one element from half_q and another from q.
	for(int i = 0; i < n/2; i++){
		ans.push(half_q.front());
		half_q.pop();

		ans.push(q.front());
		q.pop();
	}

	// returning the interleaved queue.
	return ans;
}

int main(){
    queue<int> q({11, 12, 13, 14, 15, 16, 17, 18, 19, 20});

    q = interleave_queue(q, q.size());

    // printing interleaved queue.
    while(!q.empty()){
    	cout << q.front() << " ";
    	q.pop();
    }
    return 0;
}