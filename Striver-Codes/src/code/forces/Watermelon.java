package code.forces;

import java.util.Scanner;

public class Watermelon {

    private static final Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        int w = sc.nextInt();

        if(isDivisonPossible(w)) {
            System.out.println("YES");
        } else {
            System.out.println("NO");
        }
    }

    private static boolean isDivisonPossible(int w) {
        if (w == 2) {
            return false;
        }

        return w % 2 == 0;
    }
}
