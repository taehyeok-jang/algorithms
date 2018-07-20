package sw.expert.academy.d4._3812;

import java.io.*;
import java.util.StringTokenizer;

public class Solution {

    public static int[] SIZE;
    public static int[] CENTER;
    public static int N;

    public static long[][] modulus;

    public static long[][] cache;

    // TODO long -> BigInteger? unnecessary.
    public static long solve(int d, int left) {

//        System.out.println(d + ", " + left);

        if(cache[d][left] != -1)
            return cache[d][left];

        if(d == 2) {
            if(left < N)
                return cache[d][left] = modulus[2][left];
            else
                return 0;
        }

        // TODO
        // what if left >= N?
        int bound = (left<N)?left:N-1;
        long count = 0;
        for(int i=0; i<bound+1; i++)
            count += modulus[d][i] * solve(d+1, left-i);

        return cache[d][left] = count;
    }

    public static void main(String[] args) throws FileNotFoundException {

//        final String INPUT_FILE = "data/sw.expert.academy/3812_input.txt";
//        FastReader in = new FastReader(INPUT_FILE);

        FastReader in = new FastReader(args);

        int t = in.nextInt();
        int test = 0;
        while(test++ < t) {

//            System.out.println("Test " + test);

            SIZE = new int[3];
            for(int i=0; i<3; i++)
                SIZE[i] = in.nextInt();
            CENTER = new int[3];
            for(int i=0; i<3; i++)
                CENTER[i] = in.nextInt();

            N = in.nextInt();

            cache = new long[3][3*N];
            for(int i=0; i<3; i++)
                for(int j=0; j<3*N; j++)
                    cache[i][j] = -1;

            // print all combinations of coordinates.
//            for(int i=0; i<SIZE[0]; i++) {
//                for(int j=0; j<SIZE[1]; j++) {
//                    for(int k=0; k<SIZE[2]; k++) {
//
//                        System.out.println(i + " " + j + " " + k + " -> " + (i+j+k) + " (mod: " + (i+j+k)%N + ")\n");
//                    }
//                }
//            }

            // modulus[0][j]: the number of x for getting 'j' from j modulus N operation in 1 d.
            modulus = new long[3][N];
            for(int i=0; i<3; i++) {
                int k = CENTER[i];
                int jump = 0;
                // k ~ A-1
                // several jumps, and iterate.
                while(k < SIZE[i]) {
                    if(k+N < SIZE[i]) {
                        k += N;
                        jump++;
                    }
                    else {
                        modulus[i][(k-CENTER[i])%N]++;
                        k++;
                    }
                }
                for(int j=0; j<N; j++)
                    modulus[i][j] += jump;

                k = CENTER[i]-1;
                jump = 0;
                // k-1 ~ 0
                while(k >= 0) {
                    if(k-N >= 0) {
                        k -= N;
                        jump++;
                    }
                    else {
                        modulus[i][(CENTER[i]-k)%N]++;
                        k--;
                    }
                }
                for(int j=0; j<N; j++)
                    modulus[i][j] += jump;
            }

//            for(int i=0; i<3; i++) {
//                for(int j=0; j<N; j++)
//                    System.out.print(modulus[i][j] + " ");
//                System.out.println();
//            }

            System.out.print("#" + test);

            for(int i=0; i<N; i++)
                System.out.print(" " + (solve(0, i) + solve(0, N+i) + solve(0, 2*N+i)));
            System.out.println();
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
