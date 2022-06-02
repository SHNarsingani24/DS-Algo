// Problem: Two players Bill and Mandy are playing one game. You are given two arrays, A and B. A[i]=0 if mandy is winner of ith round,
// A[i]=1 if Billy is winner of ith round. B[i] shows score of winner in ith round.
// However, Mandy has a superpower using which she can reverse result of X rounds from begining or ending, for example if last round was won by Billy then A[N]=1
// however using powers mandy will do it, A[N]=0.
// Find maximum points Mandy can score.

#include<iostream>
#include<vector>
using namespace std;

// Bottom Up Dynamic Programming Approach.
int getMaxPoints(vector<int>winner, vector<int>scores){
	// we will build two tables and based on that we will find max score that mandy can score.
	int n = winner.size();
	// prefix_sum[0][i] shows how much score till ith round 0 which is mandy has scored.
	// prefix_sum[1][i] shows how much score till ith round 1 which is billy has scored.
	vector<vector<int>>prefix_sum(2, vector<int>(n, 0));
	// suffix_sum[0][i] shows how much score from ith to Nth(last) round 0 which is mandy has scored.
	// suffix_sum[1][i] shows how much score from ith to Nth(last) round 1 which is billy has scored.
	vector<vector<int>>suffix_sum(2, vector<int>(n, 0));

	// building prefix_sum
	for(int i=0; i<n; i++){
		if(i!=0){
			prefix_sum[0][i] = prefix_sum[0][i-1];
			prefix_sum[1][i] = prefix_sum[1][i-1];
		}

		prefix_sum[winner[i]][i] += scores[i];
	}

	// building suffix_sum
	for(int i=n-1; i>-1; i--){
		if(i!=(n-1)){
			suffix_sum[0][i] = suffix_sum[0][i+1];
			suffix_sum[1][i] = suffix_sum[1][i+1];
		}
		suffix_sum[winner[i]][i] += scores[i];
	}

	// op3 is one in which all the rounds are either flipped or all the rounds are kept as they are.
	int op1 = INT_MIN, op2=INT_MIN, op3=max(prefix_sum[0][n-1], prefix_sum[1][n-1]);
	// making partitions from start and end.
	for(int i=0; i<n-1; i++){
		// OP1: last N-i rounds are flipped.
		int temp1 = prefix_sum[0][i] + suffix_sum[1][i+1];
		if(temp1 > op1) op1 = temp1;

		// OP2: first i rounds are flipped.
		int temp2 = prefix_sum[1][i] + suffix_sum[0][i+1];
		if(temp2 > op2) op2 = temp2;
	}
	
	return max(op3, max(op1, op2));
}

int main(){
	vector<int>winner={0, 0, 1, 0, 1};
	vector<int>scores={41, 47, 11, 20, 33};
	cout << getMaxPoints(winner, scores); 
	return 0;
}