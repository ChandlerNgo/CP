#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n; // participants
        int m; // problems
        cin >> n >> m;
        vector<int> participantRating(n);
        vector<int> problemDifficulty(m);

        for(int i = 0; i < n; i++){
            int num;
            cin >> num;
            participantRating[i] = num;
        }
        for(int i = 0; i < m; i++){
            int num;
            cin >> num;
            problemDifficulty[i] = num;
        }
        
    }
}