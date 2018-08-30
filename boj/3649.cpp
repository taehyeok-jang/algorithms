#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;
#define MAX 1000001
int N, L;
//int A[MAX];
vector<int> vec;

#ifdef DEBUG
#endif


int main() {

    int a, b;
    while(scanf("%d", &a)==1) {

        vec.clear();

        L = a*10000000;
        scanf("%d", &N);
        for(int i=0; i<N; i++) {
            scanf("%d", &b);
            vec.push_back(b);
        }
        sort(vec.begin(), vec.end());

        int l1 = -1;
        for(int i=0; i<N; i++) {
            if(binary_search(vec.begin(), vec.end(), L-vec[i])) {
                if(vec[i]==L-vec[i])
                    if(i==N-1||vec[i+1]!=L-vec[i])
                        break;

                l1 = vec[i];
                break;
            }
        }

        if(l1==-1) printf("danger\n");
        else       printf("yes %d %d\n", l1, L-l1);

    }

    return 0;
}
