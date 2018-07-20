package BOJ._12100;

import java.io.*;
import java.util.*;

public class Main {

    // up, right, down, left.
    public static int[] dx = {-1, 0, 1, 0};
    public static int[] dy = {0, 1, 0, -1};

    public static int N;
    public static int[][] ORIGINAL;

    public static int MAX;

    public static void solve(int index, int[][] board) {

//        System.out.println("index: " + index);

        if(index == 5) {

            for(int i=0; i<N; i++)
                for(int j=0; j<N; j++)
                    MAX = Math.max(MAX, board[i][j]);
            return;
        }

        for(int d=0; d<4; d++) {

            int[][] copy = new int[N][N];
            for(int i=0; i<N; i++)
                for(int j=0; j<N; j++)
                    copy[i][j] = board[i][j];

            Deque<Integer> deque = new LinkedList<>();

            // move blocks by 'd' direction.
            int ix = (d==0||d==1)?(0):(N-1);
            int iy = (d==1||d==2)?(N-1):(0);

//            System.out.println("initial coords " + ix + ", " + iy);

            int x = ix;
            int y = iy;

//            System.out.println("for direction " + d + " %%%%%");
//            System.out.println("inner: " + dx[(d+2)%4] + ", " + dy[(d+2)%4]);
//            System.out.println("outer: " + dx[(d+1)%4] + ", " + dy[(d+1)%4]);

            if(d==0 || d==2) {

                while(y>=0 &&y<N) {

                    deque.clear();

                    // add & merge blocks into queue.
                    int merge = -1;
                    while(x>=0 && x<N) {

//                        System.out.println(x + ", " + y);

                        if(copy[x][y] != 0) {

                            if(deque.size() == 0) {
//                                System.out.println("@@ case 0. size 0");
                                deque.addLast(copy[x][y]);
                            }
                            else {

                                if(copy[x][y] == deque.getLast()) {

                                    if(copy[x][y] == merge) {

//                                        System.out.println("@@ case 1-1. already merged");
                                        deque.addLast(copy[x][y]);
                                        merge = -1;
                                    }
                                    else {
//                                        System.out.println("@@ case 1-2. merge.");
                                        merge = 2*deque.removeLast();
                                        deque.addLast(merge);
                                    }
                                }
                                else {
//                                    System.out.println("@@ case default. add into deque.");
                                    deque.addLast(copy[x][y]);
                                    merge = -1;
                                }
                            }
                        }

                        x += dx[(d+2)%4];
                        y += dy[(d+2)%4];
                    }

                    // inner
                    x = ix;
                    while(deque.size() != 0) {
                        copy[x][y] = deque.removeFirst();
                        x += dx[(d+2)%4];
                        y += dy[(d+2)%4];
                    }
                    while(x>=0 && x<N) {
                        copy[x][y] = 0;
                        x += dx[(d+2)%4];
                        y += dy[(d+2)%4];
                    }

                    // outer
                    x = ix;
                    y += dy[(d+1)%4];
                }
            }
            else { // d==1 || d==3

                while(x>=0 && x<N) {

                    deque.clear();

                    // add & merge blocks into queue.
                    int merge = -1;
                    while(y>=0 && y<N) {

//                        System.out.println(x + ", " + y);

                        if(copy[x][y] != 0) {

                            if(deque.size() == 0) {
//                                System.out.println("@@ case 0. size 0. just add.");
                                deque.addLast(copy[x][y]);
                            }
                            else {

                                if(copy[x][y] == deque.getLast()) {

                                    if(copy[x][y] == merge) {

//                                        System.out.println("@@ case 1-1. cannot merge (merged just before).");
                                        deque.addLast(copy[x][y]);
                                        merge = -1;
                                    }
                                    else {
//                                        System.out.println("@@ case 1-2. merge 2 blocks.");
                                        merge = 2*deque.removeLast();
                                        deque.addLast(merge);
                                    }
                                }
                                else {
//                                    System.out.println("@@ case default. add.");
                                    deque.addLast(copy[x][y]);
                                    merge = -1;
                                }
                            }
                        }

                        x += dx[(d+2)%4];
                        y += dy[(d+2)%4];
                    }

                    // inner
                    y = iy;
                    while(deque.size() != 0) {
                        copy[x][y] = deque.removeFirst();
                        x += dx[(d+2)%4];
                        y += dy[(d+2)%4];
                    }
                    while(y>=0 && y<N) {
                        copy[x][y] = 0;
                        x += dx[(d+2)%4];
                        y += dy[(d+2)%4];
                    }

                    // outer
                    y = iy;
                    x += dx[(d+1)%4];
                }
            }

//            System.out.println("original");
//            for(int i=0; i<N; i++) {
//                for(int j=0; j<N; j++) {
//                    System.out.print(board[i][j] + " ");
//                }
//                System.out.println();
//            }
//            System.out.println();
//
//            for(int i=0; i<N; i++) {
//                for(int j=0; j<N; j++) {
//                    System.out.print(copy[i][j] + " ");
//                }
//                System.out.println();
//            }
//            System.out.println();

            // back-tracking difficult...
            // so use more memory.
            solve(index+1, copy);
        }
    }

    public static void main(String[] args) throws FileNotFoundException {

//        final String INPUT_FILE = "data/boj/12100_input.txt";
//        FastReader in = new FastReader(INPUT_FILE);

        FastReader in = new FastReader(args);

//        int test = in.nextInt();
        int test = 1;
        int t = 0;
        while(t++< test) {

            N = in.nextInt();

            ORIGINAL = new int[N][N];
            for(int i=0; i<N; i++)
                for(int j=0; j<N; j++)
                    ORIGINAL[i][j] = in.nextInt();

            int[][] board = new int[N][N];
            for(int i=0; i<N; i++)
                for(int j=0; j<N; j++)
                    board[i][j] = ORIGINAL[i][j];

            MAX = 0;
            solve(0, board);

            System.out.println(MAX);
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
