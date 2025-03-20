#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    set<int> provedNumbers;
    map<int,set<int>> adj;
    for(int i = 1; i <= n; i++){
        int amt;
        cin >> amt;
        for(int j = 1; j <= amt; j++){
            int m;
            cin >> m;
            if(adj.find(m) == adj.end()){
                adj[m] = set<int>();
            }
            adj[m].insert(i);
        }
    }

    set<int> visited;
    vector<string> answer;
    set<pair<int,int>> pairs;

    for(auto pair: adj){ // O(200000)
        // pair.first == connection
        // pair.second == set of connected numbers

        if(pair.second.size() <= 1){
            continue;
        }

        int val = -1;

        for(auto x: pair.second){
            if(val == -1){
                val = x;
                visited.insert(val);
            }else{
                if(visited.find(x) == visited.end()){
                    stringstream s;
                    int a = x;
                    int b = val;
                    if(val < x){
                        a = val; b = x;
                    }
                    if(pairs.find({a,b}) == pairs.end()){
                        s << val << ' ' << x << ' ' << pair.first << '\n';
                        // cout << val << ' ' << x << ' ' << pair.first << endl;
                        answer.push_back(s.str());
                        visited.insert(val);
                        pairs.insert({a,b});
                    }
                }
            }
        }
    }

    
    for(auto s : answer){
        cout << s;
    }

    if(answer.size() == n-1){
        for(auto s : answer){
            cout << s;
        }
    }else{
        cout << "impossible" << endl;
    }
}