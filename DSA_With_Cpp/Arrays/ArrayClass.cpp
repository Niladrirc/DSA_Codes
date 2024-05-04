//
//  main.cpp
//  ArrayADT
//
//  Created by Niladri Choudhury on 27/12/23.
//

#include <iostream>
using namespace std;

class Array
{
private:
    int *A;
    int size;
    int length;
public:
    Array() {
        cout << "Enter size of the array: ";
        cin >> size;
        A = new int[size]; // Creating the array in Heap
        length = 0; // Setting initial length to 0 as no element is present.
        int n;
        cout << "Enter the number of elements in the array: ";
        cin >> n;
        fillArray(n);
    }
    
    Array(int size) {
        this->size = size;
        this->length = size;
        A = new int[size];
        fillArray(size);
    }
    
    
    void fillArray(int n) {
        for (int i=0; i<n; i++) {
            printf("\nEnter the %d number: ", (i+1));
            cin >> A[i];
            length++;
        }
    }
    
    ~Array() {
        delete []A;
    }
    
    void display() {
        cout << "Elements in the array: " << endl;
        for (int i=0; i<this->length; i++)
        {
            cout << this->A[i] << '\t';
        }
        cout << endl;
    }
    
    void insertElement(int index, int x) {
        int n = this->length;
        if (this->length == this->size)
            n = this->length - 1;
        for (int i=n; i>index; i--)
        {
            this->A[i] = this->A[i-1];
        }
        
        this->A[index] = x;
        this->length++;
    }
    
    void deleteElement(int index) {
        if (index < 0 || index > this->length)
        {
            cout << "Wrong index entered";
            return;
        }
        for (int i=index; i<this->length; i++) {
            this->A[i] = this->A[i+1];
        }
        this->length--;
    }
    
    void searchLinear(int key) {
        for (int i=0; i<this->length; i++)
        {
            if (this->A[i] == key)
            {
                cout << "Search successful" << endl;
                printf("Element %d found at index %d\n", key, i);
                return;
            }
        }
        cout << "Search unsuccessful" << endl;
    }
    
    int searchBinaryLoop(int key) {
        int low = 0, high = this->length-1, mid=1;
        
        while (low <= high) {
            mid = (low + high) / 2;
            if (A[mid] == key)
                return mid;
            else if (A[mid] > key)
                high = mid-1;
            else if (A[mid] < key)
                low = mid+1;
        }
        return -1;
    }
    
    int searchBinaryRecursion(int low, int high, int key) {
        int mid;
        if (low <= high)
        {
            mid = (low+high)/2;
            if (A[mid] == key)
                return mid;
            else if (A[mid] < key)
                return searchBinaryRecursion(mid+1, high, key);
            else if (A[mid] > key)
                return searchBinaryRecursion(low, mid-1, key);
        }
        return -1;
    }
    
    int get(int index) {
        if (index < 0 || index > this->length) {
            cout << "Wrong index provided";
            return -1;
        }
        
        return this->A[index];
    }
    
    void set(int index, int x) {
        if (index < 0 || index > this->length) {
            cout << "Wrong index provided";
            return;
        }
        
        this->A[index] = x;
    }
    
    int max() {
        int max = A[0];
        for (int i=0; i<length; i++) {
            if (A[i] > max) {
                max = A[i];
            }
        }
        return max;
    }
    
    int min() {
        int min = A[0];
        for (int i=0; i<length; i++) {
            if (A[i] < min) {
                min = A[i];
            }
        }
        return min;
    }
    
    int sum() {
        int sum = 0;
        for (int i=0; i<length; i++) {
            sum += A[i];
        }
        return sum;
    }
    
    int sumRecursion(int n) {
        if (n < 0) {
            return 0;
        }
        return sumRecursion(n-1) + A[n];
    }
    
    int average() {
        int total = sum();
        return total/length;
    }

    void auxReverse() {
        int *B;
        int i,j;
        B = new int[length];
        for(i=length-1, j=0; i>0, j<length; i--,j++) {
            B[j] = A[i];
        }
        for(int x=0; x<length; x++) {
            A[x] = B[x];
        }
    }
    
    void swapReverse() {
        int i,j;
        for(i=0,j=length-1; i<j; i++,j--) {
            int temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    }

    
    void insertSorted(int value) {
        int counter = length-1;
        if (length == size) {
            if (A[length-1] < value) {
                cout << "Value cannot be inserted. Larger then all the elements in the list";
                return;
            }
            counter --;
        }
        for (int i=counter; i>=0; i--) {
            if (A[i] > value) {
                A[i+1] = A[i];
            }else {
                A[i+1] = value;
                length += 1;
                return;
            }
        }
    }
    
    int checkSorting() {
        bool flag = true;
        for (int i=0; i<length-2; i++) {
            if (A[i+1] <= A[i]) {
                flag = false;
            }
        }
        if (flag) {
            cout << "List is sorted" << endl;
            return 0;
        }
        else {
            cout << "List is not sorted" << endl;
            return -1;
        }
    }
    
    void sortNegative() {
        int i=0, j=length-1;
        while (i<j) {
            while (A[i] < 0) i++;
            while (A[j] >= 0) j--;
            if (i<j) {
                int temp = A[i];
                A[i] = A[j];
                A[j] = temp;
            }
        }
    }
    
    Array* merge(Array *B) {
        Array *C = new Array;
        
        int i=0, j=0, k=0;
        while(i<this->length && j<B->length)
        {
            if (this->A[i] < B->A[j]) {
                C->A[k++] = this->A[i++];
            }else {
                C->A[k++] = B->A[j++];
            }
        }
        
        for(; i<this->length; i++)
            C->A[k++] = this->A[i];
        for(; j<B->length; j++)
            C->A[k++] = B->A[j];
        
        C->size = this->size + B->size;
        C->length = k;
        
        return C;
    }
    
    Array* unsortedUnion(Array *B) {
        Array* C = new Array;
        C->size = this->size + B->size;
        int k=0;
        // Copy the 1st set
        for(int i=0; i<this->length; i++) {
            C->A[k++] = this->A[i];
        }
        //Check 2nd set and copy
        for(int i=0; i<B->length; i++) {
            int flag = 0;
            for (int j=0; j<k; j++) {
                if (B->A[i] == C->A[j])
                    flag = 1;
            }
            if (flag == 0)
                C->A[k++] = B->A[i];
        }
        C->length = k;
        return C;
    }
    
    Array* sortedUnion(Array *B) {
        int i=0, j=0, k=0;
        Array *C = new Array;
        
        while (i<this->length && j<B->length) {
            if (this->A[i] > B->A[j]) {
                C->A[k++] = B->A[j++];
            }else if (this->A[i] < B->A[j]) {
                C->A[k++] = this->A[i++];
            }else if (this->A[i] == B->A[j]) {
                C->A[k++] = this->A[i++];
                j++;
            }
        }
        for (;i<this->length;i++) {
            C->A[k++] = this->A[i];
        }
        for (;j<B->length;j++) {
            C->A[k++] = B->A[j];
        }
        C->length = k;
        C->size = this->size + B->size;
        return C;
    }
    
    Array* unsortedIntersection(Array *B) {
        Array *C = new Array;
        int k=0;
        for (int i=0; i<this->length; i++) {
            for (int j=0; j<B->length; j++) {
                if (this->A[i] == B->A[j]) {
                    C->A[k++] = this->A[i];
                    break;
                }
            }
        }
        C->length = k;
        C->size = this->size + B->size;;
        return C;
    }
    
    Array* sortedIntersection(Array *B) {
        Array *C = new Array;
        int i=0, j=0, k=0;
        
        while (i<this->length && j<B->length) {
            if (this->A[i] > B->A[j]) {
                j++;
            }else if (this->A[i] < B->A[j]) {
                i++;
            }else if (this->A[i] == B->A[j]) {
                C->A[k++] = this->A[i++];
                j++;
            }
        }

        C->length = k;
        C->size = this->size + B->size;
        
        return C;
    }
    
    Array* unsortedDifference(Array *B) {
        // Reslut of A-B
        Array *C = new Array;
        int k=0;
        for (int i=0; i<length; i++) {
            int flag = 0;
            for (int j=0; j<B->length; j++) {
                if (A[i] == B->A[j]) {
                    flag = 1;
                    break;
                }
            }
            if (flag == 0) {
                C->A[k++] = A[i];
            }
        }
        C->length=k;
        C->size = size + B->size;
        
        return C;
    }
    
    Array* sortedDifference(Array *B) {
        Array *C = new Array;
        int i=0, j=0, k=0;
        
        while (i<this->length && j<B->length) {
            if (this->A[i] > B->A[j]) {
                j++;
            }else if (this->A[i] < B->A[j]) {
                C->A[k++] = this->A[i++];
            }else if (this->A[i] == B->A[j]) {
                j++;
                i++;
            }
        }
        C->size = this->size + B->size;
        C->length = k;
        
        return C;
    }
    
    void getMissingElements() {
        
    }
};

int main(int argc, const char * argv[])
{
    
    Array arr1 = Array();
    Array arr2 = Array();
    int ch;
    bool flag = true;
    
    while (flag) {
        cout << "Select choice from menu: " << endl;
        cout << "1. Insert" << endl;
        cout << "2. Delete" << endl;
        cout << "3. Search" << endl;
        cout << "4. Get" << endl;
        cout << "5. Set" << endl;
        cout << "6. Find Max" << endl;
        cout << "7. Find Min" << endl;
        cout << "8. Sum" << endl;
        cout << "9. Average" << endl;
        cout << "10. Reverse" << endl;
        cout << "11. Check Sorting" << endl;
        cout << "12. Merge" << endl;
        cout << "13. Display" << endl;
        cout << "14. Exit" << endl;
        
        cout << "Enter choise from menu: ";
        cin >> ch;
        
        switch (ch) {
            case 14:
                cout << "Exiting Program..."<< endl;
                flag = false;
                break;
            default:
                break;
        }
    }
    
    return 0;
}
