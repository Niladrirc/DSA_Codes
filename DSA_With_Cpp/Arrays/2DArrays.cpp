//
//  main.cpp
//  2D_Array
//
//  Created by Niladri Choudhury on 26/12/23.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    // Notrmal method
    int A[3][4];
    int n=0;
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<4; j++)
        {
            A[i][j] = ++n;
        }
    }
    
    // Printing the array
    for(int i=0; i<3; i++) {
        for (int j=0; j<4; j++) {
            cout << A[i][j] << '\t';
        }
        cout << endl;
    }
    cout << endl;
    
    // Using pointers
    int m=0;
    int *P[3];
    for (int i=0; i<3; i++) {
        P[i] = new int[4];
    }
    
    // Populating the Heap
    for (int i=0; i<3; i++) {
        for (int j=0; j<4; j++) {
            P[i][j] = ++m;
        }
    }
    
    for (int i=0; i<3; i++) {
        for (int j=0; j<4; j++) {
            cout << P[i][j] << '\t';
        }
        cout << endl;
    }
    cout << endl;
    
    // Using double pointers
    int x=0;
    int **Q;
    Q = new int*[3];
    for (int i=0; i<3; i++)
    {
        Q[i] = new int[4];
    }
    
    // Populate the Heap
    for (int i=0; i<3; i++) {
        for (int j=0; j<4; j++) {
            Q[i][j] = ++x;
        }
    }
    
    for (int i=0; i<3; i++) {
        for (int j=0; j<4; j++) {
            cout << Q[i][j] << '\t';
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}
