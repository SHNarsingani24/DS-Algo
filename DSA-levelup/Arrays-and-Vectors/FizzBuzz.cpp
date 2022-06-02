#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> FizzBuzz(int n){
    vector<string> results;
    for(int i=1; i<=n; i++){
        if((i%3==0) and (i%5==0)){
            results.push_back("FizzBuzz");
        } else if(i%3==0){
            results.push_back("Fizz");
        } else if(i%5==0){
            results.push_back("Buzz");
        } else {
            results.push_back(to_string(i));
        }
    }
    return results;
}

int main(){
    int n;
    cin >> n;
    vector<string> fizzbuzz = FizzBuzz(n);
    for(string i: fizzbuzz){
        cout << i << " ";
    }
    return 0;
}