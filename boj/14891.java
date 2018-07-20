package BOJ._14891;

import java.io.*;
import java.util.*;

public class Main {

    private static class Wheel {

        private Deque<Integer> deque;

        public Wheel(String str) {

            deque = new LinkedList<>();
            char[] c = str.toCharArray();
            for(int i=0; i<8; i++)
                deque.addLast(c[i]-48);
        }

        public void rotate(int direction) {
            // clock-wise
            if(direction == 1)  deque.addFirst(deque.removeLast());
            // anti clock-wise
            else                deque.addLast(deque.removeFirst());
        }

        public int top() {

            return deque.getFirst();
        }

        public int get(int n) {

            Iterator<Integer> it = deque.iterator();
            for(int i=0; i<n; i++)
                it.next();

            return it.next();
        }
    }

    public static void main(String[] args) throws FileNotFoundException {

//        final String INPUT_FILE = "data/boj/14891_input.txt";
//        FastReader in = new FastReader(INPUT_FILE);

        FastReader in = new FastReader(args);

        Wheel[] wheels = new Wheel[4];
        for(int i=0; i<4; i++)
            wheels[i] = new Wheel(in.next());

        int K = in.nextInt();
        int[] target = new int[K];
        int[] direction = new int[K];
        for(int i=0; i<K; i++) {
            target[i] = in.nextInt()-1;
            direction[i] = in.nextInt();
        }

        for(int i=0; i<K; i++) {

            int pivot = target[i];
            int left = 0;
            while(pivot > 0) {
                if(wheels[pivot].get(6) != wheels[pivot-1].get(2)) {
                    left++;
                    pivot--;
                }
                else
                    break;
            }

            pivot = target[i];
            int right = 0;
            while(pivot < 3) {
                if(wheels[pivot].get(2) != wheels[pivot+1].get(6)) {
                    right++;
                    pivot++;
                }
                else
                    break;
            }

            int d = direction[i];
            pivot = target[i];
            // center
            wheels[pivot].rotate(d);
            // to the left
            for(int j=0; j<left; j++) {
                d = -d;
                wheels[pivot-j-1].rotate(d);
            }
            // to the right
            for(int j=0; j<right; j++) {
                d = -d;
                wheels[pivot+j+1].rotate(d);
            }
        }

        int sum = 0;
        for(int i=0; i<4; i++)
            sum += wheels[i].top()*(int)Math.pow(2, i);

        System.out.println(sum);

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
