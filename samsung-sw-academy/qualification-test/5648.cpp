#include <iostream>
#include <queue>
#include <set>
using namespace std;
int tc, t;
int N;
struct atom {
    float x, y;
    int d, p;
    atom() {}
    atom(float _x, float _y, int _d, int _p) { x = _x, y = _y, d = _d, p = _p; }
} atoms[1001];
struct event {
    float t;
    pair<int, int> atoms;
    event(float _t, pair<int, int> _atoms) { t = _t, atoms = _atoms; }
    bool operator < (const event &e2) const { return t>e2.t; }
};
priority_queue<event> pq;
bool alive[1001];

int main() {

    ios::sync_with_stdio(false);
    cin >> tc;
    t = 0;
    while(t++ < tc) {

        while(!pq.empty()) pq.pop();
        for(int i=0; i<1001; i++) alive[i] = 1;

        cin >> N;
        float x, y; int d, p;
        for(int i=0; i<N; i++) {
            cin >> x >> y >> d >> p;
            atoms[i].x = x, atoms[i].y = y, atoms[i].d = d, atoms[i].p = p;
        }

        atom a1, a2;
        for(int i=0; i<N-1; i++) {
            for(int j=i+1; j<N; j++) {
                a1 = atoms[i], a2 = atoms[j];
                if(a1.d==a2.d) continue;

                float time = -1.0;
                if((a1.d<2&&a2.d<2)||(a1.d>=2&&a2.d>=2)) {
                    float t;
                    if(a1.d<2&&(a1.x==a2.x))  {
                        if(a1.d==0) t = (a2.y-a1.y)/2;
                        else        t = (a1.y-a2.y)/2;
                        if(t>0) time = t;
                    }
                    if(a1.d>=2&&(a1.y==a2.y)) {
                        if(a1.d==2) t = (a1.x-a2.x)/2;
                        else        t = (a2.x-a1.x)/2;
                        if(t>0) time = t;
                    }
                }
                else {
                    float t1, t2;
                    if(a1.d<2&&a2.d>=2) {
                        t1 = ((a1.d==0)? 1:-1)*(a2.y-a1.y);
                        t2 = ((a2.d==2)? 1:-1)*(a2.x-a1.x);
                        if(t1>0&&t2>0&&t1==t2) time = t1;
                    }
                    else {
                        t1 = ((a1.d==2)? 1:-1)*(a1.x-a2.x);
                        t2 = ((a2.d==0)? 1:-1)*(a1.y-a2.y);
                        if(t1>0&&t2>0&&t1==t2) time = t1;
                    }
                }
                if(time!=-1.0)
                    pq.push(event(time, make_pair(i, j)));
            }
        }

        int ans = 0;
        set<int> candidates;
        while(!pq.empty()) {

            candidates.clear();

            event ev = pq.top(); pq.pop();
            pair<int, int> a = ev.atoms;
            if(alive[a.first]&&alive[a.second])
                candidates.insert(a.first), candidates.insert(a.second);

            while(!pq.empty()&&ev.t==pq.top().t) {
                a = pq.top().atoms; pq.pop();
                if(alive[a.first]&&alive[a.second])
                    candidates.insert(a.first), candidates.insert(a.second);
            }

            for(auto it=candidates.begin(); it!=candidates.end(); it++)
                ans += atoms[*it].p, alive[*it] = 0;
        }
        cout << "#" << t << " " << ans << "\n";
    }

    return 0;
}
