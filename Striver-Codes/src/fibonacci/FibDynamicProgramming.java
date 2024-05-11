package fibonacci;

/**
 * @author niladri.choudhury on 10/05/24
 */
public class FibDynamicProgramming {
    private static int[] fibStore;

    public FibDynamicProgramming(int n) {
        fibStore = new int[n+1];
        for (int i=0; i<=n; i++) {
            fibStore[i] = -1;
        }
    }

    public int getNthFibonacci(int n) {
        if (fibStore[n] == -1) {
            if (n <= 1) {
                fibStore[n] = n;
                return n;
            } else {
                if (fibStore[n-2] == -1)
                    fibStore[n-2] = getNthFibonacci(n-2);
                if (fibStore[n-1] == -1)
                    fibStore[n-1] = getNthFibonacci(n-1);

                return fibStore[n-2] + fibStore[n-1];
            }
        }
        return 0;
    }
    // Also called Memoization

}
