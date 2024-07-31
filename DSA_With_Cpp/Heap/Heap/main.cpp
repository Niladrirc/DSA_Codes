#include <iostream>

class HeapSort {
public:
    void insert(int a[], int n){
        int i = n, temp = a[n];
        while (i > 1 && temp > a[i/2]) {
            a[i] = a[i/2];
            i = i/2;
        }
        a[i] = temp;
    }
    
    void deleteHeap(int a[], int n) {
        int x = a[1], i = 1, j;
        a[i] = a[n];
        j = 2*i;
        while (j < (n-1)) {
            if (a[j] < a[j+1]) {
                j = j+1;
            }
            if (a[i] < a[j]) {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
                i = j;
                j = 2*j;
            } else {
                break;
            }
        }
        a[n] = x;
    }
};



int main(int argc, const char * argv[]) {
    int H[] = {0, 2, 5, 8, 9, 4, 10, 7};
    return 0;
}
