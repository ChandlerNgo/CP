#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
const ll MOD = 1e9 + 7;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    int t;
    cin >> n >> t;

    ll t0;
    ll a;
    ll b;
    ll c;
    cin >> a >> b >> c >> t0;

    vector<ll> times(n, INT_MAX);
    times[0] = t0;
    for(int i = 1; i < n; i++){
        times[i] = ((a * times[i-1] + b) % c) + 1;
    }
    sort(times.begin(), times.end());

    ll time_spent = 0;
    ll penalty = 0;
    ll solved = 0;

    for(int i = 0; i < n; i++){
        if(time_spent + times[i] <= t){
            penalty = (penalty + time_spent + times[i]) % MOD;
            time_spent += times[i];
            solved += 1;
        }else{
            break;
        }
    }

    cout << solved << " " << penalty << endl;
}