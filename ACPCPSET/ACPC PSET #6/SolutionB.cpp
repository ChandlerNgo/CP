#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int detectWin(char me, char them){
    if(me == 'R' && them == 'S'){
        return 1;
    }else if(me == 'S' && them == 'P'){
        return 1;
    }else if(me == 'P' && them == 'R'){
        return 1;
    }else if(me == them){
        return 0;
    }else{
        return -100;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    string s;
    cin >> n >> s;

    int dp[n][3];

    dp[0][0] = detectWin('R',s[0]);
    dp[0][1] = detectWin('S',s[0]);
    dp[0][2] = detectWin('P',s[0]);

    for(int i = 1; i < n; i++){
        dp[i][0] = detectWin('R',s[i]) + max(dp[i-1][1],dp[i-1][2]);
        dp[i][1] = detectWin('S',s[i]) + max(dp[i-1][0],dp[i-1][2]);
        dp[i][2] = detectWin('P',s[i]) + max(dp[i-1][1],dp[i-1][0]);
    }

    cout << max({dp[n-1][0],dp[n-1][1],dp[n-1][2]});
}