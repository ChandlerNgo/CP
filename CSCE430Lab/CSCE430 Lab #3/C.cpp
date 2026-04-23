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
        ll m;
        cin >> n >> m;
        map<ll,ll> prizes;
        vector<ll> tickets;
        for(ll i = 0; i < n; i++){
            ll amount;
            cin >> amount;
            ll prizeTickets;
            for(ll j = 0; j < amount; j++){
                ll num;
                cin >> num;
                prizeTickets += (1 << num);
            }
            ll prizeAmount;
            cin >> prizeAmount;
            prizes[prizeTickets] = prizeAmount;
        }
        for(ll i = 0; i < m; i++){
            ll ticket;
            cin >> ticket;
            tickets.push_back(ticket);
        }
        queue<pair<ll,vector<ll>>> ourPrizes;

        ll currentTickets = 0;
        for(ll i = 0; i < m; i++){
            if(tickets[i] != 0){
                currentTickets += (1 << i+1);
            }
        }

        for(auto i = prizes.begin(); i != prizes.end(); i++){
            if(i->first & currentTickets == i->first){
                vector<ll> ourTickets = tickets;
                bool good = true;
                for(ll j = 1; j <= 32; j++){
                    if(i->first >> j){
                        if(!(currentTickets >> j)){
                            good = false;
                            break;
                        }
                    }
                }
                if(good){
                    for(ll j = 1; j <= 32; j++){
                        if(i->first >> j){
                            if(!(currentTickets >> j)){
                                good = false;
                                break;
                                ourTickets[j-1] -= 1;
                            }
                        }
                    }
                    ourPrizes.push({i->second,ourTickets});
                }
            }
        }

        cout << "prize size: " << ourPrizes.size() << endl;


        ll maxPrizeWinning = 0;
        while(!ourPrizes.empty()){
            pair<ll,vector<ll>> temp = ourPrizes.front();
            ourPrizes.pop();
            vector<ll> ourTickets = temp.second;
            currentTickets = 0;
            for(ll i = 0; i < m; i++){
                if(ourTickets[i] != 0){
                    currentTickets += (1 << i+1);
                }
            }

            for(auto i = prizes.begin(); i != prizes.end(); i++){
                if(i->first & currentTickets == i->first){
                    bool good = true;
                    for(ll j = 1; j <= 32; j++){
                        if(i->first >> j){
                            if(!(currentTickets >> j)){
                                good = false;
                                break;
                            }
                        }
                    }
                    if(good){
                        for(ll j = 1; j <= 32; j++){
                            if(i->first >> j){
                                ourTickets[j-1] -= 1;
                            }
                        }
                        ourPrizes.push({temp.first + i->second,ourTickets});
                    }
                }
            }
            maxPrizeWinning = max(maxPrizeWinning,temp.first);
        }
        cout << maxPrizeWinning << "\n";
    }
    cout << flush;
}