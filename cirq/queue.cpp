#include <iostream>

using namespace std;

class Queue {
    int *arr;
    int front; // Points to next location after popping current
    int rear;  // Needs to be incremented before push
    int qsize;
    bool QFull() {
        return ((rear+1)%qsize == front);
    }
    bool QEmpty() {
        return (front = rear == -1);
    }

  public:
    Queue(int size) {

        if(size <= 0) {
            size = 1;
        }
        arr = new int[size];
        
        front = -1;
        rear = -1;
        qsize = size;
    }
    
    int QInsert(int num) {
        if(!QFull()) {
            if(QEmpty()) {
                front = 0;
            } 
            arr[(++rear)%qsize] = num;
            return 0;
        } else {
            return -1;
        }
       
    }
   
    int QRemove(int* removed) {  
        if(!QEmpty()) {
            *removed = arr[front++];
            if ((front - rear) == 1) {
                front = -1;
                rear = -1;
            } else {
                front = (front)%qsize;
            }
            return 0;
        } else {
            return -1;
        } 
    }
};

// Push
void insert(Queue& q, int item, bool should_fail) {
    int res = q.QInsert(item);
    if (res == -1) {
        if (!should_fail) {
            cout<<"Error when inserting "<<item<<endl;
            abort();
        }
        return;
    } else if (res != -1 && should_fail) {
        cout<<"No error when inserting "<<item<<endl;
        abort();
    }
    cerr<<"Successfully inserted "<<item<<endl;
}

// Pop
void remove(Queue& q, int expected_item, bool should_fail) {
    int removed;
    int res = q.QRemove(&removed);
    if (res == -1) {
        if (!should_fail) {
            cout<<"Error when removing "<<expected_item<<endl;
            abort();
        }
        return;
    } else if (should_fail) {
        cout<<"No error when removing "<<expected_item<<endl;
        abort();
    } else if (removed!= expected_item) {
        cout<<"Removed item "<<removed<<" does not match "<<expected_item<<endl;
        abort();
    }
    cout<<"Successfully removed "<<removed<<endl;
}

// Main Function
int main() {
    cout<<"Running test"<<endl;

    Queue q(5);

    remove(q, 1, true);

    insert(q, 1, false);
        
    remove(q, 1, false);
    

    cout<<"Test passed"<<endl;
    return 0;
}
