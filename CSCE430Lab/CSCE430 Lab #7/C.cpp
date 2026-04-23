#include <bits/stdc++.h>

#include <iostream>
#define ll long long
#define pii pair<int, int>

using namespace std;

constexpr int INF = 1e9;
constexpr int MOD = 1e9 + 7;

void setIO(string name = "") {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

int main() {
    setIO();

    int n;
    cin >> n;
    vector<ll> price(n);
    for (int i = 0; i < n; i++) {
        cin >> price[i];
    }

    price.push_back(0);

    ll cash = 100ll;
    ll shares = 0ll;

    for (int i = 0; i < n; i++) {
        cout << shares << " " << cash << endl;
        if (price[i] < price[i + 1]) {  // buy
            shares = min(100000ll, (cash / price[i]));
            cout << "buy: " << i << " shares bought: " << shares << " " << min(100000ll, cash/price[i]) << endl;
            cash -= (shares * price[i]);
        } else {
            cash += (shares * price[i]);
            cout << "sell: " << i << " shares sold: " << shares << " " << shares * price[i] << endl;
            shares = 0ll;
        }
    }

    cout << shares << endl;

    cout << cash + (shares*price[n-1]) << endl;
}