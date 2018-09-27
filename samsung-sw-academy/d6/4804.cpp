/*
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;
class FW
{
public:
    int F[(int)5e5 + 2], SZ = 5e5 + 1;
    void reset() { for (int i = 0; i <= SZ; i++)F[i] = 0; }
    void in(int X, int K) { for (; X<SZ; X += X & -X)F[X] += K; }
    int out(int X) { int S = 0; for (X = min(X, SZ - 1); X; X -= X & -X)S += F[X]; return S; }
}tr;/// 구간합 트리 (BIT트리 )
int N, M;
vector<int>V;
const int KM = 101; /// 작은수는 미리 계산하는크기( 1~KM-1 까지)
ll K[KM];

//ll nogada(int L)
//{
//    ll S = 0;
//    for (auto&I : V)S += (I + L - 1) / L;
//    return S;
//}
ll play(int L)
{
    if (L<KM)return K[L];
    ll res = 0;
    int cnt = 0, cur;
    for (int X = 0, y = 0; X <= 500000 + L;)
    {
        X += L, y++;
        cur = tr.out(X);
        res += (cur - cnt)*y; /// (L*(y-1),L*y]에 속한수 갯수에 y를 곱함
        cnt = cur;
    }
    return res;
}
void sets(int BF, int CU)///CU가 바뀐 이후 값
{
    for (int i = 1; i<KM; i++)
        K[i] += (CU + i - 1) / i - (BF + i - 1) / i;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int TC; cin >> TC;
    for (int Ti = 1; Ti <= TC; Ti++)
    {
        tr.reset();
        for (int i = 0; i<KM; i++)K[i] = 0;
        ll tot = 0;
        cin >> N >> M;
        V.resize(N);
        for (auto&I : V)cin >> I, tr.in(I, 1), sets(0, I);
        for (int i = 1; i <= M; i++)
        {
            int T, O, P;
            cin >> T >> O;
            if (T == 3)tot += play(O);
            else P = V[--O], tr.in(V[O], -1), tr.in(V[O] += (T == 1 ? 1 : -1), 1), sets(P, V[O]);
        }
        printf("#%d %lld\n", Ti, tot);
    }
}
*/

/*

#include <stdio.h>
#include <cmath>

using namespace std;

#define MAX 100001
int tc, t;
int N, M;
int input[MAX], arr[5*MAX];

struct st {

    int *tree;
    int size;
    st(int n, int arr[]) {
        size = n;
        int h = (int)ceil(log2(n));
        tree = new int[1<<(h+1)];
        init(arr, 1, 0, size-1);
    };
    int init(int arr[], int now, int s, int e) {
        if(s==e) return tree[now] = arr[s];
        else return tree[now] = init(arr, 2*now, s, (s+e)/2)
                                +init(arr, 2*now+1, (s+e)/2+1, e);
    }
    int qry(int l, int r) {
        return qry(l, r, 1, 0, size-1);
    }
    int qry(int l, int r, int now, int s, int e) {
        if(r<s||l>e) return 0;
        if(l<=s&&e<=r) return tree[now];
        return qry(l, r, 2*now, s, (s+e)/2)
               +qry(l, r, 2*now+1, (s+e)/2+1, e);
    }
    void upd(int pos, int val) {
        upd(pos, val, 1, 0, size-1);
    }
    int upd(int pos, int val, int now, int s, int e) {
        if(pos<s||pos>e) return tree[now];
        if(s==e) return tree[now] += val;
        else return tree[now] = upd(pos, val, 2*now, s, (s+e)/2)
                                +upd(pos, val, 2*now+1, (s+e)/2+1, e);
    }
};

int max(int a, int b) { return a>b? a:b; }

int main() {

//    FILE *fp = freopen("../data/battle.input", "r", stdin);
//    if(!fp)
//        perror("freopen error");

    scanf("%d", &tc);
    t = 0;
    while(t++ < tc) {

        scanf("%d%d", &N, &M);
        int m = -1;
        for(int i=1; i<N+1; i++) {
            scanf("%d", &input[i]);
            arr[input[i]]++;
            m = max(m, input[i]);
        }

        for(int i=0; i<m+5; i++) arr[i] = 0;
        for(int i=1; i<N+1; i++) arr[input[i]]++;

        st seg_tree(m+5, arr);

        long long ans = 0;
        int q, v;
        for(int i=0; i<M; i++) {

            scanf("%d%d", &q, &v);

            if(q==1||q==2) {
                int j = (q==1)? 1:-1;
                arr[input[v]]--, arr[input[v]+j]++;
                seg_tree.upd(input[v], -1), seg_tree.upd(input[v]+j, 1);
                input[v] += j;
            }
            else {
                long long sum = 0;

//                int cnt = 0, c;
//                for(int i=0; i*v+v<5*MAX&&cnt<N; i++) {
//                    c = seg_tree.qry(i*v+1, i*v+v);
//                    sum += (i+1)*c;
//                    cnt += c;
//                }

                if(N<1001||v<101) {
                    for(int i=1; i<N+1; i++)
                        sum += input[i]%v? input[i]/v+1:input[i]/v;
                }
                else {
                    int cnt = 0, c;
                    for(int i=0; i*v+v<5*MAX&&cnt<N; i++) {
                        c = seg_tree.qry(i*v+1, i*v+v);
                        sum += (i+1)*c;
                        cnt += c;
                    }
                }
                ans += sum;
            }

        }

        printf("#%d %lld\n", t, ans);
    }

    return 0;
}
*/


/*
 * this code'idea is referred from kitoha's code at 2018-08-19 16:42 in swexpertacademy.com
 * for academic purpose.
 */
#include <stdio.h>
#include <cstring>

#define MAX 500005
typedef long long ll;

using namespace std;

int tc, t;
ll num[MAX], arr[MAX];

int max(int a, int b) { return a>b? a:b; }

int main() {

    scanf("%d", &tc);
    t = 0;
    while(t++ < tc) {

        int N, M;
        ll sum = 0, mx = 0;
        scanf("%d%d", &N, &M);

        memset(num, 0, sizeof(num));
        memset(arr, 0, sizeof(arr));

        for(int i=0; i<N; i++) {
            scanf("%d", &arr[i]);
            num[arr[i]]++;
            mx = max(mx, arr[i]);
            sum += arr[i];
        }
        for(int i=1; i<MAX; i++)
            num[i] += num[i - 1];

        ll ans = 0;

        for(int i=0; i<M; i++) {
            int q, v;
            scanf("%d%d", &q, &v);
            if(q==1) {
                sum++, v--;
                num[arr[v]]--;
                arr[v]++;
                mx = max(arr[v], mx);
            }
            if(q==2) {
                sum--, v--;
                arr[v]--;
                num[arr[v]]++;
            }
            if(q==3) {
                if(v==1) {
                    ans += sum;
                }
                else {
                    int j;
                    for (j = 1; j*v <mx; j++)
                        ans += (ll)(num[j*v]-num[(j-1)*v])*j;
                    ans += (ll)(num[mx] - num[(j - 1)*v])*j;
                }
            }
        }

        printf("#%d %lld\n", t, ans);

    }

    return 0;
}


