#include <iostream>
#include <cstring>

using namespace std;
int tc, t;
int N;
char A[10005][10];

struct node {
    node* children[10];
    bool end;
};

node* create_node(void) {
    node* p = new node();
    for(int i=0; i<10; i++)
        p->children[i] = 0;
    p->end = false;
    return p;
}
bool insert(node* root, char data[]) {
    node* p = root;
    for(int i=0; i<strlen(data); i++) {
        if(p->end) return false;
        int idx = data[i]-'0';
        if(!p->children[idx])
            p->children[idx] = create_node();
        p = p->children[idx];
    }
    p->end = true;
    for(int i=0; i<10; i++)
        if(p->children[i]!=0)
            return false;
    return true;
}
void destruct(node* root) {
    node* p = root;
    for(int i=0; i<10; i++)
        if(p->children[i])
            destruct(p->children[i]);
    delete p;
}

int main() {

    scanf("%d", &tc);
    t = 0;
    while(t++ < tc) {

        scanf("%d", &N);
        for(int i=0; i<N; i++) scanf("%s", A[i]);

        node* root = create_node();
        bool clear = 1;
        for(int i=0; i<N; i++)
            if(!insert(root, A[i]))
                clear = 0;
        puts(clear? "YES":"NO");

        destruct(root);
    }

    return 0;
}

/**
 * another implementation using hash.
 *
 */

/*
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <map>
#include <vector>

using namespace std;
#define DONE 99999
int tc, t;
int N;
char A[10005][10];
map<long long, int> dic;

//#define DEBUG 1
#ifdef DEBUG
#endif

int main() {

    scanf("%d", &tc);
    t = 0;
    while(t++ < tc) {

        dic.clear();

        scanf("%d", &N);
        bool error = 0;
        for(int i=1; i<N+1; i++) scanf("%s", A[i]);

        for(int i=1; i<N+1; i++) {

            vector<long long> vec;
            long long key = 0;
            for(int j=0; j<strlen(A[i]); j++) {
                key = key*11+(A[i][j]-47);
                vec.push_back(key);
            }

            int l = vec.size();
            for(int j=0; j<l-1; j++) {
                if(dic[vec[j]] == DONE) { error = 1; break; }
                else dic[vec[j]] = i;
            }
            if(dic[vec[l-1]]&&dic[vec[l-1]]<i) { error = 1; break;}
            else dic[vec[l-1]] = DONE;
        }

//        for(auto it=dic.begin(); it!=dic.end(); it++)
//            cout << it->first << " -> " << it->second << "\n";

        puts((error)? "NO":"YES");
    }

    return 0;
}
*/
