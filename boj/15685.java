package BOJ._15685;

import java.io.*;
import java.util.*;

public class Main {

    public static int[] dx = {1, 0, -1, 0};
    public static int[] dy = {0, -1, 0, 1};

    private static class Point {

        public int x, y;

        public Point(int x, int y) {
            this.x = x;
            this.y = y;
        }

        // generate 90 degree rotated point.
        public Point(Point original, Point pivot) {

            int nx = original.x - pivot.x;
            int ny = original.y - pivot.y;

            int temp = nx;
            nx = -ny;
            ny = temp;

            nx += pivot.x;
            ny += pivot.y;

            this.x = nx;
            this.y = ny;
        }
    }

    public static void main(String[] args) throws FileNotFoundException {

//        final String INPUT_FILE = "data/boj/15685_input.txt";
//        FastReader in = new FastReader(INPUT_FILE);

        FastReader in = new FastReader(args);

//        int test = in.nextInt();
        int test = 1;
        int t = 0;
        while(t++< test) {

            int N = in.nextInt();

            int[][] array = new int[101][101];
            for(int i=0; i<101; i++)
                for(int j=0; j<101; j++)
                    array[i][j] = 0;

            for(int c=0; c<N; c++) {

                int x = in.nextInt();
                int y = in.nextInt();
                int d = in.nextInt();
                int g = in.nextInt();

                List<Point> curve = new LinkedList<>();

                curve.add(new Point(x, y));
                curve.add(new Point(x+dx[d], y+dy[d]));

                // make dragon curve.
                for(int i=0; i<g; i++) {

                    Iterator<Point> it = curve.iterator();
                    while(it.hasNext()) {
                        Point p = it.next();
                        array[p.x][p.y] = 1;
                    }

                    ListIterator<Point> curveIt = curve.listIterator(curve.size());
                    Point pivot = curveIt.previous();

                    List<Point> children = new LinkedList<>();
                    while(curveIt.hasPrevious())
                        children.add(new Point(curveIt.previous(), pivot));

                    Iterator<Point> childIt = children.iterator();
                    while(childIt.hasNext())
                        curve.add(childIt.next());
                }

                Iterator<Point> it = curve.iterator();
                while(it.hasNext()) {
                    Point p = it.next();
                    array[p.x][p.y] = 1;
                }
            }

            int square = 0;
            for(int i=0; i<100; i++)
                for(int j=0; j<100; j++)
                    if((array[i][j] == 1) && (array[i][j+1] == 1) && (array[i+1][j] == 1) && (array[i+1][j+1] == 1))
                        square++;

            System.out.println(square);
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
