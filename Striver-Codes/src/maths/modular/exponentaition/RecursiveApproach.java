package maths.modular.exponentaition;

import java.util.Scanner;

/**
 * @author niladri.choudhury on 13/05/24
 */
public class RecursiveApproach {
    private static final Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        System.out.print("Enter base(x): ");
        int x = sc.nextInt();

        System.out.print("Enter exponent(n): ");
        int n = sc.nextInt();

        System.out.print("Enter modulus(p): ");
        int p = sc.nextInt();

        System.out.println("Result: " + power(x, n, p));
    }

    /**
     * Tricks used:
     * <p>
     *      1) (a * b) % p = ((a % p) * (b % p)) % p
     * <p>
     *      2) If b is even then, (a ^ b) % p = ((a ^ b/2) * (a ^ b/2)) % p
     * <p>
     *      3) If b is odd then, (a ^ b) % p = (a * (a ^ (b-1)) % p
     * <p>
     *      4) If we have to return the mod of a negative number x whose absolute value is less than y then
     *      (x + y) % y will do the trick
     */
    private static int power(int x, int n, int p) {
        long result;

        if (x == 0) return 0;
        if (n == 0) return 1;

        if (n % 2 == 0) {
            result = power(x, n/2, p);
            result = (result * result) % p;
        } else {
             // (a * (a ^ (b-1)) % p = ((a % p) * ((a ^ (b-1)) % p)) % p
            result = ((long) (x % p) * power(x, n-1, p) % p) % p;
        }
        return (int)((result + p) % p);
    }
}
