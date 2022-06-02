#include<bits/stdc++.h>
using namespace std;

// time complexity: O(N).
void get_stock_spans(int prices[], int spans[], int n){
	stack<int> i;

	// pushing index of 1st element, it will always have span of 1.
	i.push(0);
	spans[0] = 1;

	// for each day finding corresponding span.
	for(int j = 1; j < n; j++){
		int curr_price = prices[j];
		// while today's price is greater than price on the top of stack.
		while(!i.empty() and curr_price >= prices[i.top()]){
			i.pop();
		}

		// if today's price is max till now than whole stack will be empty.
		if(i.empty()){
			spans[j] = j+1;
		} else {	// else for some span it will be max.
			spans[j] = j - i.top();
		}

		// pushing the today's index in stack.
		i.push(j);
	}

	return;
}

int main(){
    int prices[] = {100, 80, 60, 70, 60, 75, 85};
    int spans[100] = {0};
    int n = sizeof(prices)/sizeof(int);

    get_stock_spans(prices, spans, n);

    // printing the span of all days.
    for(int i = 0; i < n; i++){
    	cout << spans[i] << " ";
    }

    return 0;
}