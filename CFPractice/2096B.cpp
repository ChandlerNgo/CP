#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while(t--){
        ll n;
        ll k;
        cin >> n >> k;
        vector<ll> leftGloves;
        vector<ll> rightGloves;
        for(ll i = 0; i < n; i++){
            ll left; cin >> left;
            leftGloves.push_back(left);
        }
        for(ll i = 0; i < n; i++){
            ll right; cin >> right;
            rightGloves.push_back(right);
        }
        ll pulls = 1; // last pull
        priority_queue<ll> pq;

        for(ll i = 0; i < n; i++){
            if(leftGloves[i] < rightGloves[i]){
                pq.push(leftGloves[i]);
                pulls += rightGloves[i];
            }else{
                pq.push(rightGloves[i]);
                pulls += leftGloves[i];
            }
        }

        for(ll i = 0; i < k-1; i++){
            pulls += pq.top();
            pq.pop();
        }
        cout << pulls << "\n";
    }
}