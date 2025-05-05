#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

pair<ll,pair<ll,ll>> extended_gcd(ll a, ll b){
    if(b == 0){
        return {a,{1,0}};
    }
    pair<ll,pair<ll,ll>> current = extended_gcd(b, a % b);
    ll gcd = current.first;
    ll x1 = current.second.first;
    ll y1 = current.second.second;

    ll x = y1;
    ll y = x1 - (a/b) * y1;
    return {gcd,{x,y}};
}

ll mod_inverse(ll a, ll m){
    pair<ll,pair<ll,ll>> current = extended_gcd(a,m);
    ll gcd = current.first;
    ll x = current.second.first;
    if(gcd != 1){
        return -1;
    }
    return (x % m + m) % m;
}