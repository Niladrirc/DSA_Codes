package arrays;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/**
 * @author niladri.choudhury on 16/05/24
 */
public class FindWordWithCharachter {
    public static void main(String[] args) {
        String[] words = {"abc","bcd","aaaa","cbc"};
        char x = 'z';

        List<Integer> output = findWordsContaining(words, x);
        System.out.println(Arrays.toString(output.toArray()));
    }

    private static List<Integer> findWordsContaining(String[] words, char x) {
        List<Integer> output = new ArrayList<>();
        for (int i=0; i<words.length; i++) {
            if (words[i].indexOf(x) != -1) {
                output.add(i);
            }
        }
        return output;
    }
}
