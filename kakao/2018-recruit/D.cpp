#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> food_times, long long k) {

    int ans = 0;
    int L = food_times.size(); // L < 2*10^5
    vector<int> s;
    map<int, int> food;
    for(int i=0; i<L; i++)
        food[food_times[i]]++;

    long long time = 0, jump = 0, prev = 0;
    int idx = 0, num = L, cnt;
    for(auto it:food) { // iterate by ascending order.
        jump = it.first;
        if(k<time+(jump-prev)*num) {
            int turn = (k-time)%num+1;
            for(int i=0; i<L; i++) {
                if(food_times[i]>prev) {
                    if(turn==1) return (i+1);
                    else turn--;
                }
            }
        }
        time += (jump-prev)*num;
        prev = jump;
        num -= it.second;
    }

    return -1;
}

int main() {

    vector<vector<int>> food_times;
    food_times = {
            {3, 1, 2},
            {100, 100, 500, 777, 10}
    };

    int k[] = {5, 331};

    for(int i=0; i<2; i++)
        cout << solution(food_times[i], k[i]) << "\n";

    return 0;
}
