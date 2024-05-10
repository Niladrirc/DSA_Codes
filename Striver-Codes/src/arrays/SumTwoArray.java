package arrays;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/**
 * @author niladri.choudhury on 08/05/24
 */
public class SumTwoArray {
    public static void main(String[] args) {
        int[] arr1 = {9, 9, 9, 9};
        int[] arr2 = {9, 9, 9, 9};
        System.out.println("Sum: " + Arrays.toString(findArraySum(arr1, 4, arr2, 4)));
    }

    private static int[] findArraySum(int[] a, int n, int[] b, int m) {
        List<Integer> result = new ArrayList<>();
        int takeOver=0;
        for (int i=n-1, j=m-1; i>=0||j>=0||takeOver!=0; i--,j--) {
            int digitSum = takeOver;
            if (i >= 0) {
                digitSum += a[i];
            }
            if (j >= 0) {
                digitSum += b[j];
            }
            takeOver = digitSum/10;
            digitSum %= 10;
            result.add(digitSum);
        }

        int[] sumArray = new int[result.size()];
        for (int k = 0; k < result.size(); k++) {
            sumArray[k] = result.get(result.size() - 1 - k);
        }
        return sumArray;
    }
}
