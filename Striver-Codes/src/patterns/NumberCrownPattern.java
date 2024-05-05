package patterns;

import java.util.Scanner;

/**
 * @author niladri.choudhury on 05/05/24
 */
public class NumberCrownPattern {
    private static final Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        System.out.print("Enter pattern size: ");
        int n = sc.nextInt();
        printPattern(n);
    }

    private static void printPattern(int n) {
        for (int i=1; i<=n; i++) {
            for (int a=1; a<=i; a++) {
                System.out.print(a+" ");
            }
            int spaces = 2*(n-i);
            for (int b=1; b<=spaces; b++) {
                System.out.print(" ");
            }
            for (int c=i; c>0; c--) {
                System.out.print(c+" ");
            }
            System.out.print("\n");
        }
    }
}
