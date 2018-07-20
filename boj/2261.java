package BOJ.computational.geometry._2261;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

/**
 *  Closest Pair
 *
 *  Refer: JOI(Japan Olympiad in Informatics) 2006 Preliminary Test#1 Problem#4
 *  Refer: https://www.acmicpc.net/problem/2261
 *
 *  N points are placed in the coordinate plane. Write a program which calculates
 *  a minimum distance between any two points.
 *
 */

public class Main {

    private static final int MAX = 1000*1000;
    private static final int BASE = 200;

    private static Point[] points;

    private static int closest(int start, int end) {

/*
        Approach

        1. We use divide-and-conquer method.
        2. Divide the points by their x's coordinate into two sets, and find the minimum distance of each sub-set.
        3. To efficiently 'conquer' the points, we use the geometric property of points near the split-line.
        4. Given the minimum distance from the sub-set above, we only need to check points closer than the minimum.
 */

        // the performance of algorithm varies in the size of BASE.
        // the optimized size is near 100~1000.
        if(end-start <= BASE)
            return brute_force(start, end);

        // divide points into 2 sets, and find each minimum distance of sets.
        int mid = (start+end)/2;
        int min = Math.min(closest(start, mid), closest(mid+1, end));

        // find adjacent points of points[mid] closer than the minimum distance.
        List<Point> adjs = new ArrayList<>();
        adjs.add(points[mid]);
        int index;
        index = mid;
        while(++index < points.length && points[index].x <= points[mid].x+Math.sqrt(min))
            adjs.add(points[index]);
        index = mid;
        while(--index > 0 && points[index].x >= points[mid].x-Math.sqrt(min))
            adjs.add(points[index]);

        // sort the points to make use of their geometric property.
        Collections.sort(adjs, new Y_comparator());

        // core method.
        // it seems that it takes O(^2n), but O(n).
        // the inner iteration iterates at most 7 times.
        int temp;
        for(int i=0; i<adjs.size(); i++)
            for(int j=i+1; j<adjs.size() && adjs.get(j).y-adjs.get(i).y<min; j++) {
                temp = euclidian_distance(adjs.get(i), adjs.get(j));
                if(temp < min)
                    min = temp;
            }

        return min;
    }

    private static int brute_force(int start, int end) {

        int min = MAX;
        for(int i=start; i<end; i++)
            for(int j=i+1; j<end+1; j++)
                min = Math.min(min, euclidian_distance(points[i], points[j]));

        return min;
    }

    private static int euclidian_distance(Point p1, Point p2) {

        return (p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y);
    }

    public static void main(String[] args) throws FileNotFoundException {

        FastReader in = new FastReader(args);

        int n = in.nextInt();
        points = new Point[n];
        for(int i=0; i<n; i++)
            points[i] = new Point(in.nextInt(), in.nextInt());

        // takes O(nlogn)
        Arrays.sort(points, new X_comparator());

        System.out.print(closest(0, n-1));
   }

    private static class Point {

        public int x;
        public int y;

        public Point(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    private static class X_comparator implements Comparator<Point> {
        @Override
        public int compare(Point a, Point b) {
            if(a.x >= b.x)  return 1;
            else            return -1;
        }
    }

    private static class Y_comparator implements Comparator<Point> {
        @Override
        public int compare(Point a, Point b) {
            if(a.y >= b.y)  return 1;
            else            return -1;
        }
    }


    private static class FastReader {

        private BufferedReader br;
        private StringTokenizer st;

        public FastReader(String[] args) throws FileNotFoundException {
            br = new BufferedReader(new InputStreamReader(System.in));
//            br = new BufferedReader(new FileReader(args[0]));
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
