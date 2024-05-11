package fibonacci;

/**
 * @author niladri.choudhury on 10/05/24
 */
public class RecursiveFibonacci {
    public int getNthFibonacci(int n) {
        if (n <= 1)
            return n;
        else
            return this.getNthFibonacci(n-1) + this.getNthFibonacci(n-2);
    }
}
