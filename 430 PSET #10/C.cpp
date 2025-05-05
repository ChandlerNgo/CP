#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        int n;
        int m;
        cin >> n >> m;

        // if(m == 0){
        //     cout << (n == 1 ? 0 : n) << endl;
        //     continue;
        // }

        map<int,set<int>> adj;
        map<int,set<int>> reversedAdj;
        for(int i = 0; i < m; i++){
            int a;
            int b;
            cin >> a >> b;
            adj[a].insert(b);
            reversedAdj[b].insert(a);
        }

        set<int> visited;
        stack<int> order;
        for(int node = 1; node <= n; node++){
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

        map<int,set<int>> componentGraph;
        map<int,set<int>> reversedComponentGraph;
        map<int,int> componentNumber;

        for(int i = 0; i < components.size(); i++){
            for(auto node : components[i]){
                componentNumber[node] = i;   
            }
        } // gives each node a componentnumber

        for(int i = 0; i < components.size(); i++){ // connects one component to another
            for(auto node : components[i]){
                for(auto neighbor : adj[node]){
                    if(i != componentNumber[neighbor]){
                        componentGraph[i].insert(componentNumber[neighbor]);
                        reversedComponentGraph[componentNumber[neighbor]].insert(i);
                    }
                }
            }
        }

        int sinks = 0;
        int sources = 0;
        for(int i = 0; i < components.size(); i++){
            if(componentGraph[i].size() == 0){
                sinks += 1;
            }

            if(reversedComponentGraph[i].size() == 0){
                sources += 1;
            }
        }

        if(components.size() == 1){
            cout << 0 << endl;
            continue;
        }

        // for(auto component : componentGraph){
        //     cout << component.first << ": ";
        //     for(auto node : component.second){
        //         cout << node << " ";
        //     }
        //     cout << endl;
        // }
        // cout << components.size() << " " << sinks << " " << sources << endl;
        cout << max(sources,sinks) << endl;
    }
    
}