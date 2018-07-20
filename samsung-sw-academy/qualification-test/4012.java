package sw.expert.academy.test._4012;

import java.io.*;
import java.util.*;

public class Solution {

    public static int N;
    public static int[][] S;

    public static int TOTAL;
    public static int MIN;

    public static void solve(int k, Stack<Integer> team1) {

        if(k == N) {

            int[] temp = new int[N];
            for(int i=0; i<N; i++)
                temp[i] = 1;
            Iterator<Integer> it = team1.iterator();
            while(it.hasNext())
                temp[it.next()] = 0;

            // team2 build.
            Stack<Integer> team2 = new Stack<>();
            for(int i=0; i<N; i++)
                if(temp[i] == 1)
                    team2.add(i);

//            it = team1.iterator();
//            while(it.hasNext()) {
//                System.out.print(it.next() + " ");
//            }
//            System.out.println();
//
//            it = team2.iterator();
//            while(it.hasNext()) {
//                System.out.print(it.next() + " ");
//            }
//            System.out.println();

            Iterator<Integer> it1, it2;

            int sum1 = 0;
            it1 = team1.iterator();
            while(it1.hasNext()) {
                int member = it1.next();
                it2 = team1.iterator();
                while(it2.hasNext())
                    sum1 += S[member][it2.next()];
            }

            int sum2 = 0;
            it1 = team2.iterator();
            while(it1.hasNext()) {
                int member = it1.next();
                it2 = team2.iterator();
                while(it2.hasNext())
                    sum2 += S[member][it2.next()];
            }

//            System.out.println("sum1: " + sum1 + ", sum2: " + sum2);

            MIN = Math.min(MIN, Math.abs(sum1-sum2));
        }
        else {
            if(N/2-team1.size()+1 > N-k ) {

                team1.add(k);
                solve(k+1, team1);
                team1.pop();
            }
            else {
                // add k'th member.
                if(team1.size() < N/2) {
                    team1.add(k);
                    solve(k+1, team1);
                    team1.pop();
                }

                solve(k+1, team1);
            }
        }
    }

    public static void main(String[] args) throws FileNotFoundException {

//        final String INPUT_FILE = "data/boj/14889_input.txt";
//        FastReader in = new FastReader(INPUT_FILE);

        FastReader in = new FastReader(args);

        int test = in.nextInt();
//        int test = 1;
        int t = 0;
        while(t++< test) {

            N = in.nextInt();

            S = new int[N][N];
            for(int i=0; i<N; i++)
                for(int j=0; j<N; j++)
                    S[i][j] = in.nextInt();

            Stack<Integer> team1 = new Stack<>();

            MIN = 654321;
            solve(0, team1);

            System.out.println("#" + t  + " " + MIN);
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
