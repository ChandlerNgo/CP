#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

struct Val{
    ll sum1;
    ll sum2;
    ll i;
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    vector<ll> numbers(n,0);
    for(ll i = 0; i < n; i++){
        cin >> numbers[i];
    }

    queue<Val> q;
    ll minDifference = INT_MAX;
    q.push({0,0,0});
    while(!q.empty()){
        Val val = q.front();
        q.pop();

        if(val.i == n){
            minDifference = min(abs(val.sum1-val.sum2),minDifference);
            continue;
        }

        q.push({val.sum1 + numbers[val.i], val.sum2, val.i + 1});
        q.push({val.sum1, val.sum2 + numbers[val.i], val.i + 1});
    }
    cout << minDifference << endl;
}