#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        vector<ll> numbers;
        for(ll i = 0; i < n; i++){
            ll num;
            cin >> num;
            numbers.push_back(num);
        }

        if(n == 1){
            cout << 1 << endl;
            continue;
        }

        if(n % 2 == 1){
            ll minDistance = LONG_LONG_MAX;
            for(ll skip = 0; skip < n; skip += 2){
                ll cur = 0;
                for(ll i = 0; i < n; i += 2){
                    if(i == skip){
                        i += 1;
                    }
                    if(i >= n){
                        break;
                    }
                    cur = max(cur, numbers[i+1] - numbers[i]);
                }
                minDistance = min(minDistance, cur);
            }
            cout << minDistance << endl;
        }else{
            ll maxDistance = 0;
            for(ll i = 0; i < n; i += 2){
                maxDistance = max(maxDistance, numbers[i+1] - numbers[i]);
            }
            cout << maxDistance << endl;
        }
    }
}