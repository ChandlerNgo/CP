#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

// ll sum(ll n){
//     if(n == 0 || n == 1){
//         return n;
//     }else{
//         return n + sum(n-1);
//     }
// }

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n;
    cin >> n;

    if(n == 1){
        cout << 1 << endl;
        return 1;
    }

    map<ll,ll> numbers;
    numbers[0] = 1;

    ll currentSum = 0;
    ll total = 0;

    for(ll i = 0; i < n; i++){
        ll num;
        cin >> num;

        currentSum += num;
        
        ll remainder = currentSum % n;

        if(remainder < 0){
            remainder += n;
        }

        if(numbers.find(remainder) == numbers.end()){
            numbers[remainder] = 1;
        }else{
            total += numbers[remainder];
            numbers[remainder] += 1;
        }
    }

    cout << total << endl;
}