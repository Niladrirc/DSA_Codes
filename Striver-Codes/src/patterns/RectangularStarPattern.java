package patterns;

import java.util.Scanner;

/**
 * @author niladri.choudhury on 05/05/24
 */
public class RectangularStarPattern {
    public static void main(String[] args) {
        System.out.print("Enter pattern size: ");
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                System.out.print("*  ");
            }
            System.out.println(" ");
        }
    }
}
