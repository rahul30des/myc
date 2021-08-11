#include<iostream>

using namespace std;

// Class to implement Queue Functionality
class Queue {
    int front, rear;
    int *arr;
    int qsize;
    bool QFull() {
        return (rear >= (qsize - 1));
    }
    bool QEmpty() {
        return ((front == -1 && rear == -1) || (front > rear));
    }
    public :
    // Initialize the Queue Array
    Queue(int size) {
        if (size <= 0) {
            size = 1;
        }
        arr = new int[size];
        front = -1;
        rear = -1;
        qsize = size;
    }

    //Display Function
    void display() {
        int head = front;
        int tail = rear;

        while(head <= tail) {
            cout<<arr[head]<<endl;
            head++; 
        }
    }

    // Remove Function
    int peek_front() {
        if(QEmpty()) {
            return INT_MIN;
        } else {
            return arr[front];
        }
    }

    // Remove Function
    int peek_rear() {
        if(QEmpty()) {
            return INT_MIN;
        } else {
            return arr[rear];
        }
    } 

    // Remove Function
    void remove() {
        if(!QEmpty()) {
            ++front;
        } 
    }

    // Insert Function
    bool insert(int item) {
        if(QFull()) {
            return false;
        }
        if(QEmpty()) {
            front = 0;
        }
        arr[++rear] = item;
        return true;
    }
};

// Main Function
int main() {
    int size = 0;
    cout<<"Enter the size of the queue : ";
    cin>>size;

    Queue *q = new Queue(size);

    // Adding items to a queue
    for (int i = 0; i < size;i++) {
        q->insert(i);
        cout<<"Peeking Rear :"<<q->peek_rear()<<endl;
    }

    q->display();
    cout<<"Peeking and Removing"<<endl;

    // Removing items from a queue
    for (int i = 0; i < size;i++) {
        cout<<"Peeking Front and Removing:"<<q->peek_front()<<endl;
        q->remove();
    }

    return 0;
}
