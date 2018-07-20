package BOJ._11025;

import java.io.*;
import java.math.BigInteger;
import java.util.StringTokenizer;

public class Main {

    private static BigInteger ZERO = BigInteger.valueOf(0);
    private static BigInteger ONE = BigInteger.valueOf(1);
    private static BigInteger TWO = BigInteger.valueOf(2);


    public static void main(String[] args) throws FileNotFoundException {

//        final String INPUT_FILE = "data/sw.expert.academy/4411_input.txt";
//        FastReader in = new FastReader(INPUT_FILE);

        FastReader in = new FastReader(args);

//        int t = in.nextInt();
        int t = 1;
        int test = 0;
        while(test++ < t) {

            double start = System.currentTimeMillis();

            BigInteger N = new BigInteger(in.next());
            BigInteger K = new BigInteger(in.next());

            BigInteger f = ONE;

            BigInteger i = ONE;
            while((i=i.add(ONE)).compareTo(N) <= 0) {

//                System.out.print("i: " + i);

                f = (f.add(K).subtract(ONE)).mod(i).add(ONE);

//                System.out.println(" -> f: " + f);
            }

            double end = System.currentTimeMillis();
//            System.out.println((end-start)/1000.0 + "s");

            System.out.println(f);
//            System.out.println("#" + test + " " + f);
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
