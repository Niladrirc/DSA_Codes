package fibonacci;

/**
 * @author niladri.choudhury on 10/05/24
 */
public class FibonacciMatrixExponentiationOptimised {
    public static void main(String[] args) {
        int n = 5;

        System.out.println("F(5) is " + findNthTerm(n));
    }

    private static int findNthTerm(int n) {
        if (n == 0) return 0;
        if (n == 1 || n == 2) return 1;

        int[][] F = {{1,0,0}, {1,0,0}, {0,0,0}};

        return power(F, n-2);
    }

    private static int power(int[][] F, int i) {
        int[][] base = {{1,1,1}, {1,0,0}, {1,0,0}};
        while (i > 0) {
            if (i%2 == 1) {
                multiply(F, base);
            }
            multiply(base,base);
            i >>= 1;
        }
        return F[0][0] + F[0][1];
    }

    private static void multiply(int[][] a, int[][] b) {
        int[][] mul = new int[3][3];
        for (int i=0; i<3; i++) {
            for (int j=0; j<3; j++) {
                mul[i][j] = 0;
                for (int k = 0; k < 3; k++)
                    mul[i][j] += a[i][k] * b[k][j];
            }
        }

        for (int i = 0; i < 3; i++)
            System.arraycopy(mul[i], 0, a[i], 0, 3);
    }

}
