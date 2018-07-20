package BOJ._14500;

import java.io.*;
import java.util.*;

public class Main {

    public static int[] dx = {-1, 0, 1, 0};
    public static int[] dy = {0, 1, 0, -1};

    public static int N, M;
    public static int[][] BOARD;

    public static int MAX;

    public static void dfs(int sum, int depth, int x, int y, int prev_d) {

//        System.out.println(x + ", " + y);

        if(depth == 4) {
            MAX = Math.max(MAX, sum);
            return;
        }

        for(int i=0; i<4; i++) {

            if((prev_d != -1) && (prev_d+2)%4 == i)
                continue;

            int nx = x+dx[i];
            int ny = y+dy[i];
            if((nx>=0 && nx<N) && (ny>=0 && ny<M))
                dfs(sum+BOARD[nx][ny], depth+1, nx, ny, i);

        }
    }

    private static class Point {

        public int x, y;
        public Point(int x, int y) {

            this.x = x;
            this.y = y;
        }
    }

    public static void main(String[] args) throws FileNotFoundException {

//        final String INPUT_FILE = "data/boj/14500_input.txt";
//        FastReader in = new FastReader(INPUT_FILE);

        FastReader in = new FastReader(args);

//        int test = in.nextInt();
        int test = 1;
        int t = 0;
        while(t++< test) {

            N = in.nextInt();
            M = in.nextInt();

            BOARD = new int[N][M];
            for(int i=0; i<N; i++)
                for(int j=0; j<M; j++)
                    BOARD[i][j] = in.nextInt();

            MAX = 0;

            // case 1~4.
            for(int i=0; i<N; i++)
                for(int j=0; j<M; j++)
                    dfs(BOARD[i][j], 1, i, j, -1);

            // case 5.
            for(int i=0; i<N; i++) {
                for(int j=0; j<M; j++) {
                    int bound = 0;
                    int sum = BOARD[i][j];
                    int min = 654321;
                    for(int k=0; k<4; k++) {
                        int nx = i+dx[k];
                        int ny = j+dy[k];
                        if((nx>=0 && nx<N) && (ny>=0 && ny<M)) {
                            bound++;
                            sum += BOARD[nx][ny];
                            min = Math.min(min, BOARD[nx][ny]);
                        }
                        else
                            min = 0;
                    }
                    if(bound < 3)
                        continue;

                    sum -= min;

                    MAX = Math.max(MAX, sum);
                }
            }

            System.out.println(MAX);
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
