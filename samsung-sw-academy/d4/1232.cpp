#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

int tc, t;
int N;

bool DEBUG = false;

struct node {
    float value;
    char op;
    int left, right;
} nodes[1001];

//char buffer[100];

float calculate(int num) {

    if(nodes[num].op == 0)
        return nodes[num].value;

    float a = calculate(nodes[num].left);
    float b = calculate(nodes[num].right);

    switch(nodes[num].op) {
        case '+':   return a+b;
        case '-':   return a-b;
        case '*':   return a*b;
        case '/':   return a/b;
    }
}

int main() {

//    FILE *fp = freopen("../data/1232.input", "r", stdin);
//    if(!fp)
//        perror("freopen error");

    tc = 10;
    t = 0;
    while(t++ < tc) {

        memset(nodes, 0, sizeof(node)*1001);

        scanf("%d", &N);
//        cout << "N: " << N << "\n";
        for(int i=1; i<N+1; i++) {

            int num;
            char buffer[100];
            string s;

            scanf("%d", &num);
            scanf(" %s", buffer);

            char c = buffer[0];
            if(c=='+'||c=='-'||c=='*'||c=='/') {
                nodes[num].op = c;
                scanf(" %d %d", &nodes[num].left, &nodes[num].right);
            }
            else {
                int value = 0;
                for(int i=0; i<strlen(buffer); i++)
                    value += pow(10, strlen(buffer)-i-1)*(buffer[i]-48);
                nodes[num].value = value;
            }

//            cout << "node: " << i << nodes[num].value << nodes[num].op << nodes[num].left << nodes[num].right << "\n";
        }

        printf("#%d %d\n", t, (int)calculate(1));
    }

    return 0;
}