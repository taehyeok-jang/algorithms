#include<cstdio>
using namespace std;
int main() {

    int N, L;
    scanf("%d", &N);
    for(int i=0; i<N; i++) {
        scanf("%d", &L);
        for(int j=0; j<L; j++) printf("=");
        printf("\n");
    }
    return 0;
}
