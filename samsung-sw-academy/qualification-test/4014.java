package sw.expert.academy.test._4014;

import java.io.*;
import java.util.*;

public class Solution {

    public static int[] dx = {-1, 0, 1, 0};
    public static int[] dy = {0, 1, 0, -1};

    public static int N, L;
    public static int[][] MAP;

    public static boolean canPass(int sx, int sy, int d) {

//        System.out.println(sx + ", " + sy + " ... " + d);

        int[] tilt = new int[N];
        for(int i=0; i<N; i++)
            tilt[i] = 0;

        int x = sx;
        int y = sy;
        // when faced with different height, check the lower plane can have tilt. (check both direction).
        int height = MAP[x][y];
        while((x < N) && (y < N)) {

            if(height != MAP[x][y]) {

                if(Math.abs(height-MAP[x][y]) > 1)
                    return false;
                // check backward.
                else if(height < MAP[x][y]) {
                    int tx = x-dx[d];
                    int ty = y-dy[d];
                    for(int i=0; i<L; i++) {
                        if((tx<0 || tx>=N) || (ty<0 || ty>=N))
                            return false;
                        if(MAP[tx][ty] != height)
                            return false;

                        int t = (d%2 == 0)? tx:ty;
                        if(tilt[t] != 0)
                            return false;

                        tilt[t] = 1;
                        tx -= dx[d];
                        ty -= dy[d];
                    }
                }
                // check forward.
                else { // height == MAP[x][y]+1
                    int tx = x;
                    int ty = y;
                    for(int i=0; i<L; i++) {
                        if((tx<0 || tx>=N) || (ty<0 || ty>=N))
                            return false;
                        if(MAP[tx][ty] != MAP[x][y])
                            return false;

                        int t = (d%2 == 0)? tx:ty;
                        if(tilt[t] != 0)
                            return false;

                        tilt[t] = 1;
                        tx += dx[d];
                        ty += dy[d];
                    }
                    x = tx-dx[d];
                    y = ty-dy[d];
                }
            }

            height = MAP[x][y];

            x += dx[d];
            y += dy[d];
        }

//        System.out.println("pass.");
        return true;
    }

    public static void main(String[] args) throws FileNotFoundException {

//        final String INPUT_FILE = "data/boj/14890_input.txt";
//        FastReader in = new FastReader(INPUT_FILE);

        FastReader in = new FastReader(args);

        int test = in.nextInt();
//        int test = 1;
        int t = 0;
        while(t++< test) {

            N = in.nextInt();
            L = in.nextInt();

            MAP = new int[N][N];
            for(int i=0; i<N; i++)
                for(int j=0; j<N; j++)
                    MAP[i][j] = in.nextInt();

            int count = 0;
            for(int i=0; i<N; i++)
                if(canPass(0, i, 2))
                    count++;
            for(int i=0; i<N; i++)
                if(canPass(i, 0, 1))
                    count++;


            System.out.println("#" + t + " " + count);
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

