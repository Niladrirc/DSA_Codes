//
//  main.cpp
//  HornerTaylorSeries
//
//  Created by Niladri Choudhury on 11/12/23.
//

#include <iostream>

double hornerTaylor(double x, double n) {
    static double sum = 1;
    if (n > 0) {
        sum = 1 + (x/n)*sum;
        return hornerTaylor(x, n-1);
    } else {
        return sum;
    }
}

double hornersTaylorUsingLoop(double x, double n) {
    
    double s=1;
    while (n>0) {
        s = 1 + (x/n)*s;
        n--;
    }
    return s;
}

int main(int argc, const char * argv[]) {
    
    printf("Taylor series output: %lf\n", hornerTaylor(1, 100));
    return 0;
}
