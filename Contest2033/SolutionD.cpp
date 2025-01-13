#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while(t--){
        set<ll> numbers;
        ll currentSum = 0;
        ll n;
        cin >> n;
        ll segments = 0;
        for(ll i = 0; i < n; i++){
            ll num;
            cin >> num;
            if(num == 0){
                numbers.clear();
                segments += 1;
                currentSum = 0;
                continue;
            }

            currentSum += num;

            if(currentSum != 0 && numbers.find(currentSum) == numbers.end()){
                numbers.insert(currentSum);
            }else{
                numbers.clear();
                segments += 1;
                currentSum = 0;
            }
        }
        cout << segments << endl;
    }
}