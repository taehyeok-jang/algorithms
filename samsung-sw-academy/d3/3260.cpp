#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <stack>

using namespace std;

int tc, t;
int i, j;
stack<int> s;

bool DEBUG = false;

int main() {

//    FILE *fp = freopen("../data/3501.input", "r", stdin);
//    if(!fp)
//        perror("freopen error");

    scanf("%d", &tc);
    t = 0;
    while(t++ < tc) {

        char A[101], B[101];
        scanf("%s%s", A, B);
        i = strlen(A)-1, j = strlen(B)-1;
        int a, b;
        int carry = 0;
        while(i>=0||j>=0) {
//            cout << i << " ... " << j << "\n";
            a = (i>=0)? (A[i]-48):0;
            b = (j>=0)? (B[j]-48):0;
//            cout << a << ", " << b << "\n";
            s.push((a+b+carry)%10);
            carry = (a+b+carry)/10;
            i--, j--;
            if(i<0&&j<0&&carry==1) s.push(1);
        }
        printf("#%d ", t);
        while(!s.empty()) printf("%d", s.top()), s.pop();
        printf("\n");

//        printf("#%d %d\n", t, a);
    }

    return 0;
}
