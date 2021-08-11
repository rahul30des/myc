#include<iostream>
#include<vector>

using namespace std;

// Nth Fibonacci number
int fib(int n, vector<int> &arr) {
    if (arr[n] == -1) {
        if (n == 0) {
            arr[n] = 0;
        } else if (n == 1 || n == 2) {
            arr[n] = 1;
        } else {
            arr[n] = fib(n-2, arr) + fib(n-1, arr);
        }
    }
    return arr[n];
}

// Main Function
int main() {
    int n = INT_MIN;
    cin>>n;
    
    vector<int> arr(n+1, -1);
    cout<<fib(n, arr)<<endl;
    return 0;
}
