#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll p; ll k;
    cin >> p >> k;
    vector<ll> characters;
    for(ll i = 0; i < p; i++){
        characters.push_back(i);
    }
    vector<pair<ll,ll>> legs;
    for(ll i = 0; i < k; i++){
        ll loc; ll depth;
        cin >> loc >> depth;
        legs.push_back({depth,loc});
    }
    sort(legs.begin(),legs.end());

    for(ll i = k-1; i >= 0; i--){
        ll temp = characters[legs[i].second];
        characters[legs[i].second] = characters[legs[i].second+1];
        characters[legs[i].second+1] = temp;
    }

    for(ll i = 0; i < p; i++){
        cout << characters[i];
        if(i != p-1){
            cout << " ";
        }
    }
    cout << endl;
}