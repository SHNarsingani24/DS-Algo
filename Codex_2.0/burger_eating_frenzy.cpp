// Problem: Your friend loves to eat burgers, more he eats he gets hungrier.
// He starts with rate of X burgers/minute.
// you are given a 2D array A, in which A[i][0] shows burgers eaten and A[i][1] shows increment in speed from that point.
//for example, if X = 4 and A = [[5, 2]] then after eating 5 burgers, which takes 1.25min(5/4) his speed will be 6(4+2).
// You are given Number of burgers(B) and time limit(C), you need to find minimum initial speed, using which your friend can
// finish B burgers in C time.

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// for given initial speed, is it possible to complete task or not?
bool canEat(int speed, vector<vector<int>>A, int B, int C){
	// burger eaten initially is 0.
	int eaten=0;
	float time=0;
	for(int i; i<A.size(); i++){
		// in gap between two check points how many burgers were eaten.
		int eatenInGap = A[i][0] - eaten;
		// how much time required to eat burgers in that gap, with current speed.
		time = time + float(eatenInGap/speed);
		// increase the speed now.
		speed = speed + A[i][1];
		// updating value of burgers eaten.
		eaten = A[i][0];
	}
	// after last checkpoint if burgers are remaining then we will 
	// calculate time taken to eat them with last speed.
	int remaining = B - eaten;
	time = time + float(remaining/speed);
	// is total time required here is less than or equal to time limit?
	return time <= C;
}

// custom comparator for sorting.
bool compare(vector<int> parent, vector<int> child){
	return (parent[0] < child[0]);
}

// driver function to find minimum initial speed.
// Time Complexity: O(NlogN + NlogB)
// Space Complexity: O(1)
int getMinStartRate(vector<vector<int>>A, int B, int C){
	int start=1, end=B;
	int mid;

	// sorting according to first element(burgers eaten).
	sort(A.begin(), A.end(), compare);
	// binary search for the initial speed.
	while(start < end){
		mid = start + (end-start)/2;
		bool eaten = canEat(mid, A, B, C);
		if(eaten){
			end = mid - 1;
		} else {
			start = mid + 1;
		}
	}

	return mid;
}

int main(){
	vector<vector<int>>A={{2,2}};
	int B=10, C=3;
	cout<< getMinStartRate(A, B, C);
	return 0;
}