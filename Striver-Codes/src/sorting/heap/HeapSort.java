package sorting.heap;

import sorting.Sort;
import sorting.SortingOrder;

import java.util.Arrays;
import java.util.Comparator;
import java.util.List;

public class HeapSort extends Sort {

    @Override
    public Integer[] doSort(Integer[] array, SortingOrder order) {
        Integer[] arr = fixArrayForSorting(array);
        if (arr == null || arr.length == 0) {
            System.err.println("The array is null or empty");
            return null;
        }

        if (order == SortingOrder.ASC) {
            System.out.println("Using Max Heap to sort the array in ascending order");
            maxHeapify(arr);
            for (int i=arr.length-1; i>0; i--) {
                deleteFromMaxHeap(arr, i);
            }
        } else {
            System.err.println("Using Min Heap to sort the array in descending order");
            for (int i=2; i<arr.length; i++) {
                insertMinHeap(arr, i);
            }
            for (int i=arr.length-1; i>0; i--) {
                deleteFromMinHeap(arr, i);
            }
        }
        return Arrays.copyOfRange(arr, 1, arr.length);
    }

    @Override
    public <T extends Comparable<T>> List<T> doSort(List<T> list, SortingOrder order) {
        if (list.isEmpty() || list == null) {
            System.err.println("List is null or empty");
            return null;
        }
        if (order == SortingOrder.ASC) {
            System.out.println("Using Max Heap to sort the array in ascending order");

        } else {
            System.out.println("Using Min Heap to sort the array in descending order");
        }
        return null;
    }

    @Override
    public <T> T[] doSort(T[] array, Comparator<T> comparator) {
        System.out.println("Sort using comparator not implemented yet!!!");
        return null;
    }

    private void insertMaxHeap(Integer[] arr, int n) {
        int temp = arr[n];
        int i = n;
        while (temp > arr[i/2] && i > 0) {
            arr[i] = arr[i/2];
            i /= 2;
        }
        arr[i] = temp;
    }

    private void insertMinHeap(Integer[] a, int n) {
        int temp = a[n], i = n;
        while(temp < a[i/2] && i>1) {
            a[i] = a[i/2];
            i = i/2;
        }
        a[i] = temp;
    }

    private void deleteFromMaxHeap(Integer[] a, int n) {
        Integer x = a[1];
        a[1] = a[n];
        int i = 1, j=2*i;
        while (j <= n-1) {
            if (a[j+1] > a[j])
                j++;
            if (a[j] > a[i]) {
                Integer temp = a[i];
                a[i] = a[j];
                a[j] = temp;
                i = j;
                j = 2*j;
            } else
                break;
        }
        a[n] = x;
    }

    private void deleteFromMinHeap(Integer[] a, int n) {
        Integer x = a[1];
        a[1] = a[n];
        int i = 1, j=2*i;
        while (j <= n-1) {
            if (a[j+1] < a[j])
                j++;
            if (a[j] < a[i]) {
                Integer temp = a[i];
                a[i] = a[j];
                a[j] = temp;
                i = j;
                j = 2*j;
            } else
                break;
        }
        a[n] = x;
    }

    private void maxHeapify(Integer[] arr) {
        int l = arr.length-1;
        for (int a=l; a>=1; a--) {
            int i = a;
            while ((2*i) < l) {
                int j = 2 * i;
                if (arr[j] < arr[j + 1])
                    j = j + 1;
                if (arr[i] < arr[j]) {
                    Integer temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                    i = j;
                }
            }
        }
    }
}
