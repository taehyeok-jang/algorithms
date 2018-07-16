
#include <iostream>
#include <vector>

using namespace std;

#define MAX 1000001

int tc, t;
int P, Q;
int quote, mod;
int size;

int divs[MAX];
vector<int> quotes;

int main() {

    FILE *fp = freopen("../data/3501.input", "r", stdin);
    if(!fp)
        perror("freopen error");

    cin >> tc;
    t = 0;
    while(t++ < tc) {

        cin >> P >> Q;
//        cout << "@@@@@@@ " << P << ", " << Q << "\n";

        for(int i=0; i<MAX; i++)
            divs[i] = 0;
        quotes.clear();

        size = 0;

        cout << "#" << t << " ";

        int p = P;
        int q = Q;
        bool pointed = false;
        for(int i=0; i<Q+1; i++) {

            if(p<q && !pointed) {
                if(i == 0)
                    cout << "0";
                cout << ".";
                pointed = true;
            }

            if(p<q)
                p *= 10;

            // divs[p] is non-zero? (has divided by 'p' before?)
            if(divs[p]) {

                int start = divs[p]-1;
                int end = size;

                // print non-circular part.
                for(int i=0; i<start; i++)
                    cout << quotes.at(i);
                cout << "(";
                // print circular part.
                for(int i=start; i<end; i++)
                    cout << quotes.at(i);
                cout << ")";

                break;
            }

            quote = p/q;
            mod = p%q;

            if(!pointed)
                cout << quote;
            else {
                divs[p] = ++size;
                quotes.push_back(quote);
            }

            p = mod;

            if(p == 0) {
                for(int i=0; i<quotes.size(); i++)
                    cout << quotes.at(i);
                break;
            }
        }

        cout << "\n";
    }

    return 0;
}
