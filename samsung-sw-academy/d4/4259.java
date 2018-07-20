package sw.expert.academy.d4._4259;

import javax.swing.plaf.synth.SynthTextAreaUI;
import java.io.*;
import java.math.BigInteger;
import java.util.StringTokenizer;

/**
 * Samsung SW Academy (www.swexpertacademy.com)
 * problem 4259
 */

public class Solution {

    public static void main(String[] args) throws FileNotFoundException {

//        final String INPUT_FILE = "data/sw.expert.academy/4259_input.txt";
//        FastReader in = new FastReader(INPUT_FILE);

        FastReader in = new FastReader(args);

        int t = in.nextInt();
        int test = 0;
        while(test++ < t) {

            BigInteger b = BigInteger.valueOf(0);
            int N = in.nextInt();
            for(int i=0; i<N; i++) {

                String a = in.next();
//                System.out.println(a);
                int base = Integer.valueOf(a.substring(0, a.length()-1));
                int exp = (int)a.charAt(a.length()-1)-48;

                b = b.add(BigInteger.valueOf(base).pow(exp));
            }

            System.out.println("#" + test + " " + b);
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
