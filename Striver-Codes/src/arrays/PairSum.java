package arrays;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;

/**
 * @author niladri.choudhury on 08/05/24
 */
public class PairSum {
    public static void main(String[] args) {
        int[] arr = {2, -3, 3, 3, -2};
        System.out.println("Max Value: " + pairSum(arr, 0));
    }

    private static List<int[]> pairSum(int[] arr, int s) {
        List<int[]> sumList = new ArrayList<>();
        Arrays.sort(arr);
        for (int i=0; i<arr.length; i++) {
            for (int j=i+1; j<arr.length; j++) {
                if (arr[i] + arr[j] == s) {
                    sumList.add(new int[]{arr[i], arr[j]});
                }
            }
        }
        return sumList;
    }
}
