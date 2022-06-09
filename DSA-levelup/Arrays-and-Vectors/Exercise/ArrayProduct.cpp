// Given an array input return array output where output[i] contains product of all elements except input[i].
// You can't use Division.

#include <iostream>
#include <vector>
using namespace std;

// Time Complexity: O(N^2)
// Space Complexity: O(N)
// Brute Force
vector<int> product(vector<int> arr){
    int n = arr.size();
    vector<int> prdct(n);

    for(int i=0; i<n; i++){
        int prod = 1;
        for(int j=0; j<n; j++){
            if(j==i) continue;
            prod = prod * arr[j];
        }
        prdct[i] = prod;
    }

    return prdct;
}

// Time Complexity: O(N)
// Space Complexity: O(N)
// Optimized
vector<int> getProduct(vector<int> arr){
    int n = arr.size();
    vector<int> prdct(n);
    vector<int> pre(n);
    vector<int> post(n);

    pre[0] = arr[0];
    post[n-1] = arr[n-1];

    for(int i=1; i<n;i++){
        pre[i] = arr[i] * pre[i-1];
        post[n-i-1] = post[n-i] * arr[n-i-1];
    }

    prdct[0] = post[1];
    prdct[n-1] = pre[n-2];

    for(int i=1; i<n-1; i++){
        prdct[i] = pre[i-1] * post[i+1];
    }

    return prdct;

}

// Time Complexity: O(N)
// Space Complexity: O(1)
vector<int> getProductOP(vector<int> arr){
    int n = arr.size();

    // initializing with value 1.
    vector<int> prdct(n, 1);

    // all the elements are multiplied with left product.
    int prod = 1;   // will maintain left product.
    for(int i=0; i<n; i++){
        prdct[i] = prdct[i] * prod;
        prod = prod * arr[i];
    }

    // all the elements are multiplied with right product.
    prod=1;     // will maintain right product.
    for(int i=n-1; i>=0; i--){
        prdct[i] = prdct[i] * prod;
        prod = prod*arr[i];
    }

    return prdct;
}

int main(){
    vector<int> prod = getProductOP({1,2, 3, 4, 5});
    for(int i: prod){
        cout << i << " ";
    }
    return 0;
}