#include<iostream>
#include<algorithm>

using namespace std;

// Can be optimized further
int expo(int a, int b){
  int result = 1;

  while (b){
    if (b&1){
      result *= a;
    }
    b >>=1 ;
    a *= a;
  }

  return result;
}

// Main Function
int main() {
    int num1 = 0, num2 = 0;
    cin>>num1>>num2;
    cout<<expo(num1, num2);
    return 0;
}
