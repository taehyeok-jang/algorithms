package BOJ._15684;

import java.io.*;
import java.util.*;

public class Main {

    public static int MIN;

    // actual size N * (M+2).
    public static void solve(int put, final int px, final int py, int N, int H, int[][] ladders) {

//        System.out.println("solve. " + put + ", (" + px + "," + py + ")");
//
//        for(int i=0; i<N; i++) {
//            for(int j=0; j<H+2; j++) {
//                System.out.print(ladders[i][j] + " ");
//            }
//            System.out.println();
//        }

        if(put > 3)
            return;
        if(isSuccess(N, H, ladders)) {

//            System.out.println("Success");

            if(MIN == -654321)  MIN = put;
            else                MIN = Math.min(MIN, put);

            return;
        }

        int x = px;
        int y = py;
        while(x < N-1) {

            while(y < H+1) {

                // can put line.
                if(ladders[x][y] == 0 && ladders[x+1][y] == 0) {

                    ladders[x][y] = 1;
                    ladders[x+1][y] = 2;

                    solve(put+1, x, y+1, N, H, ladders);

                    // back-track.
                    ladders[x][y] = 0;
                    ladders[x+1][y] = 0;
                }

                y++;
            }

            x++;
            y = 1;
        }
    }

    public static boolean isSuccess(int N, int M, int[][] ladders) {

        for(int i=0; i<N; i++) {

            int x = i;
            int y = 0;

            while(y < M+1) {

                if(ladders[x][y] == 1)      x++;
                else if(ladders[x][y] == 2) x--;

                y++;
            }

            if(x != i)
                return false;
        }

        return true;
    }

    public static void main(String[] args) throws FileNotFoundException {

//        final String INPUT_FILE = "data/boj/15684_input.txt";
//        FastReader in = new FastReader(INPUT_FILE);

        FastReader in = new FastReader(args);

//        int test = in.nextInt();
        int test = 1;
        int t = 0;
        while(t++< test) {

            int N = in.nextInt();
            int M = in.nextInt();
            int H = in.nextInt();

            int[][] line = new int[M][2];
            for(int i=0; i<M; i++) {
                line[i][0] = in.nextInt();
                line[i][1] = in.nextInt();
            }

            int[][] ladders = new int[N][H+2];
            for(int i=0; i<N; i++)
                for(int j=0; j<H+2; j++)
                    ladders[i][j] = 0;

            for(int i=0; i<M; i++) {
                int a = line[i][0];
                int b = line[i][1];
                ladders[b-1][a] = 1;
                ladders[b][a] = 2;
            }

//            for(int i=0; i<N; i++) {
//                for(int j=0; j<H+2; j++) {
//                    System.out.print(ladders[i][j] + " ");
//                }
//                System.out.println();
//            }

            MIN = -654321;

            solve(0, 0, 1, N, H, ladders);

            if(MIN == -654321)  System.out.println(-1);
            else                System.out.println(MIN);
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
