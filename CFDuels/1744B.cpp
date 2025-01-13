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
        ll q;
        cin >> n >> q;
        ll odd = 0;
        ll even = 0;
        ll sum = 0;
        for(ll j = 0; j < n; j++){
            ll num;
            cin >> num;
            if(num % 2 == 0){
                even += 1;
            }else{
                odd += 1;
            }
            sum += num;
        }
        for(ll j = 0; j < q; j++){
            ll type;
            ll amount;
            cin >> type >> amount;
            if(type == 0){
                if(amount % 2 == 0){
                    sum += (amount * even);
                }else{
                    sum += (amount * even);
                    odd += even;
                    even = 0;
                }
            }else{
                if(amount % 2 == 0){
                    sum += (amount * odd);
                }else{
                    sum += (amount * odd);
                    even += odd;
                    odd = 0;
                }
            }
            cout << sum << endl;
        }
    }
}