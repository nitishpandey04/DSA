#include <bits/stdc++.h>

using namespace std;

#include "Node.cpp"

void print(Node * head) {
    while (head != NULL) {
        cout << head -> data << " ";
        head = head -> next;
    }
    cout << "\n";
}

int length(Node* head) {
    int l = 0;
    while (head != NULL) {
        head = head -> next;
        l ++;
    }
    return l;
}

Node* input() {
    int d;
    cin >> d;
    Node * head = NULL;
    Node * tail = NULL;
    while (d != -1) {
        Node * newNode = new Node(d);
        if (head == NULL) {
            head = newNode;            
            tail = newNode;
        }
        else {
            tail -> next = newNode;
            tail = tail -> next;
        }
        cin >> d;
    }
    return head;
}

void insert(Node * &head, int index, int value) {
    Node * newNode = new Node(value);
    Node * temp = head;
    for (int i = 0 ; i < index - 1 ; i ++) {
        if (temp == NULL) break;
        temp = temp -> next;
    }
    if (!index){
        newNode -> next = head;
        head = newNode;
        return;
    }
    if (temp != NULL) {
        newNode -> next = temp -> next;
        temp -> next = newNode;
    }
}

Node *deleteNode(Node * head, int pos) {
    if (head == NULL) return head;
    Node * temp = head;
    for (int i = 0 ; i < pos - 1 ; i ++) {
        if (temp -> next == NULL) break;
        temp = temp -> next;
    }
    if (!pos) {
        head = head -> next;
        delete temp;
    }
    else if (temp -> next != NULL) {
        Node * n = temp -> next;
        temp -> next = (temp -> next) -> next;
        delete n;
    }
    return head;
}

Node* reverse(Node* head) {
    if (head -> next == NULL || head == NULL) return head;
    Node* newHead = reverse(head -> next);
    head -> next -> next = head;
    head -> next = NULL;
    return newHead;
}

void deallocate(Node * head) {
    while (head != NULL) {
        Node * nxt = head -> next;
        delete head;
        head = nxt;
    }
}

int main() {

    Node * head = input();
    print(head);
    int i, value;
    cin >> i >> value;
    insert(head, i, value);
    print(head);
    deallocate(head);

    return 0;
}
