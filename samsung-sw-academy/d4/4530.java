package sw.expert.academy.d4._4530;

import java.io.*;
import java.util.StringTokenizer;

/**
 * Samsung SW Academy (www.swexpertacademy.com)
 * problem 4530
 */

public class Solution {

    public static long[][] combination_cache;
    public static long[] tenth_cache;

    public static long bruteforce_count(long floor) {

        long count = 0;
        for(long i=1; i<floor+1; i++) {

            char[] arr = String.valueOf(i).toCharArray();
            for(int j=0; j<arr.length; j++)
                if(arr[j] == '4') {
                    count++;
                    break;
                }
        }

        return count;
    }

    public static long count(long floor) {

        String str = String.valueOf(floor);
        int l = str.length();

        int[] arr = new int[l];
        for(int i=0; i<l; i++)
            arr[i] = str.charAt(i) - '0';

        long count = 0;
        for(int i=0; i<l; i++) {

            long tenth = tenth(l-i-1);

            if(i>0 && arr[i-1] == 4) {
                count += floor%((long)Math.pow(10, l-i))+1;
                break;
            }
            else {
                if(arr[i] <= 4)
                    count += tenth*arr[i];
                else
                    count += (long)Math.pow(10, l-i-1) + tenth*(arr[i]-1);
            }
        }

        return floor-count;
    }

    // count of 10^n
    public static long tenth(int n) {

        if(tenth_cache[n] != -1)
            return tenth_cache[n];

        long count = 0;
        for(int i=0; i<n; i++)
            count += combination(n, i+1) * (long)Math.pow(-1, i) * (long)Math.pow(10, n-i-1);

        return tenth_cache[n] = count;
    }

    public static long combination(int n, int r) {

        if(r == 0 || n == r)
            return 1;
        else if(combination_cache[n][r] != -1)
            return combination_cache[n][r];
        else
            return combination_cache[n][r] = combination(n-1, r) + combination(n-1, r-1);
    }

    public static void main(String[] args) throws FileNotFoundException {

//        final String INPUT_FILE = "data/sw.expert.academy/4530_input.txt";
//        FastReader in = new FastReader(INPUT_FILE);

        FastReader in = new FastReader(args);

        int t = in.nextInt();
        int test = 0;

        while(test++ < t) {

            long A = Long.valueOf(in.next());
            long B = Long.valueOf(in.next());

//            System.out.println(A);
//            System.out.println(B);

            combination_cache = new long[14][14];
            for(int i=0; i<14; i++)
                for(int j=0; j<14; j++)
                    combination_cache[i][j] = -1;

            tenth_cache = new long[14];
            for(int i=0; i<14; i++)
                tenth_cache[i] = -1;

//            long TEST = 950042;
//            System.out.print("bruteforce-count: ");
//            System.out.println(bruteforce_count(TEST));

//            System.out.print("count: ");
//            System.out.println(count(50));
//
            long count = -1;
            if(B>0 && A>0) count = count(B)-count(A);
            if(B>0 && A<0) count = count(B)+count(-A)-1;
            if(B<0 && A<0) count = count(-A)-count(-B);

            System.out.println("#" + test + " " + count);
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
