//
//  main.cpp
//  TaylorSeriesSimple
//
//  Created by Niladri Choudhury on 11/12/23.
//

#include <iostream>
using namespace::std;

double taylor(int x, int n) {
    static double p = 1, f = 1;
    double sum = 0;
    if (n > 0) {
        sum = taylor(x, n-1);
        p *= x;
        f *= n;
        return sum + (p/f);
    } else
        return 1;
}

int main(int argc, const char * argv[]) {
//    int n, x;
//    cout << "Starting Taylor Series calculation...\n";
//    cout << "Enter the highest power to which Taylor Series will be calculated: ";
//    cin >> n;
//    cout << "Enter point of calculation: ";
//    cin >> x;
    printf("Taylor series output: %lf\n", taylor(1, 100));
    return 0;
}
