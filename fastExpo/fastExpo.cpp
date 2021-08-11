#include<iostream>

using namespace std;

// Calculate exponential in a performant manner
long FastExpo(int num1, int num2) {
     long result = 1;
     while(num2) {
         if(num2&1) {
             result *= num1;
         }
         num2 >>= 1;
         num1 *= num1;
     }
     return result;
}

// Main Function
int main() {
    int num1 = INT_MIN, num2 = INT_MIN;
    cout<<"Enter the 2 numbers : "; 
    cin>>num1>>num2;
    cout<<FastExpo(num1, num2)<<endl;
    return 0;
}
