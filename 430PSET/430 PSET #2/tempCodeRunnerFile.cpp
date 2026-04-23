#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

struct Node{
    int data;
    Node* prevNode;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<Node*> stacks;
    vector<int> stackSize;
    stacks.push_back(nullptr);
    stackSize.push_back(0);
    for(int i = 0; i < n; i++){
        char action;
        int v;
        cin >> action >> v;
        Node* parentNode = stacks[v];
        if(action == 'a'){
            Node* newNode = new Node();
            newNode->data = v;
            newNode->prevNode = parentNode;
            stacks.push_back(newNode);
            stackSize.push_back(stackSize[v]+1);
        }else if(action == 'b'){
            stacks.push_back(parentNode->prevNode);
            stackSize.push_back(stackSize[v]-1);
            cout << parentNode->prevNode->data << endl;
        }
        else{
            int w;
            cin >> w;
            //! only measures stack size and not union of two stacks
            stacks.push_back(stacks[v]);
            stackSize.push_back(stackSize[v]);
            cout << abs(stackSize[v] - stackSize[w]) << endl;
        }
    }
}