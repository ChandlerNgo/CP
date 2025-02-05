#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        ll badness = 0;
        vector<ll> scores(n+1,0);
        for(ll i = 1; i <= n; i++){
            string teamname;
            ll score;
            cin >> teamname >> score;
            scores[i] = score;
        }

        sort(scores.begin(),scores.end());
        for(ll i = 1; i <= n; i++){
            badness += abs(scores[i]-i);
        }
        cout << badness << endl;
    }
}