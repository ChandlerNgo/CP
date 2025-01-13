#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
// 
int dp(string& game, int i, int firstTeamScore, int secondTeamScore, bool currentTeam){
    // return if
    if(i == 10){
        return min(10,10-abs(firstTeamScore-secondTeamScore));
    }
    int remainingGames = 10-i+1;
    if(abs(firstTeamScore-secondTeamScore) > remainingGames){
        return i;
    }
    if(game[i] == '1'){
        if(currentTeam){
            firstTeamScore += 1;
        }else{
            secondTeamScore += 1;
        }
    }else if(game[i] == '?'){
        return min(dp(game, i+1, firstTeamScore+1, secondTeamScore, !currentTeam),dp(game, i+1, firstTeamScore, secondTeamScore+1, !currentTeam));
    }
    return dp(game, i+1, firstTeamScore, secondTeamScore, !currentTeam);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    for(int i = 0; i < t; i++){
        string kicks;
        cin >> kicks;
        cout << dp(kicks,0,0,0,true) << endl;
    }
    
}