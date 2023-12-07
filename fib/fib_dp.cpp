#include<iostream>
#include<vector>

using namespace std;

// Nth Fibonacci number
int fib(int n, vector<int> &arr) {
    if(arr[n] == -1) {
        if(n == 0) {
            arr[n] = 0;
        }
        if(n == 1) {
            arr[n] = 1;
        }
        if(n == 2) {
            arr[n] = 2;
        }
        if(int i = 3; i <=n i++) {
            arr[i] = arr[i-1] + arr[i-2];
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
