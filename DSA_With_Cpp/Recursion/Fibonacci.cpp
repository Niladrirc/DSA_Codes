//
//  main.cpp
//  Fibonacci
//
//  Created by Niladri Choudhury on 11/12/23.
//

#include <iostream>
using namespace std;

int F[30];

void fibonacciLoop(int n) {
    int A[n];
    for(int i=0; i<n; i++) {
        if (i==0 || i==1) {
            A[i] = i;
        } else {
            A[i] = A[i-1] + A[i-2];
        }
        printf("%d, ", A[i]);
    }
}

int fibRecursion(int n) {
    if (n<=1)
        return n;
    else
        return fibRecursion(n-2) + fibRecursion(n-1);
}

int fibMemoization1(int n) {
    if (n<=1)
    {
        F[n] = n;
        return n;
    }
    else
    {
        
        if (F[n-2] == -1)
            F[n-2] = fibMemoization1(n-2);
        
        if (F[n-1] == -1)
            F[n-1] = fibMemoization1(n-1);
        
        return F[n-2] + F[n-1];
    }
}

int main(int argc, const char * argv[]) {
    
    fibonacciLoop(15);
    cout << endl;
    printf("Output with recursion is: %d\n", fibRecursion(5));
    for (int i=0; i<15; i++){
        F[i] = -1;
    }
    printf("Output with memoization is: %d\n", fibMemoization1(5));
    return 0;
}
