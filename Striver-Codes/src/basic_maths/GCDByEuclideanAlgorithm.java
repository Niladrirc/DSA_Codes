package basic_maths;

import java.util.Scanner;

/**
 * @author niladri.choudhury on 08/05/24
 */
public class GCDByEuclideanAlgorithm {
    private static final Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        System.out.print("Enter the number 1: ");
        int n1 = sc.nextInt();
        System.out.print("Enter the number 2: ");
        int n2 = sc.nextInt();
        System.out.println("The GCD of " + n1 + " and "+ n2 + " is: "+findGCD(n1, n2));
    }

    /**
     * The Algorithm
     * The Euclidean Algorithm for finding GCD(A,B) is as follows:
     * If A = 0 then GCD(A,B)=B, since the GCD(0,B)=B, and we can stop.
     * If B = 0 then GCD(A,B)=A, since the GCD(A,0)=A, and we can stop.
     * Write A in quotient remainder form (A = B⋅Q + R)
     * Find GCD(B,R) using the Euclidean Algorithm since GCD(A,B) = GCD(B,R)
     */
    private static int findGCD(int n, int m) {
        int max = Math.max(n, m);
        int min = Math.min(n, m);

        while (true) {
            int rem = max%min;
            if (rem == 0)
                return min;
            else {
                max = min;
                min = rem;
            }
        }
    }
}
