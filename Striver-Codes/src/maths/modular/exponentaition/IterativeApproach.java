package maths.modular.exponentaition;

import java.util.Scanner;

/**
 * @author niladri.choudhury on 12/05/24
 */
public class IterativeApproach {
    /**
     * Modular exponentiation is the remainder when an integer b (the base) is raised to the power e (the exponent),
     * and divided by a positive integer m (the modulus); that is, c = be mod m. From the definition of division,
     * it follows that 0 ≤ c < m.
     */
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

    private static int power(int x, int n, int p) {
        int result = 1;
        x %= p;

        while (n > 0) {
            if (n % 2 == 1) {
                result = (result * x) % p;
            }
            n = (n * n) % p;
            n >>= 1;
        }

        return result;
    }
}
