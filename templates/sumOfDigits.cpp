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