#include <iostream>
#include <cstring>

using namespace std;
#define MAX 1000001

int main() {

    int cnt = 0;
    char buf[MAX];
    scanf("%[^\n]", buf);

    if(buf[0]=='\0') { printf("%d", 0); return 0; }
    if(buf[0]==' '&&buf[1]=='\0') { printf("%d", 0); return 0; }

    bool c = 0;
    for(int i=0; i<strlen(buf); i++){
        if(i==0&&buf[i]==' ') continue;
        if(buf[i]!=' ') {
            c = 1;
            if(i==strlen(buf)-1) cnt++;
        }
        else {
            c = 0, cnt++;
        }
    }

    printf("%d", cnt);
    return 0;
}


//    while(scanf("%s", buf)!=EOF) {
//        for(int i=0; i<strlen(buf); i++)
//            if(buf[i]>=64&&buf[i]<91) buf[i] += 32;
////        cout << buf << "\n";
//        if(!dic[buf]) {
//            cnt++;
//            dic[buf] = 1;
//        }
//    }
