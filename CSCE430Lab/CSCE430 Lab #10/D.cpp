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

    ll nums = 9;

    for (ll i = 1; i < n; i++) {
        nums *= 10;
        nums /= (i + 1);
    }

    cout << nums << endl;
}