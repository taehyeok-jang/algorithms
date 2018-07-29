#include <iostream>
#include <cstring>

using namespace std;

int tc, t;
int N;

bool DEBUG = false;

struct node {
    char data;
    int left, right;
} nodes[101];

//char buffer[100];

void inorder_traverse(int num) {

    if(num) {
        inorder_traverse(nodes[num].left);
        printf("%c", nodes[num].data);
        inorder_traverse(nodes[num].right);
    }
}

int main() {

    FILE *fp = freopen("../data/1231.input", "r", stdin);
    if(!fp)
        perror("freopen error");

    tc = 10;
    t = 0;
    while(t++ < tc) {

        memset(nodes, 0, sizeof(node)*101);

        scanf("%d", &N);
        for(int i=1; i<N+1; i++) {

            int num;
            scanf("%d", &num);
            scanf(" %c", &nodes[num].data);

            if(2*i+1 <= N)
                scanf(" %d %d", &nodes[num].left, &nodes[num].right);
            else if(2*i == N)
                scanf(" %d", &nodes[num].left);

//            cout << "node: " << i << nodes[num].data << nodes[num].left << nodes[num].right << "\n";
        }

        printf("#%d ", t);
        inorder_traverse(1);
        printf("\n");
    }

    return 0;
}