package arrays;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/**
 * @author niladri.choudhury on 18/05/24
 */
public class SubrectangleQueries {

    private final int[][] rectangle;

    public SubrectangleQueries(int[][] rectangle) {
        this.rectangle = rectangle;
    }

    public void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) {
        for (int i=row1; i<=row2; i++) {
            for (int j=col1; j<=col2; j++) {
                this.rectangle[i][j] = newValue;
            }
        }
    }

    public int getValue(int row, int col) {
        return rectangle[row][col];
    }

    @Override
    public String toString() {
        return "SubrectangleQueries{" +
                "rectangle=" + Arrays.deepToString(rectangle) +
                '}';
    }
}

class Test {
    public static void main(String[] args) {
        int[][] rectangle = {{1,2,1},{4,3,4},{3,2,1},{1,1,1}};
        SubrectangleQueries subrectangleQueries = new SubrectangleQueries(rectangle);
        System.out.println("Value at location Row: " + 0 + " and Column: " + 2 + " is "+subrectangleQueries.getValue(0, 2));

        subrectangleQueries.updateSubrectangle(0, 0, 3, 2, 5);
        System.out.println(subrectangleQueries);
    }
}
