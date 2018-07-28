#include <iostream>
#include <vector>
#include <list>
#include <cstring>

using namespace std;

int tc, t;
int P, Q;
char str1[11][81];
char str2[11][81];

const char l_brackets[3] = {'(', '{', '['};
const char r_brackets[3] = {')', '}', ']'};
vector<vector<int>> equations;
int num[3];
bool solution[21][21][21];

bool DEBUG = false;

int main() {

//    FILE *fp = freopen("../data/3378.input", "r", stdin);
//    if(!fp)
//        perror("freopen error");

    scanf("%d", &tc);
    t = 0;
    while(t++ < tc) {

        scanf("%d%d", &P, &Q);
//        cout << P << ", " << Q << "\n";

        for(int i=0; i<P; i++)
            scanf("%s", str1[i]);
        for(int i=0; i<Q; i++)
            scanf("%s", str2[i]);

        // initialize.
        equations.clear();
        for(int i=0; i<3; i++)
            num[i] = 0;
        for(int x=1; x<=20; x++)
            for(int y=1; y<=20; y++)
                for(int z=1; z<=20; z++)
                    solution[x][y][z] = true;

        // get equations from first P lines.
        for(int i=0; i<P; i++) {

            int j = 0;
            if(str1[i][j]=='.')
                while(str1[i][j]=='.')
                    j++;

            vector<int> vec;
            for(int k=0; k<3; k++)
                vec.push_back(num[k]);
            vec.push_back(j);

            equations.push_back(vec);

            while(j < strlen(str1[i])) {
                for(int k=0; k<3; k++) {
                    if(str1[i][j] == l_brackets[k])
                        num[k]++;
                    else if(str1[i][j] == r_brackets[k])
                        num[k]--;
                }
                j++;
            }
        }

//        for(int i=0; i<P; i++) {
//            for(int j=0; j<4; j++)
//                cout << equations[i][j] << " ";
//            cout << "\n";
//        }

        // O(10*8000) ~= O(10^5)
        for(int i=0; i<P; i++) {

            vector<int> args = equations[i];
            int c = 0;
            for(int j=0; j<3; j++)
                if(args[j] != 0)
                    c++;

            if(c == 0)
                continue;

            for(int x=1; x<=20; x++)
                for(int y=1; y<=20; y++)
                    for(int z=1; z<=20; z++)
                        if(args[0]*x+args[1]*y+args[2]*z != args[3])
                            solution[x][y][z] = false;
        }

//        for(int x=1; x<=20; x++) {
//            for(int y=1; y<=20; y++) {
//                for(int z=1; z<=20; z++) {
//                    if(solution[x][y][z])
//                        cout << x << " " << y << " " << z << "\n";
//                }
//            }
//        }

        vector<vector<int>> solutions;

        for(int x=1; x<=20; x++)
            for(int y=1; y<=20; y++)
                for(int z=1; z<=20; z++)
                    if(solution[x][y][z])
                        solutions.push_back({x, y, z});

        printf("#%d", t);

        // iterate Q lines, and if there exists more than two indent values, print -1.
        for(int i=0; i<Q; i++) {

            int indent = 0;
            bool determined = false;

            vector<vector<int>>::iterator it;
            for(it=solutions.begin(); it!=solutions.end(); it++) {

                vector<int> s = *it;

                int temp = num[0]*s[0]+num[1]*s[1]+num[2]*s[2];
                if(determined) {
                    if(indent != temp) {
                        indent = -1;
                        break;
                    }
                }
                else { // first.
                    indent = temp;
                    determined = true;
                }
            }

            printf(" %d", indent);

            for(int j=0; j<strlen(str2[i]); j++) {
                for(int k=0; k<3; k++) {
                    if(str2[i][j] == l_brackets[k])
                        num[k]++;
                    else if(str2[i][j] == r_brackets[k])
                        num[k]--;
                }
            }
        }

        printf("\n");
    }

    return 0;
}
