#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int tc, t;
int N;
char str[200];

vector<char> vec, op_stack;
vector<int> cal;

bool DEBUG = false;

bool isNum(char c) {

    return c>=48 && c<58;
}

int getWeight(char c) {

    if(c == '*' || c == '/')
        return 9;
    else if(c == '+' || c == '-')
        return 7;
    else if(c == '(')
        return 5;
    else
        return 1;
}

double calc(int a, int b, char op) {
    if(op == '+')       return a+b;
    else if(op == '-')  return a-b;
    else if(op == '*')  return a*b;
    else                return a/b;
}

int main() {

//    FILE *fp = freopen("../data/1222.input", "r", stdin);
//    if(!fp)
//        perror("freopen error");

    tc = 10;
    t = 0;
    while(t++ < tc) {

        scanf("%d%s", &N, str);

        vec.clear();
        op_stack.clear();

        int i = 0;
        while(i < N) {

            if(isNum(str[i])) {
                vec.push_back(str[i]);
            }
            else {
                if(str[i] == '(' || op_stack.empty()) {
                    op_stack.push_back(str[i]);
                }
                else if(str[i] == ')') {
                    while(op_stack.back() != '(') {
                        vec.push_back(op_stack.back());
                        op_stack.pop_back();
                    }
                    op_stack.pop_back();
                }
                else { // operators
                    if(getWeight(str[i]) > getWeight(op_stack.back()))
                        op_stack.push_back(str[i]);
                    else {
                        while(!op_stack.empty() && (getWeight(str[i])<=getWeight(op_stack.back()))) {
                            vec.push_back(op_stack.back());
                            op_stack.pop_back();
                        }
                        op_stack.push_back(str[i]);

                    }
                }
            }

            i++;
        }
        while(!op_stack.empty()) {
            vec.push_back(op_stack.back());
            op_stack.pop_back();
        }

        cal.clear();
        vector<char>::iterator it;
        // calculate postfix.
        for(it=vec.begin(); it!=vec.end(); it++) {

            if(isNum(*it)) {
                cal.push_back(*it-48);
            }
            else {
                int b = cal.back();
                cal.pop_back();
                int a = cal.back();
                cal.pop_back();

                cal.push_back(calc(a, b, *it));
            }
        }

        printf("#%d %d\n", t, cal.back());
    }

    return 0;
}