package patterns;

import java.util.Scanner;

/**
 * @author niladri.choudhury on 05/05/24
 */
public class StarPyramid {
    private static final Scanner sc = new Scanner(System.in);
    public static void main(String[] args) {
        System.out.print("Enter pattern size: ");
        int n = sc.nextInt();
        printPattern(n);
    }

    private static void printPattern(int n) {
        for (int i=1; i<=n ; i++) {
            for (int j=n-i; j>0; j--) {
                System.out.print(" ");
            }
            for (int j=1; j<=(2*i - 1); j++) {
                System.out.print("*");
            }
            System.out.println("\n");
        }
    }
}
