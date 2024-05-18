package arrays;

import java.util.Arrays;

/**
 * @author niladri.choudhury on 18/05/24
 */
public class OriginalPrefixXor {
    public static void main(String[] args) {
        int[] prefix = {5,2,0,3,1};

        System.out.println(Arrays.toString(findArray(prefix)));
    }

    private static int[] findArray(int[] prefix) {
        int[] result = new int[prefix.length];
        result[0] = prefix[0];
        for (int i=1; i<prefix.length; i++) {
            result[i] = prefix[i] ^ prefix[i-1];
        }
        return result;
    }
}
