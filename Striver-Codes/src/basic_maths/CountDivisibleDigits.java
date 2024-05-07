package basic_maths;

import java.util.Scanner;

/**
 * @author niladri.choudhury on 07/05/24
 */
public class CountDivisibleDigits {
    private static final Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        System.out.print("Enter the number: ");
        int n = sc.nextInt();
        System.out.println("The number of digits of " + n + " that evenly divide "+n+" is: "+countDigits(n));
    }

    private static int countDigits(int n) {
        int temp = n;
        int count = 0;
        while (temp>0) {
            int rem = temp%10;
            if (rem != 0){
                if (n%rem == 0){
                    count++;
                }
            }
            temp = temp/10;
        }
        return count;
    }
}
