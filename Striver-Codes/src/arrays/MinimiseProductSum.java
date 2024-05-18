package arrays;

import java.util.Arrays;
import java.util.Collections;

/**
 * @author niladri.choudhury on 18/05/24
 */
public class MinimiseProductSum {
    public static void main(String[] args) {
        Integer[] A = { 6, 1, 9, 5, 4 };
        Integer[] B = { 3, 4, 8, 2, 4 };

        System.out.println("Minimum Product Sum: "+minProdSum(A, B));
    }

    private static int minProdSum(Integer[] a, Integer[] b) {
        Arrays.sort(a);
        Arrays.sort(b, Collections.reverseOrder());

        int prod = 0;
        for (int i=0; i<a.length; i++) {
            prod += a[i]*b[i];
        }
        return prod;
    }

    private static void sortArray(int[] arr, String type) {
        if (type.equals("asc")) {
           return;
        }
    }

}
