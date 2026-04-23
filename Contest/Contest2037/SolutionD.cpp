#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

bool inHurdle(vector<pair<int,int>> hurdles, int i){
    for(int i = 0; i < hurdles.size(); i++){
        if(i >= hurdles[i].first && i <= hurdles[i].second){
            return true;
        }
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        int n;
        int m;
        int L;
        cin >> n >> m >> L;
        vector<pair<int,int>> hurdles;
        for(int j = 0; j < n; j++){
            int l;
            int r;
            cin >> l >> r;
            hurdles.push_back({l,r});
        }

        vector<pair<int,int>> powerUps; // (index, powerup bonus)

        for(int j = 0; j < m; j++){
            int x;
            int v;
            cin >> x >> v;
            powerUps.push_back({x,v});
        }

        int currentJumpPower = 0;
        // loop through all hurdles
        // for each hurdle
        //   loop through the powerups til powerup index > right of hurdle
        int powerUpIndex = 0;
        int amountPowerUps = 0;
        priority_queue<int> potentialPowerUps;
        for(int j = 0; j < n; j++){
            int hurdleLength = hurdles[j].second - hurdles[j].first + 1;
            while(powerUpIndex < m && powerUps[powerUpIndex].first <= hurdles[j].second){
                potentialPowerUps.push(powerUps[powerUpIndex].second);
                powerUpIndex += 1;
            }


            while(currentJumpPower < hurdleLength && !potentialPowerUps.empty()){
                currentJumpPower += potentialPowerUps.top();
                potentialPowerUps.pop();
                amountPowerUps += 1;
            }

            if(currentJumpPower < hurdleLength){
                amountPowerUps = -1;
                break;
            }
        }
        cout << amountPowerUps << endl;
    }
}