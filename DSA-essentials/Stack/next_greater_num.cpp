#include<iostream>
#include<stack>
using namespace std;

int * get_next_greater(int nums[], int n){
	stack<int> s;
	// creating array to store answers.
	int* ans = new int [n];
	s.push(0);	// pushing the index of first element in stack.
	for(int i = 1; i < n; i++){
		int cur = nums[i], top = nums[s.top()];
		while(cur > top){	// if greater element found.
			ans[s.top()] = cur;
			s.pop();
			if(!s.empty()) top = nums[s.top()];
			else break;
		}
		s.push(i);	// pushing index of current element in stack.
	}

	// if stack is not empty yet.
	while(!s.empty()){
		ans[s.top()] = -1;
		s.pop();
	}
	return ans;
}
int main(){
	int nums[] = {4, 30, 5, 2, 25};
	int n = sizeof(nums)/sizeof(int);
	int *ans = get_next_greater(nums, n);

	// printing the final answer.
	for(int i = 0; i < n; i++){
		cout << ans[i] << " ";
	}

	delete [] ans;		// to prevent memory linkage.
	return 0;
}