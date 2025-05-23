#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

template<typename T>
struct Tree {
    static constexpr T base = 0;
    vector<T> v;
    int n, size;
    T comb(T a, T b) { //change this when doing maximum vs minimum etc.
        return a + b;
    }
    Tree(int n = 0, T def = base) {
        this->n = n; //max number of elements
        size = 1;
        while(size < n) size *= 2;
        v.assign(size * 2, def);
    }
    void update(int pos, T val) { //update 0 indexed, assignment
        assert(pos < n && pos >= 0);
        int curr = pos + size;
        v[curr] = val;
        while(curr != 1) {
            if(curr & 1) { //handles non-communative operations
                v[curr / 2] = comb(v[curr ^ 1], v[curr]);
            } else {
                v[curr / 2] = comb(v[curr], v[curr ^ 1]);
            }
            curr /= 2;
        }
    }
    T at(int idx) {
        assert(idx >= 0 && idx < n);
        return v[idx + size];
    }
    T query(int l, int r) {//queries in range [l,r)
        return _query(1,0,size,l,r);
    }
    T _query(int idx, int currl, int currr, int &targetl, int &targetr) {
        if(currr <= targetl || currl >= targetr) return base;
        if(currl >= targetl && currr <= targetr) return v[idx];
        int mid = (currl + currr) / 2;
        return comb(
            _query(idx * 2, currl, mid, targetl, targetr),
            _query(idx * 2 + 1, mid, currr, targetl, targetr)
        );
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, queries;
    cin >> n >> queries;
    
    vector<ll> gemValues(7,0);
    vector<Tree<ll>> trees(7);

    for(ll i = 1; i <= 6; i++){
        ll val;
        cin >> val;
        gemValues[i] = val;
        trees[i] = Tree<ll>(n+1,0);
    }

    string s;
    cin >> s;
    for(ll i = 0; i < s.size(); i++){
        trees[s[i]-'0'].update(i+1,1);
    }

    for(ll i = 0; i < queries; i++){
        ll action;
        cin >> action;
        if(action == 1){
            ll index;
            ll newType;
            cin >> index >> newType;
            for(ll j = 1; j <= 6; j++){
                trees[j].update(index,0);
            }
            trees[newType].update(index,1);
        }else if(action == 2){
            ll type;
            ll val;
            cin >> type >> val;
            gemValues[type] = val;
        }else{
            ll l;
            ll r;
            cin >> l >> r;
            ll curSum = 0;
            for(ll j = 1; j <= 6; j++){
                curSum += (gemValues[j] * trees[j].query(l,r+1));
            }
            cout << curSum << endl;
        }
    }
}