#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    for(ll i = 0; i < t; i++){
        ll n;
        cin >> n;
        vector<ll> a;
        vector<ll> b;
        for(ll j = 0; j < n; j++){
            ll num;
            cin >> num;
            a.push_back(num);
        }
        for(ll j = 0; j < n; j++){
            ll num;
            cin >> num;
            b.push_back(num);
        }

        for(ll j = 0; j < n; j++){
            if(j % 2 == 0){
                // maximize a minimize b
                ll curIndex = -1;
                for(ll k = 0; k < n; k++){
                    if(a[k] > 0 && b[k] > 0){
                        if(b[k] > b[curIndex]){
                            curIndex = k;
                        }else if(b[k] == b[curIndex] && a[k] > a[curIndex]){
                            curIndex = k;
                        }
                    }
                }
                a[curIndex] -= 1;
                b[curIndex] = 0;
            }else{
                // maximize b minimize a
                ll curIndex = -1;
                for(ll k = 0; k < n; k++){
                    if(a[k] > 0 && b[k] > 0){
                        if(a[k] > a[curIndex]){
                            curIndex = k;
                        }else if(a[k] == a[curIndex] && b[k] > b[curIndex]){
                            curIndex = k;
                        }
                    }
                }
                a[curIndex] = 0;
                b[curIndex] -= 1;
            }
        }
        ll aScore = 0;
        ll bScore = 0;

        for(ll i = 0; i < n; i++){
            aScore += a[i];
            bScore += b[i];
        }

        cout << aScore - bScore << endl;
    }
}