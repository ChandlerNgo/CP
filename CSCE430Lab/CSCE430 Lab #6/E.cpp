#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    vector<ll> numbers;
    for(ll i = 0; i < n; i++){
        ll num;
        cin >> num;
        numbers.push_back(num);
    }

    sort(numbers.begin(),numbers.end());
    ll maxIndex = 0;
    for(ll i = n-1; i >= 0; i--){
        maxIndex = max(maxIndex,min((n-1)-i+1,numbers[i]));
    }
    cout << maxIndex << endl;
}