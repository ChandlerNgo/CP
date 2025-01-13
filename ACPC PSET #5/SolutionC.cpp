#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll findMachines(vector<ll>& machines, ll time, ll target){
    ll amtOfMachines = 0;
    for(ll i = 0; i < machines.size(); i++){
        if(amtOfMachines > target){
            return LLONG_MAX;
        }
        amtOfMachines += time/machines[i];
    }
    return amtOfMachines;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n; ll t;
    cin >> n >> t;
    vector<ll> numbers;
    for(ll i = 0; i < n; i++){
        ll num;
        cin >> num;
        numbers.push_back(num);
    }

    ll l = 0;
    ll r = LLONG_MAX;
    while(l <= r){
        ll mid = (r + l)/2;
        if(findMachines(numbers, mid, t) < t){
            l = mid + 1;
        }else{
            r = mid - 1;
        }
    }
    cout << l << endl;
}