package arrays;

/**
 * @author niladri.choudhury on 15/05/24
 */
public class RemoveDuplicates {
    public static void main(String[] args) {
        int[] nums = {1,1,1,1,2,2};
        int[] expectedNums = {1,2};

        int k = removeDuplicates2(nums);
        assert k == expectedNums.length;

        for (int i=0; i<k; i++) {
            assert nums[i] == expectedNums[i];
        }
    }

    private static int removeDuplicates(int[] nums) {
        int uniqueIndex = 1;
        for (int i=1; i<nums.length; i++) {
            if (nums[i] != nums[i-1]) {
                nums[uniqueIndex] = nums[i];
                uniqueIndex++;
            }
        }
        return uniqueIndex;
    }

    private static int removeDuplicates2(int[] nums) {
        int latestUniqueIndex = 0;
        for (int i=1; i<nums.length; i++) {
            if (nums[i] != nums[latestUniqueIndex]) {
                nums[latestUniqueIndex+1] = nums[i];
                latestUniqueIndex += 1;
            }
        }
        return latestUniqueIndex+1;
    }
}
