package patterns;

import java.util.Scanner;

/**
 * @author niladri.choudhury on 05/05/24
 */
public class InvertedRightPyramid {
    private static final Scanner sc = new Scanner(System.in);
    public static void main(String[] args) {
        System.out.print("Enter pattern size: ");
        int n = sc.nextInt();
        printPattern(n);
    }

    private static void printPattern(int n) {
        for (int i=1; i<=n; i++) {
            for (int j=(n-i); j>0; j--) {
                System.out.print("*  ");
            }
            System.out.println("\n");
        }
    }
}
