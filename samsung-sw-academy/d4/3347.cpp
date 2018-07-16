#include <iostream>

using namespace std;

int tc, t;

int N, M;
int A[1000], B[1000];
int vote[1000];

int main(int argc, char* argv[]) {

//    FILE *fp = freopen("../data/3347.input", "r", stdin);
//    if(!fp)
//        perror("freopen error");

    cin >> tc;
    t = 0;
    while(t++ < tc) {

        cin >> N >> M;
        for(int i=0; i<N; i++)
            cin >> A[i];
        for(int i=0; i<M; i++)
            cin >> B[i];
/*
        for(int i=0; i<N; i++)
            cout << A[i] << " ";
        cout << "\n";

        for(int i=0; i<M; i++)
            cout << B[i] << " ";
        cout << "\n";
*/

        for(int i=0; i<N; i++)
            vote[i] = 0;

        for(int i=0; i<M; i++) {
            for(int j=0; j<N; j++) {
                if(A[j] <= B[i]) {
                    vote[j]++;
                    break;
                }
            }
        }

        int choice = 0;
        int max = 0;
        for(int i=0; i<N; i++) {
            if(vote[i] > max) {
                choice = i;
                max = vote[i];
            }
        }

//        for(int i=0; i<N; i++)
//            cout << vote[i] << " ";
//        cout << "\n";

        cout << "#" << t << " " << choice+1 << "\n";
    }


    return 0;
}