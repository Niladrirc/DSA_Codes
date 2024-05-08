package basic_maths;

import java.util.Scanner;

/**
 * @author niladri.choudhury on 08/05/24
 */
public class GCDMyApproach {
private static final Scanner sc = new Scanner(System.in);

public static void main(String[] args) {
        System.out.print("Enter the number 1: ");
        int n1 = sc.nextInt();
        System.out.print("Enter the number 2: ");
        int n2 = sc.nextInt();
        System.out.println("The GCD of " + n1 + " and "+ n2 + " is: "+findGCD(n1, n2));
        }

    private static int findGCD(int n1, int n2) {
        int min = Math.min(n1, n2);
        int gcd = 1;
        for (int i=1; i<=min/2; i++) {
            gcd = (n1%i == 0 && n2%i == 0)?i:gcd;
        }
        return gcd;
    }
}
