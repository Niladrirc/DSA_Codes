package fibonacci;

/**
 * @author niladri.choudhury on 10/05/24
 */
public class BruteForce {

    public int getNthFibonacci(int n) {
        int a=0, b=1, c = 0;
        for (int i=2; i<=n; i++) {
            c = a + b;
            a = b;
            b = c;
        }
        return c;
    }
}
