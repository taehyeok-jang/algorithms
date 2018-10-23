#include <stdio.h>
using namespace std;
#define MAX (int)1e6+1
int N;
int A[MAX];

int main() {

    scanf("%d", &N);
    for(int i=0; i<N; i++) scanf("%d", &A[i]);



    return 0;
}
// 이 알고리즘의 핵심은 수열을 차례대로 훑으면서 그 때까지의 길이가 n인 증가 부분 수열들의 최소 마지막 항을
// 모두 기억하는 겁니다.
// 이 값들을 배열로 저장하여 C[i] = (길이가 i인 부분 증가 수열의 마지막 항 중 최소값)이라 합시다.

// C[n]을 안다면, 새로운 항과 단 한 번의 비교만으로 길이가 n+1인 부분 증가 수열을
// 만들 수 있는지를 알 수 있죠.
//[출처] [3745번] 오름세(★★★☆☆)|작성자 라이