package sw.expert.academy.test._1767;

import java.io.*;
import java.util.StringTokenizer;

/**
 * Samsung SW Academy (www.swexpertacademy.com)
 * problem 1767
 */

/**
 * output: 8, 12, 10, 24
 */

public class Solution {

    private static int[] dx = {-1, 0, 1, 0};
    private static int[] dy = {0, -1, 0, 1};

    private static class Processor {

        private int N;
        private int[][] array;

        private int totalCore;
        private int totalLength;

        private Processor(int N, int[][] array) {

            this.N = N;
            this.array = array;

            this.totalCore = 0;
            this.totalLength = N*N;
        }

        private int solve() {

            solve(0, 0, 0, 0);
            return totalLength;
        }

        private void solve(int x, int y, int core, int length) {

            int cx = x, cy = y;

            while(cx<N) {

//                System.out.println(cx + ", " + cy);
                if(cy == N) {
                    cx++; cy = 0;
                    continue;
                }

                if(array[cx][cy] == 1) {

                    // direction. up, left, down, right
                    for(int d=0; d<4; d++) {

                        if(canConnect(cx, cy, d)) {
                            connect(true, cx, cy, d);
                            solve(cx, cy+1, core+1, length+getLineLength(cx, cy, d));
                            connect(false, cx, cy, d);
                        }
                    }
                }

                cy++;
            }

            if(core == totalCore)
                totalLength = Math.min(totalLength, length);
            else if(core > totalCore) {
                totalCore = core;
                totalLength = length;
            }
        }

        private boolean canConnect(int x, int y, int d) {

//            System.out.println("can connect? " + x + "," + y + ": " + d);

            int cx = x+dx[d];
            int cy = y+dy[d];

            while(cx>=0 && cx<N && cy>=0 && cy<N) {

                if(array[cx][cy] > 0) {
//                    System.out.println("no");
                    return false;
                }

                cx += dx[d];
                cy += dy[d];
            }
//            System.out.println("yes");
            return true;
        }

        // connect or disconnect
        private void connect(boolean cd, int x, int y, int d) {

            int cx = x+dx[d];
            int cy = y+dy[d];

            while(cx>=0 && cx<N && cy>=0 && cy<N) {

                if(cd)  array[cx][cy] = 2;
                else    array[cx][cy] = 0;

                cx += dx[d];
                cy += dy[d];
            }
        }

        private int getLineLength(int x, int y, int d) {

            switch (d) {
                case 0: return x;
                case 1: return y;
                case 2: return N-1-x;
                case 3: return N-1-y;
                default: return Integer.MIN_VALUE;
            }
        }
    }

    public static void main(String[] args) throws FileNotFoundException {

//        final String INPUT_FILE = "data/sw.expert.academy/1767_input.txt";
//        FastReader in = new FastReader(INPUT_FILE);

        FastReader in = new FastReader(args);

        int t = in.nextInt();
        int test = 0;

        while(test++ < t) {
            int N = in.nextInt();
            int[][] array = new int[N][N];

            for(int i=0; i<N; i++)
                for(int j=0; j<N; j++)
                    array[i][j] = in.nextInt();

            Processor p = new Processor(N, array);
            System.out.println("#" + test + " " + p.solve());
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
