#include <iostream>
#include <cmath>

using namespace std;

int tc, t;

int W, H, N;

struct coord {
    double x, y;
} c[1000];

int distance(coord c1, coord c2) {

    if(c1.x == c2.x) {
        return abs(c2.y-c1.y);
    }
    else {
        if((c2.y-c1.y)/(c2.x-c1.x) > 0) {
            return max(abs(c2.x-c1.x), abs(c2.y-c1.y));
        }
        else {
            return abs(c2.y-c1.y)+abs(c2.x-c1.x);
        }
    }
}

int main() {

//    FILE *fp = freopen("../data/3349.input", "r", stdin);
//    if(!fp)
//        perror("freopen error");

    cin >> tc;
    t = 0;
    while(t++ < tc) {

        // coordinate space upside down.

        cin >> W >> H >> N;
        for(int i=0; i<N; i++)
            cin >> c[i].x >> c[i].y;

        int d = 0;
        for(int i=0; i<N-1; i++)
            d += distance(c[i], c[i+1]);

        cout << "#" << t << " " << d << "\n";
    }



    return 0;
}