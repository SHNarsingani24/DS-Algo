#include<iostream>
#include<vector>
using namespace std;

/* ------------------------------- merge sort ------------------------------- */
void conqure(vector<int>&v, int s, int e){
    vector<int> temp;
    int mid = s+(e-s)/2;
    int i=s, j=mid+1;

    // sorting 
    while(i<=mid and j<=e){
        if(v[i] < v[j]){
            temp.push_back(v[i++]);
        } else {
            temp.push_back(v[j++]);
        }
    }

    while(i <= mid){
        temp.push_back(v[i++]);
    }

    while (j <= e){
        temp.push_back(v[j++]);
    }

    int l = 0;
    for(int k=s; k<=e; k++){
        v[k] = temp[l++];
    }

    return;
}

void divide(vector<int> &v, int s, int e){
    // base condition
    if(s >= e) return;

    int mid = s + (e-s)/2;

    divide(v, s, mid);
    divide(v, mid+1, e);

    conqure(v, s, e);

    return;
}

/* ------------------------------- quick sort ------------------------------- */
int sort(vector<int> &v, int s, int e){
    int i = s-1, pivot=v[e];
    for(int j=s; j<e; j++){
        if(v[j] < pivot){
            swap(v[++i], v[j]);
        }
    }

    swap(v[++i], v[e]);

    return i;
}

void quick(vector<int>&v, int s, int e){
    // base condition
    if(s >= e) return;

    int p = sort(v, s, e);
    quick(v, s, p-1);
    quick(v, p+1, e);

    return;
}

int main(){
    vector<int> v = {7, 2, 9, 1, 5, 4, 3};

    for(int i: v){
        cout << i << " ";
    }
    cout << endl;

    quick(v, 0, v.size()-1);

    for(int i: v){
        cout << i << " ";
    }

    return 0;
}

