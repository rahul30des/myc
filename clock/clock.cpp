#include<iostream>
#include<unistd.h>

using namespace std;

struct custom_time{
    int hours;
    int mins;
    int secs;
};

void timer(custom_time *t) {
    while(1) {
        cout<<t->hours<<" "<<t->mins<<" "<<t->secs<<" "<<endl;
        sleep(1);
        system("clear");
        t->secs++;
        if(t->secs == 60) {
            t->mins++;
            if(t->mins == 60) {
                t->hours++;
                t->mins = 0;
            }
            t->secs = 0;
        }
    }
}

// Main Function
int main() {
    custom_time *t = new custom_time;
    timer(t);
    return 0;
}
