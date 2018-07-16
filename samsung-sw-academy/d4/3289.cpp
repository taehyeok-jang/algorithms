#include <iostream>


using namespace std;

int tc, t;
int n, m;

// weighted-quickunion UF
//struct UnionFind {
//    int count;
//    int* parent;
//    int* size;
//} UF;

struct UnionFind {
    int count;
    int parent[1000001];
    int size[1000001];
} UF;


int find(int p) {
    int root = p;
    while (root != UF.parent[root])
        root = UF.parent[root];
    while (p != root) {
        int newp = UF.parent[p];
        UF.parent[p] = root;
        p = newp;
    }
    return root;
}

void _union(int p, int q) {
    int rootP = find(p);
    int rootQ = find(q);
    if(rootP == rootQ)
        return;
    // make smaller root point to larger one
    if (UF.size[rootP] < UF.size[rootQ]) {
        UF.parent[rootP] = rootQ;
        UF.size[rootQ] += UF.size[rootP];
    }
    else {
        UF.parent[rootQ] = rootP;
        UF.size[rootP] += UF.size[rootQ];
    }
    UF.count--;
}

bool connected(int p, int q) {
    return find(p) == find(q);
}

int main() {

    FILE *fp = freopen("../data/3289.input", "r", stdin);
    if(!fp)
        perror("freopen error");

    cin >> tc;
    t = 0;
    while(t++ < tc) {

        scanf("%d%d", &n, &m);

        UF.count = n;
//        UF.parent = new int[n];
        for(int i=0; i<n; i++)
            UF.parent[i] = i;
//        UF.size = new int[n];
        for(int i=0; i<n; i++)
            UF.size[i] = 1;

        cout << "#" << t << " ";

        int command;
        int a, b;
        for(int i=0; i<m; i++) {

            scanf("%d", &command);
            scanf("%d%d", &a, &b);
            if(command == 0) {
                if(a == b)
                    continue;
                _union(a-1, b-1);
            }
            else {
                if(a == b)
                    printf("1");
                else {
                    if(connected(a-1, b-1))
                        printf("1");
                    else
                        printf("0");
                }
            }
        }

        cout << "\n";
    }

    return 0;
}