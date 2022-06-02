// Prolblem: Check if given number(given as string) is divisible by 30 or not.
#include<iostream>
#include<string>
using namespace std;

// function to check weather num(string) is divisible by 30 or not.
bool divisibilityTest(string num){
	int n = num.size();
	// if num is not divisible by 10 return false, as it can't be divisible by 30 then.
	if(num[n-1]!='0') return false;

	// if sum of all digits is divisible by 3 then, number is divisible by 3 and it is already divisible
	// by 10 if we reached here.
	int digiSum = 0;
	for(int i=0; i<n; i++){
		char temp = num[i];
		digiSum = digiSum + atoi(&temp);
	}

	// Hence if digit sum is divisible by 3, we will return true, otherwise false.
	return !(digiSum%3);
}

int main(){
	string num;;
	cin >> num;
	cout << divisibilityTest(num) << endl;
	return 0;
}