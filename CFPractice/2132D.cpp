#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

ll sumOfDigitsFrom1ToNUtil(ll n, vector<ll> &a) {
    if (n < 10)
        return (n * (n + 1) / 2);

    ll d = (ll)(log10(n));
    ll p = (ll)(ceil(pow(10, d)));
    ll msd = n / p;

    return (msd * a[d] + (msd * (msd - 1) / 2) * p 
            + msd * (1 + n % p) + sumOfDigitsFrom1ToNUtil(n % p, a));
}

// Function to computer sum of digits in
// numbers from 1 to n
ll sumOfDigits(ll n) {
    ll d = max(((ll)(log10(n))), (ll)1);
    vector<ll> a(d + 1);
    a[0] = 0;
    a[1] = 45;

    for (ll i = 2; i <= d; i++)
        a[i] = a[i - 1] * 10 + 45 * (ll)(ceil(pow(10, i - 1)));

    return sumOfDigitsFrom1ToNUtil(n, a);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    vector<ll> numbers; // how many numbers each digit count has
    for(int i = -1; i < 16; i++){
        numbers.push_back(9*pow(10,i+1));
    }
    while(t--){
        ll n;
        cin >> n;
        // find digit count
        ll digits = 1;
        ll count = 9;
        ll base = 1;

        while(n > (digits*count)){
            n -= (digits*count);
            count *= 10;
            base *= 10;
            digits += 1;
        }

        ll number = base + (n-1)/digits;
        ll index = (n-1) % digits;
        ll total = sumOfDigits(number-1);
        string s = to_string(number);
        for(int i = 0; i <= index; i++){
            total += (s[i]-'0');
        }
        cout << total << "\n";
    }
}