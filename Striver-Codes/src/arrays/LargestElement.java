package arrays;

/**
 * @author niladri.choudhury on 08/05/24
 */
public class LargestElement {
    public static void main(String[] args) {
        int[] arr = {4, 7, 8, 6, 7, 6 };
        System.out.println("Max Value: " + findMax(arr, 6));
    }

    private static int findMax(int[] arr, int n) {
        int max = arr[0];

        for (int i=1; i<n; i++) {
            if (max < arr[i]) {
                max = arr[i];
            }
        }
        return max;
    }
}
