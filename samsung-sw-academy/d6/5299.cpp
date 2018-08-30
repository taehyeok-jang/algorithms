#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

int tc, t;
int P, Q;

//#define DEBUG 1
#ifdef DEBUG
#endif

int f(int n) {

    // TODO


}

void convert(int n, int b) {

    vector<int> vec;
    while(n>0) {
        vec.push_back(n%b);
        n /= b;
    }
    bool equal = 1;
    for(int i=0; i<vec.size()-1; i++)
        if(vec[i]!=vec[i+1]) {
            equal = 0; break;
        }

    if(equal) {
        cout << b << "\' ";
        for(int i=0; i<vec.size(); i++)
            cout << vec[vec.size()-i-1] << " ";
        printf("\n");
    }
}

int main() {

//    FILE *fp = freopen("../data/3501.input", "r", stdin);
//    if(!fp)
//        perror("freopen error");



    for(int i=1; i<2; i++) {
        cout << "n: " << i << "\n";
        for(int b=2; b<=9998; b++) {
//            cout << b << "\' ";
            convert(9998, b);
//            for(int k=0; k<v.size(); k++)
//                cout << v[k];
//            cout << "\n";
        }
    }


//    scanf("%d", &tc);
//    t = 0;
//    while(t++ < tc) {
//
//
//
////        printf("#%d %d\n", t, a);
//    }

    return 0;
}
