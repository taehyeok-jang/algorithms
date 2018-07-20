package BOJ._15686;

import java.io.*;
import java.util.*;

public class Main {

    private static class Distance {

        private int M;
        private List<Coord> houses, chickens;

        private int MIN;

        public Distance(int M, List<Coord> houses, List<Coord> chickens) {

            this.M = M;
            this.houses = houses;
            this.chickens = chickens;

            this.MIN = 654321;
        }

        public int solve() {

            Stack<Integer> combination = new Stack<>();
            min(0, M, combination);

            return MIN;
        }

        public void min(int index, int remain, Stack<Integer> combination) {

            if(remain == 0) {

                // for each house, find chicken distance.
                int sum = 0;
                Iterator<Coord> houseIterator = houses.iterator();
                while(houseIterator.hasNext()) {

                    Coord house = houseIterator.next();
//                    System.out.println("house at " + house.x + "," + house.y);
                    int min = 654321;

                    Iterator<Integer> combinationIterator = combination.iterator();
                    while(combinationIterator.hasNext()) {
                        int c = combinationIterator.next();
                        min = Math.min(min, manhattan_distance(house, chickens.get(c)));
                    }
//                    System.out.println("min distance " + min);

                    sum += min;
                }

                MIN = Math.min(MIN, sum);
                return;
            }

            // select.
            combination.add(index);
            min(index+1, remain-1, combination);
            combination.pop();

            // not select.
            if(chickens.size()-index > remain)
                min(index+1, remain, combination);
        }
    }

    private static class Coord {

        private int x, y;

        public Coord(int x, int y) {

            this.x = x;
            this.y = y;
        }
    }

    private static int manhattan_distance(Coord c1, Coord c2) {

        return Math.abs(c2.x-c1.x)+Math.abs(c2.y-c1.y);
    }

    public static void main(String[] args) throws FileNotFoundException {

//        final String INPUT_FILE = "data/boj/15686_input.txt";
//        FastReader in = new FastReader(INPUT_FILE);

      FastReader in = new FastReader(args);

        int test = 1;
        int t = 0;
        while(t++< test) {

            int N = in.nextInt();
            int M = in.nextInt();

            List<Coord> houses = new ArrayList<>();
            List<Coord> chickens = new ArrayList<>();
            for(int i=0; i<N; i++) {
                for(int j=0; j<N; j++) {
                    int idx = in.nextInt();
                    if(idx == 1)       houses.add(new Coord(i, j));
                    else if(idx == 2)  chickens.add(new Coord(i, j));
                }
            }

            Distance d = new Distance(M, houses, chickens);
            System.out.println(d.solve());
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
