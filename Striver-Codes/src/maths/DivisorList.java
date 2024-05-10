package maths;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

/**
 * @author niladri.choudhury on 10/05/24
 */
public class DivisorList {
    private static final Scanner sc = new Scanner(System.in);
    public static void main(String[] args) {
        System.out.print("Enter n: ");
        int n = sc.nextInt();

        List<Integer> divisolList = printDivisors(n);
        System.out.print("The divisors of "+n+" are: ");
        for (Integer a: divisolList) {
            System.out.print(a+",");
        }
    }

    private static List<Integer> printDivisors(int n) {
        List<Integer> divisorList = new ArrayList<>();
        divisorList.add(1);
        for (int i=2; i<=n/2; i++) {
            if (n%i == 0){
                divisorList.add(i);
            }
        }
        divisorList.add(n);
        return divisorList;
    }
}
