#include <iostream>
#include <vector>
//#include <algorithm>

#include <cmath>
#include <cstring>

using namespace std;

int tc, t;
int P, Q;

int A[26];
char SEQUENCE[10];
vector<int> alphabet;
vector<bool> single;
//vector<int> vec;

bool DEBUG = false;

int solve(int left, vector<int> &vec) {

    if(left == 0) {

//        for(int i=0; i<vec.size(); i++)
//            cout << (char)(vec[i]+97) << " ";
//        cout << "\n";

        int count = 0;
        for(int l=1; l<=strlen(SEQUENCE); l++) {

//            cout << "l: " << l << "\n";

            for(int i=0; i<strlen(SEQUENCE); i++) {
                int a = i;
                int b = i+l-1;
//                cout << "a: " << a << ", b: " << b << "\n";

                if(b>=strlen(SEQUENCE))
                    break;

                bool is_palindrome = true;
                while(a<b) {

                    if(vec[a] != vec[b]) {
                        is_palindrome = false;
                        break;
                    }
                    a++;
                    b--;
                }
                if(is_palindrome) {
                    count++;
//                    cout << "i: " << i << ", l: " << l << "\n";
                }
            }
        }

//        cout << "count: " << count << "\n";
        return count;
    }

    int count = 0;
    int s = 0;
    for(int i=0; i<alphabet.size(); i++) {

        if(alphabet[i]) {
            alphabet[i] -= 1;
            vec.push_back(i);
            if(single[i] && s>0)
                continue;
            count = max(count, solve(left-1, vec));
            if(single[i] && s==0)
                s++;
            alphabet[i] += 1;
            vec.pop_back();
        }
    }

    return count;
}

int main() {

//    FILE *fp = freopen("../data/4672.input", "r", stdin);
//    if(!fp)
//        perror("freopen error");

    scanf("%d", &tc);
    t = 0;
    while(t++ < tc) {

        memset(A, 0, sizeof(int)*26);
        alphabet.clear();
        single.clear();

        scanf("%s", SEQUENCE);
        for(int i=0; i<strlen(SEQUENCE); i++)
            A[SEQUENCE[i]-97]++;

        for(int i=0; i<26; i++)
            if(A[i])
                alphabet.push_back(A[i]);
        for(int i=0; i<alphabet.size(); i++) {
            if(alphabet[i] == 1)    single.push_back(true);
            else                    single.push_back(false);
        }

//        for(int i=0; i<26; i++)
//            cout << A[i] << " ";
//        cout << "\n";
//        for(int i=0; i<alphabet.size(); i++)
//            cout << alphabet[i] << " ";
//        cout << "\n";
//        for(int i=0; i<single.size(); i++)
//            cout << single[i] << " ";
//        cout << "\n";

        vector<int> vec;
        printf("#%d %d\n", t, solve(strlen(SEQUENCE), vec));
    }

    return 0;
}
