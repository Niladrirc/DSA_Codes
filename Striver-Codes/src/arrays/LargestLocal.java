package arrays;

import java.util.Arrays;

/**
 * @author niladri.choudhury on 15/05/24
 */
public class LargestLocal {
    public static void main(String[] args) {
        int[][] grid = {{1,1,1,1,1},{1,1,1,1,1},{1,1,2,1,1},{1,1,1,1,1},{1,1,1,1,1}};
        int [][] maxLocal = largestLocal(grid);

        System.out.println(Arrays.deepToString(maxLocal));
    }

    private static int[][] largestLocal(int[][] grid) {
        int n = grid.length;
        int[][] maxLocal = new int[n-2][n-2];
        int subMatrixSize = 3;

        for (int i=0; i<maxLocal.length; i++) {
            for (int j=0; j<maxLocal[0].length; j++) {
                maxLocal[i][j] = getMaxLocal(grid, subMatrixSize, i, j);
            }
        }
        return maxLocal;
    }

    private static int getMaxLocal(int[][] grid, int subMatrixSize, int i, int j) {
        int localMax = 0;
        for (int m=i; m<i+subMatrixSize; m++) {
            for (int n=j; n<j+subMatrixSize; n++) {
                localMax = Math.max(localMax, grid[m][n]);
            }
        }
        return localMax;
    }
}
