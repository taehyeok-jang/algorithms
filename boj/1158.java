package BOJ._1158;

import java.io.*;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws FileNotFoundException {

        FastReader in = new FastReader(args);

        int t = 1;
        int test = 0;
        while(test++ < t) {

            int N = in.nextInt();
            int K = in.nextInt();

            Queue<Integer> queue = new LinkedList<>();
            for(int i=0; i<N; i++)
                queue.add(i+1);

            System.out.print("<");
            while(queue.size() > 1) {

                for(int i=0; i<K-1; i++)
                    queue.add(queue.remove());

                System.out.print(queue.remove() + ", ");
            }

            System.out.println(queue.remove() + ">");
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
