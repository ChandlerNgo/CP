#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

bool isStronglyConnected(int m, map<int,set<int>> adj){
    set<int> visited;
    stack<int> order;

    map<int,set<int>> reversedAdj;

    for(auto key : adj){
        for(auto neighbor : key.second){
            reversedAdj[neighbor].insert(key.first);
        }
    }

    for(int node = 0; node < m; node++){
        if(visited.find(node) == visited.end()){
            stack<pair<int, bool>> dfs; // pair<node, processed>
            dfs.push({node, false});
            while(!dfs.empty()){
                auto [name, processed] = dfs.top();
                dfs.pop();
                if(processed){
                    order.push(name);
                    continue;
                }
                if(visited.find(name) != visited.end()){
                    continue;
                }
                visited.insert(name);
                dfs.push({name, true}); // Mark as processed
                for(auto neighbor : adj[name]){
                    if(visited.find(neighbor) == visited.end()){
                        dfs.push({neighbor, false});
                    }
                }
            }
        }
    }

    visited.clear();
    vector<vector<int>> components;

    while(!order.empty()){
        int name = order.top();
        order.pop();
        if(visited.find(name) != visited.end()){
            continue;
        }

        vector<int> component;
        stack<int> dfs;
        dfs.push(name);
        while(!dfs.empty()){
            int newName = dfs.top();
            dfs.pop();

            if(visited.find(newName) != visited.end()){
                continue;
            }
            
            visited.insert(newName);
            component.push_back(newName);

            for(auto neighbor : reversedAdj[newName]){
                dfs.push(neighbor);
            }
        }

        components.push_back(component);
    }

    return components.size() == 1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m;
    int n;
    int caseNumber = 1;
    while(cin >> m >> n){
        map<int,set<int>> adj;
        vector<pair<int,int>> edges;

        for(int i = 0; i < n; i++){
            int a;
            int b;
            cin >> a >> b;
            adj[a].insert(b);
            edges.push_back({a,b});
        }

        cout << "Case " << caseNumber << ": ";


        if(isStronglyConnected(m, adj)){
            cout << "valid" << "\n";
        }else{
            bool foundCase = false;

            for(auto key : edges){
                map<int,set<int>> newAdj = adj;
                newAdj[key.first].erase(key.second);
                newAdj[key.second].insert(key.first);
                if(isStronglyConnected(m,newAdj)){
                    foundCase = true;
                    cout << key.first << " " << key.second << "\n";
                    break;
                }
            }

            if(!foundCase){
                cout << "invalid" << "\n";
            }
        }

        caseNumber += 1;
    }
    cout << endl;
}