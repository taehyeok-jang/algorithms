package sw.expert.academy.d4._3459;

import java.io.*;
import java.util.Scanner;

public class Solution {

    public static long N;
    public static int WIN = 1, LOSE = -1;
    public static String Alice = "Alice", Bob = "Bob";

    public static int[] cache;

    public static int play(long x) {

        // 1: win, -1: lose.
        if(2*x > N)
            return LOSE;

        if(play(2*x)==WIN && play(2*x+1)==WIN)
            return LOSE;
        else
            return WIN;
    }

    public static void main(String[] args) throws FileNotFoundException {

//        File file = new File("data/sw.expert.academy/3459_input.txt");
//        Scanner in = new Scanner(file);

        Scanner in = new Scanner(System.in);

//        int test = 1000;
        int test = in.nextInt();
        int t = 0;

        while(t++ < test) {

            long count = 1;
            long jump = 4;

            // bound
            N = in.nextLong();

            String winner;
            if(N == 1) {
                winner = Bob;
            }
            else {
                while(true) {
                    count += jump;
                    if(count >= N) {
                        winner = Alice;
                        break;
                    }
                    count += jump;
                    if(count >= N) {
                        winner = Bob;
                        break;
                    }
                    jump *= 4;
                }

            }

            System.out.println("#" + t + " " + winner);




//            System.out.println(N);


//            String winner = (play(1)==WIN)?"Alice":"Bob";
//            System.out.println("#" + t + " " + winner);
        }
    }
}
