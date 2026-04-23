#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

struct State{
    int cat;
    int traveled;
};

struct Compare{
    bool operator()(State a, State b){

        return (a.traveled > b.traveled);
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    while(t--){
        int m;
        int c;
        cin >> m >> c;
        map<int,set<pair<int,int>>> adj;

        map<int,int> minTravelingDistance;
        map<int,int> minTravelingDistance2;
        for(int i = 0; i < (c*(c-1))/2; i++){
            int a;
            int b;
            int c;
            cin >> a >> b >> c;
            adj[a].insert({b,c+1});
            minTravelingDistance[a] = INT_MAX;
            minTravelingDistance[b] = INT_MAX;
            minTravelingDistance2[a] = INT_MAX;
            minTravelingDistance2[b] = INT_MAX;
        }

        set<int> visited;

        priority_queue<State,vector<State>, Compare> q;
        q.push({0,0});

        while(!q.empty()){
            State cur = q.top();
            q.pop();

            if(visited.find(cur.cat) != visited.end()){
                continue;
            }
            visited.insert(cur.cat);


            minTravelingDistance2[cur.cat] = min(minTravelingDistance2[cur.cat], cur.traveled);
            minTravelingDistance[cur.cat] = min(minTravelingDistance[cur.cat], cur.traveled);

            for(auto catPath : adj[cur.cat]){
                if(catPath.second < minTravelingDistance[catPath.first]){
                    q.push({catPath.first, cur.traveled + catPath.second});
                    minTravelingDistance[catPath.first] = catPath.second;
                }
            }
        }

        int catNeeds = 0;
        for(auto x : minTravelingDistance){
            catNeeds += x.second;
        }
        // catNeeds += c;

        if(catNeeds < m){
            cout << "yes" << endl;
        }else{
            cout << "no" << endl;
        }
    }
}