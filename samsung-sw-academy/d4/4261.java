package sw.expert.academy.d4._4261;

import java.io.*;
import java.util.StringTokenizer;

/**
 * Samsung SW Academy (www.swexpertacademy.com)
 * problem 4261
 */

public class Solution {

    public static char[][] BUTTON = {
            {'a', 'b', 'c'},        // 2
            {'d', 'e', 'f'},        // 3
            {'g', 'h', 'i'},        // 4
            {'j', 'k', 'l'},        // 5
            {'m', 'n', 'o'},        // 6
            {'p', 'q', 'r', 's'},   // 7
            {'t', 'u', 'v'},        // 8
            {'w', 'x', 'y', 'z'},   // 9
    };

    public static char translate(char c) {

        for(int i=0; i<8; i++)
            for(int j=0; j<BUTTON[i].length; j++)
                if(BUTTON[i][j] == c)
                    return (char)(i+50); // translate into char.

        return (char)-1; // dummy.
    }

    public static void main(String[] args) throws FileNotFoundException {

//        final String INPUT_FILE = "data/sw.expert.academy/4261_input.txt";
//        FastReader in = new FastReader(INPUT_FILE);

        FastReader in = new FastReader(args);

        int t = in.nextInt();
//        int t = 1;
        int test = 0;
        while(test++ < t) {

            char[] S = in.next().toCharArray();
            int N = in.nextInt();

            char[][] words = new char[N][];
            for(int i=0; i<N; i++)
                words[i] = in.next().toCharArray();

            int count = 0;
            for(int i=0; i<N; i++) {

                for (int j = 0; j < words[i].length; j++)
                    words[i][j] = translate(words[i][j]);

                // must be same length.
                if (S.length != words[i].length)
                    continue;

                boolean isCorrespond = true;
                for (int j = 0; j < S.length; j++) {
                    if (S[j] != words[i][j]) {
                        isCorrespond = false;
                        break;
                    }
                }

                if (isCorrespond)
                    count++;
            }

//            for(int i=0; i<N; i++) {
//                for(int j=0; j<words[i].length; j++)
//                    System.out.print(words[i][j]);
//                System.out.println();
//            }

            System.out.println("#" + test + " " + count);
        }
    }

    private static class FastReader {

        private BufferedReader br;
        private StringTokenizer st;

        public FastReader(String[] args) {
            br = new BufferedReader(new InputStreamReader(System.in));
        }
        public FastReader(String FILE_NAME) throws FileNotFoundException {
            br = new BufferedReader(new FileReader(FILE_NAME));
        }
        public String next() {
            while(st == null || !st.hasMoreElements()) {
                try                 { st = new StringTokenizer(br.readLine()); }
                catch(IOException e){ e.printStackTrace(); }
            }
            return st.nextToken();
        }
        public int nextInt() {
            return Integer.parseInt(next());
        }
        public double nextDouble() {
            return Double.parseDouble((next()));
        }
        public String nextLine() {
            String str = "";
            try                 { str = br.readLine(); }
            catch(IOException e){ e.printStackTrace(); }
            return str;
        }
    }
}
