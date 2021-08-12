#include <iostream>

using namespace std;

class Node{
    int data;
    Node *next;
    public:
        Node(int value) {
            this->data = value;
            this->next = NULL;
        }
        Node* RecRev() {
            Node *head = this;
            Node *next = head;
            if(head && head->next) {
                Node *temp = head->next;
                next = head->next->RecRev();
                temp->next = head;
                head->next = NULL;
            }
            return next;
        }
        Node* IterRev() {
            Node *head = this;
            Node *prev = NULL, *next = NULL;
            while(head) {
                next = head->next;
                head->next = prev;            
                prev = head;
                head = next;                
            }
            return prev;
        }
        void display() {
            Node *head = this;
            while(head) {
                cout<<head->data<<"->";
                head = head->next;
            }
            cout<<"NULL"<<endl;
        }
        void append(int data) {
            Node *head = this;
            while(head->next) {
                head = head->next;
            }
            head->next = new Node(data);
        }
};

int main() {
    Node *head = new Node(5);    

    head->append(6);
    head->append(7);
    head->append(8);

    head->display();
    head = head->RecRev();
    head->display();
    head = head->IterRev();
    head->display();
    return 0;
}
