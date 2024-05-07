package patterns;

import java.util.Scanner;

/**
 * @author niladri.choudhury on 07/05/24
 */
public class SymmetricButterflyPattern {
    private static final Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        System.out.print("Enter pattern size: ");
        int n = sc.nextInt();
        printPattern(n);
    }

    private static void printPattern(int n) {
        int spaceCount = 2*n-2;
        for (int i=0; i<n; i++) {
            for (int star1=0; star1<=i; star1++) {
                System.out.print("*");
            }
            for (int spaces=0; spaces<spaceCount; spaces++) {
                System.out.print(" ");
            }
            spaceCount -= 2;
            for (int star2=0;star2<=i; star2++) {
                System.out.print("*");
            }
            System.out.println(" ");
        }
        spaceCount = 0;
        for (int i=1; i<n; i++) {
            for (int star1=0; star1<n-i; star1++) {
                System.out.print("*");
            }
            spaceCount += 2;
            for (int space=0; space<spaceCount; space++) {
                System.out.print(" ");
            }
            for (int star2=0; star2<n-i; star2++) {
                System.out.print("*");
            }
            System.out.println(" ");
        }
    }
}
