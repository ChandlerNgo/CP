#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int dp(vector<vector<int>>& memo, vector<vector<int>>& activities, int i, int activity){
    if(i == memo[0].size()-1){
        memo[activity][i] = activities[activity][i];
        return memo[activity][i];
    }

    if(memo[activity][i] == -1){
        if(activity == 0){
            memo[activity][i] = activities[activity][i] + max(dp(memo, activities, i+1, 1), dp(memo, activities, i+1, 2));
        }else if(activity == 1){
            memo[activity][i] = activities[activity][i] + max(dp(memo, activities, i+1, 0), dp(memo, activities, i+1, 2));
        }else{
            memo[activity][i] = activities[activity][i] + max(dp(memo, activities, i+1, 1), dp(memo, activities, i+1, 0));
        }
    }else{
        if(activity == 0){
            memo[activity][i] = max(memo[activity][i], activities[activity][i] + max(activities[1][i+1],activities[2][i+1]));
        }else if(activity == 1){
            memo[activity][i] = max(memo[activity][i], activities[activity][i] + max(activities[0][i+1],activities[2][i+1]));
        }else{
            memo[activity][i] = max(memo[activity][i], activities[activity][i] + max(activities[1][i+1],activities[0][i+1]));
        }
    }

    return memo[activity][i];
}

// do top down silly goose

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        int n;
        cin >> n;
        vector<vector<int>> activities;
        vector<vector<int>> memos;
        for(int j = 0; j < 3; j++){
            vector<int> activity(n);
            vector<int> memo(n);
            for(int k = 0; k < n; k++){
                int num;
                cin >> num;
                activity[k] = num;
                memo[k] = -1;
            }
            activities.push_back(activity);
            memos.push_back(memo);
        }

        cout << dp(memos, activities, 0, 0) << endl;
        cout << dp(memos, activities, 0, 1) << endl;
        cout << dp(memos, activities, 0, 2) << endl;
    }
}