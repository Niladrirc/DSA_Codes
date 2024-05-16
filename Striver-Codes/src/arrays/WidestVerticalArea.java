package arrays;

import java.util.Arrays;
import java.util.Comparator;

/**
 * @author niladri.choudhury on 16/05/24
 */
public class WidestVerticalArea {
    public static void main(String[] args) {
        int[][] points = {{1,5}, {1,70},{3,1000},{55,700},{999876789,53},{987853567,12}};
        System.out.println("Widest Vertical Area Between Two Points Containing No Points: "+maxWidthOfVerticalArea(points));
    }

    public static int maxWidthOfVerticalArea(int[][] points) {
        Arrays.sort(points, Comparator.comparingInt(a -> a[0]));
        int diff = 0;
        for (int i=0; i<points.length-1; i++) {
            if (points[i+1][0] - points[i][0] > diff)
                diff = points[i+1][0] - points[i][0];
        }
        return diff;
    }
}
