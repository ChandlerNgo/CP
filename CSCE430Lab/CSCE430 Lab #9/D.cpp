#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

double findDistance(pair<int,int> first, pair<int,int> second){
    return abs(first.first-second.first) + abs(first.second-second.second);
}

struct Jo{
    pair<int,int> currentPosition;
    set<pair<int,int>> stores;

    bool operator<(const Jo& other) const {
        return this->currentPosition.first < other.currentPosition.first;
    }
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

        stack<Jo> dfs;
        // set<Jo> visited;
        dfs.push({start,stores});
        bool madeIt = false;
        while(!dfs.empty() && !madeIt){
            Jo cur = dfs.top();
            dfs.pop();
            
            if(findDistance(end,cur.currentPosition) <= 1000){
                madeIt = true;
            }else{
                for(auto store : cur.stores){
                    if(findDistance(cur.currentPosition,store) <= 1000){
                        set<pair<int,int>> newStores = cur.stores;
                        newStores.erase(store);
                        dfs.push({store,newStores});
                    }
                }
            }
        }
        cout << (madeIt ? "happy" : "sad") << endl;
    }
}