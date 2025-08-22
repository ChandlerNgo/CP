#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        priority_queue<ll> oddTower;
        ll evenSum = 0;
        ll oddSum = 0;
        ll answer = 0;
        ll maxEvenNumber = 0;
        for(ll i = 0; i < n; i++){
            ll num;
            cin >> num;
            if(num % 2 == 1){
                oddTower.push(num);
            }else{
                maxEvenNumber = max(maxEvenNumber,num);
                evenSum += num;
            }
        }

        if(oddTower.empty()){
            cout << maxEvenNumber << "\n";
            continue;
        }else{
            answer = oddTower.top();
            oddTower.pop();
            while(!oddTower.empty()){
                oddSum += (oddTower.top()-1);
                oddTower.pop();
            }
            if(evenSum > 0){
                answer += (evenSum + oddSum);
                cout << answer << "\n";
            }else{
                cout << answer << "\n";
            }
        }
    }   
}