#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll t;
    cin >> t;

    for(ll i = 0; i < t; i++){
        ll n;
        cin >> n;
        priority_queue <ll, vector<ll>, greater<ll>> pq;
 
        for (ll j = 0; j < n; j++) {
            ll num;
            cin >> num;
            pq.push(num);
        }

        while(pq.size() >= 2){
            ll first = pq.top();
            pq.pop();
            ll second = pq.top();
            pq.pop();
            pq.push((first+second)/2);
        }

        cout << pq.top() << endl;
    }
}