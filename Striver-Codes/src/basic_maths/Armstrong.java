package basic_maths;

import java.util.Scanner;

/**
 * @author niladri.choudhury on 08/05/24
 */
public class Armstrong {
    private static final Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        System.out.print("Enter the number 1: ");
        int n = sc.nextInt();
        if (checkArmstrong(n))
            System.out.println(n + " is an Armstrong Number");
        else
            System.out.println(n + " is not an Armstrong Number");
    }

    private static boolean checkArmstrong(int n) {
        int count = (int) Math.log10(n) + 1;
        int sum = 0;
        int temp = n;
        while(temp != 0) {
            int rem = temp%10;
            sum = sum + (int) Math.pow(rem, count);
            temp /= 10;
        }
        return sum == n;
    }
}
