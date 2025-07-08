#include<bits/stdc++.h>
using namespace std;

class Node {
    int data;
    Node *next;

public:
    Node(int d): data(d), next(nullptr) {};
    Node(int d, Node *nextNode): data(d), next(nextNode) {};

    void setNextNode(Node *nextNode) {
        this->next = nextNode;
    }

    int getNodeData() {
        return this->data;
    }

    Node *getNextNode() {
        return this->next;
    }

    static void printLinkedList(Node *head) {
        while(head != NULL) {
            cout << head->getNodeData() << endl;
            head = head->getNextNode();
        }
    }

    static Node* insertNodeAtHead(Node *head, int item) {
        Node *newNode = new Node(item, head);
        return newNode;
    }

    static int lengthOfLinkedList(Node *head) {
        int cnt = 0;

        while(head != NULL) {
            head = head->getNextNode();
            cnt++;
        }

        return cnt;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    Node *a = new Node(0);
    Node *b = new Node(1);
    Node *c = new Node(2);

    a->setNextNode(b);
    b->setNextNode(c);

    Node::printLinkedList(a);
    cout << endl;

    int item = 5;
    Node *newHead = Node::insertNodeAtHead(a, item);
    Node::printLinkedList(newHead);
    cout << endl;

    int length = Node::lengthOfLinkedList(newHead);
    cout << length << endl;











    
    return 0;
}