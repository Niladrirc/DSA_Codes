package basic_maths;

import java.util.Scanner;

/**
 * @author niladri.choudhury on 07/05/24
 */
public class ReverseDigits {
    private static final Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        System.out.print("Enter the number: ");
        int n = sc.nextInt();
        System.out.println("The reverse number of " + n + " is: "+reverseDigits(n));
    }

    private static int reverseDigits(int n) {
        int temp = n;
        boolean isNegative = false;
        int reverseValue = 0;
        if (n < 0) {
            isNegative = true;
            temp = -n;
        }

        while (temp > 0) {
            int rem = temp%10;
            temp = temp/10;
            if (reverseValue > Integer.MAX_VALUE/10 || reverseValue < Integer.MIN_VALUE/10)
                return 0;
            reverseValue = reverseValue*10 + rem;
        }

        return isNegative?-reverseValue:reverseValue;
    }
}
