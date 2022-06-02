#include<iostream>
#include<vector>
using namespace std;

int getHappiness(vector<int> a, vector<int> b, vector<int> c, vector<vector<int>> &grid, int prev, int day){
	// base case -- all three vectors a, b, and c will have same elements as number of vacation days.
	if(day > a.size()){
		return 0;
	}

	// if solution already exists.
	if(grid[prev][day]!=0){
		// grid[i][j] will give max points that can be gained if previous activity was i and current day is j.
		return grid[prev][day];  
	}

	int op1 = INT_MIN, op2 = INT_MIN, op3 = INT_MIN;
	// when we have not done x in prev we can make x prev for next iteration.
	if(prev!=1)	op1 = a[day] + getHappiness(a, b, c, grid, 1, day+1);
	if(prev!=2)	op2 = b[day] + getHappiness(a, b, c, grid, 2, day+1);
	if(prev!=3)	op3 = c[day] + getHappiness(a, b, c, grid, 3, day+1);

	// returning the maximum one.
	return grid[prev][day] = max(op1, max(op2, op3));
}

int main(){
	vector<int> a = {10, 20, 30},
				b = {40, 50, 60},
				c = {70, 80, 90};
	int n = a.size();
	// there are three kind of activities, A, B and C, but here at first we are asuming activity 0 is done, so that in
	// first iteration we can traverse through all the three options.
	vector<vector<int>> grid(4, vector<int>(n, 0));
	cout << getHappiness(a, b, c, grid, 0, 0);
	return 0;
}