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
        ll k;
        cin >> n >> k;
        priority_queue<ll> machines;
        for(ll j = 0; j < n; j++){
            ll num;
            cin >> num;
            machines.push(-1 * num);
        }

        ll cansCollected = 0;
        ll buttonsPressed = 0;
        ll diff = 0;
        while(cansCollected < k){
            while(!machines.empty() && (-1*machines.top())-diff == 0){
                machines.pop();
                buttonsPressed += 1;
            }
            ll additionalPresses = ((-1 * machines.top()) - diff) * machines.size();
            if(cansCollected + additionalPresses >= k){
                additionalPresses = min(k-cansCollected,additionalPresses);
            }
            buttonsPressed += additionalPresses;
            cansCollected += additionalPresses;
            diff = -1*machines.top();
        }

        cout << buttonsPressed << endl;
    }
}