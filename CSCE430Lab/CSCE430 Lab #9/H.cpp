#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

bool search(vector<ll>& numbers, ll k){
    ll nums = 1;
    for(ll i = k+k; i < numbers.size(); i += k){
        nums += 1;
        if(numbers[i] <= numbers[i-k]){
            return false;
        }
    }

    if(nums < 2){
        return false;
    }else{
        return true;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    vector<ll> numbers(n+1, 0);
    for(ll i = 1; i <= n; i++){
        cin >> numbers[i];
    }

    for(int k = 1; k <= n/2; k++){
        if(search(numbers, k)){
            cout << k << endl;
            return 0;
        }
    }
    cout << "ABORT!" << endl;
}