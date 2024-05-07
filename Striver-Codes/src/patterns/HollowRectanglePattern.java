package patterns;

import java.util.Scanner;

/**
 * @author niladri.choudhury on 07/05/24
 */
public class HollowRectanglePattern {
    private static final Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        System.out.print("Enter pattern size: ");
        int n = sc.nextInt();
        printPattern(n);
    }

    private static void printPattern(int n) {
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                if (i==0 || i==(n-1)) {
                    System.out.print("* ");
                } else {
                    if (j == 0 || j == n-1) {
                        System.out.print("* ");
                    } else
                        System.out.print("  ");
                }
            }
            System.out.println(" ");
        }
    }
}
