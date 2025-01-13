#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll bs(ll val, vector<ll>& numbers){
    ll l = 0;
    ll r = numbers.size()-1;
    while(l <= r){
        ll mid = (l + r)/2;

        if(numbers[mid] <= val){
            l = mid + 1;
        }else{
            r = mid - 1;
        }
    }
    return l;
}

int main(){

    freopen("haybales.in","r",stdin);
    freopen("haybales.out","w",stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    ll q;
    cin >> n >> q;
    vector<ll> numbers;
    for(ll i = 0; i < n; i++){
        ll num;
        cin >> num;
        numbers.push_back(num);
    }

    sort(numbers.begin(),numbers.end());

    for(ll i = 0; i < q; i++){
        ll a;
        ll b;
        cin >> a >> b;
        
        cout << bs(b,numbers) - bs(a-1,numbers) << '\n';
    }

}