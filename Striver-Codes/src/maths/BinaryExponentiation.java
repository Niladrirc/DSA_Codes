package maths;

import java.util.Scanner;

/**
 * @author niladri.choudhury on 12/05/24
 */
public class BinaryExponentiation {
    /**
     * Binary exponentiation, also known as exponentiation by squaring, is a method used to efficiently compute the exponentiation of a number to a non-negative integer power. It relies on the observation that exponentiation can be performed more quickly if the exponent is represented in binary form.
     * Here's how binary exponentiation works:
     * <p>
     * Representing the exponent in binary: Convert the exponent to binary representation.
     *  For example, if the exponent is 13, its binary representation is 1101.
     * Iterating through the binary digits: Start with the least significant bit (rightmost bit) of the binary representation and iterate towards the most significant bit (leftmost bit).
     * Doubling the base: For each bit position:
     * If the current bit is 0, square the base.
     * If the current bit is 1, multiply the result by the base and then square the base.
     * Combining results: After iterating through all the bits, the result is obtained by multiplying together all the intermediate results obtained during the process.
     * Binary exponentiation is more efficient than the naive method of repeated multiplication because it reduces the number of multiplication operations required. It also avoids potential overflow issues that may occur with large exponents.
     */
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter n: ");
        long n = sc.nextLong();

        System.out.print("Enter Exponent: ");
        long e = sc.nextLong();

        System.out.println(n+" raised to "+ e +" is " + power(n,e));
    }

    private static long power(long base, long exp) {
        long result = 1;
        while (exp != 0) {
            if ((exp % 2) == 1)
                result *= base;
            base *= base;
            exp >>= 1;
        }
        return result;
    }
}
