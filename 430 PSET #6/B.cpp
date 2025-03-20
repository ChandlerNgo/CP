#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n; ll k;
    cin >> n >> k;

    vector<pair<ll,ll>> gallery(n+1,{0,0});

    vector<vector<vector<ll>>> dp(n + 1, vector<vector<ll>>(k + 1, vector<ll>(3, -1e9))); // [n,k,(0,1,2 for none, left, right)]

    ll left;
    ll right;
    for(ll i = 1; i <= n; i++){
        cin >> left >> right;
        gallery[i] = {left,right};
    }

    cin >> left >> right;

    dp[0][0][0] = 0;

    for(ll i = 1; i <= n; i++){
        for(ll j = 0; j <= k; j++){
            // close no doors
            dp[i][j][0] = max({dp[i-1][j][0],dp[i-1][j][1],dp[i-1][j][2]}) + gallery[i].first + gallery[i].second;
            if(j > 0){
                // close left door
                dp[i][j][1] = max(dp[i-1][j-1][0],dp[i-1][j-1][1]) + gallery[i].second;
                // close right door
                dp[i][j][2] = max(dp[i-1][j-1][0],dp[i-1][j-1][2]) + gallery[i].first;
            }
        }
    }

    cout << max({dp[n][k][0],dp[n][k][1],dp[n][k][2]}) << endl;
}