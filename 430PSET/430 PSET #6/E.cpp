#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

void printPriests(const vector<map<int, int>>& priests) {
    cout << "Priests' Preference Rankings:\n";
    for (int i = 0; i < priests.size(); i++) {
        cout << "Priest " << i << ": ";
        for (auto& p : priests[i]) {
            cout << "(" << p.first << " -> " << p.second << ") ";
        }
        cout << endl;
    }
    cout << endl;
}

void printInversedPriests(const vector<map<int, int>>& inversedPriests) {
    cout << "Inversed Priests' Rankings (Rank -> Option):\n";
    for (int i = 0; i < inversedPriests.size(); i++) {
        cout << "Priest " << i << ": ";
        for (auto& p : inversedPriests[i]) {
            cout << "(" << p.first << " -> " << p.second << ") ";
        }
        cout << endl;
    }
    cout << endl;
}

void printDPTable(vector<vector<int>>& dp) {
    cout << "DP Table:\n";
    for (int i = dp.size()-2; i >= 0; i--) {
        cout << "Priest " << i << ": ";
        for (int j = 0; j < 8; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    map<int,string> intToOutcome;

    intToOutcome[0] = "NNN";
    intToOutcome[1] = "NNY";
    intToOutcome[2] = "NYN";
    intToOutcome[3] = "NYY";
    intToOutcome[4] = "YNN";
    intToOutcome[5] = "YNY";
    intToOutcome[6] = "YYN";
    intToOutcome[7] = "YYY";

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<map<int,int>> priests(n,map<int,int>()); // priest {option, rank}
        vector<map<int,int>> inversedPriests(n,map<int,int>()); // inversedPriest {rank, option}
        vector<vector<int>> dp(n+1,vector<int>(8,1e6)); // i : priest, j : results
        for(int i = 0; i < n; i++){
            for(int j = 0; j < 8; j++){
                int num;
                cin >> num;
                inversedPriests[i][num-1] = j;
                priests[i][j] = num-1;
            }
        }

        for(int i = 0; i < 8; i++){
            dp[n][i] = i;
        }


        // printPriests(priests);
        // printInversedPriests(inversedPriests);

        for(int i = n-1; i >= 0; i--){
            for(int j = 0; j < 8; j++){
                vector<int> newStates;
                newStates.push_back(j ^ 1);
                newStates.push_back(j ^ 2);
                newStates.push_back(j ^ 4);

                dp[i][j] = inversedPriests[i][min({priests[i][dp[i+1][newStates[0]]],priests[i][dp[i+1][newStates[1]]],priests[i][dp[i+1][newStates[2]]]})];

            }
            // cout << endl;
        }

        cout << intToOutcome[dp[0][0]] << endl;
        // printDPTable(dp);
    }
}