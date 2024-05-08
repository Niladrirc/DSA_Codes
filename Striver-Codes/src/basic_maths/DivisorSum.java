package basic_maths;

import java.util.Scanner;

/**
 * @author niladri.choudhury on 08/05/24
 */
public class DivisorSum {
    private static final Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        System.out.print("Enter the number 1: ");
        int n = sc.nextInt();
        System.out.println("Sum of all divisor of "+n+" is: "+sumOfAllDivisors(n));
    }

    private static int sumOfAllDivisors(int n) {
        int sum=0;
        for (int i=1; i<=n; i++) {
            for(int j=1; j<=i; j++) {
                if (i%j == 0) {
                    sum += j;
                }
            }
        }
        return sum;
    }
}
