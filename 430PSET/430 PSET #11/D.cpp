#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

const int INF = INT_MAX;

struct HopcroftKarp{
    int n;
    int m;
    vector<vector<int>> adj;
    vector<int> pairU, pairV, dist;

    HopcroftKarp(int n, int m) : n(n), m(m), adj(n), pairU(n,-1), pairV(n, -1), dist(n){}

    void add_edge(int u, int v){
        adj[u].push_back(v);
    }

    bool bfs(){
        queue<int> q;
        for(int u = 0; u < n; u++){
            if(pairU[u] == -1){
                dist[u] = 0;
                q.push(u);
            }else{
                dist[u] = INF;
            }
        }

        bool found = false;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            for(int v : adj[u]){
                if(pairV[v] == -1){
                    found = true;
                }else if(dist[pairV[v]] == INF){
                    dist[pairV[v]] = dist[u] + 1;
                    q.push(pairV[v]);
                }
            }
        }
        return found;
    }

    bool dfs(int u){
        for(int v : adj[u]){
            if(pairV[v] == -1 || (dist[pairV[v]] == dist[u] + 1 && dfs(pairV[v]))){
                pairU[u] = v;
                pairV[v] = u;
                return true;
            }
        }

        dist[u] = INF;
        return false;
    }

    int max_matching(){
        int matching = 0;
        while(bfs()){
            for(int u = 0; u < n; u++){
                if(pairU[u] == -1 && dfs(u)){
                    matching += 1;
                }
            }
        }
        return matching;
    }

    vector<pair<int,int>> get_matching_pairs(){
        vector<pair<int,int>> pairs;

        for(int u = 0; u < n; u++){
            if(pairU[u] != -1){
                pairs.push_back({u,pairU[u]});
            }
        }
        return pairs;
    }
};

int main(){

    int n,m,s,v;
    while(cin >> n >> m >> s >> v){
        vector<pair<double,double>> gophers, holes;
        for(int i = 0; i < n; i++){
            double x;
            double y;
            cin >> x >> y;
            gophers.push_back({x,y});
        }
    
        for(int i = 0; i < m; i++){
            double x;
            double y;
            cin >> x >> y;
            holes.push_back({x,y});
        }
    
        HopcroftKarp hopcraft(n,m);
    
        double maxDistance = s*v;
        for(int i = 0; i < gophers.size(); i++){
            pair<double,double> gopher = gophers[i];
            for(int j = 0; j < holes.size(); j++){
                pair<double,double> hole = holes[j];
                if(sqrt(pow(gopher.first-hole.first,2) + pow(gopher.second-hole.second,2)) <= maxDistance){
                    hopcraft.add_edge(i,j);
                }
            }
        }
    
        cout << n - hopcraft.max_matching() << endl;
    }
}