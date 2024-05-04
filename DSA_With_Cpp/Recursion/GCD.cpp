//
//  main.cpp
//  GCD
//
//  Created by Niladri Choudhury on 14/12/23.
//

#include <iostream>

int gcdPrimeFactorization(int a, int b, int c)
{
    return 0;
}

int gcdPrimeFactorization(int a, int b)
{
    return 0;
}
int main(int argc, const char * argv[]) {
    int a = 22;
    int *p = &a;
    
    printf("p = %p\n", p);
    p++;
    printf("p++ = %p\n", p);
    p--;
    printf("p-- = %p\n", p);
    
    
    float b = 22.22;
    float *q = &b;
    printf("q = %p\n", q);  //q = 6422284
    q++;
    printf("q++ = %p\n", q); //q++ = 6422288      +8   // 8 bytes
    q--;
    printf("q-- = %p\n", q);
    
    return 0;
}
