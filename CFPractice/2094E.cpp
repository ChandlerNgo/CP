#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        vector<ll> numbers;
        vector<string> nums;
        vector<bool> xorVals;
        int trueVals = 0;
        vector<int> ones(32,0);
        vector<int> zeros(32,0);
        for(ll i = 0; i < n; i++){
            ll num;
            cin >> num;
            numbers.push_back(num);
            string s = bitset<32>(num).to_string();
            nums.push_back(s);
            for(int j = 0; j < s.size(); j++){
                if(s[j] == '0'){
                    zeros[j] += 1;
                }else{
                    ones[j] += 1;
                }
            }
        }



        ll xorSum = 0;
        for(int i = 0; i < n; i++){
            ll curSum = 0;
            for(int j = 0; j < 32; j++){
                if(numbers[i] & (1LL << 31-j)){
                    curSum += ((1LL << 31-j) * zeros[j]);
                }else{
                    curSum += ((1LL << 31-j) * ones[j]);
                }
            }
            xorSum = max(xorSum,curSum);
        }
        cout << xorSum << "\n";
    }
}