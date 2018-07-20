package sw.expert.academy.d4._4613;

import java.io.*;
import java.util.StringTokenizer;

public class Solution {

    public static int N, M;
    public static char[][] ARRAY;
    public static int[][] NEED;

    // color: can paint from 'color'
    // index: paint at index'th row.
    public static int solve(int color, int index) {

//        System.out.println(color + ", " + index);

        if(index == N)
            return 0;
        if(index == 0)
            return NEED[0][0] + Math.min(solve(0, 1), solve(1, 1));
        if(color == 2)
            return NEED[index][color] + solve(color, index+1);
        if(2-color == N-index)
            return NEED[index][color+1] + solve(color+1, index+1);

        int a = NEED[index][color] + solve(color, index+1);
        int b = NEED[index][color+1] + solve(color+1, index+1);

        return Math.min(a, b);
    }

    public static void main(String[] args) throws FileNotFoundException {

//        final String INPUT_FILE = "data/sw.expert.academy/4613_input.txt";
//        FastReader in = new FastReader(INPUT_FILE);

        FastReader in  = new FastReader(args);

        int t = in.nextInt();
        int test = 0;
        while(test++ < t) {

            N = in.nextInt();
            M = in.nextInt();

            ARRAY = new char[N][M];
            for(int i=0; i<N; i++) {
                char[] cs = in.next().toCharArray();
                for(int j=0; j<M; j++) {
                    ARRAY[i][j] = cs[j];
                }
            }

            // 0: W, 1: B, 2:R
            NEED = new int[N][3];
            for(int i=0; i<N; i++) {
                for (int j = 0; j < M; j++) {
                    if (ARRAY[i][j] != 'W')
                        NEED[i][0]++;
                    if (ARRAY[i][j] != 'B')
                        NEED[i][1]++;
                    if (ARRAY[i][j] != 'R')
                        NEED[i][2]++;
                }
            }

            System.out.println("#" + test + " " + solve(0, 0));

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
