#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int tc, t;
int N, A;
int X, Y;
int MOD = 20171109; // ~2*10^7
/**
 *
 * template<
    class T,
    class Container = std::vector<T>,
    class Compare = std::less<typename Container::value_type>
> class priority_queue;
 */
priority_queue<int, vector<int>, greater<int>> minPQ;
priority_queue<int, vector<int>, less<int>> maxPQ;

bool DEBUG = false;

int main() {

    FILE *fp = freopen("../data/3000.input", "r", stdin);
    if(!fp)
        perror("freopen error");

    scanf("%d", &tc);
    t = 0;
    while(t++ < tc) {

        while(!minPQ.empty())
            minPQ.pop();
        while(!maxPQ.empty())
            maxPQ.pop();

//        cout << minPQ.size() << ", " << maxPQ.size() << "\n";

        scanf("%d%d", &N, &A);

        maxPQ.push(A);

        long long sum = 0;
        for(int i=0; i<N; i++) {

            scanf("%d%d", &X, &Y);

            if(X>maxPQ.top() && Y>maxPQ.top()) {

                minPQ.push(X);
                minPQ.push(Y);

                maxPQ.push(minPQ.top());
                minPQ.pop();
            }
            else if(X<maxPQ.top() && Y<maxPQ.top()) {

                maxPQ.push(X);
                maxPQ.push(Y);

                minPQ.push(maxPQ.top());
                maxPQ.pop();
            }
            else {

                minPQ.push(max(X, Y));
                maxPQ.push(min(X, Y));
            }

//            cout << "medium: " << maxPQ.top() << "\n";
            sum += maxPQ.top();
            sum %= MOD;
        }

        printf("#%d %lld\n", t, sum);
    }

    return 0;
}