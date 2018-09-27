#include <stdio.h>
#define ll long long
using namespace std;
int tc, t;
ll N;
ll power[30], cache[100];

ll pow(ll num, int exp) {
    if(power[exp]!=0) return power[exp];
    ll p = 1;
    for(int i=0; i<exp; i++) p *= num;
    return power[exp] = p;
}

/**
 * @@ optimization.
 * divide&conquer -> O(N) if all l==r are called.
    1. in 5 iterations of 5^(n-1), it occurs that c1, c2, c1, c2, c1(or c3).
      we just can call T(n) = max(3*T(1/5*N)+2*T(1/5*N)), in log2(N) time.
    2. more efficient way is,
      we can get num of bits in case of full ranges. just using range and bit.
    3. marginal case is also calculated in log5(N) time.
 */
ll solve(ll left, ll right, int exp, bool flip) {

    ll range = pow(5, exp);
    if(right-left+1==5*range&&cache[exp]) {
        if(flip==0) return cache[exp];
        else        return (right-left+1)-cache[exp];
    }

    if(left==right) return !flip;
    if(exp==0) return (right-left+1)*!flip;

    ll l, r;
    ll ans = 0, c[2] = {0, 0};
    bool f = flip;
    for(int i=0; i<5; i++) {
        l = left+(i)*range;
        r = left+(i+1)*range-1;
        if(r>right) {
            ans += solve(l, right, exp-1, f);
            break;
        }
        if(i==0) c[0] = solve(l, r, exp-1, f);
        if(i==1) c[1] = solve(l, r, exp-1, f);
        ans += c[i%2];
        f = exp%2? !f:f;
    }

    if(right-left+1==5*range) cache[exp] = ans;
    return ans;
};

int main() {

//    FILE *fp = freopen("../data/battle.input", "r", stdin);
//    if(!fp)
//        perror("freopen error");

    scanf("%d", &tc);
    t = 0;
    while(t++ < tc) {

        scanf("%lld", &N);
        ll range = 1; int exp = 0;
        while(5*range<=N) range *= 5, exp++;
        printf("#%d %lld\n", t, solve(0, N, exp, 0));
    }

    return 0;
}

/*
 *

ll solve(ll left, ll right, int exp, bool flip) {

//    printf("%lld~%lld, %d %d\n", left, right, exp, flip);

    if(left==right) {
//        cout << "return " << (!flip) << "\n";
        return !flip;
    }
    if(exp==0) {
//        cout << "return " << ((right - left + 1) * !flip) << "\n";
        return (right - left + 1) * !flip;
    }

    // TODO l==r 인 지점을 다 건드리면 O(N)인 거니까 불가능. ㅜ
    // T(n) = max(3*T(1/5*N)+2*T(1/5*N))이라서, log2(N)만에 해결 가능하다.
    // marginal case 도 segment tree 처럼 한쪽은 수렴하기에 log5(N) 안에 해결 가능하다.

ll range = power(5, exp);
//    cout << "range: " << range << "\n";
ll l, r;
ll c1 = 0, c2 = 0, c3 = 0;
bool f = flip;
for(int i=0; i<5; i++) {

l = left+(i)*range;
r = left+(i+1)*range-1;

//        printf("l: %lld, r: %lld\n", l, r);

if(r>right) {
//            cout << "out of range\n";
c3 = solve(l, right, exp-1, f);
break;
}

if(i%2==0) c1 += (c1==0)? solve(l, r, exp-1, f):c1;
else       c2 += (c2==0)? solve(l, r, exp-1, f):c2;

f = exp%2? !f:f;
}

return c1+c2+c3;
};
 */



//ll facto(ll l, ll r, int k) {
//
//
//    if(i==0) return dp[0] = 1;
//    if(dp[i]>0) return dp[i];
//    return (i*facto(i-1))%100000000000000;
//}
/**

ll pow(ll num, int exp) {
    if(power[exp]!=0) return power[exp];
    ll p = num;
    for(int i=0; i<exp-1; i++) p *= num;
    return power[exp] = p;
}

ll solve(ll left, ll right, int exp, bool flip) {

    pair<ll, ll> key = make_pair(left, right);
    if(dict.count(key)) {
//        printf("caching %lld~%lld \n", left, right);
        return dict[key];
    }

#ifdef DEBUG
    printf("\n%lld~%lld, %d %d\n", left, right, exp, flip);
#endif
    if(left==right) return !flip;
    if(exp==0) return (right-left+1)*!flip;

    ll range = pow(5, exp);
#ifdef DEBUG
    cout << "range: " << range << "\n";
#endif
    ll l, r;
    ll ans = 0, c1 = 0, c2 = 0;
    bool f = flip;
    for(int i=0; i<5; i++) {

        l = left+(i)*range;
        r = left+(i+1)*range-1;

#ifdef DEBUG
        printf("i: %d, l: %lld, r: %lld\n", i, l, r);
#endif
        if(r>right) {
#ifdef DEBUG
            cout << "out of range\n";
#endif
            ans += solve(l, right, exp-1, f);
            break;
        }

        if(i==0) { c1 = solve(l, r, exp-1, f); ans += c1; }
        if(i==1) { c2 = solve(l, r, exp-1, f); ans += c2; }
        if(i==2) { ans += c1; }
        if(i==3) { ans += c2; }
        if(i==4) { ans += c1; }

        f = exp%2? !f:f;
    }

    if(exp>1) dict[key] = ans;
    return ans;
};
*/