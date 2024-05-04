//
//  main.cpp
//  ArrayADT
//
//  Created by Niladri Choudhury on 27/12/23.
//

#include <iostream>
using namespace std;

struct Array
{
    int *A;
    int size;
    int length;
};

struct Array fillArray(struct Array *arr)
{
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    for (int i=0; i<n; i++)
    {
        printf("\nEnter the %d number: ", (i+1));
        cin >> arr->A[i];
        arr->length++;
    }
    
    return *arr;
}

struct Array initializeArray()
{
    struct Array arr;
    cout << "Enter size of the array: ";
    cin >> arr.size;
    arr.A = new int[arr.size]; // Creating the array in Heap
    arr.length = 0; // Setting initial length to 0 as no element is present.
    
    arr = fillArray(&arr);
    
    return arr;
}

void insertElement(struct Array *p, int index, int x)
{
    int n = p->length;
    if (p->length == p-> size)
        n = p->length - 1;
    for (int i=n; i>index; i--)
    {
        p->A[i] = p->A[i-1];
    }
    
    p->A[index] = x;
    p->length++;
    
}

void deleteElement(struct Array *p, int index)
{
    if (index < 0 || index > p->length)
    {
        cout << "Wrong index entered";
        return;
    }
    
    for (int i=index; i<p->length; i++) {
        p->A[i] = p->A[i+1];
    }
    
    p->length--;
    
}

void displayArray(struct Array arr)
{
    cout << "Elements in the array: " << endl;
    for (int i=0; i<arr.length; i++)
    {
        cout << arr.A[i] << '\t';
    }
    cout << endl;
}

void displayArray(Array *arr) {
    cout << "Elements in the array: " << endl;
    for (int i=0; i<arr->length; i++) {
        cout << arr->A[i] << '\t';
    }
    cout << endl;
}

void searchLinear(struct Array a, int key)
{
    for (int i=0; i<a.length; i++)
    {
        if (a.A[i] == key)
        {
            cout << "Search successful" << endl;
            printf("Element %d found at index %d\n", key, i);
            return;
        }
    }
    
    cout << "Search unsuccessful" << endl;
}

int searchBinaryLoop(struct Array a, int key)
{
    int low = 0, high = a.length-1, mid=1;
    
    while (low <= high) {
        mid = (low + high) / 2;
        if (a.A[mid] == key)
            return mid;
        else if (a.A[mid] > key)
            high = mid-1;
        else if (a.A[mid] < key)
            low = mid+1;
    }
    
    return -1;
}

int searchBinaryRecursion(struct Array a, int low, int high, int key)
{
    int mid;
    if (low <= high)
    {
        mid = (low+high)/2;
        if (a.A[mid] == key)
            return mid;
        else if (a.A[mid] < key)
            return searchBinaryRecursion(a, mid+1, high, key);
        else if (a.A[mid] > key)
            return searchBinaryRecursion(a, low, mid-1, key);
    }
    return -1;
}

int get(struct Array *arr, int index)
{
    if (index < 0 || index > arr->length) {
        cout << "Wrong index provided";
        return -1;
    }
    
    return arr->A[index];
}

void set(struct Array *arr, int index, int x)
{
    if (index < 0 || index > arr->length) {
        cout << "Wrong index provided";
        return;
    }
    
    arr->A[index] = x;
}

int findMax(struct Array *arr)
{
    int max = arr->A[0];
    for (int i=0; i<arr->length; i++) {
        if (arr->A[i] > max) {
            max = arr->A[i];
        }
    }
    return max;
}

int findMin(struct Array *arr)
{
    int min = arr->A[0];
    for (int i=0; i<arr->length; i++) {
        if (arr->A[i] < min) {
            min = arr->A[i];
        }
    }
    return min;
}

int sum(struct Array *arr)
{
    int sum = 0;
    for (int i=0; i<arr->length; i++) {
        sum += arr->A[i];
    }
    return sum;
}

int sumRecursion(struct Array *arr, int n)
{
    if (n < 0) {
        return 0;
    }
    return sumRecursion(arr, n-1) + arr->A[n];
}

int average(struct Array *arr)
{
    int total = sum(arr);
    return total/arr->length;
}

void auxReverse(struct Array *arr)
{
    int *B;
    int i,j;
    
    B = new int[arr->length];
    
    // Copy in reverse
    for(i=arr->length-1, j=0; i>0,j<arr->length; i--,j++)
    {
        B[j] = arr->A[i];
    }
    // Copying back
    for(int x=0; x<arr->length; x++)
    {
        arr->A[x] = B[x];
    }
}

void swapReverse(struct Array *arr)
{
    int i,j;
    for(i=0,j=arr->length-1; i<j; i++,j--)
    {
        int temp = arr->A[i];
        arr->A[i] = arr->A[j];
        arr->A[j] = temp;
    }
    
}

void insertSorted(struct Array *arr, int value)
{
    int counter = arr->length-1;
    if (arr->length == arr->size)
    {
        if (arr->A[(arr->size)-1] < value)
        {
            cout << "Value cannot be inserted. Larger then all the elements in the list";
            return;
        }
        counter --;
    }
    
    for (int i=counter; i>=0; i--)
    {
        if (arr->A[i] > value) {
            arr->A[i+1] = arr->A[i];
        }else {
            arr->A[i+1] = value;
            arr->length += 1;
            return;
        }
    }
}

void checkSorting(struct Array arr)
{
    bool flag = true;
    for (int i=0; i<arr.length-2; i++) {
        if (arr.A[i+1] < arr.A[i]) {
            flag = false;
        }
    }
    
    if (flag) cout << "List is sorted" << endl;
    else cout << "List is not sorted" << endl;
}

void sortNegative(struct Array *arr)
{
    int i=0, j=arr->length-1;
    while (i<j) {
        while (arr->A[i] < 0) i++;
        while (arr->A[j] >= 0) j--;
        
        if (i<j)
        {
            int temp = arr->A[i];
            arr->A[i] = arr->A[j];
            arr->A[j] = temp;
        }
    }
}

Array* merge(Array *A, Array *B)
{
    Array *C = new Array;
    
    int i=0, j=0, k=0;
    while(i<A->length && j<B->length)
    {
        if (A->A[i] < B->A[j]) {
            C->A[k++] = A->A[i++];
        }else {
            C->A[k++] = B->A[j++];
        }
    }
    
    for(; i<A->length; i++)
        C->A[k++] = A->A[i];
    for(; j<B->length; j++)
        C->A[k++] = B->A[j];
    
    C->size = A->size + B->size;
    C->length = k;
    
    return C;
}

Array* unsortedUnion(Array *A, Array *B) {
    Array* C = new Array;
    C->size = A->size + B->size;
    int k=0;
    // Copy the 1st set
    for(int i=0; i<A->length; i++) {
        C->A[k++] = A->A[i];
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

Array* sortedUnion(Array *A, Array *B) {
    int i=0, j=0, k=0;
    Array *C = new Array;
    
    while (i<A->length && j<B->length) {
        if (A->A[i] > B->A[j]) {
            C->A[k++] = B->A[j++];
        }else if (A->A[i] < B->A[j]) {
            C->A[k++] = A->A[i++];
        }else if (A->A[i] == B->A[j]) {
            C->A[k++] = A->A[i++];
            j++;
        }
    }
    for (;i<A->length;i++) {
        C->A[k++] = A->A[i];
    }
    for (;j<B->length;j++) {
        C->A[k++] = B->A[j];
    }
    C->length = k;
    C->size = A->size + B->size;
    return C;
}

Array* unsortedIntersection(Array *A, Array *B) {
    Array *C = new Array;
    int k=0;
    for (int i=0; i<A->length; i++) {
        for (int j=0; j<B->length; j++) {
            if (A->A[i] == B->A[j]) {
                C->A[k++] = A->A[i];
                break;
            }
        }
    }
    C->length = k;
    C->size = A->size + B->size;;
    return C;
}

Array* sortedIntersection(Array *A, Array *B) {
    Array *C = new Array;
    int i=0, j=0, k=0;
    
    while (i<A->length && j<B->length) {
        if (A->A[i] > B->A[j]) {
            j++;
        }else if (A->A[i] < B->A[j]) {
            i++;
        }else if (A->A[i] == B->A[j]) {
            C->A[k++] = A->A[i++];
            j++;
        }
    }

    C->length = k;
    C->size = A->size + B->size;
    
    return C;
}
Array* unsortedDifference(Array *A, Array *B) {
    // Reslut of A-B
    Array *C = new Array;
    int k=0;
    for (int i=0; i<A->length; i++) {
        int flag = 0;
        for (int j=0; j<B->length; j++) {
            if (A->A[i] == B->A[j]) {
                flag = 1;
                break;
            }
        }
        if (flag == 0) {
            C->A[k++] = A->A[i];
        }
    }
    C->length=k;
    C->size = A->size + B->size;
    
    return C;
}

Array* sortedDifference(Array *A, Array *B) {
    Array *C = new Array;
    int i=0, j=0, k=0;
    
    while (i<A->length && j<B->length) {
        if (A->A[i] > B->A[j]) {
            j++;
        }else if (A->A[i] < B->A[j]) {
            C->A[k++] = A->A[i++];
        }else if (A->A[i] == B->A[j]) {
            j++;
            i++;
        }
    }
    C->size = A->size + B->size;
    C->length = k;
    
    return C;
}
int main(int argc, const char * argv[])
{
    
    Array arr1 = initializeArray();
    Array arr2 = initializeArray();
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
