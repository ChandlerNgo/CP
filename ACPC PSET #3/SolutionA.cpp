#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n;
    ll t;
    cin >> n >> t;
    vector<ll> prefixSum;
    ll sum = 0;
    prefixSum.push_back(-1);
    for(ll i = 0; i < n; i++){
        ll num;
        cin >> num;
        sum += num;
        prefixSum.push_back(sum);
    }

    for(ll i = 0; i < t; i++){
        ll a;
        ll b;
        cin >> a >> b;
        if(a == 1){
            cout << prefixSum[b] << endl;
        }else{
            cout << prefixSum[b] - prefixSum[a-1] << endl;
        }
    }
}