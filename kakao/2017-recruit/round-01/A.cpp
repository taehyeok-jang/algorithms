#include <string>
#include <vector>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {

    for(int i=0; i<n; i++)
        arr1[i] |= arr2[i];

    vector<string> ans;
    for(int i=0; i<n; i++) {
        char buf[n];
        string str = "";
        for(int j=0; j<n; j++) {
            if(arr1[i]%2) buf[n-j-1] = '#';
            else          buf[n-j-1] = ' ';
            arr1[i] /= 2;
        }
        buf[n] = 0;
        ans.push_back(string(buf));
    }

    return ans;
}

#include <iostream>

int main() {

//    int n = 5;
//    vector<int> arr1 = vector<int>({9, 20, 28, 18, 11});
//    vector<int> arr2 = vector<int>({30, 1, 21, 17, 28});
//    int n = 6;
//    vector<int> arr1 = vector<int>({46, 33, 33 ,22, 31, 50});
//    vector<int> arr2 = vector<int>({27 ,56, 19, 14, 14, 10});
    int n = 1;
    vector<int> arr1 = vector<int>({0});
    vector<int> arr2 = vector<int>({1});

    vector<string> ans = solution(n, arr1, arr2);

    for(int i=0; i<n; i++)
        cout << ans[i] << "\n";



    return 0;
}
