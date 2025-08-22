#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while(t--){
        ll n; ll x; ll y;
        cin >> n >> x >> y;
        ll currentSum = 0;
        vector<ll> numbers;
        for(ll j = 0; j < n; j++){
            ll num;
            cin >> num;
            currentSum += num;
            numbers.push_back(num);
        }
        ll lowerBound = currentSum - y;
        ll upperBound = currentSum - x;
        ll left = 0;
        ll right = numbers.size()-1;
        sort(numbers.begin(),numbers.end());
        ll pairs = 0;
        while(right > left){
            ll curSum = numbers[left] + numbers[right];
            if()
        }
    }
}