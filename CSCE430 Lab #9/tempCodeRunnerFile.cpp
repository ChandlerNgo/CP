#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

double findDistance(pair<int,int> first, pair<int,int> second){
    return sqrt(pow(first.first-second.first,2) + pow(first.second-second.second,2));
}

struct Jo{
    pair<int,int> currentPosition;
    set<pair<int,int>> stores;
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        pair<int,int> start;
        set<pair<int,int>> stores;
        cin >> start.first >> start.second;
        for(int i = 0; i < n; i++){
            pair<int,int> store;
            cin >> store.first >> store.second;
            stores.insert(store);
        }
        pair<int,int> end;
        cin >> end.first >> end.second;

        queue<Jo> bfs;
        set<Jo> visited;
        bfs.push({start,stores});
        bool madeIt = false;
        while(!bfs.empty() && !madeIt){
            Jo cur = bfs.front();
            bfs.pop();
            
            if(visited.find(cur) != visited.end()){
                continue;
            }
            
            visited.insert(cur);
            if(findDistance(end,cur.currentPosition) <= 1000){
                madeIt = true;
            }else{
                for(auto store : cur.stores){
                    if(findDistance(cur.currentPosition,store) <= 1000 && findDistance(cur.currentPosition,store) < findDistance(cur.currentPosition, end)){
                        set<pair<int,int>> newStores = cur.stores;
                        newStores.erase(store);
                        bfs.push({store,newStores});
                    }
                }
            }
        }
        cout << (madeIt ? "happy" : "sad") << endl;
    }
}