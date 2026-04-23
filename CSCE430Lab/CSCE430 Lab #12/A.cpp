#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    ll t;
    cin >> n >> t;

    vector<ll> people(n,-1);

    for(ll i = 0; i < n; i++){
        ll a;
        ll b;
        cin >> a >> b;
        people[i] = a;
    }

    vector<vector<ll>> dp(t,vector<ll>(2,0));

    dp[0][0] = people[0];
    for(int i = 1; i < n; i++){
        dp[i][1] = max(dp[i-1][0],dp[i-1][1]);
        dp[i][0] = max(dp[i-1][0],dp[i-1][1]) + people[i];
    }

    cout << max(dp[n-1][1],dp[n-1][0]) << endl;
}