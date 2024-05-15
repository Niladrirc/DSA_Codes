package arrays;

/**
 * @author niladri.choudhury on 15/05/24
 */
public class SortedAndRotated {
    public static void main(String[] args) {
        int[] nums = {2,1,3,4};
        if (check(nums)) {
            System.out.println("Array is Sorted");
        } else
            System.out.println("Array is not Sorted");
    }
    public static boolean check(int[] nums) {
        int abruptChange = 0;
        int l = nums.length;

        if (nums[0] < nums[l-1])
            abruptChange++;

        int i = 1;
        while (i < l) {
            if (nums[i-1] > nums[i])
                abruptChange++;
            if (abruptChange > 1)
                return false;
            i++;
        }
        return true;
    }
}
