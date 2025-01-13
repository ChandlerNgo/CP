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
        ll x;
        cin >> n >> x;
        priority_queue<ll> numbers; // max_heap
        for(ll i = 0; i < n; i++){
            ll num;
            cin >> num;
            numbers.push(num);
        }

        ll people = 0;
        
        while(!numbers.empty()){
            priority_queue<ll, vector<ll>, greater<ll>> nums;
            for(ll i = 0; i < x && !numbers.empty(); i++){
                ll num = numbers.top();
                if(num > 0){
                    nums.push(num);
                }
                numbers.pop();
            }
            ll curMin = nums.top();
            while(!nums.empty()){
                if(nums.top() > curMin){
                    numbers.push(nums.top() - curMin);
                }
                nums.pop();
            }
            people += curMin;
        }
        cout << people << endl;
    }
}