#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    vector<pair<ll,ll>> deals; // watermelons : price
    for(int x = 0; x < 20; x++){
        deals.push_back({pow(3,x), pow(3,x+1) + x*pow(3,x-1)});
    }
    while(t--){
        int n;
        int k;
        cin >> n >> k;
        
        ll cost = 0;
        int dealCount = 0;
        vector<int> currentDeals(20);

        for(int i = 19; i >= 0; i--){
            if(deals[i].first <= n){
                int amount = n/deals[i].first;
                dealCount += amount;
                n -= deals[i].first * amount;
                currentDeals[i] = amount;
            }
        }
        if(dealCount > k){ // ternary representation of the watermelons is the minimum config
            cout << -1 << "\n";
            continue;
        }

        int dealIndex = 19;
        while(dealCount < k && dealIndex >= 1){
            if(currentDeals[dealIndex] > 0){
                // convert the most deals to lower watermelon counts aka 1 3watermelon deal to 3 1 watermelon deal
                int availableDeals = k-dealCount;
                int conversions = min(availableDeals/2, currentDeals[dealIndex]);
                // each conversion increases deals by +2

                dealCount += (2*conversions);
                currentDeals[dealIndex] -= conversions;
                currentDeals[dealIndex-1] += (3*conversions);
            }
            dealIndex -= 1;
        }

        for(int i = 0; i < 20; i++){
            cost += currentDeals[i] * deals[i].second;
        }
        cout << cost << "\n";
    }
}