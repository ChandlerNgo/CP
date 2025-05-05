#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
const int MOD = 1e9 + 7;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    vector<ll> fib;
    fib.push_back(1);
    fib.push_back(2);
    for(ll i = 2; i <= 10000; i++){
        fib.push_back(fib[i-1]+fib[i-2] % (MOD));
    }
    while(t--){
        ll n;
        cin >> n;
        cout << fib[n] % (MOD)<< endl;
    }
}