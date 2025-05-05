#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll s; // socks
    ll c; // capacity
    ll k; // color dif
    cin >> s >> c >> k;
    vector<ll> socks(s,0);
    for(ll i = 0; i < s; i++){
        cin >> socks[i];
    }
    sort(socks.begin(),socks.end());

    ll l = 0;
    ll r = 0;
    ll washes = 0;
    while(l < s && r < s){
        if(abs(socks[r]-socks[l]) <= k && ((abs(r-l)) < c)){
            r += 1;
        }else{
            l = r;
            washes += 1;
        }
    }
    if(l != r){
        washes += 1;
    }
    cout << washes << endl;
}