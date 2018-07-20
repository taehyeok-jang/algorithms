package BOJ.computational.geometry._1711;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

/**
 *  Number of Rectangles
 *
 *  Refer: COCI(Croatian Open Competition in Informatics) 2007/2008 Contest#2 Problem#6
 *  Refer: https://www.acmicpc.net/problem/1711
 *
 *  N points are placed in the coordinate plane. Write a program which calculates in how many ways
 *  a right triangle can be formed by three of the given points. A right triangle is one in which
 *  one of the angles is 90 degrees.
 *
 */

public class Main {

    private static int n;
    private static int[] x, y;

    public static int num_of_rectangles() {

/*
        Brute-Force Approach

//      time overflow... O(n^3)
//      need to optimize the algorithm below O(n^3)
        int rect = 0;
        for(int i=0; i<n-2; i++)
            for(int j=i+1; j<n-1; j++)
                for(int k=j+1; k<n; k++) {
                    // calculate dot products to find if two vectors consisting of given three points form a right angle.
                    if(Double.compare(Math.abs((x[i]-x[j])*(x[j]-x[k])+(y[i]-y[j])*(y[j]-y[k])), 0) == 0 ||
                       Double.compare(Math.abs((x[j]-x[k])*(x[k]-x[i])+(y[j]-y[k])*(y[k]-y[i])), 0) == 0 ||
                       Double.compare(Math.abs((x[k]-x[i])*(x[i]-x[j])+(y[k]-y[i])*(y[i]-y[j])), 0) == 0)
                        rect++;
                }

        System.out.print(rect);
        */

/*
        Approach

        1. For each point, transform the coordinate plane so that the point is the origin.
        2. Rotate the rest of points into the first quadrant.
        3. To count how many points form the right angle with each other, store these into hash-map.
        4. For each set of points with the same angle, add up how many of them are across the neighbouring quadrants.
 */

        int result = 0;

        for(int i=0; i<n; i++) {

            Point origin = new Point(x[i], y[i]);

            // copy points on each iteration.
            // more efficient than transform & transform back the points.
            Point[] points = new Point[n];
            for(int j=0; j<n; j++)
                points[j] = new Point(x[j], y[j]);

            // transform the coordinate plane so that point[i] is the origin.
            for(int j=0; j<n; j++) {

                points[j].x -= origin.x;
                points[j].y -= origin.y;

                if(i == j)
                    continue;
                // rotate each point into the first quadrant.
                while(!(points[j].x > 0 && points[j].y >= 0))
                    points[j].rotate_by_90();
            }

            // for each set of points with the same angle, count how many of them
            // are in each of the four quadrants into hash-map.
            Map<Double, Integer[]> map = new HashMap<>();
            for(int j=0; j<n; j++) {

                double angle = Math.abs(points[j].y/points[j].x);

                if(map.get(angle) == null) {

                    Integer[] list = new Integer[4];
                    for(int k=0; k<4; k++)
                        list[k] = 0;

                    map.put(angle, list);
                }

                Integer[] update = map.get(angle);
                update[points[j].rotate]++;
            }

            // multiply the number of points on the same angles for neighbouring quadrants.
            Iterator<Map.Entry<Double, Integer[]>> iterator = map.entrySet().iterator();
            while(iterator.hasNext()) {
                Integer[] quads = iterator.next().getValue();
                for(int q=0; q<4; q++)
                    result += quads[(q)%4]*quads[(q+1)%4];
            }
        }

        return result;
    }

    public static void main(String[] args) throws FileNotFoundException {

        FastReader in = new FastReader(args);

        n = in.nextInt();
        x = new int[n];
        y = new int[n];
        for(int i=0; i<n; i++) {
            x[i] = in.nextInt();
            y[i] = in.nextInt();
        }

        System.out.print(num_of_rectangles());
    }

    private static class Point implements Comparable<Point> {

        public double x;
        public double y;
        public int rotate;

        public Point(double x, double y) {
            this.x = x;
            this.y = y;
            this.rotate = 0;
        }

        public void rotate_by_90() {
            double tmp = this.x;
            this.x = -this.y;
            this.y = tmp;
            this.rotate = (this.rotate+1)%4;
        }

        @Override
        public int compareTo(Point that) {
            // compare by angle
            if(this.x == 0 && that.x == 0)  return 0;
            else if(this.x == 0)            return 1;
            else if(that.x == 0)            return -1;
            else                            return Double.compare(this.y/this.x, that.y/that.x);

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




