#include<iostream>

using namespace std;

class Queue{
    int front, rear;
    int qsize;
    int *arr;
    bool queue_full() {
        if(((rear == qsize - 1) && (front == 0)) || (rear == (front - 1))) {
            return true;
        } else {
             return false;
        }
    }
    bool last_item() {
        if((front != -1) && (front == rear)) {
            return true;
        } else {
            return false;
        }
    }
    bool queue_empty() {
        if (front == -1 && rear == -1) {
            return true;
        } else {
            return false;
        }
    }
    public:
    Queue(int size) {
        if (size <= 0 ) {
            size = 1;
        }
        front = rear = -1;
        qsize = size;
        arr = new int[qsize];
    }
    bool enqueue(int item) {
        if(queue_full()) {
            return false;
        }
        if(queue_empty()) {
            front =  0;
        }
        rear = (rear + 1)%qsize;
        arr[rear] = item;
        return true;
    }
    bool dequeue() {
        bool mark_queue_empty = false;
        if(queue_empty()) {
            return false;
        }
        if(last_item()) {
            mark_queue_empty = true;
        }
        front = (front + 1)%qsize;
        if(mark_queue_empty) {
            front = -1;
            rear = -1;
        }
        return true;
    }

    int peek_front() {
        if(queue_empty()) {
            return false;
        }
        return arr[front];
    }
    int peek_rear() {
        if(queue_empty()) {
            return false;
        }
        return arr[rear];
    }
    void display() {
        int head = front;
        int tail = rear;
        while(head != tail) {
            cout<<arr[head]<<endl;
            head = (head + 1)%qsize;
        }
        if ((head == tail) && head != -1) {
            cout<<arr[head]<<endl;
        }
    }
};

// Main Function
int main() {
    int size = 0;
    cout<<"Enter the size of the queue : ";
    cin>>size;

    Queue *q = new Queue(size);

    for(int i = 0;i < size; i++) {
        q->enqueue(i);
        cout<<q->peek_rear()<<endl;
    }

    q->display();

    for(int i = 0;i < size; i++) {
        q->dequeue();
        cout<<q->peek_front()<<endl;
    }

    return 0;
}
