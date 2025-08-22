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