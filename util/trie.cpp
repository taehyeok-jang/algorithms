#include <iostream>

#define SIZE 26
#define OFFSET 'a'

using namespace std;

struct node {
    node* children[SIZE];
    bool end;
};
node* create_node(void) {
    node* p = new node();
    for(int i=0; i<SIZE; i++)
        p->children[i] = 0;
    p->end = false;
    return p;
}
void insert(node* root, string key) {
    node* p = root;
    for(int i=0; i<key.length(); i++) {
        int idx = key[i]-OFFSET;
        if(!p->children[idx])
            p->children[idx] = create_node();
        p = p->children[idx];
    }
    p->end = true;
}
bool search(node* root, string key) {
    node* p = root;
    for(int i=0; i<key.length(); i++) {
        int idx = key[i]-OFFSET;
        if(!p->children[idx])
            return false;
        p = p->children[idx];
    }
    return p->end;
}
void destruct(node* root) {
    node* p = root;
    for(int i=0; i<SIZE; i++)
        if(p->children[i])
            destruct(p->children[i]);
    delete p;
}

void traverse(node *root) {
    node* p = root;
    for(int i=0; i<SIZE; i++)
        if(p->children[i]) {
            cout << (char)(i+OFFSET) << "\n";
            traverse(p->children[i]);
        }
}

int main() {
    /**
     * example on 'https://www.geeksforgeeks.org/trie-insert-and-search/'
     */
    string keys[] = {"the", "a", "there",
                     "answer", "any", "by",
                     "bye", "their" };
    int n = sizeof(keys)/sizeof(keys[0]);

    node* root = create_node();
    for (int i = 0; i < n; i++)
        insert(root, keys[i]);
//    traverse(root);

    puts(search(root, "the")? "Yes":"No");
    puts(search(root, "these")? "Yes":"No");
    destruct(root);
    return 0;
}

