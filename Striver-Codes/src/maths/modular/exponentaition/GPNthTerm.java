package maths.modular.exponentaition;

/**
 * @author niladri.choudhury on 14/05/24
 */
public class GPNthTerm {
    public static void main(String[] args) {
        int N = 34;
        int A = 17;
        int R = 13;

        System.out.println(N+"th term of GP with A: "+A+" and R: "+R+" is: "+nthTermOfGP(N, A, R));
    }
    public static int nthTermOfGP(int N, int A, int R) {
        int result = 1;
        int mod = 1000000000+7;
        result = power(R, N-1, mod) % mod;
        return A*result;
    }

    public static int power(int base, int exp, int mod) {
        int result = 1;

        base %= mod;

        while (exp > 0) {
            if ((exp % 2) == 1) {
                result = (result * base) % mod;
            }
            base = (base * base) % mod;
            exp >>= 1;
        }

        return result;
    }
}
