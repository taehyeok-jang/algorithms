#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

struct node {
    int key;
    node *left, *right;
};

/**
 * O(c*N)
 */
struct lca1 {

    bool find_path(node *root, vector<int> &path, int k) {

        if(root==NULL) return 0;

        path.push_back(root->key);
        if(root->key==k) return 1;
        if((root->left&&find_path(root->left, path, k))
           ||(root->right&&find_path(root->right, path, k)))
            return 1;

        path.pop_back();
        return 0;
    }

    int find_lca(node *root, int n1, int n2) {

        vector<int> path1, path2;
        if(!find_path(root, path1, n1)||!find_path(root, path2, n2))
            return -1;
        int i;
        for(i=0; i<path1.size()&&i<path2.size(); i++)
            if(path1[i]!=path2[i])
                break;
        return path1[i-1];
    }
};


struct lca2 {
/**
 * O(N).
 * single traversal.
 * suppose both node n1, n2 exist.
 */
    struct node *find_lca(node *root, int n1, int n2) {

        if(root==NULL) return NULL;
        if(root->key==n1||root->key==n2) return root;

        node *l_lca = find_lca(root->left, n1, n2);
        node *r_lca = find_lca(root->right, n1, n2);

        if(l_lca&&r_lca) return root;
        return (l_lca!=NULL)? l_lca:r_lca;
    }
};
int main() {

    cout << "hello world!\n";
    return 0;
}

