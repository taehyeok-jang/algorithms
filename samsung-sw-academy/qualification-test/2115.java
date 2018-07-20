package sw.expert.academy.test._2115;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class Solution {

    public static int N, M, C;
    public static int[][] ARRAY;

    public static void main(String[] args) throws FileNotFoundException {

        File file = new File("data/sw.expert.academy/2115.input");
        Scanner in = new Scanner(file);

//        Scanner in = new Scanner(System.in);

        int test = in.nextInt();
        int t = 0;
        while(t++ < test) {

            N = in.nextInt();
            M = in.nextInt();
            C = in.nextInt();

            ARRAY = new int[N][N];
            for(int i=0; i<N; i++)
                for(int j=0; j<N; j++)
                    ARRAY[i][j] = in.nextInt();




        }
    }
}
