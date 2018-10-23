#define MAX 10001 // 10^4.

struct stack {
    int arr[MAX]; int st;
    void push(int a) { arr[st++] = a; }
    int pop() { return arr[--st]; }
    // or
    /**
    void push(int a) { arr[++st] = a; }
    int pop() { return arr[st--]; }
     */
    void clear() { while(st) printf(" %d", s[--st]); }
};