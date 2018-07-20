package sw.expert.academy.d4._4050;

import javax.swing.plaf.synth.SynthTextAreaUI;
import java.io.*;
import java.math.BigInteger;
import java.util.Arrays;
import java.util.Collections;
import java.util.StringTokenizer;

/**
 * Samsung SW Academy (www.swexpertacademy.com)
 * problem 4050
 */

public class Solution {

    public static void main(String[] args) throws FileNotFoundException {

//        final String INPUT_FILE = "data/sw.expert.academy/4259_input.txt";
//        FastReader in = new FastReader(INPUT_FILE);

        FastReader in = new FastReader(args);

        int t = in.nextInt();
        int test = 0;
        while(test++ < t) {

            int N = in.nextInt();
            Integer[] price = new Integer[N];
            for(int i=0; i<N; i++)
                price[i] = in.nextInt();

//            for(int i=0; i<N; i++)
//                System.out.print(price[i] + " ");
//            System.out.println();

            long total = 0;
            Arrays.sort(price, Collections.reverseOrder());

//            for(int i=0; i<N; i++)
//                System.out.print(price[i] + " ");
//            System.out.println();

            for(int i=0; i<N; i++) {
                if(i%3 == 2) {
//                    System.out.println("jump " + price[i]);
                    continue;
                }
                else
                    total += (long)price[i];
            }

            System.out.println("#" + test + " " + total);
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
