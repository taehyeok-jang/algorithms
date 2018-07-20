package sw.expert.academy.d4._4408;

import java.io.*;
import java.util.StringTokenizer;

import java.util.Scanner;

import java.util.Collections;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.List;

/**
 * Samsung SW Academy (www.swexpertacademy.com)
 * problem 4408
 */

public class Solution {

    private static class Student implements Comparable<Student> {

        public int start;
        public int end;

        public Student(int start, int end) {

            this.start = start;
            this.end = end;
        }

        @Override
        public int compareTo(Student that) {

            if(this.start >= that.start)    return 1;
            else                            return -1;
        }
    }

    public static void main(String[] args) {

//        final String INPUT_FILE = "data/sw.expert.academy/4408_input.txt";
//        FastReader in = new FastReader(INPUT_FILE);
        Scanner in = new Scanner(System.in);

//        FastReader in = new FastReader(args);

        int t = in.nextInt();
        int test = 0;

        while(test++ < t) {

//            System.out.println("Test " + test);

            int N = in.nextInt();
            List<Student> students = new LinkedList<>();
            for(int i=0; i<N; i++)
                students.add(new Student(in.nextInt(), in.nextInt()));

            Collections.sort(students);

            int time = 0;
            while(students.size() != 0) {

                time++;

                int last = -1;
                Iterator<Student> it = students.iterator();
                while(it.hasNext()) {

                    Student s = it.next();
                    if(s.start > last) {

//                        System.out.println("remove " + s.start + "~" + s.end);
                        last = s.end;
                        it.remove();
                    }
                }
            }

            System.out.println("#" + test + " " + time);
        }
    }
//
//    private static class FastReader {
//
//        private BufferedReader br;
//        private StringTokenizer st;
//
//        public FastReader(String[] args) {
//            br = new BufferedReader(new InputStreamReader(System.in));
//        }
//        public FastReader(String FILE_NAME) throws FileNotFoundException {
//            br = new BufferedReader(new FileReader(FILE_NAME));
//        }
//        public String next() {
//            while(st == null || !st.hasMoreElements()) {
//                try                 { st = new StringTokenizer(br.readLine()); }
//                catch(IOException e){ e.printStackTrace(); }
//            }
//            return st.nextToken();
//        }
//        public int nextInt() {
//            return Integer.parseInt(next());
//        }
//        public double nextDouble() {
//            return Double.parseDouble((next()));
//        }
//        public String nextLine() {
//            String str = "";
//            try                 { str = br.readLine(); }
//            catch(IOException e){ e.printStackTrace(); }
//            return str;
//        }
//    }
}
