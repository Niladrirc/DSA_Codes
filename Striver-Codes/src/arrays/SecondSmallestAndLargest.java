package arrays;

/**
 * @author niladri.choudhury on 11/05/24
 */
public class SecondSmallestAndLargest {
    public static void main(String[] args) {
        int [] arr = {1, 2, 4, 7, 7, 5};
        int largest = arr[0], seconfLargest = arr[0], smallest = Integer.MAX_VALUE, secondSmallest = Integer.MAX_VALUE;

        for (int j : arr) {
            if (j > largest) largest = j;
            if (j > seconfLargest && j < largest) seconfLargest = j;
            if (j < smallest) smallest = j;
            if (j < secondSmallest && j > smallest) secondSmallest = j;
        }

        System.out.println("Second Largest = "+seconfLargest);
        System.out.println("Second Smallest = "+secondSmallest);
    }
}
