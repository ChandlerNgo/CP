#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // n = x * ( 1 + 10^k )
    int t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;

        ll amount = 10;
        vector<ll> nums;
        while(1+amount <= n){
            if(n % (1+amount) == 0){
                // possible x
                nums.push_back(n/(1+amount));
            }
            amount *= 10;
        }
        cout << nums.size() << "\n";
        sort(nums.begin(),nums.end());
        for(int i = 0; i < nums.size(); i++){
            cout << nums[i];
            if(i == nums.size()-1){
                cout << "\n";
            }else{
                cout << " ";
            }
        }
    }
}