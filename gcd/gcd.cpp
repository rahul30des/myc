#include <iostream>
#include <algorithm>

using namespace std;

int CalculateGCD(int first_num, int second_num) {
    while(second_num != 0) {
        int remainder = first_num % second_num;
        first_num = second_num;
        second_num = remainder;
    }
    return first_num;
}

// Main Function
int main() {
    int first_num = 0, second_num = 0;
    cin>>first_num>>second_num;
    
    cout<<endl<<"GCD is "<<CalculateGCD(first_num, second_num)<<endl;
    return 0;
}
