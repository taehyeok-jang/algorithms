package BOJ._3190;

import java.io.*;
import java.util.*;

public class Main {

    public static int[] dx = {-1, 0, 1, 0};
    public static int[] dy = {0, 1, 0, -1};

    public static int N, K, L;
    public static int[][] MAP;
    public static int[] TURN_TIME;
    public static char[] DIRECTION;

    private static class Point {

        public int x, y;

        public Point(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    public static void main(String[] args) throws FileNotFoundException {

//        final String INPUT_FILE = "data/boj/3190_input.txt";
//        FastReader in = new FastReader(INPUT_FILE);

        FastReader in = new FastReader(args);

//        int test = in.nextInt();
        int test = 1;
        int t = 0;
        while(t++< test) {

            N = in.nextInt();
            MAP = new int[N][N];
            for(int i=0; i<N; i++)
                for(int j=0; j<N; j++)
                    MAP[i][j] = 0;

            // 0: blank, 1: apple
            K = in.nextInt();
            for(int i=0; i<K; i++)
                MAP[in.nextInt()-1][in.nextInt()-1] = 1;

            L = in.nextInt();
            TURN_TIME = new int[L+1];
            DIRECTION = new char[L+1];
            for(int i=0; i<L; i++) {
                TURN_TIME[i] = in.nextInt();
                DIRECTION[i] = in.next().charAt(0);
            }
            TURN_TIME[L] = -1; // dummy

            Deque<Point> snake = new LinkedList<>();
            snake.add(new Point(0, 0));

            int d = 1;
            int time = 0;
            int index = 0;

            while(true) {

                if(TURN_TIME[index] == time) {
                    if(DIRECTION[index] == 'L') d = (d+3)%4;
                    else                        d = (d+1)%4;
                    index++;
                }

                Point head = snake.getLast();
                int nx = head.x + dx[d];
                int ny = head.y + dy[d];

                // out of bounds.
                if((nx<0 || nx>=N) || (ny<0 || ny>=N))
                    break;
                // duplicate body parts.
                boolean duplicate = false;
                Iterator<Point> it = snake.iterator();
                while(it.hasNext()) {
                    Point body = it.next();
                    if((body.x == nx) && (body.y == ny)) {
                        duplicate = true;
                        break;
                    }
                }
                if(duplicate)
                    break;

                // or go.
                snake.add(new Point(nx, ny));

                if(MAP[nx][ny] == 0)
                    snake.removeFirst();
                else
                    MAP[nx][ny] = 0;

                time++;
            }


//            for(int i=0; i<N; i++) {
//                for(int j=0; j<N; j++)
//                    System.out.print(MAP[i][j] + " ");
//                System.out.println();
//            }
//
//            for(int i=0; i<L; i++) {
//                System.out.println(TIME[i]);
//                System.out.println(DIRECTION[i]);
//            }

            System.out.println(time+1);
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
