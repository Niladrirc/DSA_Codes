//
//  main.cpp
//  Tower_of_Hanoi
//
//  Created by Niladri Choudhury on 20/12/23.
//

#include <iostream>

int fun(int n)
{
    int x = 1, k;
    if (n==1)return x;
    for(k=1;k<n;++k)
        x = x+fun(k)*fun(n-k);
    return x;
    
}
int main()
{
    int p = 5;
    int result = fun(p);
    std::cout << result << std::endl;
    return 0;
}
