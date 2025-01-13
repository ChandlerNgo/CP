#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll t;
    cin >> t;
    for(int m = 0; m < t; m++){
        ll n;
        ll q;
        cin >> n >> q;
        vector<ll> prefixSum;
        ll sum = 0;
        prefixSum.push_back(0);
        for(ll i = 0; i < n; i++){
            ll num;
            cin >> num;
            sum += num;
            prefixSum.push_back(sum);
        }

        for(ll i = 0; i < q; i++){
            ll l;
            ll r;
            ll k;
            cin >> l >> r >> k;

            // 
            ll currentSum = (r-l+1)*k;
            
            currentSum -= prefixSum[r] + prefixSum[l-1];
            if((prefixSum[prefixSum.size()-1] + currentSum) % 2 == 0){
                cout << "NO" << endl;
            }else{
                cout << "YES" << endl;
            }
        }
    }

}