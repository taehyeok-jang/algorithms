#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

long long INF = 8765432187654321;

// time complexity: O((E+V)logV).
class Dijkstra {

private:
    int start;
    int V;
    vector<vector<pair<int, int>>> adjs; // adjs[0]: dummy, pair<v, weight>
//    int *prev;
    long long *d;

public:
    Dijkstra(int s, int v, vector<vector<pair<int, int>>> &a) {

        start = s;
        V = v;
        adjs = a;
//        prev = new int[V+1];
//        memset(prev, -1, sizeof(int)*(V+1));
        d = new long long[V+1];

        initialize();
    }

    void initialize() {
        // pair sorted by pair.first. (edge weight)
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for(int i=0; i<V+1; i++) d[i] = INF;
        bool inMST[V+1];
        memset(inMST, 0, sizeof(bool)*(V+1));

        pq.push(make_pair(0, start));
        d[start] = 0;

        while(!pq.empty()) {

            int u = pq.top().second; // O(VlogE)
            pq.pop();
            inMST[u] = true;

            for(auto edge: adjs[u]) { // O(ElogE)
                // (u, v)
                int v = edge.first;
                int weight = edge.second;
                if(!inMST[v]&&d[u]+weight<d[v]) {
                    d[v] = d[u]+weight;
                    pq.push(make_pair(d[v], v));
//                    prev[v] = u;
                }
            }
        }
//        for(int i=1; i<V+1; i++)
//            cout << i << " ~ " << prev[i] << "\n";
    }

    long long min_distance(int v) {

        return d[v];
    }
};