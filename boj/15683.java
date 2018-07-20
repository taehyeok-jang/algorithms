package BOJ._15683;

import java.io.*;
import java.util.*;

public class Main {

    public static int[] dx = {-1, 0, 1, 0};
    public static int[] dy = {0, 1, 0, -1};

    public static int N, M;
    public static int C;
    public static CCTV[] CCTVs;
    // 0: empty, 1~5: CCTV, 6: wall.
    public static int[][] MAP;
    // 0: blind spot, 1~: under the control.
    public static int[][] WATCH;

    public static int MIN;


    public static void solve(int index) {

//        System.out.println("index: " + index);

        if(index == C) {

//            for(int i=0; i<N; i++) {
//                for(int j=0; j<M; j++) {
//                    System.out.print(WATCH[i][j] + " ");
//                }
//                System.out.println();
//            }
//            System.out.println();

            int count = 0;
            for(int i=0; i<N; i++)
                for(int j=0; j<M; j++)
                    if((MAP[i][j] == 0) && WATCH[i][j] == 0)
                        count++;

            MIN = Math.min(MIN, count);
            return;
        }

        // TODO
        // TODO
        // can be optimized.
        int nx, ny;
        if(CCTVs[index].type == 1) {

            for(int i=0; i<4; i++) {

                nx = CCTVs[index].x+dx[i];
                ny = CCTVs[index].y+dy[i];

                watch(true, nx, ny, i);

                solve(index+1);

                watch(false, nx, ny, i);
            }
        }
        else if(CCTVs[index].type == 2) {

            for(int i=0; i<2; i++) {
                // watch out!
                for(int j=0; j<3; j+=2) {

                    nx = CCTVs[index].x+dx[(i+j)%4];
                    ny = CCTVs[index].y+dy[(i+j)%4];

                    watch(true, nx, ny, (i+j)%4);
                }

                solve(index+1);
                // watch out!
                for(int j=0; j<3; j+=2) {

                    nx = CCTVs[index].x+dx[(i+j)%4];
                    ny = CCTVs[index].y+dy[(i+j)%4];

                    watch(false, nx, ny, (i+j)%4);
                }
            }
        }
        else if(CCTVs[index].type == 3) {

            for(int i=0; i<4; i++) {
                for(int j=0; j<2; j++) {

                    nx = CCTVs[index].x+dx[(i+j)%4];
                    ny = CCTVs[index].y+dy[(i+j)%4];

                    watch(true, nx, ny, (i+j)%4);
                }

                solve(index+1);

                for(int j=0; j<2; j++) {

                    nx = CCTVs[index].x+dx[(i+j)%4];
                    ny = CCTVs[index].y+dy[(i+j)%4];

                    watch(false, nx, ny, (i+j)%4);
                }
            }
        }
        else if(CCTVs[index].type == 4) {

            for(int i=0; i<4; i++) {
                for(int j=0; j<3; j++) {

                    nx = CCTVs[index].x+dx[(i+j)%4];
                    ny = CCTVs[index].y+dy[(i+j)%4];

                    watch(true, nx, ny, (i+j)%4);
                }

                solve(index+1);

                for(int j=0; j<3; j++) {

                    nx = CCTVs[index].x+dx[(i+j)%4];
                    ny = CCTVs[index].y+dy[(i+j)%4];

                    watch(false, nx, ny, (i+j)%4);
                }
            }
        }
        else { // == 5

            for(int i=0; i<4; i++) {

                nx = CCTVs[index].x+dx[i];
                ny = CCTVs[index].y+dy[i];

                watch(true, nx, ny, i);
            }

            solve(index+1);

            for(int i=0; i<4; i++) {

                nx = CCTVs[index].x+dx[i];
                ny = CCTVs[index].y+dy[i];

                watch(false, nx, ny, i);
            }
        }
    }

    public static void watch(boolean wc, int x, int y, int d) {

        while((x>=0 && x<N) && (y>=0 && y<M)) {

            if(MAP[x][y] == 6) {
                break;
            }
            else {
                if(wc)  WATCH[x][y]++;
                else    WATCH[x][y]--;
            }

            x += dx[d];
            y += dy[d];
        }
    }

    private static class CCTV {
        int type;
        int x, y;
        public CCTV(int type, int x, int y) {
            this.type = type;
            this.x = x;
            this.y = y;
        }
    }

    public static void main(String[] args) throws FileNotFoundException {

//        final String INPUT_FILE = "data/boj/15683_input.txt";
//        FastReader in = new FastReader(INPUT_FILE);

        FastReader in = new FastReader(args);

//        int test = in.nextInt();
        int test = 1;
        int t = 0;
        while(t++< test) {

//            System.out.println("Test " + t);

            N = in.nextInt();
            M = in.nextInt();

            C = 0;

            MAP = new int[N][M];
            for(int i=0; i<N; i++) {
                for(int j=0; j<M; j++) {
                    MAP[i][j] = in.nextInt();
                    if(MAP[i][j]>0 && MAP[i][j]<6)
                        C++;
                }
            }

            CCTVs = new CCTV[C];
            int index = 0;
            for(int i=0; i<N; i++)
                for(int j=0; j<M; j++)
                    if(MAP[i][j]>0 && MAP[i][j]<6)
                        CCTVs[index++] = new CCTV(MAP[i][j], i, j);

            WATCH = new int[N][M];
            for(int i=0; i<N; i++)
                for(int j=0; j<M; j++)
                    WATCH[i][j] = 0;

            MIN = 654321;
            solve(0);

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
