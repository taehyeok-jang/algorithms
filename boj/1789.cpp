#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>

using namespace std;
long long S;

int main() {

    scanf("%lld", &S);
    long long m = sqrt(S);
    while((m*(m+1))/2 <= S) m++;

    printf("%lld", m-1);
    return 0;
}
