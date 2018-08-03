#include <iostream>

using namespace std;


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


    return 0;
}


