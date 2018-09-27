#include <iostream>

using namespace std;

int N, M;
int check[11];
char result[22];

void dfs(int depth) {

    if(depth==M) {
        cout << result << "\n";
        return;
    }

    for(int i=1; i<N+1; i++) {
        if(check[i]) continue;
        result[2*depth] = i+'0';
        check[i] = 1;
        dfs(depth+1);
        result[2*depth] = ' ';
        check[i] = 0;
    }
}

int main() {

    scanf("%d%d", &N, &M);
    for (int i=0; i<2*M; i++)
        result[i] = ' ';

    dfs(0);
    return 0;
}
