package patterns;

import java.util.Scanner;

/**
 * @author niladri.choudhury on 05/05/24
 */
public class IncreasingLetterTrianglePattern {
    private static final Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        System.out.print("Enter pattern size: ");
        int n = sc.nextInt();
        printPattern(n);
    }

    private static void printPattern(int n) {
        for (int i=1; i<=n; i++) {
            for (char j='A'; j<'A'+i; j++) {
                System.out.print(j + " ");
            }
            System.out.print("\n");
        }
    }
}
