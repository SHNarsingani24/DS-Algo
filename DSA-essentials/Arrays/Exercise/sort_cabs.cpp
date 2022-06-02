#include<bits/stdc++.h>
using namespace std;

float get_dist(pair<int, int> x){
	return sqrt((x.first*x.first) + (x.second*x.second));
}

bool compare(pair<int, int> a, pair<int, int> b){
	return get_dist(a) < get_dist(b);
}

vector<pair<int, int>> sort_cabs(vector<pair<int, int>> v){
	sort(v.begin(), v.end(), compare);
	return v;
}

int main(){
    
    vector<pair<int, int>> v= {{2,3}, {1,2}, {3,4}, {2,4}, {1,4}};

    v = sort_cabs(v);

    for(int i = 0; i < int(v.size()); i++){
    	cout << "(" << v[i].first << ", " << v[i].second << ") ";
    }
    cout << endl;

    return 0;
}