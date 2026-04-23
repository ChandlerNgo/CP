#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

int main() {
    ll n, t, a, b, c, p, s, i, t_p;
    vector<ll> ti(n,INT_MAX);

    cin >> n >> t >> a >> b >> c >> ti[0];

    for (i = 1; i < n; i++)
        ti[i] = (a * ti[i-1] + b) % c + 1;

    sort(ti.begin(), ti.end());

    p = 0;
    s = 0;
    t_p = 0;
    for (i = 0; i < n; i++) {
        if (t_p + ti[i] <= t) {
        t_p += ti[i];
            p = (p + t_p) % 1000000007;
            s++;
        } else {
            break;
        }
    }

    cout << s << " " << p << endl;
    return 0;
}