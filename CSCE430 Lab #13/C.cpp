#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

map<ll,ll> primeFactors(ll n) {
    map<ll,ll> factors;
    while (n % 2 == 0) {
        factors[2] += 1;
        n /= 2;
    }
    for (ll i = 3; i <= sqrt(n); i += 2) {
        while (n % i == 0) {
            factors[i] += 1;
            n /= i;
        }
    }
    if (n > 2) {
        factors[n] += 1;
    }
    return factors;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    ll m;
    while(cin >> n >> m){
            map<ll,ll> factors = primeFactors(m);
            bool possible = true;
            for(auto x : factors){
                ll prime = x.first;
                ll amount = x.second;
                
                ll maxAmount = 0;
                ll val = prime;
                for(ll i = 1; i < 33; i++){
                    if(val > n){
                        break;
                    }
                    maxAmount += (n/prime);
                    val *= prime;
                }

                
                if(maxAmount < amount){
                    possible = false;
                    break;
                }
                
            }
            if(!possible){
                cout << m << " does not divide " << n << "!" << endl;
            }else{
                cout << m << " divides " << n << "!" << endl;
            }
    }
}
