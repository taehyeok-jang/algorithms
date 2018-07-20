package BOJ._14501;

import java.io.*;
import java.util.*;

public class Main {

    public static int[] cache;

    public static int max(int d, int N, int[] T, int[] P) {

//        System.out.println(d + ", " + N);

        if(d == N)
            return 0;
        if(cache[d] != -1)
            return cache[d];

        int a = max(d+1, N, T, P);
        int b = 0;
        if(d+T[d] <= N)
            b = P[d]+max(d+T[d], N, T, P);

        return cache[d] = Math.max(a, b);
    }

    public static void main(String[] args) throws FileNotFoundException {

//        final String INPUT_FILE = "data/boj/14501_input.txt";
//        FastReader in = new FastReader(INPUT_FILE);

        FastReader in = new FastReader(args);

//        int test = in.nextInt();
        int test = 1;
        int t = 0;
        while(t++< test) {

            int N = in.nextInt();
            int[] T = new int[N];
            int[] P = new int[N];
            for(int i=0; i<N; i++) {
                T[i] = in.nextInt();
                P[i] = in.nextInt();
            }

            cache = new int[N];
            for(int i=0; i<N; i++)
                cache[i] = -1;

            int max = max(0, N, T, P);
            System.out.println(max);
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
