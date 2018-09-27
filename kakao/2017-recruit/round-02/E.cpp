#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define SIZE 26
#define OFFSET 'a'

using namespace std;

struct node {
    node* children[SIZE];
    bool end;
    int count;
};
node* create_node(void) {
    node* p = new node();
    for(int i=0; i<SIZE; i++)
        p->children[i] = 0;
    p->end = false;
    p->count = 0;
    return p;
}
void insert(node* root, string key) {
    node* p = root;
    for(int i=0; i<key.length(); i++) {
        int idx = key[i]-OFFSET;
        if(!p->children[idx])
            p->children[idx] = create_node();
        p = p->children[idx];
        p->count++;
    }
    p->end = true;
}
/*bool search(node* root, string key) {
    node* p = root;
    for(int i=0; i<key.length(); i++) {
        int idx = key[i]-OFFSET;
        if(!p->children[idx])
            return false;
        p = p->children[idx];
    }
    return p->end;
}*/
int find_words(node *root) {
    int count = (root->end)? 1:0;
    for(int i=0; i<SIZE; i++)
        if(root->children[i])
            count += find_words(root->children[i]);
    return count;
}
void destruct(node* root) {
    node* p = root;
    for(int i=0; i<SIZE; i++)
        if(p->children[i])
            destruct(p->children[i]);
    delete p;
}

int solution(vector<string> words) {

    node *root = create_node();
    // 2.6*O(10^7). (amortized complexity)
    for(int i=0; i<words.size(); i++)
        insert(root, words[i]);

    int ans = 0, idx, c, branch;
    for(int i=0; i<words.size(); i++) {
        node *p = root;
        branch = 0;
        for(int j=0; j<words[i].size(); j++) {
            idx = words[i][j]-OFFSET;
            p = p->children[idx];
            c = 0;
            for(int i=0; i<26; i++)
                if(p->children[i]) c++;
            if((j<words[i].size()-1&&p->end)||c>1)
                branch = j+1;
            else if(j==words[i].size()-1&&c>0)
                branch = j;
        }
        ans += (branch+1);
    }

    /* @@ another solution using count.
     * for(int i=0; i<words.size(); i++) {
        node *p = root;
        for(int j=0; j<words[i].size(); j++) {
            idx = words[i][j]-OFFSET;
            p = p->children[idx];
            if((j==words[i].size()-1&&p->end)||p->count==1) {
                ans += (j+1);
                break;
            }
        }
    }*/

    destruct(root);
    return ans;
}

int main() {

    vector<vector<string>> input(3);
    input[0] = {"go","gone","guild"};
    input[1] = {"abc","def","ghi","jklm"};
    input[2] = {"word","war","warrior","world"};

    for(int i=0; i<3; i++)
        cout << solution(input[i]) << "\n";


    return 0;
}













