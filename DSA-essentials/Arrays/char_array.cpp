#include<iostream>
#include<cstring>
using namespace std;

int main(){

	// this will append garbage values to the string.
	// char str[] = {'a', 'b', 'c'};

	// this will show exact string.
	// char str[] = {'a', 'b', 'c', '\0'}; - NULL character is really important.

	char str[100];

	// this will only take one word as input even the size of array is enough.
	// cin >> str;


	// to get whole line as input.
	int i = 0;
	char temp = cin.get();

	while(temp!='\n'){  // can put any other char instead of '\n' too.
		str[i++] = temp;
		temp = cin.get();
	}

	str[i] = '\0'; // adding NULL at last!

	// can't print int array directly like this!
	cout << str << endl;

	// method to get whole sentance at a time. 3rd parameter is the termination condition.
	char sentance[1000];
	cin.getline(sentance, 1000, '\n');
	cout << sentance;

	char a[100], b[100];
	cin.getline(a, 100, '\n');
	// function to copy string from a to b.
	strcpy(b, a); // Syntax : strcpy(dest, src);

	// function to compare two strings.
	cout << strcmp(a, b) << endl; // can give -ve, 0(if strings are same) or +ve values.

	// function for concatintion(a+b).
	cout << strcat(a, b) << endl; 

    return 0;
}