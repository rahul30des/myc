#include<iostream>

using namespace std;

int main() {
  int num = 5, tnum = 0;
  int count = 0;
  
  
  tnum = num;
  // Method 1
  while(num) {
    count += num&1;
    num >>= 1;
  }
  cout<<"Result by Method 1 : "<<count<<endl;
  
  num = tnum;
  count = 0;
  // Method 2
  while(num) {
    count += num%2;
    num >>= 1;
  }
  cout<<"Result by Method 2 : "<<count<<endl;
  
  num = tnum;
  count = 0;
  // Method 3
  while(num) {
    count++;
    num = num & (num-1);
  }
  cout<<"Result by Method 3 : "<<count<<endl;
  
  return 0;
}
