#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

struct Player{
    string name;
    double leg1;
    double leg2;
};

bool comp(Player a, Player b) {
    return a.leg2 < b.leg2;
};

bool comp1(Player a, Player b){
    return a.leg1 < b.leg1;
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<Player> leg1guys;
    vector<Player> leg2guys;

    for(int i = 0; i < n; i++){
        string name;
        double leg1;
        double otherleg;
        leg1guys.push_back({name,leg1,otherleg});
        leg2guys.push_back({name,leg1,otherleg});
    }
    sort(leg1guys.begin(), leg1guys.end(), comp);
    sort(leg2guys.begin(), leg2guys.end(), comp1);
    vector<Player> players;
    float fastest = 10000000;
    for(int i = 0; i < n; i++){
        vector<Player> players1;
        float time = 0;
        players1.push_back(leg1guys[i]);
        time += leg1guys[i].leg1;
        for(int j = 0; j < n; j++){
            if(players1.size() == 4){
                break;
            }
            if(players1[0].name != leg2guys[j].name){
                time += leg2guys[j].leg2;
                players1.push_back(leg2guys[j]);
            }
        }
        if(time < fastest){
            time = fastest;
            players = players1;
        }
    }
    cout << fastest << endl;
    for(int i = 0; i < players.size(); i++){
        cout << players[i].name << endl;
    }
}