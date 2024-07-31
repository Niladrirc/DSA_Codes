package sorting;

import sorting.heap.HeapSort;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Sorting {
    public static void main(String[] args) {
        Sort heapSort = new HeapSort();


        Integer[] array = {2, 5, 8, 9, 4, 10, 7};

        ArrayList<Integer> listArray = new ArrayList<>(Arrays.asList(array));

        System.out.println("Unsorted Array: " + Arrays.toString(array));
        Integer[] heapSortedArray = heapSort.doSort(array, SortingOrder.ASC);
        List<Integer> heapSortedList = heapSort.doSort(listArray, SortingOrder.ASC);
        System.out.println("Heap Sorted Array: "+ Arrays.toString(heapSortedArray));
    }
}
