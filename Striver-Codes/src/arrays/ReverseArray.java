package arrays;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;

/**
 * @author niladri.choudhury on 08/05/24
 */
public class ReverseArray {
    public static void main(String[] args) {
        ArrayList<Integer> arr = new ArrayList<>();
        arr.add(10);
        arr.add(9);
        arr.add(8);
        arr.add(7);
        arr.add(6);
        reverseArray(arr, 2);
        System.out.println("Reversed Array: " + Arrays.toString(arr.toArray()));
    }

    private static void reverseArray(ArrayList<Integer> arr, int m) {
        int midIndex = ((m+1)+ arr.size()-1)/2;
        for (int i=m+1, j=arr.size()-1; i<=midIndex; i++, j--) {
            Collections.swap(arr, i, j);
        }
        System.out.println(midIndex);
    }
}
