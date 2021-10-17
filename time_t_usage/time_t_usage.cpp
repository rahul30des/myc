#include<iostream>
#include<unistd.h>
#include<time.h>
using namespace std;

// Main Function
int main() {
    time_t timer = time(NULL);
    sleep(2);
    cout<<"Time elapsed in seconds : "<<difftime(time(NULL), timer)<<endl;
    return 0;
}
