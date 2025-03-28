#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

class Tarjan{
    public:
        map<int,set<int>> graph;
        vector<int> discovery_time;
        vector<int> low_time;
        set<int> visited;
        int time = 0;
        set<pair<int,int>> bridges;

        Tarjan(map<int,set<int>> adj, int n): graph(adj), discovery_time(n), low_time(n){
            graph = adj;
            for(int i = 0; i < n; i++){
                discovery_time[i] = 0;
                low_time[i] = INT_MAX;
            }
        }

        void findBridges(){
            for(auto edge : graph){
                if(visited.find(edge.first) == visited.end()){
                    dfs(-1,edge.first);
                }
            }
        }

        void dfs(int parent, int node){
            visited.insert(node);
            discovery_time[node] = time;
            low_time[node] = time;
            time += 1;

            for(auto neighbor : graph[node]){
                if(neighbor == parent){
                    continue;
                }

                if(visited.find(neighbor) != visited.end()){
                    // found cycle
                    low_time[node] = min(low_time[node],discovery_time[neighbor]);
                    continue;
                }
                dfs(node,neighbor);
                low_time[node] = min(low_time[node], low_time[neighbor]);
                if(low_time[neighbor] > discovery_time[node]){
                    bridges.insert({min(neighbor,node),max(neighbor,node)});
                }
            }
        }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int p; int c;
    cin >> p >> c;

    map<int,set<int>> adj;

    for(int i = 0; i < c; i++){
        int a;
        int b;
        cin >> a >> b;
        adj[a].insert(b);
        adj[b].insert(a);
    }

    bool possible = true;

    Tarjan alg(adj, p);

    alg.findBridges();
    
    // for(auto dis_time : alg.discovery_time){
    //     cout << dis_time << " ";
    // }
    // cout << "\n";
    // for(auto l_time : alg.low_time){
    //     cout << l_time << " ";
    // }
    // cout << "\n";

    for(auto bridge : alg.bridges){
        adj[bridge.first].erase(bridge.second);
        adj[bridge.second].erase(bridge.first);
    }

    stack<int> s;
    s.push(0);
    set<int> visited;
    while(!s.empty()){
        int cur = s.top();
        s.pop();

        if(visited.find(cur) != visited.end()){
            continue;
        }
        visited.insert(cur);

        for(auto neighbor: adj[cur]){
            s.push(neighbor);
        }
    }

    cout << visited.size() << endl;

}