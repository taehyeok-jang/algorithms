package sw.expert.academy.d4._4366;

import java.io.*;
import java.math.BigInteger;
import java.util.StringTokenizer;

public class Solution {

    public static BigInteger binaryTodecimal(int[] binary) {

        BigInteger b = BigInteger.valueOf(0);
        for(int i=0; i<binary.length; i++)
            b = b.add(BigInteger.valueOf(binary[i]*(int)Math.pow(2, binary.length-i-1)));

        return b;
    }

    public static boolean equal(int[] binary, int[] ternary) {

        BigInteger db = BigInteger.valueOf(0);
        BigInteger dt = BigInteger.valueOf(0);

        for(int i=0; i<binary.length; i++)
            db = db.add(BigInteger.valueOf(binary[i]*(int)Math.pow(2, binary.length-i-1)));
        for(int i=0; i<ternary.length; i++)
            dt = dt.add(BigInteger.valueOf(ternary[i]*(int)Math.pow(3, ternary.length-i-1)));

//        if(db.equals(dt)) {
//            for(int i=0; i<binary.length; i++)
//                System.out.print(binary[i]);
//            System.out.println();
//            for(int i=0; i<ternary.length; i++)
//                System.out.print(ternary[i]);
//            System.out.println();
//            System.out.println("db: " + db);
//            System.out.println("dt: " + dt);
//            System.out.println(db.equals(dt));
//        }

        return db.equals(dt);
    }

    public static void main(String[] args) throws FileNotFoundException {

//        final String INPUT_FILE = "data/sw.expert.academy/4366_input.txt";
//        FastReader in = new FastReader(INPUT_FILE);

        FastReader in  = new FastReader(args);

        int t = in.nextInt();
        int test = 0;
        while(test++ < t) {

            // 9223372036854775807
            System.out.println(Long.MAX_VALUE);
            System.out.println(Integer.MAX_VALUE);

            char[] c = in.next().toCharArray();
            int[] binary = new int[c.length];
            int B = binary.length;
            for(int i=0; i<B; i++)
                binary[i] = c[i]-48;

            c = in.next().toCharArray();
            int[] ternary = new int[c.length];
            int T = ternary.length;
            for(int i=0; i<T; i++)
                ternary[i] = c[i]-48;

            // binary i'th, ternary j'th.
            // fault.
            for(int i=0; i<B; i++) {
                for(int j=0; j<T; j++) {

                    int bo = binary[i];
                    int to = ternary[j];

                    for(int bb=0; bb<2; bb++) {
                        for(int tt=0; tt<3; tt++) {
                            if(bb == bo)
                                continue;
                            if(tt == to)
                                continue;

                            binary[i] = bb;
                            ternary[j] = tt;

                            if(equal(binary, ternary)) {

                                System.out.println("#" + test + " " + binaryTodecimal(binary));
                            }

                        }
                    }

                    binary[i] = bo;
                    ternary[j] = to;
                }
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
