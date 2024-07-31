package sorting;

import java.util.Comparator;
import java.util.List;

public abstract class Sort {
    // Sorts an array and returns the sorted array
    public abstract Integer[] doSort(Integer[] arr, SortingOrder order);

    // Sorts a list and returns the sorted list
    public abstract <T extends Comparable<T>> List<T> doSort(List<T> list, SortingOrder order);

    // Sorts an array with a custom comparator and returns the sorted array
    public abstract <T> T[] doSort(T[] array, Comparator<T> comparator);

    protected Integer[] fixArrayForSorting(Integer[] arr) {
        Integer[] newArray = new Integer[arr.length + 1];
        newArray[0] = 0;
        System.arraycopy(arr, 0, newArray, 1, arr.length);
        return newArray;
    }
}
