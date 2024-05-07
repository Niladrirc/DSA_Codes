package basic_maths;

import java.util.Scanner;

/**
 * @author niladri.choudhury on 07/05/24
 */
public class Palindrome {
    private static final Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        System.out.print("Enter the number: ");
        int n = sc.nextInt();
        if (isPalindrome(n))
            System.out.println("The number is a palindrome");
        else
            System.out.println("The number is not a palindrome");
    }

    private static boolean isPalindrome(int n) {
        String initial = String.valueOf(n);

        for (int i=0, j=initial.length()-1; i<=initial.length()/2; i++,j--) {
            if (initial.charAt(i) != initial.charAt(j))
                return false;
        }
        return true;
    }
}
