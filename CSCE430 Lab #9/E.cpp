#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;

    vector<ll> cards(n,0);


    for(ll i = 0; i < n; i++){
        ll card;
        cin >> card;
        cards[i] = card;
    }

    sort(cards.begin(),cards.end());
    
    ll q;
    cin >> q;
    for(ll i = 0; i < q; i++){
        ll start;
        ll end;
        cin >> start >> end;
        if(end < 0 || start > 1E9){
            cout << 0 << endl;
            // cout << (end < 0) << " " << (start > (1E9)) << endl;
        }else{
            auto left = lower_bound(cards.begin(),cards.end(),start);
            auto right = lower_bound(cards.begin(),cards.end(),end+1);
            cout << (right - cards.begin())-(left-cards.begin()) << endl;
        }
    }
}