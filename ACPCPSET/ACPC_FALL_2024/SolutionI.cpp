#include <bits/stdc++.h>

using namespace std;

int main(){
    map<int,int> roots;
    queue<int> curBranch;
    queue<int> curTime;
    queue<string> curAction;

    int n;
    int k;
    cin >> n >> k;
    string trees;
    cin >> trees;
    for(int i = 0; i < n; i++){
        if(trees[i] == 'T'){
            if(roots.find(i) == roots.end()){
                roots[i] = 1;
            }else{
                roots[i] += 1;
            }
            curBranch.push(i-1);
            curAction.push("left");
            curTime.push(1);
            curBranch.push(i+1);
            curAction.push("right");
            curTime.push(1);
        }
    }

    if(roots.size() < k){
        cout << -1 << "\n" << endl;
        return 0;
    }

    if(k == 1){
        cout << 0 << "\n" << endl;
        return 0;
    }

    while(!curAction.empty()){
        int currentBranch = curBranch.front();
        curBranch.pop();
        int currentTime = curTime.front();
        curTime.pop();
        string currentAction = curAction.front();
        curAction.pop();
        if(currentBranch < 0 || currentBranch >= trees.size()){
            continue;
        }

        if(roots.find(currentBranch) == roots.end()){
            roots[currentBranch] = 1;
        }else{
            roots[currentBranch] += 1;
        }

        if(roots[currentBranch] == k){
            cout << currentTime << "\n";
            break;
        }

        if(currentAction == "left"){
            curBranch.push(currentBranch-1);
            curAction.push("left");
            curTime.push(currentTime+1);
        }else{
            curBranch.push(currentBranch+1);
            curAction.push("right");
            curTime.push(currentTime+1);
        }
    }
}