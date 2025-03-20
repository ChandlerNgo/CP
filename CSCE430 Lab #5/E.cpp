#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

struct Team{
    ll team;
    ll count;
    ll penalty;
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n; ll m;
    cin >> n >> m;
    struct myComp {
        constexpr bool operator()(
            Team const& a,
            Team const& b)
            const noexcept
        {   
            if(a.count == b.count){
                return a.penalty > b.penalty;
            }
            return a.count < b.count;
        }
    };
    priority_queue<Team, vector<Team>,myComp> bestTeam; // penalty,team
    priority_queue<Team, vector<Team>,myComp> copyTeam; // penalty,team
    vector<ll> count(n+1,0);
    vector<ll> penalty(n+1,0);

    
    for(int i = 0; i < m; i++){
        ll team;
        ll ppenalty;
        cin >> team >> ppenalty;
        count[team] += 1;
        penalty[team] += ppenalty;
        cout << count[team] << " " << penalty[team] << endl;
        bestTeam.push({team,count[team],penalty[team]});
        cout << bestTeam.top().team << endl;
    }
}