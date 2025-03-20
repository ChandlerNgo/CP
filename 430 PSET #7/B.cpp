#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

void solve(){
    ll n;
    cin >> n;
    ll left = 1;
    ll right = n;
    ll searches = 0;
    while(left < right){
        ll portion_size = (right - left) / 3;
        ll leftmiddle = left + portion_size;
        ll rightmiddle = right - portion_size;

        cout << 'Q' << " " << left << " " << leftmiddle << " " << rightmiddle << " " << right << endl;

        pair<ll,ll> results = {};

        cin >> results.first >> results.second;

        if(left == leftmiddle && results.first == 1){
            cout << "A " << left << endl;
            break;
        }

        if(right == rightmiddle && results.second == 1){
            cout << "A " << right << endl;
            break;
        }

        if (results.first == 1 && results.second == 0) {
            right = leftmiddle;
            left = max(1LL, left - 1);
        } 
        else if (results.first == 0 && results.second == 1) {
            left = rightmiddle;
            right = min(n, right + 1);
        } 
        else {
            left = leftmiddle + 1;
            right = rightmiddle - 1;
        }
    }
    
    // if(answer != left){
    //     cout << "N: " << n << " " << answer << " " << left << endl;
    // }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    // solve(1000000000,1);
    // solve(2,2);
    
    // for(ll i = 1; i <= 100000; i++){
    //     for(ll j = 1; j <= i; j++){
    //         solve(i,j);
    //     }
    //     if(i % 1000 == 0){
    //         cout << i << endl;
    //     }
    // }
}