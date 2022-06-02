#include<iostream>
#include<stack>
using namespace std;

int *get_min_dist_r(int hist[], int n){
	stack<int>s;
	int *dist = new int [n];
	s.push(0);
	for(int i = 1; i < n; i++){
		int cur = hist[i], top = hist[s.top()];
		while(!s.empty() and cur < top){
			dist[s.top()] = i;
			s.pop();
			if(!s.empty())	top = hist[s.top()];
		}
		s.push(i);
	}
	while(!s.empty()){
		dist[s.top()] = n;
		s.pop();
	}
	return dist;
}

int *get_min_dist_l(int hist[], int n){
	stack<int>s;
	int *dist = new int [n];
	s.push(n-1);
	for(int i = n-2; i >= 0; i--){
		int cur = hist[i], top = hist[s.top()];
		while(!s.empty() and cur < top){
			dist[s.top()] = i;
			s.pop();
			if(!s.empty())	top = hist[s.top()];
		}
		s.push(i);
	}
	while(!s.empty()){
		dist[s.top()] = -1;
		s.pop();
	}
	return dist;
}

int get_max_area(int hist[], int n){
	int *right_dist = get_min_dist_r(hist, n);
	int *left_dist = get_min_dist_l(hist, n);
	int max_area = INT_MIN;
	for(int i = 0; i < n; i++){
		int cur_area = (right_dist[i] - left_dist[i] - 1) * hist[i];
		if(cur_area > max_area){
			max_area = cur_area;
		}
	}
	return max_area;
}
int main(){
	int hist[] = {6, 2, 5, 4, 5, 1, 6};
	int n = sizeof(hist)/ sizeof(int);

	// int* temp = get_min_dist_r(hist, n);
	// for(int i=0; i<n; i++){
	// 	cout << temp[i] << " ";
	// }
	cout << get_max_area(hist, n);
	return 0;
}
