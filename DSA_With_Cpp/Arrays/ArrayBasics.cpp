//
//  main.cpp
//  Arrays
//
//  Created by Niladri Choudhury on 26/12/23.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    int A[5] = {0};
    int *p = new int[5];
    cout << "Printing Array from Stack" << endl;
    for (int i=0; i<5; i++)
    {
        cout << A[i];
    }
    cout << endl;
    for (int i=0; i<5; i++)
    {
        p[i] = i+1;
    }
    cout << "Printing Array from Heap" << endl;
    for (int i=0; i<5; i++)
    {
        cout << p[i];
    }
    cout << endl;
    
    int *q = new int[100];
    for(int i=0; i<5; i++)
    {
        q[i] = p[i];
    }
    delete []p;
    p = q;
    q = NULL;
    cout << "Printing larger array" << endl;
    for (int i=0; i<100; i++)
    {
        cout << p[i];
    }
    cout << endl;
    return 0;
}
