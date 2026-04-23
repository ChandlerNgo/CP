#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<vector<int>> numbers(n+1);
    for(int i = 1; i <= n; i++){
        vector<int> nums;
        
        int a;
        int b;
        int c;
        cin >> a >> b >> c;
        nums[0] = a;
        nums[1] = b;
        nums[2] = c;
        numbers[i] = nums;
    }

    int dp[n+1][3];
    dp[1][0] = numbers[1][0];
    dp[1][1] = numbers[1][1];
    dp[1][2] = numbers[1][2];

    for(int i = 2; i < n; i++){
        dp[i][0] = numbers[i][0] + max(dp[i-1][1],dp[i-1][2]);
        dp[i][1] = numbers[i][1] + max(dp[i-1][0],dp[i-1][2]);
        dp[i][2] = numbers[i][2] + max(dp[i-1][1],dp[i-1][0]);
    }

    cout << max({dp[n][0],dp[n][1],dp[n][2]});
}