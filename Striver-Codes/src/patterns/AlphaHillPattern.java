package patterns;

import java.util.Scanner;

/**
 * @author niladri.choudhury on 05/05/24
 */
public class AlphaHillPattern {
    private static final Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        System.out.print("Enter pattern size: ");
        int n = sc.nextInt();
        printPattern(n);
    }

    private static void printPattern(int n) {
        for (int i=0; i<n; i++) {
            for (int a=0; a<n-i; a++) {
                System.out.print(" ");
            }
            char b;
            for (b='A'; b<='A'+i; b++) {
                System.out.print(b);
            }
            for (char c = (char) (b-2); c>='A'; c--) {
                System.out.print(c);
            }
            System.out.println(" ");
        }
    }

}
