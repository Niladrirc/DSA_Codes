package patterns;

import java.util.Scanner;

/**
 * @author niladri.choudhury on 05/05/24
 */
public class HalfDiamondStarPattern {
    private static final Scanner sc = new Scanner(System.in);
    public static void main(String[] args) {
        System.out.print("Enter pattern size: ");
        int n = sc.nextInt();
        printPattern(n);
    }

    private static void printPattern(int n) {
        for(int i=1;i<=2*n-1;i++) {
            int stars = i;
            if(i>n) stars = 2*n-i;
            for(int j=1;j<=stars;j++){
                System.out.print("*");
            }
            System.out.println();
        }
    }
}
