#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

const int INF = 1e9;

struct Edge{
    int to, rev, cap;
};

struct MaxFlow{
    int n;
    vector<vector<Edge>> g;
    vector<int> level, iter;

    MaxFlow(int n): n(n), g(n), level(n,-1), iter(n,0){}

    void add_edge(int from, int to, int cap){
        g[from].push_back({to, (int)g[to].size(), cap});
        g[to].push_back({from, (int)g[from].size() - 1, 0});
    }

    void bfs(int s){
        for(int i = 0; i < level.size(); i++){
            level[i] = -1;
        }
        queue<int> q;
        level[s] = 0;
        q.push(s);
        while(!q.empty()){
            int v = q.front();
            q.pop();
            for(auto &e : g[v]){
                if(e.cap > 0 && level[e.to] < 0){
                    level[e.to] = level[v] + 1;
                    q.push(e.to);
                }
            }
        }
    }

    int dfs(int v, int t, int f){
        if(v == t){
            return f;
        }

        for(int &i = iter[v]; i < g[v].size(); i++){
            Edge &e = g[v][i];
            if(e.cap > 0 && level[v] < level[e.to]){
                int d = dfs(e.to, t, min(f, e.cap));
                if(d > 0){
                    e.cap -= d;
                    g[e.to][e.rev].cap += d;
                    return d;
                }
            }
        }
        return 0;
    }

    int max_flow(int s, int t){
        int flow = 0;
        while(true){
            bfs(s);
            if(level[t] < 0){
                break;
            }
            for(int i = 0; i < iter.size(); i++){
                iter[i] = 0;
            }
            int f;
            while((f = dfs(s, t, INF)) > 0){
                flow += f;
            }
        }
        return flow;
    }
};