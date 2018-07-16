#include<iostream>

using namespace std;

int tc, t;
int n;
string s;
long long MOD = 1000000007;

int turn[10001];
long long cache[10001][16];

// if key == 1101 -> the man who has key is A or C or D.
long long solve(int index, int key) {

    if(cache[index][key] != -1)
        return cache[index][key];

    if(index == n)
        return 1;

    long long count = 0;

    if(index == n-1) {
        for(int i=0; i<16; i++)
            if((i & key) && (i & turn[index]))
                count++;
    }
    else {
        for(int i=0; i<16; i++) {
            if((i & key) && (i & turn[index])) {
                if(i & turn[index+1])
                    count += solve(index+1, turn[index+1]) % MOD;
                else
                    count += solve(index+1, i) % MOD;
            }
        }
    }

    return cache[index][key] = (count % MOD);
}

int main() {

    cin >> tc;
    t = 0;
    while(t++ < tc) {

        cin >> s;
        n = s.length();

        for(int i=0; i<n; i++)
            turn[i] = (1<<(s[i]-65));

        for(int i=0; i<10001; i++)
            for(int j=0; j<16; j++)
                cache[i][j] = -1;

        long long count = solve(0, (1<<0));
        cout << "#" << t << " " << count << "\n";
    }

    return 0;
}