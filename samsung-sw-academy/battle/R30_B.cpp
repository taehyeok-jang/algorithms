#pragma once
#include <cstdio>
#include <cstring>
#define MAX 100001
int col[3][MAX];
int check[3][MAX]; bool enque[MAX];
int idx[MAX], temp[MAX];
int que[MAX], f, r;

/**
 * This code is refered from 'http://sangdo913.tistory.com/entry/SW-Expert-Academy-Code-Battle-2'
 * for studying.
 */

void sort(int left, int right) {

    if(left>=right) return;

    int m = (left+right)/2;
    sort(left, m);
    sort(m+1, right);

    int l = left, r = m+1, k = l;
    while(l<=m&&r<=right)
        temp[k++] = (col[0][idx[l]]<col[0][idx[r]])? idx[l++]:idx[r++];
    while(l<=m) temp[k++] = idx[l++];
    while(r<=right) temp[k++] = idx[r++];

    for(int i=left; i<=right; i++)
        idx[i] = temp[i];
}

int main() {

//    FILE *fp = freopen("../data/battle.input", "r", stdin);
//    if(!fp)
//        perror("freopen error");

    int t;
    scanf("%d", &t);

    for(int tc=1; tc<t+1; tc++) {

        int n;
        scanf("%d", &n);
        memset(check, 0, sizeof(check));
        memset(enque, 0, sizeof(enque));
        for(int i=1; i<n+1; i++) idx[i] = i;
        for(int i=0; i<3; i++) {
            for(int j=1; j<n+1; j++) {
                scanf("%d", &col[i][j]);
                // check[i][v]
                // the number of v on i'th row.
                check[i][col[i][j]]++;
            }
        }

        f = r = 0;
        sort(1, n);

        for(int i=0; i<3; i++)
            for(int j=1; j<n+1; j++) {
                if(check[i][j]==0) {
                    if(enque[j]) continue;
                    enque[j] = 1;
                    que[r++] = j;
                    check[0][j]--;
                }
            }

        while(f!=r) {

            int pos = idx[que[f++]];
//            printf("%d -> %d %d %d\n", pos, col[0][pos], col[1][pos], col[2][pos]);
            int val;

            val = col[1][pos];
            check[1][val]--;
            if(check[1][val]==0&&enque[val]==0) {
                enque[val] = 1;
                que[r++] = val;
                check[0][val]--;
            }
            val = col[2][pos];
            check[2][val]--;
            if(check[2][val]==0&&enque[val]==0) {
                enque[val] = 1;
                que[r++] = val;
                check[0][val]--;
            }
        }

        int ans = 0;
        for(int i=1; i<n+1; i++) ans += enque[i];
        printf("#%d %d\n", tc, ans);
    }


}


