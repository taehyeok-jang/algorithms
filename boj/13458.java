package BOJ._13458;

import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws FileNotFoundException {

//        final String INPUT_FILE = "data/boj/13458_input.txt";
//        FastReader in = new FastReader(INPUT_FILE);

        FastReader in = new FastReader(args);

//        int test = in.nextInt();
        int test = 1;
        int t = 0;
        while(t++< test) {

            int N = in.nextInt();
            int[] arr = new int[N];
            for(int i=0; i<N; i++)
                arr[i] = in.nextInt();

            int B = in.nextInt();
            int C = in.nextInt();

            long supervisor = N;
            for(int i=0; i<N; i++) {

                int member = arr[i]-B;
                if(member <= 0)
                    continue;
                else {
                    if(member%C == 0)
                        supervisor += member/C;
                    else
                        supervisor += member/C+1;
                }
            }

            System.out.println(supervisor);

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
