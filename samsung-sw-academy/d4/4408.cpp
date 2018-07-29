#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

struct Student {
    int start, end;
    bool operator<(const Student& s) const {
        return start < s.start;
    }
    Student(int s, int e) {
        start = s;
        end = e;
    }
};

int tc, t;
int N;
list<Student> students;

bool DEBUG = false;

int main() {

    FILE *fp = freopen("../data/4408.input", "r", stdin);
    if(!fp)
        perror("freopen error");

    scanf("%d", &tc);
    t = 0;
    while(t++ < tc) {

        students.clear();

        scanf("%d", &N);
        for(int i=0; i<N; i++) {
            int s, e;
            scanf("%d%d", &s, &e);
            students.push_back(Student(min(s, e), max(s, e)));
        }

        students.sort();

        int time = 0;
        while(students.size() != 0) {

            time++;

            list<Student>::iterator it;

//            cout << "time: " << time << "\n";
//            for(it=students.begin(); it!=students.end(); it++)
//                printf("%d %d\n", ((Student)(*it)).start, ((Student)(*it)).end);

            int last = -1;
            for(it=students.begin(); it!=students.end(); it++) {

                Student s = *it;
//                cout << "student " << s.start << ", " << s.end << "\n";
                if(s.start>last && !(last%2==1&&s.start==(last+1))) {

                    last = s.end;
                    students.erase(it);
                    it--;
                }
            }
        }

        printf("#%d %d\n", t, time);
    }

    return 0;
}