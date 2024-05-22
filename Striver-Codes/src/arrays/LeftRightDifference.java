package arrays;

import java.util.Arrays;

/**
 * @author niladri.choudhury on 22/05/24
 */
public class LeftRightDifference {
    public static void main(String[] args) {
        int nums[] = {10,4,8,3};
        int[] answer = leftRightDifference(nums);
        System.out.println("Answer: \n" + Arrays.toString(answer));

    }

    public static int[] leftRightDifference(int[] nums) {
        int[] answer = new int[nums.length];
        int leftSum = 0, rightSum = 0, arrSum = 0;

        for (int num : nums) {
            arrSum += num;
        }

        for (int i=0; i<nums.length; i++) {
            if (i==0)
                leftSum = 0;
            else
                leftSum += nums[i-1];
            rightSum = arrSum - nums[i];
            arrSum -= nums[i];
            answer[i] = Math.abs(leftSum - rightSum);
        }
        return answer;
    }
}
