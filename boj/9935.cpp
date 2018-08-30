#include <stdio.h>
#include <cstring>

using namespace std;

char input[1000001], p[40];
char s[1000001]; int idx;
int a, b, i;

#ifdef DEBUG
#endif

int main() {

    scanf("%s%s", input, p);
    a = strlen(input), b = strlen(p);

    i = idx = 0;
    while(i<a+1) {
        bool match = 0;
        if(idx-b>=0) {
            match = 1;
            for(int j=0; j<b; j++)
                if(s[idx-1-j]!=p[b-1-j]) {
                    match = 0;
                    break;
                }
        }

        if(match) idx -= b;
        else s[idx++] = input[i++];
    }

    s[idx] = 0;
    if(idx==1) printf("FRULA");
    else printf("%s", s);

    return 0;
}
