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
        map<ll,ll> numberDict;
        for(ll j = 0; j < n; j++){
            ll num;
            cin >> num;
            currentSum += num;
            numbers.push_back(num);
            if(numberDict.find(num) == numberDict.end()){
                numberDict[num] = 1;
            }else{
                numberDict[num] += 1;
            }
        }
        ll pairAmount = 0;
        for(auto i = numberDict.begin(); i != numberDict.end(); i++){
            for(auto j = i; j != numberDict.end(); j++){
                if(i->first != j->first){
                    ll target = currentSum - (i->first + j->first);
                    if(target >= x && target <= y){
                        pairAmount += (i->second*j->second);
                    }
                }else{
                    if(i->second > 1){
                        ll target = currentSum - (i->first + i->first);
                        if(target >= x && target <= y){
                            pairAmount += (i->second*(i->second-1))/2;
                        }
                    }
                }
            }
        }
        cout << pairAmount << endl;
    }
}