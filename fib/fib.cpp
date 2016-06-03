#include <iostream>

using namepsace std;

int fib(int num) {
    if (num == 1 || num == 2) {
        return 1;
    }
    if (num == 0) {
        return 0;
    }
    return fib(n - 1) + fib (n - 2); 
}
// Find nth Fibonacci number
int main() {
    int n = 0;
    cin>>n;
    cout<<fib(n);
    return 0;
}
