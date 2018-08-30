#include <iostream>

using namespace std;

int N, MAX;
int score[101];
bool used[101];
bool sum[10001];

int main() {

    int tc;
    cin >> tc;

    int t = 0;
    while(t++ < tc) {

        for(int i=0; i<101; i++) {
            score[i] = 0;
            used[i] = false;
        }

        for(int i=0; i<10001; i++) {
            sum[i] = false;
        }

        cin >> N;
        MAX = 0;

        for(int i=0; i<N; i++) {
            cin >> score[i];
            MAX += score[i];
        }

        sum[0] = true;
        for(int i=0; i<N; i++)
            for(int j=MAX; j>=0; j--)
                if(sum[j])
                    sum[j+score[i]] = true;

        int count = 0;
        for(int i=0; i<10001; i++)
            if(sum[i])
                count++;

        cout << "#" << t << " " << count << "\n";
    }

    return 0;
}