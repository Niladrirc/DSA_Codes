package maths.modular.exponentaition;

/**
 * @author niladri.choudhury on 14/05/24
 */
public class LoopApproach {
    public static void main(String[] args) {
        System.out.println("Result: " + power(4, 13, 497));
    }

    private static int power(int b, int e, int m) {
        long e1 = 0; int c = 1;
        while (e1 < e) {
            e1 += 1;
            c = (c * b) % m;
        }
        return c;
    }
}
