#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

struct TreeNode{
    int val;
    TreeNode* parent;
    map<int,TreeNode*> children;
    int level;

    TreeNode(int _val, TreeNode* _parent, int _level){
        val = _val;
        parent = _parent;
        children = map<int,TreeNode*>();
        level = _level;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<TreeNode*> stacks;
    for(int i = 1; i <= n; i++){
        char action;
        int v;
        cin >> action >> v;
        Node* parentNode = stacks[v];
        if(action == 'a'){
            Node* newNode = new Node();
            newNode->data = i;
            newNode->prevNode = parentNode;
            stacks.push_back(newNode);
        }else if(action == 'b'){
            stacks.push_back(parentNode->prevNode);
            cout << parentNode->data << endl;
        }
        else{
            int w;
            cin >> w;
            //! only measures stack size and not union of two stacks
            stacks.push_back(stacks[v]);

            // find lca
            cout << abs(stackSize[v] - stackSize[w]) << endl;
        }
    }
}