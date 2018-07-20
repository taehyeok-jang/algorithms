package sw.expert.academy.d4._4301;

import java.io.*;
import java.util.StringTokenizer;

/**
 * Samsung SW Academy (www.swexpertacademy.com)
 * problem 4301
 */

public class Solution {

    // down, right,.
    public static int[] dx = {2, 0};
    public static int[] dy = {0, 2};

    /*
    public static int max(int x, int y, int prev_state, final int N, final int M, int[][] array) {

//        System.out.println(x + ", " + y + " ... " + prev_state);

        if(x == N)
            return 0;
        if(y == M)
            return max(x+1, 0, prev_state, N, M, array);

//        if(cache[x][y][prev_state] != -1)
//            return cache[x][y][prev_state];

        // 0: not decided yet.
        // 1: be put already.
        // 2: cannot paint.
        if(array[x][y] == 2)
            return cache[x][y][prev_state] = max(x, y+1, 2, N, M, array);

        int cx = x;
        int cy = y;

        int max = 0;

        while(cx < N) {

            while(cy < M) {

                if(array[cx][cy] == 0) {

                    // case 1.
                    // put bean at (x,y).
                    array[x][y] = 1;

                    List<Coord> banned = new ArrayList<>();
                    for(int i=0; i<2; i++) {

                        if ((cx+dx[i]>=0 && cx+dx[i]<N) && (cy+dy[i]>=0 && cy+dy[i]<M)) {

                            array[cx+dx[i]][cy+dy[i]] = 2;
                            banned.add(new Coord(cx+dx[i], cy+dy[i]));
                        }
                    }
                    int a = 1 + max(cx, cy+1, 1, N, M, array);

                    // back-track
                    array[x][y] = 0;
                    Iterator<Coord> it = banned.iterator();
                    while(it.hasNext()) {
                        Coord c = it.next();
                        array[c.x][c.y] = 0;
                    }

                    // case 2.
                    // not put.
                    int b = max(cx, cy+1, 0, N, M, array);

                    max = Math.max(max, Math.max(a, b));
                }

                cy++;
            }

            cy = 0;
            cx++;
        }

        return cache[x][y][prev_state] = max;
    }*/

    /*
    private static class Coord {

        public int x, y;
        public Coord(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }
*/

    public static void main(String[] args) throws FileNotFoundException {

//        final String INPUT_FILE = "data/sw.expert.academy/4301_input.txt";
//        FastReader in = new FastReader(INPUT_FILE);

        FastReader in = new FastReader(args);

        int t = in.nextInt();
        int test = 0;

        while(test++ < t) {

            // M, N. (not N, M)
            int M = in.nextInt();
            int N = in.nextInt();

            int[][] array = new int[N][M];
            for(int i=0; i<N; i++)
                for(int j=0; j<M; j++)
                    array[i][j] = 0;

            for(int x=0; x<N; x++) {
                for (int y=0; y<M; y++) {

                    if(array[x][y] == 0) {

                        array[x][y] = 1;

                        for(int i=0; i<2; i++) {

                            if ((x+dx[i]>=0 && x+dx[i]<N) && (y+dy[i]>=0 && y+dy[i]<M))
                                array[x+dx[i]][y+dy[i]] = -1;
                        }
                    }
                    else
                        continue;
                }
            }

            int bean = 0;
            for(int i=0; i<N; i++)
                for(int j=0; j<M; j++)
                    if(array[i][j] == 1)
                        bean++;

            System.out.println("#" + test + " " + bean);
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
