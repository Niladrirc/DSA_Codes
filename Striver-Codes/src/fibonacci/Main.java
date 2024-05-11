package fibonacci;

import java.util.Scanner;

/**
 * @author niladri.choudhury on 10/05/24
 */
public class Main {

    private static final Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        System.out.print("Enter the number n: ");
        int n = sc.nextInt();

        BruteForce bf = new BruteForce();
        System.out.println("The "+n+"th Fibonacci Number using Brute Force is: "+bf.getNthFibonacci(n));

        RecursiveFibonacci rf = new RecursiveFibonacci();
        System.out.println("The "+n+"th Fibonacci Number using Recursion is: "+rf.getNthFibonacci(n));

        FibDynamicProgramming dpf = new FibDynamicProgramming(n);
        System.out.println("The "+n+"th Fibonacci Number using Memoization is: "+dpf.getNthFibonacci(n));
    }
}
