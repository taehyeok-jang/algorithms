#include <stdio.h>
#include <sstream>
/**
 * I/O
 * 1) scanf, printf (standard input/output)
 *  in scanf ' ', or '\n' as default specifier.
 *
 * 2) sscanf, sprintf (input/output from string)
 *  read cstring where we should set specifier. s
 *
 *  3) stringstream
 *
 */

/**
 * ref.
 * http://www.cplusplus.com/reference/cstdio/sscanf/?kw=sscanf
 * https://eastroot1590.tistory.com/entry/CC-sscanf-sscanfs
 * https://m.blog.naver.com/PostView.nhn?blogId=kks227&logNo=220245263973&proxyReferer=https%3A%2F%2Fwww.google.com%2F
 */
int main() {

    /*
     * ex 1. c++ string to cstring by .c_str().
     */
    char a[20], b[20], c[20];
    vector<string> input = {"Enter uid1234 Muzi", "Enter uid4567 Prodo", "Leave uid1234", "Enter uid1234 Prodo", "Change uid4567 Ryan"};
    sscanf(input[0].c_str(), "%s %s %s", a, b, c);

    /*
     * ex 2. *: read and ignore.
     */
    char sentence []="Rudolph is 12 years old";
    char str [20];
    int i;
    sscanf(sentence, "%s %*s %d", str, &i);

    /*
     * ex 3. [@] read string that contains @.
     */
    char message[126] = "iamaBoy man";
    char little[10];
    sscanf(message, "%[a-z]", little);
    // little = "iama"

    /*
     * ex 4. in case of Visual Studio's compiler, we should specify the size of arg.
     */
    char message[128] = "iamaBoy";
    char little[10];
    sscanf_s(message, "%[a-z]", little, sizeof(little));
    // sscanf_s(message, "%[a-z]", little, 10);

    /*
     * ex 5. sprintf
     */
    char output[50];
    sprintf(output,"%s is coming to my house.\n", cstring);

    /*
     * ex 6. stringstream
     * stream: abstraction of io.
     */
    string line;
    getline(cin, line);  // drop a newline trailing n
    cout << n << "\n";
//    while (n-- > 0) {
    while (getline(cin, line)) {
//        getline(cin, line);  // drop a newline trailing n
        stringstream ss(line);
        for (int val; !(ss>>val).fail();) {  // stringstream input into val.
            cout << val << " ";
        }
    }
    /**
     * ex input.
    8
    1 2 4 7
    3 4 7 9
    5 8 9
    6 8
    10 12 14
    11 12 14 17
    15 17
    13 16 17
    */
}