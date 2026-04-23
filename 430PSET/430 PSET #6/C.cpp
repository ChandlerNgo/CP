#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    vector<vector<ll>> dp(n+1,vector<ll>(n+1,1e7)); // [index ,length of jump] = min cost

    vector<ll> costs(n+1,0);
    for(ll i = 1; i <= n; i++){
        ll num;
        cin >> num;
        costs[i] = num;
    }

    dp[1][1] = 0;

    for(ll j = 1; j <= n; j++){
        for(ll i = n; i >= 1; i--){
            // i = index
            // j = jump size
            // cout << "i j: " << i << " " << j << endl;
            if(dp[i][j] == 1e7){
                continue;
            }
            // jump back
            
            if((i-j+1) > 0){
                // cout << "i-j+1: " << i-j+1 << endl;
                // cout << "j: " << j << endl;
                dp[i-j+1][j] = min(dp[i-j+1][j], costs[i-j+1]+dp[i][j]);
            }
            
            // jump forward
            
            if((i+j) <= n){
                // cout << "i+j: " << i+j << endl;
                // cout << "j+1: " << j+1 << endl;
                dp[i+j][j+1] = min(dp[i+j][j+1], costs[i+j]+dp[i][j]);
            }
        }
    }

    ll answer = 1e7;

    for(ll i = 1; i <= n; i++){
        answer = min(answer,dp[n][i]);
    }
    cout << answer << endl;


    // for(ll j = n; j >= 1; j--){ // i = index
    //     for(ll i = 1; i <= n; i++){ // j = jump size
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;
}