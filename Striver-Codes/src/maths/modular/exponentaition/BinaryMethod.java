package maths.modular.exponentaition;

/**
 * @author niladri.choudhury on 14/05/24
 */
public class BinaryMethod {
    public static void main(String[] args) {
        System.out.println("Result: " + binaryPower(4, 13, 497));
    }

    private static int binaryPower(int base, int exp, int mod) {
        int result=1;

        base = base % mod;
        while (exp > 0) {
            if ((exp & 1) == 1) {
                result = (result * base) % mod;
            }
            exp >>= 1;
            base = (base * base) % mod;
        }
        return result;
    }
}
