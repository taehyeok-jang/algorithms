#include <iostream>
using namespace std;

struct Node {
    int data;
    Node * next;
    Node * prev;
};

class DoublyLinkedlList {
    Node *head;
    Node *tail;
    int len;

public:
    DoublyLinkedlList() {

        head = NULL;
        tail = NULL;
        len = 0;
    }

    ~DoublyLinkedlList() {

        while (head != NULL) {
            Node *nextNode = head->next;
            delete head;
            head = nextNode;
        }
    }

    DoublyLinkedlList(const DoublyLinkedlList &ob) {

        if (!ob.head)
            *this = ob;

        else {
            head = new Node;
            *head = *ob.head;

            Node *prev = head;
            Node *oldtemp = ob.head;
            Node *newtemp = head;

            while (oldtemp->next) {
                // create a copy of node
                oldtemp = oldtemp->next;
                newtemp = new Node;
                *newtemp = *oldtemp;

                // connect the prev with this one
                prev->next = newtemp;
                newtemp->prev = prev;
                prev = newtemp;

            } // end while

            tail = newtemp;
            len = ob.len;
        }// end else
    }

    int length() {

        return len;
    }

    void add_begin(int new_val) {

        Node *n = new Node;
        n->data = new_val;
        n->next = head;
        n->prev = NULL;

        if (len == 0){
            head = n;
            tail = n;
            len++;
        }
        else{
            head->prev = n;
            head = n;
            len++;
        }
    }

    void add_end(int new_val) {

        Node *n = new Node;
        n->data = new_val;
        n->next = NULL;
        n->prev = tail;

        if (len == 0){
            tail = n;
            head = n;
            len++;
        }
        else {
            tail->next = n;
            tail = n;
            len++;
        }
    }

    void print_list() {

        if (len == 0)
            return;

        Node *printNode = head;

        while (printNode != NULL) {
            cout << printNode->data << ' ';
            printNode = printNode->next;
        }

        cout << endl;
    }

    void print_reverse() {

        if (len == 0)
            return;

        Node *printNode = tail;

        while (printNode != NULL) {
            cout << printNode->data << ' ';
            printNode = printNode->prev;
        }

        cout << endl;
    }

    int pop_begin() {

        if (len == 0) {
            cout << "The list is empty.\n" << endl;
            return 0;
        }
        else {
            Node *beginning = head;
            int value = beginning->data;
            head = beginning->next;
            delete beginning;
            head->prev = NULL;
            len--;
            return value;
        }
    }

    int pop_end() {

        if (len == 0) {
            cout << "The list is empty.\n" << endl;
            return 0;
        }
        else {
            Node *end = tail;
            int value = end->data;
            tail = end->prev;
            delete end;
            tail->next = NULL;
            len--;
            return value;
        }

    }

    void remove(int pos) {

        if (len == 0) {
            cout << "The list is empty.\n" << endl;
        }
        else {
            Node* temp = head;
            for(int i=0; i<pos; i++)
                temp = temp->next;

            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
        }
    }
};

int main(){

    DoublyLinkedlList dll;

    dll.add_begin(1);
    dll.add_begin(2);

    dll.add_begin(3);
    dll.add_begin(4);
    dll.add_end(5);

    dll.print_list();
    // TODO 0, x>n error.
    dll.remove(3);

    dll.print_list();

    return 0;
}
