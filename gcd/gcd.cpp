#include<iostream>
#include<algorithm>

using namespace std;

int euclid_gcd(int a, int b) {
    while(b != 0) {
        int r = a%b;
        a = b;
        b = r;
    }
    return a;
}

int main() {
    int a = 0, b = 0;
    cin>>a>>b;
    cout<<endl<<"GCD is : \t"<<euclid_gcd(a, b);
    return 0;
}


