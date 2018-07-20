package BOJ._14502;

import java.io.*;
import java.util.*;

public class Main {

    public static int[] dx = {1, 0, -1, 0};
    public static int[] dy = {0, -1, 0, 1};

    public static int MAX;

    public static int N, M;
    public static int[][] MAP;
    public static int[][] ORIGINAL;

    public static void solve(final int ox, final int oy, Stack<Point> obstacles) {

//        System.out.println(ox + ", " + oy);

        if(obstacles.size() == 3) {

            ORIGINAL = new int[N][M];
            for(int i=0; i<N; i++)
                for(int j=0; j<M; j++)
                    ORIGINAL[i][j] = MAP[i][j];

            // spread virus.
            for(int i=0; i<N; i++) {
                for(int j=0; j<M; j++) {

                    if(MAP[i][j] == 2) {

                        Queue<Point> queue = new LinkedList<>();
                        queue.add(new Point(i, j));

                        // bfs.
                        while(!queue.isEmpty()) {

                            Point v = queue.remove();
                            for(int d=0; d<4; d++) {
                                int x = v.x + dx[d];
                                int y = v.y + dy[d];
                                if((x >= 0 && x < N) && (y >= 0 && y < M)) {
                                    if(MAP[x][y] == 0) {

                                        MAP[x][y] = 2;
                                        queue.add(new Point(x, y));
                                    }
                                }
                            }
                        }
                    }
                }
            }

            int count = 0;
            for(int i=0; i<N; i++)
                for(int j=0; j<M; j++)
                    if(MAP[i][j] == 0)
                        count++;

            MAX = Math.max(MAX, count);

            // go back to the situation before virus spread yet.
            MAP = ORIGINAL;
        }
        else {

            int x = ox;
            int y = oy;
            while(x < N) {
                while(y < M) {

                    if(MAP[x][y] == 0) {

                        MAP[x][y] = 1;
                        obstacles.add(new Point(x, y));
                        solve(x, y+1, obstacles);

                        MAP[x][y] = 0;
                        obstacles.pop();
                    }
                    y++;
                }
                x++;
                y = 0;
            }
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

//        final String INPUT_FILE = "data/boj/14502_input.txt";
//        FastReader in = new FastReader(INPUT_FILE);

        FastReader in = new FastReader(args);

//        int test = in.nextInt();
        int test = 1;
        int t = 0;
        while(t++< test) {

            MAX = 0;

            N = in.nextInt();
            M = in.nextInt();

            MAP = new int[N][M];
            for(int i=0; i<N; i++)
                for(int j=0; j<M; j++)
                    MAP[i][j] = in.nextInt();

            Stack<Point> obstacles = new Stack<>();

            solve(0, 0, obstacles);
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
