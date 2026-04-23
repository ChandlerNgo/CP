#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

pair<ll,ll> solve(ll n){
    for(ll i = 1; i < n*n; i++){
        for(ll j = i; j < n*n; j++){
            if(j*j - i*i == n){
                // cout << i << " " << j << " ";
                return {i,j};
            }
        }
    }
    return {-1,-1};
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for(ll j = 1; j < 1000; j++){
        set<ll> numbers;
        ll n = j;
        // cin >> n;
        bool found = false;
        for(ll i = 1; i <= (n/2)+1; i++){
            numbers.insert(i*i);
    
            ll b = (i*i)-n;
    
    
            if(sqrt(b) * sqrt(b) == b && numbers.find(b) != numbers.end()){
                found = true;
                pair<ll,ll> val = solve(j);
                if(val.first != sqrt(b) || val.second != i){
                    cout << j << " " << sqrt(b) << " " << i << " " << val.first << " " << val.second << endl;
                }
                // cout << sqrt(b) << " " << i << endl;
                break;
            }
        }
        if(!found){
            pair<ll,ll> val = solve(j);
            if(val.first != -1 || val.second != -1){
                cout << j << " " << "impossible" << " " << val.first << " " << val.second << endl;
            }
            // cout << "impossible" << endl;
        }
    }
}