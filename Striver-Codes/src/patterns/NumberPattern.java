package patterns;

import java.util.Scanner;

/**
 * @author niladri.choudhury on 07/05/24
 */
public class NumberPattern {
    private static final Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        System.out.print("Enter pattern size: ");
        int n = sc.nextInt();
        printPattern(n);
    }

    private static void printPattern(int n) {
        for (int i=0; i<2*n-1; i++) {
            for (int j=0; j<2*n-1; j++) {
                int top = i;
                int left = j;
                int bottom = (2*n-2)-i;
                int right = (2*n-2)-j;
                System.out.print(n-Math.min(Math.min(top, bottom), Math.min(left, right))+ " ");
            }
            System.out.println(" ");
        }
    }
}
