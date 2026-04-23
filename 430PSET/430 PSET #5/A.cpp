#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

bool comparePairs(const pair<size_t, size_t>& a, const pair<size_t, size_t>& b) {
    // Sort by first element in ascending order, then by second element in ascending order
    if (a.second != b.second) {
        return a.second < b.second;
    } else {
        return a.first < b.first;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int l; int r;
    vector<pair<int,int>> minionTemps;
    for(int i = 0; i < n; i++){
        cin >> l >> r;
        minionTemps.push_back({l,r});
    }
    sort(minionTemps.begin(),minionTemps.end(),comparePairs);

    int currentLoc = minionTemps[0].second;
    int groups = 1;
    for(int i = 1; i < n; i++){
        if(currentLoc < minionTemps[i].first){
            groups += 1;
            currentLoc = minionTemps[i].second;
        }
    }
    cout << groups << endl;
}