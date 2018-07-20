package BOJ._14499;

import java.io.*;
import java.util.*;

public class Main {

    public static final int EAST = 1, WEST = 2, NORTH = 3, SOUTH = 4;
    public static int[] dx = {-999, 0, 0, -1, 1}; // 999: dummy.
    public static int[] dy = {-999, 1, -1, 0, 0};

    public static int N, M;
    public static int K;

    public static int[][] MAP;
    public static int[] DIRECTION;

    public static void rotate(int[] dice, int direction) {

        int[] temp = new int[6];

        switch (direction) {
            case EAST:
                temp[0] = dice[3];
                temp[1] = dice[1];
                temp[2] = dice[0];
                temp[3] = dice[5];
                temp[4] = dice[4];
                temp[5] = dice[2];
                break;
            case WEST:
                temp[0] = dice[2];
                temp[1] = dice[1];
                temp[2] = dice[5];
                temp[3] = dice[0];
                temp[4] = dice[4];
                temp[5] = dice[3];
                break;
            case NORTH:
                temp[0] = dice[4];
                temp[1] = dice[0];
                temp[2] = dice[2];
                temp[3] = dice[3];
                temp[4] = dice[5];
                temp[5] = dice[1];
                break;
            case SOUTH:
                temp[0] = dice[1];
                temp[1] = dice[5];
                temp[2] = dice[2];
                temp[3] = dice[3];
                temp[4] = dice[0];
                temp[5] = dice[4];
                break;
            default:
                System.out.println("Direction error.");
        }

        for(int i=0; i<6; i++)
            dice[i] = temp[i];
    }

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

            int x = in.nextInt();
            int y = in.nextInt();

            K = in.nextInt();

            MAP = new int[N][M];
            for(int i=0; i<N; i++)
                for(int j=0; j<M; j++)
                    MAP[i][j] = in.nextInt();

            DIRECTION = new int[K];
            for(int i=0; i<K; i++)
                DIRECTION[i] = in.nextInt();

            int[] dice = new int[6];
            for(int i=0; i<6; i++)
                dice[0] = 0;

            for(int i=0; i<K; i++) {

//                System.out.println("i: " + i);
//                System.out.println(x + ", " + y);

//                for(int j=0; j<6; j++)
//                    System.out.print(dice[j] + " ");
//                System.out.println();

                int d = DIRECTION[i];

                if((x+dx[d]<0 || x+dx[d]>=N) || (y+dy[d]<0 || y+dy[d]>=M)) {
//                    System.out.println("Out of bounds.");
                    continue;
                }

                rotate(dice, d);

                x += dx[d];
                y += dy[d];

                if(MAP[x][y] == 0) {
                    MAP[x][y] = dice[5];
                }
                else {
                    dice[5] = MAP[x][y];
                    MAP[x][y] = 0;
                }

                System.out.println(dice[0]);
            }
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
