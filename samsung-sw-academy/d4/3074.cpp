#include <iostream>
#include <queue>
#include <vector>
#include <list>

using namespace std;

int tc, t;
int N, M;
int required[100001];
list<int> waiting;

struct Person {
    int time;
    int supervisor;
};

struct CompareTime {
    bool operator() (Person const& p1, Person const& p2) {
        return p1.time > p2.time;
    }
};

priority_queue<Person, vector<Person>, CompareTime> minPQ;

bool DEBUG = false;

int main() {

    FILE *fp = freopen("../data/3074.input", "r", stdin);
    if(!fp)
        perror("freopen error");
//
//    list<int> list1;
//    for(int i=0; i<10; i++)
//        list1.push_back(i);
//
//    list<int>::iterator it;
//    for (it = list1.begin(); it != list1.end(); it++){
//        if(*it == 4) {
//            list1.erase(it);
//            continue;
//        }
//        std::cout << *it << " ";
//    }

//    Person p1, p2, p3;
//    p1.time = 4;
//    p2.time = 7;
//    p3.time = 11;
//
//    minPQ.push(p1);
//    minPQ.push(p2);
//    minPQ.push(p3);
//
//    cout << minPQ.top().time << "\n";

    scanf("%d", &tc);
    t = 0;
    while(t++ < tc) {

        scanf("%d%d", &N, &M);
        for(int i=0; i<N; i++)
            scanf("%d", &required[i]);
        for(int i=0; i<N; i++)
            waiting.push_back(i);

        int count = 0;
        int time = 0;
        while(count < M) {

            cout << "time: " << time << "\n";

            if(time == 8)
                break;

            // TODO
            // manage finished supervisors first.
            while(minPQ.size()>0 && time==minPQ.top().time) {

                Person p = minPQ.top();
                minPQ.pop();
                count++;

                waiting.push_back(p.supervisor);
            }

            if(waiting.size() == 0)
                continue;

            cout << "waiting size: " << waiting.size() << "\n";
            list<int>::iterator it;
            for(it=waiting.begin(); it!=waiting.end(); it++) {

                if(minPQ.size()==0 || time+required[*it]<=minPQ.top().time) {
                    // TODO
                    Person p;
                    p.supervisor = *it;
                    p.time = time+required[*it];

                    cout << "insert " << p.supervisor << ", " << p.time << "\n";
                    minPQ.push(p);

                    waiting.erase(it);
                }
            }

            time++;
        }



        printf("#%d %d\n", t, time-1);
    }

    return 0;
}