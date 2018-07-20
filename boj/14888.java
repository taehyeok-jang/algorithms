package BOJ._14888;

import java.io.*;
import java.util.*;

public class Main {

    public static int MAX, MIN;

    public static void solve(int index, Stack<Integer> combination, int N, int[] A, int[] OP) {

//        System.out.println(index);

        if (index == N-1) {

            int temp = A[0];
            Iterator<Integer> it = combination.iterator();
            for(int i=1; i<N; i++) {
                switch (it.next()) {
                    case 0:
                        temp += A[i];
                        break;
                    case 1:
                        temp -= A[i];
                        break;
                    case 2:
                        temp *= A[i];
                        break;
                    case 3:
                        temp /= A[i];
                        break;
                    default:
                        System.out.println("Operators error.");
                        break;
                }
            }

            MAX = Math.max(MAX, temp);
            MIN = Math.min(MIN, temp);

            return;
        }

        for(int i=0; i<4; i++) {
            if (OP[i] > 0) {
                combination.add(i);
                OP[i]--;
                solve(index+1, combination, N, A, OP);
                combination.pop();
                OP[i]++;
            }
        }
    }

    public static void main(String[] args) throws FileNotFoundException {

//        final String INPUT_FILE = "data/boj/14888_input.txt";
//        FastReader in = new FastReader(INPUT_FILE);

        FastReader in = new FastReader(args);

//        int test = in.nextInt();
        int test = 1;
        int t = 0;
        while(t++< test) {

            int N = in.nextInt();
            int[] A = new int[N];
            for(int i=0; i<N; i++)
                A[i] = in.nextInt();

            int[] OP = new int[4];
            for(int i=0; i<4; i++)
                OP[i] = in.nextInt();

            MAX = Integer.MIN_VALUE;
            MIN = Integer.MAX_VALUE;

            Stack<Integer> combination = new Stack<>();

            solve(0, combination, N, A, OP);

            System.out.println(MAX);
            System.out.println(MIN);
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
