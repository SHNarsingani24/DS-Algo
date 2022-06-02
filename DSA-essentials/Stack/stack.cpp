#include<bits/stdc++.h>
// #include "stackV.h"
#include "stackLL.h"
using namespace std;

// reversing the given number.
int reverse_num(int n){
	// storing number in the stack.
	Stack<int> s;
	while(n>0){
		s.push(n%10);
		n = n/10;
	}

	// extracting the number.
	int temp = 1, ans = 0;
	while(!s.is_empty()){
		ans = ans + (temp*s.top());
		s.pop();
		temp = temp*10;
	}
	return ans;
}

int main(){
    // Stack<char> s;

    int n;
    cout << "Enter the Number: ";
    cin >> n;

    printf("Reversed Number is: %d", reverse_num(n));
    // s.push('S');
    // s.push('A');
    // s.push('G');
    // s.push('A');
    // s.push('R');

    // s.insert_at_bottom('H');

    // s.reverse();

    // s.print();

    return 0;
}