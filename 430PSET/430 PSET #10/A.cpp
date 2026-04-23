#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    cin.ignore();

    map<string,set<string>> understand; // language : names
    map<string,string> spoken; // name : language

    for(int i = 0; i < n; i++){
        string line;
        getline(cin,line);
        stringstream ss(line);

        string name;
        string spokenLanguage;
        ss >> name >> spokenLanguage;
        spoken[name] = spokenLanguage;
        understand[spokenLanguage].insert(name);
        string understoodLanguage;
        while(ss >> understoodLanguage){
            understand[understoodLanguage].insert(name);
        }
    }

    map<string, set<string>> adj; // name : names
    map<string, set<string>> reversedAdj; // name : names

    for(auto key : spoken){
        for(auto people : understand[key.second]){
            if(key.first != people){
                adj[key.first].insert(people);
                reversedAdj[people].insert(key.first);
            }
        }
    }

    // dfs with first finished node on bottom of stack
    
    set<string> visited;
    stack<string> order;
    for(auto& node : adj){
        if(visited.find(node.first) == visited.end()){
            stack<pair<string, bool>> dfs; // pair<node, processed>
            dfs.push({node.first, false});
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

    int minRemoval = INT_MAX;

    visited.clear();
    vector<vector<string>> components;

    while(!order.empty()){
        string name = order.top();
        order.pop();
        if(visited.find(name) != visited.end()){
            continue;
        }

        vector<string> component;
        stack<string> dfs;
        dfs.push(name);
        while(!dfs.empty()){
            string newName = dfs.top();
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

        minRemoval = min(minRemoval, n-(int)component.size());
        components.push_back(component);
    }
    cout << minRemoval << endl;
}