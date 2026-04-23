#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

bool comparePairs(const pair<ll, ll>& a, const pair<ll, ll>& b) {
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
    ll n; ll k;
    cin >> n >> k;
    ll l; ll r;
    vector<pair<ll,ll>> activities;
    map<ll,ll> classrooms;
    classrooms[0] = k;
    for(ll i = 0; i < n; i++){
        cin >> l >> r;
        activities.push_back({l,r});
    }
    sort(activities.begin(),activities.end(),comparePairs);

    ll scheduled = 0;

    for(ll i = 0; i < n; i++){
        auto it = classrooms.lower_bound(activities[i].first);
        if(it == classrooms.begin()){
            continue;
        }
        it--;
        if(it->first < activities[i].first){
            classrooms[it->first] -= 1;
            if(classrooms[it->first] == 0){
                classrooms.erase(it->first);
            }

            classrooms[activities[i].second] += 1;
            scheduled += 1;
        }
        
    }
    cout << scheduled << endl;
}