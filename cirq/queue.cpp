#include <iostream>
using namespace std;

class Queue {
    int *arr;
    int front; 
    int rear; 
    int count;
    int qsize;
    bool QFull() {
        return (count == qsize);
    }
    
    bool QEmpty() {
        return (count == 0);
    }

  public:
    Queue(int size) {

        if(size <= 0) {
            size = 1;
        }
        arr = new int[size];
        

        
        front = 0;
        rear = -1;
        count = 0;
        qsize = size;
    }
    
    int QInsert(int num) {
        if(!QFull()) {
            // Handle case of queue filled and emptied
            if(rear == qsize - 1) {
                rear = -1;
            }
            arr[++rear] = num;
            count++;
            return 0;
        } else {
            return -1;
        }
       
    }
   
    int QRemove(int* removed) {  
        if(!QEmpty()) {
            *removed = arr[front++];
            if(front == qsize) {
                front = 0;
            }
            count--;
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

    Queue q(0);

    remove(q, 1, true);

    insert(q, 1, false);
        
    remove(q, 1, false);
    

    cout<<"Test passed"<<endl;
    return 0;
}
