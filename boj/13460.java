package BOJ._13460;

import java.io.*;
import java.util.*;

// output: 1, 5, 5, -1, 1, 7, 1
// additional: 2, -1, 2, 8, 8, 8, 8, 8, -1, 6, -1, 4, 3

public class Main {

    // up, left, down, right.
    public static int[] dx = {-1, 0, 1, 0};
    public static int[] dy = {0, -1, 0, 1};

    private static class Game {

        private int N, M;
        private char[][] board;

        private int MIN;

        public Game(int N, int M, char[][] board) {

            this.N = N;
            this.M = M;
            this.board = board;

            this.MIN = 654321;
        }

        public int solve() {

            int rx = -1, ry = -1;
            int bx = -1, by = -1;
            for(int i=0; i<N; i++) {
                for(int j=0; j<M; j++) {
                    if(board[i][j] == 'R') {
                        rx = i;
                        ry = j;
                    }
                    if(board[i][j] == 'B') {
                        bx = i;
                        by = j;
                    }
                }
            }
            Stack<Integer> combination = new Stack<>();
            combination.add(-1);
            solve(1, rx, ry, bx, by, combination);

            if(MIN > 10)    return -1;
            else            return MIN;
        }

        private void solve(int depth, final int rx, final int ry, final int bx, final int by, Stack<Integer> combination) {

            if(depth > 10)
                return;
/*
            System.out.println("depth: " + depth);
            System.out.println("(" + rx + "," + ry + "), (" + bx + "," + by + ")");

            Iterator<Integer> it = combination.iterator();
            while(it.hasNext())
                System.out.print(it.next() + " ");
            System.out.println();

            for(int j=0; j<N; j++) {
                for(int k=0; k<M; k++)
                    System.out.print(board[j][k] + " ");
                System.out.println();
            }
*/


            for(int i=0; i<4; i++) {

                if(i == combination.peek())
                    continue;

                // check if at least one ball can be moved.
                // case: #, ., R, B, O. if stepping into R, B, just go.
                boolean canMove = false;
                if(board[rx+dx[i]][ry+dy[i]] == '.' || board[rx+dx[i]][ry+dy[i]] == 'O')
                    canMove = true;
                if(board[bx+dx[i]][by+dy[i]] == '.' || board[bx+dx[i]][by+dy[i]] == 'O')
                    canMove = true;

                if(canMove) {

                    // choose which ball move first.
                    boolean isRedFirst = true;
                    int x, y;
                    x = rx+dx[i];
                    y = ry+dy[i];
                    while(board[x][y] != '#') {
                        if(board[x][y] == 'B')
                            isRedFirst = false;
                        x += dx[i];
                        y += dy[i];
                    }

                    int nrx, nry;
                    int nbx, nby;

                    if(isRedFirst) {

                        // red
                        nrx = rx+dx[i];
                        nry = ry+dy[i];
                        while(board[nrx][nry] != '#') {
                            if(board[nrx][nry] == 'O') {
                                MIN = Math.min(MIN, depth);
                                return;
                            }
                            nrx += dx[i];
                            nry += dy[i];
                        }
                        nrx -= dx[i];
                        nry -= dy[i];

                        // case: #, ., R, B, O. if stepping into R, B, just go.
                        // blue
                        nbx = bx+dx[i];
                        nby = by+dy[i];
                        boolean canGo = true;
                        while(board[nbx][nby] != '#' && !(nbx == nrx && nby == nry)) {
                            if(board[nbx][nby] == 'O') {
                                canGo = false;
                                break;
                            }
                            nbx += dx[i];
                            nby += dy[i];
                        }
                        if(!canGo)
                            continue;
                        nbx -= dx[i];
                        nby -= dy[i];
                    }
                    else {

                        // blue
                        nbx = bx+dx[i];
                        nby = by+dy[i];
                        boolean canGo = true;
                        while(board[nbx][nby] != '#') {
                            if(board[nbx][nby] == 'O') {
                                canGo = false;
                                break;
                            }
                            nbx += dx[i];
                            nby += dy[i];
                        }
                        if(!canGo)
                            continue;
                        nbx -= dx[i];
                        nby -= dy[i];

                        // red
                        nrx = rx+dx[i];
                        nry = ry+dy[i];
                        while(board[nrx][nry] != '#' && !(nrx == nbx && nry == nby)) {
                            if(board[nrx][nry] == 'O') {
                                MIN = Math.min(MIN, depth);
                                return;
                            }
                            nrx += dx[i];
                            nry += dy[i];
                        }
                        nrx -= dx[i];
                        nry -= dy[i];
                    }

                    board[rx][ry] = '.';
                    board[nrx][nry] = 'R';
                    board[bx][by] = '.';
                    board[nbx][nby] = 'B';

                    combination.add(i);

                    solve(depth+1, nrx, nry, nbx, nby, combination);

                    // back-tracking.
                    board[nrx][nry] = '.';
                    board[rx][ry] = 'R';
                    board[nbx][nby] = '.';
                    board[bx][by] = 'B';

                    combination.pop();
                }
            }
        }
    }

    public static void main(String[] args) throws FileNotFoundException {

//        final String INPUT_FILE = "data/boj/13460_input.txt";
//        FastReader in = new FastReader(INPUT_FILE);

        FastReader in = new FastReader(args);

//        int test = in.nextInt();
        int test = 1;
        int t = 0;
        while(t++< test) {

            int N = in.nextInt();
            int M = in.nextInt();

            char[][] board = new char[N][M];
            for(int i=0; i<N; i++) {
                char[] str = in.next().toCharArray();
                for(int j=0; j<M; j++)
                    board[i][j] = str[j];
            }

            Game game = new Game(N, M, board);
            System.out.println(game.solve());
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
