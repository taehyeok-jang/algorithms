#include <iostream>
#include <cstring>

using namespace std;

int tc, t;
int A[100001];
int N, M;
int C, X, Y, L, R;

bool DEBUG = false;

class BinaryIndexedTree {

public:
    int* arr;
    int length;
    int* resultOfRange;

    BinaryIndexedTree(int A[], int N) {

        arr = A;
        length = N;
        int size = 1;
        while(size < 2*length)
            size *= 2;
        resultOfRange = new int[size];
        for(int i=0; i<size; i++)
            resultOfRange[i] = 0;

        _initialize(0, length-1, 1);
    }

    int query(int left, int right) {

        return _query(left, right, 1, 0, length-1);
    }

    void update(int pos, int val) {

        arr[pos] += val;
        _update(pos, val, 1, 0, length-1);
    }

private:

    int _initialize(int left, int right, int index) {

        if(left == right) {
            resultOfRange[index] = arr[left];
            return resultOfRange[index];
        }

        int mid = (left+right)/2;
        int lResult = _initialize(left, mid, 2*index);
        int rResult = _initialize(mid+1, right, 2*index+1);

        resultOfRange[index] = lResult+rResult;
        return resultOfRange[index];
    }

    int _query(int left, int right, int index, int leftIndex, int rightIndex) {

        // exclusive
        if(right<leftIndex || left>rightIndex)
            return 0;
        // inclusive
        if(left<=leftIndex && right>=rightIndex)
            return resultOfRange[index];

        // recursive query for partial range.
        int mid = (leftIndex+rightIndex)/2;
        return _query(left, right, 2*index, leftIndex, mid)
               + _query(left, right, 2*index+1, mid+1, rightIndex);
    }

    int _update(int pos, int val, int index, int leftIndex, int rightIndex) {

        if(pos<leftIndex || pos>rightIndex)
            return resultOfRange[index];
        if(leftIndex == rightIndex) {
            resultOfRange[index] += val;
            return resultOfRange[index];
        }

        int mid = (leftIndex+rightIndex)/2;
        resultOfRange[index] = _update(pos, val, 2*index, leftIndex, mid)
                                + _update(pos, val, 2*index+1, mid+1, rightIndex);

        return resultOfRange[index];
    }
};

int main() {

//    FILE *fp = freopen("../data/3064.input", "r", stdin);
//    if(!fp)
//        perror("freopen error");

    scanf("%d", &tc);
    t = 0;
    while(t++ < tc) {

        printf("#%d", t);

        scanf("%d", &N);
        scanf("%d", &M);

        for(int i=0; i<N; i++)
            scanf("%d", &A[i]);

        BinaryIndexedTree bit(A, N);

        for(int i=0; i<M; i++) {

//            cout << "\ni: " << i << "\n";
//
//            for(int i=0; i<N; i++)
//                cout << A[i] << " ";
//            cout << "\n";
//
            scanf("%d", &C);

            if(C == 1) {
                scanf("%d%d", &X, &Y);
                bit.update(X-1, Y);
            }
            else { // == 2
                scanf("%d%d", &L, &R);
                printf(" %d", bit.query(L-1, R-1));
            }
        }

        printf("\n");
    }

    return 0;
}