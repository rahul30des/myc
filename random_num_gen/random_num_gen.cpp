#include<iostream>
#include<time.h>

using namespace std;

// Main Function
int main() {
    // Seeding with current time for true randomization
    // srand(time(NULL));
    // Else Pseudo-Random generation - same for every execution
    for(int i = 0; i < 5;i++) {
        cout<<rand()%5<<" ";
        cout<<endl;
    }
    return 0;
}
