#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

ll round(ll val){
    if(val % 10 == 0){
        return val;
    }else{
        return val+10 - (val%10);
    }
}

class DisjointSet {
    private:
        vector<int> parent;
        vector<int> setSize;
        vector<int> setSum;

    public:
        DisjointSet(ll N) : parent(N), setSize(N), setSum(N) {
            for (ll i = 0; i < N; ++i) {
                parent[i] = i;
                setSize[i] = 1;
                setSum[i] = i;
            }
        }

        ll find(ll i) {
            if (parent[i] == i)
                return i;
            return parent[i] = find(parent[i]);
        }

        void merge(ll a, ll b) {
            a = find(a);
            b = find(b);

            if (a != b) {
                parent[b] = a;
                setSize[a] += setSize[b];
                setSum[a] += setSum[b];
            }
        }

        ll getSetSize(ll a) {
            return setSize[find(a)];
        }

        ll getSetSum(ll a) {
            return setSum[find(a)];
        }

        void setSetSum(ll i, ll val) {
            setSum[i] = val;
        }

        void print() {
        cout << "Index:    ";
        for (size_t i = 0; i < parent.size(); ++i)
            cout << i << " ";
        cout << "\nParent:   ";
        for (int p : parent)
            cout << p << " ";
        cout << "\nSet Size: ";
        for (int s : setSize)
            cout << s << " ";
        cout << "\nSet Sum:  ";
        for (int sum : setSum)
            cout << sum << " ";
        cout << endl;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //! convert to ll
    ll n;
    cin >> n;
    ll trainSegments = 1;
    ll totalChaos = 0;
    vector<ll> coaches(n+1);
    vector<ll> bombs(n+1);
    DisjointSet uf = DisjointSet(n+1);
    for(ll i = 1; i <= n; i++){
        ll coach;
        cin >> coach;
        coaches[i] = coach;
        uf.setSetSum(i, coach);
    }
    for(ll i = 1; i <= n; i++){
        ll bomb;
        cin >> bomb;
        bombs[i] = bomb;
    }

    set<ll> currentLeaders = {bombs[bombs.size()-1]};
    ll currentSum = 0;
    for(ll i = bombs.size()-1; i >= 1; i--){
        // if((bombs[i]+1 > n || currentLeaders.find(uf.find(bombs[i]+1)) == currentLeaders.end()) && (bombs[i]-1 > n || currentLeaders.find(uf.find(bombs[i]-1)) == currentLeaders.end())){
        //     currentSum += round(total);
        // }
        ll right = 0;
        ll left = 0;
        currentLeaders.insert(uf.find(bombs[i]));
        if(bombs[i]+1 <= n && currentLeaders.find(uf.find(bombs[i]+1)) != currentLeaders.end()){
            right = uf.getSetSum(uf.find(bombs[i]+1));
            currentLeaders.erase(uf.find(bombs[i]+1));
            uf.merge(uf.find(bombs[i]),uf.find(bombs[i]+1));
        }
        if(bombs[i]-1 >= 0 && currentLeaders.find(uf.find(bombs[i]-1)) != currentLeaders.end()){
            left = uf.getSetSum(uf.find(bombs[i]-1));
            currentLeaders.erase(uf.find(bombs[i]-1));
            uf.merge(uf.find(bombs[i]),uf.find(bombs[i]-1));
        }
        ll rightRound = round(right);
        ll leftRound = round(left);

        ll total = uf.getSetSum(uf.find(bombs[i]));
        // cout << "coaches[i]: " << coaches[i] << endl;
        // cout << "currentSum: " << currentSum << endl;
        // cout << "left+right: " << leftRound+rightRound << endl;
        currentSum = round(currentSum-rightRound-leftRound+total);

        // uf.print();
        // cout << "currentSum: " << currentSum << endl;
        // cout << "left: " << left << endl;
        // cout << "leftRound: " << leftRound << endl;
        // cout << "right: " << right << endl;
        // cout << "rightRound: " << rightRound << endl;
        // cout << "currentLeaders.size(): " << currentLeaders.size() << endl;
        // cout << endl;

        // cout << "Coach: ";
        totalChaos = max(static_cast<unsigned long long>(totalChaos), currentSum*currentLeaders.size());
        // cout << endl;
        // cout << "Total: " << total << endl << endl;
        
    }

    cout << totalChaos << endl;
}

// iterate through bombs backwards, each train that gets revived is their own set.