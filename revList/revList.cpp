/*
 * Write a function which reverses a linked list (both recursive and
 * non-recursive)
 */

#include<iostream>
#include<algorithm>
#include<stack>
#include<queue>
#include<deque>
#include<list>
#include<array>
#include<map>
#include<unordered_map>

using namespace std;

typedef struct node{
    int data;
    struct node *next;
}NODE;

void display(NODE *node) {
    cout<<endl;
    while(node) {
        cout<<node->data<<"->";
        node = node->next;
    }
    cout<<"NULL"<<endl;
}

// Reverse Linked List with recursion
NODE* withRec(NODE *head) {
    NODE *temp;
    if(head == NULL || head->next == NULL) {
        return head;
    }
    temp = withRec(head->next);
    head->next->next = head;
    head->next = NULL;
    return temp;
}

// Reverse Linked List without recursion
NODE* withoutRec(NODE *head) {
    NODE *prev = NULL, *next = NULL;
    
    while(head) {
        next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    return prev;

}

// Main Function
int main() {
    NODE *temp = new NODE;
    NODE *temp1 = new NODE;
    NODE *temp2 = new NODE;
    NODE *head;
    temp->data = 1;
    temp1->data = 2;
    temp2->data = 3;
    temp->next = temp1;
    temp1->next = temp2;
    temp2->next = NULL;
    head = temp;
    display(head);
    head = withRec(head);
    display(head);
    head = withoutRec(head);
    display(head);
    return 0;
}

