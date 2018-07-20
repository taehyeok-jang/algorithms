package BOJ._14890;

import java.io.*;
import java.util.*;

public class Main {

    public static int[] dx = {-999, 0, 0, -1, 1}; // 999: dummy.
    public static int[] dy = {-999, 1, -1, 0, 0};

    public static int N, M;
    public static int K;

    public static int[][] MAP;
    public static int[] DIRECTION;

    public static void main(String[] args) throws FileNotFoundException {

//        final String INPUT_FILE = "data/boj/14499_input.txt";
//        FastReader in = new FastReader(INPUT_FILE);

        FastReader in = new FastReader(args);

//        int test = in.nextInt();
        int test = 1;
        int t = 0;
        while(t++< test) {

//            System.out.println("Test " + t);

            N = in.nextInt();
            M = in.nextInt();

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
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
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
            try {
                str = br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }
    }
}
