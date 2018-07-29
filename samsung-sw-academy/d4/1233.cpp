#include <iostream>
#include <cstring>

using namespace std;

int tc, t;
int N;

bool DEBUG = false;

struct node {
    char data[10];
    int left, right;
} nodes[201];

int VALID;

bool is_operator(char c) {

    return c=='+'||c=='-'||c=='*'||c=='/';
}

bool validate(int num) {

    if(num == 0)
        return true;
    else if(nodes[num].left==0 || nodes[num].right==0) {
        if(is_operator(nodes[num].data[0]))
            return false;
        else
            return true;
    }
    else {
        if(is_operator(nodes[num].data[0]))
            return validate(nodes[num].left) && validate(nodes[num].right);
        else
            return false;
    }
}

int main() {

//    FILE *fp = freopen("../data/1233.input", "r", stdin);
//    if(!fp)
//        perror("freopen error");

    tc = 10;
    t = 0;
    while(t++ < tc) {

        memset(nodes, 0, sizeof(node)*201);

        scanf("%d", &N);
        for(int i=1; i<N+1; i++) {

            int num;
            scanf("%d", &num);
            scanf(" %s", nodes[num].data);

            if(2*i+1 <= N)
                scanf(" %d %d", &nodes[num].left, &nodes[num].right);
            else if(2*i == N)
                scanf(" %d", &nodes[num].left);

//            cout << "node: " << i << nodes[num].data << nodes[num].left << nodes[num].right << "\n";
        }

        VALID = validate(1);

        printf("#%d %d\n", t, VALID);
    }

    return 0;
}