#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

struct node {
    int n;
    int x,y;
    int left, right;
    bool operator < (const node &n2) const {
        if(y==n2.y) return x<n2.x;
        else        return y>n2.y;
    }
    node(int _n, int _x, int _y) {
        n = _n; x = _x; y = _y;
        left = -1, right = -1;
    }
};

void pre_order(vector<node> &nodes, int root, vector<int> &vv) {
    if(root==-1) return;
    vv.push_back(nodes[root].n);
    pre_order(nodes, nodes[root].left, vv);
    pre_order(nodes, nodes[root].right, vv);
}

void post_order(vector<node> &nodes, int root, vector<int> &vv) {
    if(root==-1) return;
    post_order(nodes, nodes[root].left, vv);
    post_order(nodes, nodes[root].right, vv);
    vv.push_back(nodes[root].n);
}

void generate(vector<node> &nodes, int root, int current) { // relative root val.

    if(nodes[current].x<nodes[root].x) {
        if(nodes[root].left==-1) nodes[root].left = current;
        else                     generate(nodes, nodes[root].left, current);
    }
    else {
        if(nodes[root].right==-1) nodes[root].right = current;
        else                      generate(nodes, nodes[root].right, current);
    }
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {

    vector<node> nodes;
    for(int i=0; i<nodeinfo.size(); i++)
        nodes.push_back(node(i+1, nodeinfo[i][0], nodeinfo[i][1]));
    sort(nodes.begin(), nodes.end());

    for(int i=1; i<nodes.size(); i++)
        generate(nodes, 0, i);

    vector<vector<int>> ans(2);
    vector<int> v1, v2;
    pre_order(nodes, 0, v1), post_order(nodes, 0, v2);
    ans[0] = v1, ans[1] = v2;

    return ans;
}

int main() {

    vector<vector<int>> input = {
            {5,3},{11,5},{13,3},{3,5},{6,1},{1,3},{8,6},{7,2},{2,2}
    };

    vector<vector<int>> sol = solution(input);
    for(int i=0; i<2; i++) {
        for(int j=0; j<sol[i].size(); j++)
            cout << sol[i][j] << " ";
        cout << "\n";
    }



    return 0;
}