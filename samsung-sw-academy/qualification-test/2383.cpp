#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int tc, t, n, m;
int map[11][11];
int abs(int n) { return n>0? n:-n; }
int max(int a, int b) { return a>b? a:b; }
int min(int a, int b) { return a<b? a:b; }
struct p {
    int x, y;
};
vector<p> persons;
struct s {
    int x, y, t;
    bool operator < (const s &s2) const { return abs(x)+abs(y)<abs(s2.x)+abs(s2.y); }
};
vector<s> stairs;

int aux[5001];

int main() {

    cin >> tc;
    t = 0;
    while(t++ < tc) {

        persons.clear();
        stairs.clear();
        m = 0;

        cin >> n;
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                cin >> map[i][j];
                if(map[i][j]==1) persons.push_back(p{i, j}), m++;
                else if(map[i][j]>1) stairs.push_back(s{i, j, map[i][j]});
            }
        }

        int ans = 500001;

        vector<s> a, b;
        for(int perm=0; perm<(1<<m); perm++) {
            a.clear(); b.clear();
            for(int i=0; i<m; i++) {
                if(((1<<i)&perm)==0) a.push_back(s{stairs[0].x-persons[i].x, stairs[0].y-persons[i].y, stairs[0].t});
                else                 b.push_back(s{stairs[1].x-persons[i].x, stairs[1].y-persons[i].y, stairs[1].t});
            }

            int time = 0;
            sort(a.begin(), a.end());
            sort(b.begin(), b.end());

            for(int i=0; i<5001; i++)
                aux[i] = 0;
            for(int i=0; i<a.size(); i++) {
                int j = abs(a[i].x)+abs(a[i].y)+1;
                while(a[i].t>0) {
                    if(aux[j]<3)
                        aux[j]++, a[i].t--;
                    j++;
                }
                time = max(time, j);
            }

            for(int i=0; i<5001; i++)
                aux[i] = 0;
            for(int i=0; i<b.size(); i++) {
                int j = abs(b[i].x)+abs(b[i].y)+1;
                while(b[i].t>0) {
                    if(aux[j]<3)
                        aux[j]++, b[i].t--;
                    j++;
                }
                time = max(time, j);
            }

            ans = min(ans, time);
        }

        cout << "#" << t << " " << ans << "\n";
    }

    return 0;
}
