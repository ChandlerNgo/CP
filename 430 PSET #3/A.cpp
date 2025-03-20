#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

class AlmostUnionFind{
    private:
        vector<ll> parent;
        vector<vector<ll>> elements;
        vector<ll> setSize;
        vector<ll> setSum;

    public:
        AlmostUnionFind(ll N) : parent(N+1), elements(N+1), setSum(N+1), setSize(N+1) {
            for(ll i = 0; i <= N; ++i){
                parent[i] = i;
                setSum[i] = i;
                setSize[i] = 1;
                elements[i] = vector<ll>({i});
            }
        }

        void unionSet(ll a, ll b){
            ll leaderA = parent[a];
            ll leaderB = parent[b];
            // cout << a << " " << b << " before union" << endl;
            if(leaderA != leaderB){
                if(getSetSize(leaderA) >= getSetSize(leaderB)){
                    // cout << "part 1" << endl;
                    for(ll i = 0; i < elements[leaderB].size(); i++){
                        elements[leaderA].push_back(elements[leaderB][i]);
                        parent[elements[leaderB][i]] = leaderA;
                    }
                    setSize[leaderA] += setSize[leaderB];
                    setSize[leaderB] = 0;
                    setSum[leaderA] += setSum[leaderB];
                    setSum[leaderB] = 0;
                    elements[leaderB].clear();
                    // cout << "part 2" << endl;
                }else{
                    for(ll i = 0; i < elements[leaderA].size(); i++){
                        elements[leaderB].push_back(elements[leaderA][i]);
                        parent[elements[leaderA][i]] = leaderB;
                    }
                    setSize[leaderB] += setSize[leaderA];
                    setSize[leaderA] = 0;
                    setSum[leaderB] += setSum[leaderA];
                    setSum[leaderA] = 0;
                    elements[leaderA].clear();
                }
            }

            // cout << "unionSet";
            // for (size_t i = 0; i < elements.size(); i++) {
            //     cout << i << ": " << endl;
            //     for (size_t j = 0; j < elements[i].size(); j++) {
            //         cout << elements[i][j] << " ";
            //     }
            //     cout << endl;
            // }
            // cout << a << " " << b << " union" << endl;
        }

        void moveSet(ll a, ll b){
            // cout << a << " " << b << " before move" << endl;
            ll leaderA = parent[a];
            ll leaderB = parent[b];
            if(a != b){
                elements[leaderA].erase(find(elements[leaderA].begin(), elements[leaderA].end(), a));
                setSum[leaderA] -= a;
                setSize[leaderA] -= 1;
                parent[a] = leaderB;
                elements[leaderB].push_back(a);
                setSum[leaderB] += a;
                setSize[leaderB] += 1;
            }
            // cout << "moveSet";
            // for (size_t i = 0; i < elements.size(); i++) {
            //     cout << i << ": " << endl;
            //     for (size_t j = 0; j < elements[i].size(); j++) {
            //         cout << elements[i][j] << " ";
            //     }
            //     cout << endl;
            // }
            // cout << a << " " << b << " move" << endl;
        }

        ll getSetSum(ll a){
            return setSum[parent[a]];
        }

        ll getSetSize(ll a){
            return setSize[parent[a]];
        }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    ll m;
    while(cin >> n >> m){
        AlmostUnionFind uf = AlmostUnionFind(n);
        for(ll i = 0; i < m; i++){
            ll action;
            cin >> action;
            if(action == 1){
                ll a;
                ll b;
                cin >> a >> b;
                uf.unionSet(a,b);
            }else if(action == 2){
                ll a;
                ll b;
                cin >> a >> b;
                uf.moveSet(a,b);
            }else{
                ll a;
                cin >> a;
                cout << uf.getSetSize(a) << " " << uf.getSetSum(a) << endl;
            }
        }
    }
}