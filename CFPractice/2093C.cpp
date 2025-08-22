#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

vector<ll> primeFactors(ll n) {
    vector<ll> factors;
    while (n % 2 == 0) {
        factors.push_back(2);
        n /= 2;
    }
    for (ll i = 3; i <= sqrt(n); i += 2) {
        while (n % i == 0) {
            factors.push_back(i);
            n /= i;
        }
    }
    if (n > 2) {
        factors.push_back(n);
    }
    return factors;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        ll n;
        ll k;
        cin >> n >> k;
        if(n == 1 && k == 2){
            cout << "YES\n";
            continue;
        }

        if(k == 1){
            vector<ll> primes = primeFactors(n);
            if(primes.size() == 1){
                cout << "YES\n";
            }else{
                cout << "NO\n";
            }
        }else{
            cout << "NO\n";
        }
    }
}