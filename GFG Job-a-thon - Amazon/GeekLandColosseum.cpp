// Problem: https://practice.geeksforgeeks.org/contest/job-a-thon-exclusive-hiring-challenge-for-amazon-alexa/problems#
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// Time Complexity - O(N).
// Space Complexity - O(N).
int getMaxDiff(vector<int> A, int N){
    priority_queue<int, vector<int>, greater<int>> q1;
    long long s1=0;
    for(int i=0; i<N; i++){
        q1.push(A[i]);
        s1 = s1 + A[i];
    }

    vector<int> prefix;
    prefix.push_back(s1);
    for(int i=N; i<(2*N); i++){
        if(A[i]>q1.top()){
            s1 = s1 - q1.top() + A[i];
            q1.pop();
            q1.push(A[i]);
        }

        prefix.push_back(s1);
    }

    priority_queue<int> q2;
    long long s2 = 0;
    for(int i=3*N-1; i>=(2*N); i--){
        q2.push(A[i]);
        s2 = s2 + A[i];
    }

    vector<int> suffix(N+1, 0);
    suffix[N] = s2;
    for(int i=(2*N-1); i>=N; i--){
        if(A[i]<q2.top()){
            s2 = s2 - q2.top() + A[i];
            q2.pop();
            q2.push(A[i]);
        }

        suffix[i-N] = s2;
    }
    
    int maxDiff = INT_MIN;
    for(int i=0; i<=N; i++){
        maxDiff = max(maxDiff, prefix[i]-suffix[i]);
    }

    return maxDiff;
}

int main(){
    cout << getMaxDiff({1, 1, 5, 3, 7, 7}, 2);
    return 0;
}