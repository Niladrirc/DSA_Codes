package basic_maths;

import java.util.Scanner;

/**
 * @author niladri.choudhury on 07/05/24
 */
public class CountDigits {
    private static final Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        System.out.print("Enter the number: ");
        int n = sc.nextInt();
        countDigits(n);
    }

    private static void countDigits(int n) {
        int count = (int) (Math.log10(n) + 1);
        System.out.println("Number of digits in " + n + " is: " + count);
    }
}
