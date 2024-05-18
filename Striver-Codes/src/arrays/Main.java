package arrays;

/**
 * @author niladri.choudhury on 16/05/24
 */
public class Main {
    public static void main(String[] args) {
        String[] sentences = {"please wait", "continue to fight", "continue to win"};
        int maxSpaces = 0;
        for (String str:sentences) {
            int spaces = 0;
            for (int i=0; i<str.length(); i++) {
                if (str.charAt(i) == ' ')
                    spaces++;
            }

            if (maxSpaces < spaces)
                maxSpaces = spaces;
            spaces = 0;
        }

        System.out.println("Maximum Number of Words Found in Sentences: " + (int)(maxSpaces+1));
    }
}
