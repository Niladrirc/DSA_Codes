package patterns;

import java.util.Scanner;

/**
 * @author niladri.choudhury on 05/05/24
 */
public class BinaryNumberTrianglePattern {
    private static final Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        System.out.print("Enter pattern size: ");
        int n = sc.nextInt();
        printPattern(n);
    }

    private static void printPattern(int n) {
        int start = 1;
        for (int i=1; i<=n; i++) {
            if (i%2 == 0)
                start = 0;
            else
                start = 1;
            for (int j=1; j<=i; j++) {
                System.out.print(start);
                start = 1-start;
            }
            System.out.print("\n");
        }
    }
}
