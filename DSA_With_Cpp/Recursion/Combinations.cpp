//
//  main.cpp
//  Combination
//
//  Created by Niladri Choudhury on 14/12/23.
//

#include <iostream>

int fact(int x)
{
    int prod=1;
    for (int i=1; i<=x; i++)
    {
        prod *= i;
    }
    return prod;
}

int combIterative(int n, int r)
{
    return fact(n)/(fact(r)*fact(n-r));
}

int combRecursion(int n, int r)
{
    if (n==r || r==0)
        return 1;
    else
        return (combRecursion(n-1, r-1) + combRecursion(n-1, r));
}

int main(int argc, const char * argv[])
{
    printf("Value with iteration: %d\n", combIterative(5,3));
    printf("Value with recursion: %d\n", combRecursion(5,3));
    return 0;
}
