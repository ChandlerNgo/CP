#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int x;
    int y;
    int z;
    string s;
    cin >> x >> y >> z >> s;
    // x: normal press
    // y: shift + press
    // z: caps lock

    int dp[2][s.size()];

    if(s[0] == 'a'){
        dp[0][0] = x;
        dp[1][0] = z + y;
    }else{
        dp[0][0] = y;
        dp[1][0] = z + x;
    }

    
}