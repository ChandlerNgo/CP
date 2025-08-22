#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        
        vector<pair<ll,ll>> deals; // watermelons : price
        for(int x = 0; x < 20; x++){
            deals.push_back({pow(3,x), pow(3,x+1) + x*pow(3,x-1)});
        }

        ll cost = 0;

        for(int i = 19; i >= 0; i--){
            if(deals[i].first <= n){
                int amount = n/deals[i].first;
                n -= deals[i].first * amount;
                cost += amount*deals[i].second;
            }
        }
        cout << cost << "\n";
    }
}