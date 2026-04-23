#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

struct Spiderman{
    ll total = 1e9;
    string path = "";
    ll maxHeight = 1e9;

    void print(){
        cout << total << " " << path << " " << maxHeight << endl;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        vector<ll> numbers(n+1,0);
        for(ll i = 1; i <= n; i++){
            ll num;
            cin >> num;
            numbers[i] = num;
        }

        vector<vector<Spiderman>> dp(n+1, vector<Spiderman>(1001,Spiderman())); // i: index, j: height

        dp[0][0] = {0,"",0};

        for(ll i = 0; i < n; i++){
            for(ll j = 0; j < 1001; j++){

                if(dp[i][j].total == 1e9 || dp[i][j].maxHeight == 1e9){
                    continue;
                }
                ll newUp = j+numbers[i+1];
                ll newDown = j-numbers[i+1];

                Spiderman up = Spiderman();
                Spiderman down = Spiderman();

                if(newUp < 1001){
                    up = dp[i][j];
                    up.total += numbers[i+1];
                    up.maxHeight = max(up.maxHeight,up.total);
                    up.path += "U";
                    if(up.maxHeight < dp[i+1][newUp].maxHeight){
                        dp[i+1][newUp] = up;
                        // cout << i+1 << " " << newUp << ": ";
                        // dp[i+1][newUp].print();
                    }
                }
                
                if(newDown >= 0){
                    down = dp[i][j];
                    down.total -= numbers[i+1];
                    down.path += "D";
                    if(down.total < 0){
                        down = Spiderman();
                    }
                    if(down.maxHeight < dp[i+1][newDown].maxHeight){
                        dp[i+1][newDown] = down;
                        // cout << i+1 << " " << newDown << ": ";
                        // dp[i+1][newDown].print();
                    }
                }

                // cout << i << " " << j << ": ";
                // dp[i][j].print();             
            }
        }
        cout << ((dp[n][0].path == "") ? "IMPOSSIBLE" : dp[n][0].path) << endl;
    }
}