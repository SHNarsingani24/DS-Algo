#include<iostream>
#include<stack>
using namespace std;

bool is_balanced(string exp, int n){
	stack<char> s;
	for(int i = 0; i < n; i++){
		if(exp[i] == '('){
			s.push('(');
		} else if(exp[i] == ')' and s.top() == '('){
			s.pop();
		} else continue;
	}
	if(s.empty()) return true;
	else return false;
}

int main(){
	string exp = "( (a+b) + ((c+d)) )";
	cout << is_balanced(exp, exp.length());
	return 0;
}
