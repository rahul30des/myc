#include <iostream>
#include <vector>

using namespace std;

// DP solution - memoization
int fib(int n, vector <int>&  arr) {
    if (arr[n] == -1) {
        if (n == 0) {
            arr[n] = 0;
        } else if (n == 1 || n == 2) {
            arr[n] = 1;
        } else {
            arr[n] = fib(n-1, arr) + fib(n-2, arr);
        }
    }

    return arr[n];
}

// Find nth Fibonacci number
int main() {
    int n = 0;
    cin>>n;
    vector <int> arr(n+1, -1);
    cout<<fib(n, arr);
    return 0;
}
