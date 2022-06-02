#include<bits/stdc++.h>
using namespace std;


// Problem: Given the path (in direction, like north-south-east-west) 
// find the resultant displacement and final co-ordinates.

// for example, if path is SNNNEWE then final coordinates will be (1, 2) and
// resultant displacement will be NNE or ENN
int main(){

	// getting final coordinates.
    char ch = cin.get();
    int x = 0, y = 0;
    while(ch!='\n'){
    	switch(ch){
    		case 'N': y++;
    				  break;
   			case 'S': y--;
    				  break;
    		case 'E': x++;
    				  break;
    		case 'W': x--;
    				  break;
    	}

    	ch = cin.get();
    }

    cout << "Final Co-ordinates: (" << x << ", " << y << ")." << endl;

    

    // Building the displacement from the final coordinates.
    char displacement[100];
    int i = 0;
    while(x < 0){
    	displacement[i++] = 'W';
    	x++;
    }
    while(x > 0){
    	displacement[i++] = 'E';
    	x--;
    }
    while(y < 0){
    	displacement[i++] = 'S';
    	y++;
    }
    while(y > 0){
    	displacement[i++] = 'N';
    	y--;
    }

    cout << "Displacement: " << displacement << endl;

    return 0;
}